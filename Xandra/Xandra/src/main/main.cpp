#include "Version.h"
#include "GL.h"
#include "Render.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
    {
        std::cout << "GLFW Initialization Error! (Make sure to use glfwInit())" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Solo Renderer", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLFW Initialization Error! (Make sure to use glewInit())" << std::endl;
        glfwTerminate();
        return -1;
    }

    DisplayVersions();

    float positions[] = {
        -0.5f, -0.5f, // 0
         0.5f, -0.5f, // 1
         0.5f,  0.5f, // 2
        -0.5f,  0.5f  // 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    VertexArray va;
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));
    IndexBuffer ib(indices, 6);

    glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

    VertexBufferLayout layout;
    layout.Push<float>(2);

    va.AddBuffer(vb, layout);

    Shader shader("res/shaders/Shader.shader");
    shader.Bind();
    shader.SetUniform4f("u_MVP", proj);

    Render renderer;


    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();

        shader.Bind();

        renderer.Draw(va, ib, shader);

        GL(glfwSwapBuffers(window));

        GL(glfwPollEvents());
    }

    glfwTerminate();
    return 0;
}