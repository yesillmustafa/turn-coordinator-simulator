#ifndef TurnCordinator_hpp
#define TurnCordinator_hpp

#include "shaderProgram.hpp"
#include <glm/glm.hpp>

class VertexArrayObject;
class TCManager;

class TurnCordinator
{
    
public:

    glm::vec3 m_Color;

    void draw();

private:
    VertexArrayObject* m_Vao;
    unsigned int m_IndexCount;
    unsigned int m_VertexCount;

    friend TCManager;
};

#endif