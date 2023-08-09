#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "shaderProgram.hpp"
#include <vector>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "VertexArrayObject.hpp"
#include "texturemanager.hpp"
#include "TCManager.hpp"
#include "TurnCordinator.hpp"
#include <cmath>

TurnCordinator* circleFrame;
TurnCordinator* needle;
TurnCordinator* ball;

unsigned int texture1;

float rateOfTurn = 0.0f;
float rotationValue = 0.0f; // İğnenin dönüş açısı değeri
float skid_slip_amount = 0.0f;

std::string direction;
std::string state;

// klavyeden girdi alma
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        if (key == GLFW_KEY_A)
        {
            rateOfTurn += 0.1f;
        }
        else if (key == GLFW_KEY_D)
        {
            rateOfTurn -= 0.1f; 
        }
        else if (key == GLFW_KEY_RIGHT)
        {
            if(skid_slip_amount < 0.22f){
            skid_slip_amount += 0.01f;

            }
        }
        else if (key == GLFW_KEY_LEFT)
        {
            if(skid_slip_amount > -0.22f){
            skid_slip_amount -= 0.01f;

            }
        }
    }
}

int main(int argc,char** argv)
{
    if(!glfwInit())
        return -1;

    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800,800,"Turn Cordinator",NULL,NULL);
    
    
    if(window==NULL)
    {
        std::cout<<"Pencere Olusturulamadi"<<std::endl;

        glfwTerminate();

        return -1;
    }    

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }



    texture1 = TextureManager::getInstance()->loadTexture("../images/tc_texture.jpg");
    
    TCManager* tcmanager = TCManager::getInstance();
    circleFrame = tcmanager->createCircle();
    needle = tcmanager->createNeedle();
    ball = tcmanager->createBall();

    ShaderProgram program;

    program.attachShader("../shaders/vertexShaderSource.glsl",GL_VERTEX_SHADER);
    program.attachShader("../shaders/fragmentShaderSource.glsl",GL_FRAGMENT_SHADER);
    program.link();

    unsigned int modelMatrixLocation = program.getModelMatrixLocation();
    unsigned int colorLocation = glGetUniformLocation(program.getProgramId(), "color");

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        rotationValue = rateOfTurn * 6.0f;
        
        //çizimde kullanılacak olan program nesnesi aktif ediliyor
        program.use();

        // Çemberin (circleFrame) model matrisini sabit bir matris olarak belirleyin
        glm::mat4 circleModelMatrix = glm::mat4(1.0f);
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(circleModelMatrix));
        glUniform1i(glGetUniformLocation(program.getProgramId(), "useTexture"), true);

        circleFrame->draw();

        glm::mat4 modelMatrix = glm::mat4(1.0f); // modelMatrix'i tanımlayın ve varsayılan değerle başlatın
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationValue), glm::vec3(0.0f, 0.0f, 1.0f)); // İğnenin dönüşünü burada gerçekleştirin
        // Model matrisini OpenGL'ye gönder
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        glUniform3fv(colorLocation, 1, glm::value_ptr(needle->m_Color));
        glUniform1i(glGetUniformLocation(program.getProgramId(), "useTexture"), false);

        needle->draw();

        glm::mat4 ballModelMatrix = glm::mat4(1.0f);
        ballModelMatrix = glm::translate(ballModelMatrix, glm::vec3(skid_slip_amount, 0.0f, 0.0f));
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(ballModelMatrix));
        // Topun rengini OpenGL'ye gönder
        glUniform3fv(colorLocation, 1, glm::value_ptr(ball->m_Color));
        glUniform1i(glGetUniformLocation(program.getProgramId(), "useTexture"), false);

        ball->draw();


        // rateOfTurn değerine göre yön bilgisini belirle
        if (rateOfTurn > 0.0f && skid_slip_amount >= -0.01f && skid_slip_amount <= 0.01f)
        {
            state = "The aircraft is 'Turning Left' and doing 'Coordinated Flight'";
        }
        else if (rateOfTurn < 0.0f && skid_slip_amount >= -0.01f && skid_slip_amount <= 0.01f)
        {
            state = "The aircraft is 'Turning Right' and doing 'Coordinated Flight'";
        }
        else if (rateOfTurn > 0.0f && skid_slip_amount <-0.01f)
        {
            state = "The aircraft is 'Turning Left' and 'Slipping'";
        }
        else if (rateOfTurn < 0.0f && skid_slip_amount >0.01f)
        {
            state = "The aircraft is 'Turning Right' and 'Slipping'";
        }
        else if (rateOfTurn > 0.0f && skid_slip_amount >0.01f)
        {
            state = "The aircraft is 'Turning Left' and 'Skidding'";
        }
        else if (rateOfTurn < 0.0f && skid_slip_amount <-0.01f)
        {
            state = "The aircraft is 'Turning Right' and 'Skidding'";
        }
        else if(std::round(rateOfTurn) == 0.0f )
        {
            state = "The aircraft is in a 'Stable Flight'";
        }
        
        const float epsilon = 0.0001f; // Yaklaşık 0.0 kabul edilecek epsilon değeri
        if (std::fabs(rateOfTurn) < epsilon)
        {
        rateOfTurn = 0.0f; // Yaklaşık olarak 0.0 olarak kabul edilirse tamamen 0.0 yap
        }

        // Konsola durumu ve yön bilgisini yazdırma
        std::cout << "\rState: " << state << " | " <<"Turning Speed: "<<std::abs(rateOfTurn)<<"°/sc"<<"                                    "<< std::flush;
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

}