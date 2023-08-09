#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include<string>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
   
    void attachShader(const char* fileName,unsigned int shaderType);
    void link();
    void use();
    unsigned int getModelMatrixLocation();
    unsigned int getProgramId();

private:
    std::string getShaderFromFile(const char* fileName);

    unsigned int m_ProgramId;
    unsigned int modelMatrixLocation;
    unsigned int colorLocation;
  
};

#endif