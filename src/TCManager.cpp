#include "TCManager.hpp"
#include "VertexTypes.hpp"
#include "VertexArrayObject.hpp"
#include "TurnCordinator.hpp"

#include <glm/glm.hpp>


TCManager* TCManager::m_Instance = nullptr;

TCManager::TCManager()
{

}

TCManager* TCManager::getInstance()
{
    if(m_Instance==nullptr)
    {
        m_Instance = new TCManager();
    }
    return m_Instance;
}

TurnCordinator* TCManager::createCircle()
{
    Vertex3TexList vertices;
    IndexList indices;

    float radius = 0.8f;
    int numSegments = 72;

    float angle = 360.0f / numSegments;
    int vertexCount = numSegments + 1; // Include the center vertex

    vertices.clear();
    indices.clear();

    Vertex3Tex centerVertex;
    centerVertex.pos = glm::vec3(0.0f, 0.0f, 0.0f);
    centerVertex.tex = glm::vec2(0.5f, 0.5f); // Texture center coordinates
    vertices.push_back(centerVertex);

    for (int i = 0; i < vertexCount; i++) {
        float newAngle = i * angle;
        float x = radius * cos(glm::radians(newAngle));
        float y = radius * sin(glm::radians(newAngle));
        float z = 0.0f;

        Vertex3Tex vertex;
        vertex.pos = glm::vec3(x, y, z);
        vertex.tex = glm::vec2((cos(glm::radians(newAngle)) + 1.0f) * 0.5f, (sin(glm::radians(newAngle)) + 1.0f) * 0.5f); // Texture coordinates
        vertices.push_back(vertex);
    }

    for (int i = 0; i < numSegments; i++) {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }

    VertexArrayObject* vao = new VertexArrayObject();
    vao->build(vertices,indices);
    TurnCordinator* tc = new TurnCordinator();
    tc->m_Vao = vao;
    tc->m_IndexCount = indices.size();
    tc->m_VertexCount = vertices.size();


    return tc;
}

TurnCordinator* TCManager::createNeedle()
{
    Vertex3List vertices;
    IndexList indices;

    // Define the dimensions of the rectangle
    float width = 0.9f;
    float height = 0.04f;
    float innerWidth = 0.02f;
    float innerHeight = 0.1f;
    float innerWidth2 = 0.3f;
    float innerHeight2 = 0.02f;
    float temp = 0.06f;

    TurnCordinator* circle = createCircle();

    // Define the vertices of the rectangle
    Vertex3 vertex;
    vertex.pos = glm::vec3(-width / 2.0f, -height / 2.0f - temp, 0.0f); //0. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(width / 2.0f, -height / 2.0f - temp, 0.0f); //1. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(width / 2.0f, height / 2.0f - temp, 0.0f); //2. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(-width / 2.0f, height / 2.0f - temp, 0.0f); //3. index
    vertices.push_back(vertex);


    vertex.pos = glm::vec3(-innerWidth / 2.0f, innerHeight, 0.0f); //4. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(innerWidth / 2.0f, innerHeight, 0.0f); //5. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(innerWidth / 2.0f, -temp, 0.0f); //6. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(-innerWidth / 2.0f, -temp, 0.0f); //7. index
    vertices.push_back(vertex);
    //
    vertex.pos = glm::vec3(-innerWidth2 / 2.0f, innerHeight2, 0.0f); //8. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(innerWidth2 / 2.0f, innerHeight2, 0.0f); //9. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(innerWidth2 / 2.0f, 0, 0.0f); //10. index
    vertices.push_back(vertex);

    vertex.pos = glm::vec3(-innerWidth2 / 2.0f, 0, 0.0f); //11. index
    vertices.push_back(vertex);


    // Define the indices of the rectangle (two triangles to form a rectangle)
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);

    indices.push_back(4);
    indices.push_back(5);
    indices.push_back(6);

    indices.push_back(4);
    indices.push_back(6);
    indices.push_back(7);

    indices.push_back(8);
    indices.push_back(9);
    indices.push_back(10);

    indices.push_back(8);
    indices.push_back(10);
    indices.push_back(11);

    //dairesi
    float radius = 0.08f;
    int numSegments = 72;

    float angle = 360.0f / numSegments;
    int vertexCount = numSegments + 1; // Include the center vertex
    

    Vertex3 centerVertex;
    centerVertex.pos = glm::vec3(0.0f, 0.0f, 0.0f);
    vertices.push_back(centerVertex);

    for (int i = 0; i < vertexCount; i++) {
        float newAngle = i * angle;
        float x = radius * cos(glm::radians(newAngle));
        float y = radius * sin(glm::radians(newAngle));
        float z = 0.0f;

        Vertex3 vertex;
        vertex.pos = glm::vec3(x, y-temp, z);
        vertices.push_back(vertex);
    }

    for (int i = 0; i < numSegments; i++) {
        indices.push_back(12);
        indices.push_back(12+ i + 1);
        indices.push_back(12+ i + 2);
    }

    // Create a VertexArrayObject and associate the vertices and indices with it
    VertexArrayObject* vao = new VertexArrayObject();
    vao->build(vertices, indices);

    // Create a new TurnCordinator and set its vertex array object and index count
    TurnCordinator* tc = new TurnCordinator();
    tc->m_Vao = vao;
    tc->m_IndexCount = indices.size();
    tc->m_VertexCount = vertices.size();
    tc->m_Color = glm::vec3(1.0f, 1.0f, 1.0f);


    return tc;
}


TurnCordinator* TCManager::createBall()
{
    Vertex3List vertices;
    IndexList indices;

    float radius = 0.042f;
    int numSegments = 72;
    float temp = 0.325f;

    float angle = 360.0f / numSegments;
    int vertexCount = numSegments + 1; // Include the center vertex

    Vertex3 centerVertex;
    centerVertex.pos = glm::vec3(0.0f, -temp, 0.0f);
    vertices.push_back(centerVertex);

    for (int i = 0; i < vertexCount; i++)
    {
        float newAngle = i * angle;
        float x = radius * cos(glm::radians(newAngle));
        float y = radius * sin(glm::radians(newAngle));
        float z = 0.0f;

        Vertex3 vertex;
        vertex.pos = glm::vec3(x,y-temp, z);
        vertices.push_back(vertex);
    }

    for (int i = 0; i < numSegments; i++)
    {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }

    VertexArrayObject* vao = new VertexArrayObject();
    vao->build(vertices, indices);

    // Create a new TurnCordinator and set its vertex array object and index count
    TurnCordinator* tc = new TurnCordinator();
    tc->m_Vao = vao;
    tc->m_IndexCount = indices.size();
    tc->m_VertexCount = vertices.size();
    tc->m_Color = glm::vec3(0.0f, 0.0f, 0.0f);
    return tc;
}