#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "chessshader.h"
#include "Chessgame.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {

    //boilerplate code
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "NeonChess", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    Shader mainShader("chess.vs", "chess.fs");   
    mainShader.use();
    ChessGame game;
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(game.getBoard().getPiece(glm::ivec2(3, 0))->getPieceVertices()), &game.getBoard().getPiece(glm::ivec2(3, 0))->getPieceVertices().front(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    while (!glfwWindowShouldClose(window)) {

        processInput(window);
        glClearColor(100.0f / 255.0f, 166.0f / 255.0f, 234.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        mainShader.use();
        glm::mat4 MVP = glm::mat4(1.0f);
        MVP = glm::translate(MVP, glm::vec3(1.0f, 1.0f, 0.0f));
        MVP = glm::rotate(MVP, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        mainShader.setMat4("MVP", MVP);

        glBindVertexArray(VAO);     
        glDrawArrays(GL_TRIANGLES, 0, game.getBoard().getPiece(glm::ivec2(3, 0))->getPieceVertices().size());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, (GLFW_KEY_ESCAPE)) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}