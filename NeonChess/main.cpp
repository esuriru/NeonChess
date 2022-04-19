#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "chessshader.h"
#include "Chessgame.h"
#include "stb_image.h"

double mousex, mousey;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const glm::vec3 _WHITECOLOUR = glm::vec3(4.0f / 255.0f, 217.0f / 255.0f, 255.0f / 255.0f);
const glm::vec3 _BLACKCOLOUR = glm::vec3(255.0f / 255.0f, 16.0f / 255.0f, 240.0f / 255.0f);

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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Shader mainShader("chessvs", "chessfs");   
    mainShader.use();
    ChessGame game;

    /*float tileVertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 
             0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,      
    };*/

    float tileVertices[] = {
        // positions      // texture coords
     0.5f,  0.5f, 0.0f,    1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,    1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,    0.0f, 1.0f    // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    // world space positions of tiles
    glm::vec3 tilePositions[] = {
        glm::ivec3(8.0f, 0.0f, 2.0f),
        glm::ivec3(7.0f, 0.0f, 2.0f),
        glm::ivec3(6.0f, 0.0f, 2.0f),
        glm::ivec3(5.0f, 0.0f, 2.0f),
        glm::ivec3(4.0f, 0.0f, 2.0f),
        glm::ivec3(3.0f, 0.0f, 2.0f),
        glm::ivec3(2.0f, 0.0f, 2.0f),
        glm::ivec3(1.0f, 0.0f, 2.0f),
        glm::ivec3(8.0f, 1.0f, 2.0f),
        glm::ivec3(7.0f, 1.0f, 2.0f),
        glm::ivec3(6.0f, 1.0f, 2.0f),
        glm::ivec3(5.0f, 1.0f, 2.0f),
        glm::ivec3(4.0f, 1.0f, 2.0f),
        glm::ivec3(3.0f, 1.0f, 2.0f),
        glm::ivec3(2.0f, 1.0f, 2.0f),
        glm::ivec3(1.0f, 1.0f, 2.0f),
        glm::ivec3(8.0f, 2.0f, 2.0f),
        glm::ivec3(7.0f, 2.0f, 2.0f),
        glm::ivec3(6.0f, 2.0f, 2.0f),
        glm::ivec3(5.0f, 2.0f, 2.0f),
        glm::ivec3(4.0f, 2.0f, 2.0f),
        glm::ivec3(3.0f, 2.0f, 2.0f),
        glm::ivec3(2.0f, 2.0f, 2.0f),
        glm::ivec3(1.0f, 2.0f, 2.0f),
        glm::ivec3(8.0f, 3.0f, 2.0f),
        glm::ivec3(7.0f, 3.0f, 2.0f),
        glm::ivec3(6.0f, 3.0f, 2.0f),
        glm::ivec3(5.0f, 3.0f, 2.0f),
        glm::ivec3(4.0f, 3.0f, 2.0f),
        glm::ivec3(3.0f, 3.0f, 2.0f),
        glm::ivec3(2.0f, 3.0f, 2.0f),
        glm::ivec3(1.0f, 3.0f, 2.0f),
        glm::ivec3(8.0f, 4.0f, 2.0f),
        glm::ivec3(7.0f, 4.0f, 2.0f),
        glm::ivec3(6.0f, 4.0f, 2.0f),
        glm::ivec3(5.0f, 4.0f, 2.0f),
        glm::ivec3(4.0f, 4.0f, 2.0f),
        glm::ivec3(3.0f, 4.0f, 2.0f),
        glm::ivec3(2.0f, 4.0f, 2.0f),
        glm::ivec3(1.0f, 4.0f, 2.0f),
        glm::ivec3(8.0f, 5.0f, 2.0f),
        glm::ivec3(7.0f, 5.0f, 2.0f),
        glm::ivec3(6.0f, 5.0f, 2.0f),
        glm::ivec3(5.0f, 5.0f, 2.0f),
        glm::ivec3(4.0f, 5.0f, 2.0f),
        glm::ivec3(3.0f, 5.0f, 2.0f),
        glm::ivec3(2.0f, 5.0f, 2.0f),
        glm::ivec3(1.0f, 5.0f, 2.0f),
        glm::ivec3(8.0f, 6.0f, 2.0f),
        glm::ivec3(7.0f, 6.0f, 2.0f),
        glm::ivec3(6.0f, 6.0f, 2.0f),
        glm::ivec3(5.0f, 6.0f, 2.0f),
        glm::ivec3(4.0f, 6.0f, 2.0f),
        glm::ivec3(3.0f, 6.0f, 2.0f),
        glm::ivec3(2.0f, 6.0f, 2.0f),
        glm::ivec3(1.0f, 6.0f, 2.0f),
        glm::ivec3(8.0f, 7.0f, 2.0f),
        glm::ivec3(7.0f, 7.0f, 2.0f),
        glm::ivec3(6.0f, 7.0f, 2.0f),
        glm::ivec3(5.0f, 7.0f, 2.0f),
        glm::ivec3(4.0f, 7.0f, 2.0f),
        glm::ivec3(3.0f, 7.0f, 2.0f),
        glm::ivec3(2.0f, 7.0f, 2.0f),
        glm::ivec3(1.0f, 7.0f, 2.0f),
        glm::ivec3(8.0f, 8.0f, 2.0f),
        glm::ivec3(7.0f, 8.0f, 2.0f),
        glm::ivec3(6.0f, 8.0f, 2.0f),
        glm::ivec3(5.0f, 8.0f, 2.0f),
        glm::ivec3(4.0f, 8.0f, 2.0f),
        glm::ivec3(3.0f, 8.0f, 2.0f),
        glm::ivec3(2.0f, 8.0f, 2.0f),
        glm::ivec3(1.0f, 8.0f, 2.0f),
    };
    //texture tile
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tileVertices), tileVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int chessPieceTexture, tileTexture, selectedTileTexture;
    glGenTextures(1, &chessPieceTexture);
    glBindTexture(GL_TEXTURE_2D, chessPieceTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("chesspiecesadjusted.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture\n";
    }

    
    stbi_image_free(data);

    glGenTextures(1, &tileTexture);
    glBindTexture(GL_TEXTURE_2D, tileTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load("tile.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glGenTextures(1, &selectedTileTexture);
    glBindTexture(GL_TEXTURE_2D, selectedTileTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load("selectedTile.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    mainShader.use();
    mainShader.setInt("pieceTexture", 0);
    mainShader.setInt("tileTexture", 1);
    mainShader.setInt("selectedTileTexture", 2);
    glm::ivec2 selectedPiece = glm::ivec2(-1, -1);
    
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClearColor(54.0f / 255.0f, 57.0f / 255.0f, 63.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        mainShader.use();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, chessPieceTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, tileTexture);
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, selectedTileTexture);
        glm::mat4 projection = glm::ortho(0.0f, ((float)SCR_WIDTH/(float)SCR_HEIGHT)*8.0f, 0.0f, 8.0f, -100.0f, 100.0f); //glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        mainShader.setMat4("projection", projection);

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(-0.5f, 0.5f, 0.0f));
        mainShader.setMat4("view", view);

        glBindVertexArray(VAO);
        for (int i = 0; i < 64; ++i) {
            
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, tilePositions[i]);
            glfwGetCursorPos(window, &mousex, &mousey);
            if (mousex < 600) {
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
                    //std::cout << "grid selected:" << (int)(8 - (mousex / 75)) << "," << (int)(8 - (mousey / 75)) << "\n";
                    if ((!(selectedPiece.x == -1)) && glm::ivec2(8 - (mousex / 75), 8 - (mousey / 75)) != selectedPiece) {
                        for (glm::ivec2 _l : game.getBoard().getPiece(selectedPiece)->getPossibleLocations()) {
                            if (glm::ivec2(8 - (mousex / 75), 8 - (mousey / 75)) == _l) {
                                game.getBoard().movePiece(game.getBoard().getPiece(selectedPiece), _l);
                                selectedPiece = glm::ivec2(-1, -1);
                                if (game.getBoard().getTurn() == Colour::WHITE)
                                    game.getBoard().setTurn(Colour::BLACK);
                                else
                                    game.getBoard().setTurn(Colour::WHITE);
                                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE)
                                    break;
                            }
                        }
                    }
                    if (glm::ivec2(i % 8, (i - (i % 8)) / 8) == glm::ivec2(8 - (mousex / 75), 8 - (mousey / 75)) && game.getBoard().getPiece(glm::ivec2(8 - (mousex / 75), 8 - (mousey / 75))) != nullptr) {
                        if (game.getBoard().getPiece(glm::ivec2(8 - (mousex / 75), 8 - (mousey / 75)))->getPieceColour() == game.getBoard().getTurn())
                            selectedPiece = glm::ivec2(8 - (mousex / 75), 8 - (mousey / 75));
                    }
                                          
                }
            }
            if (glm::ivec2(i % 8, (i - (i % 8)) / 8) == selectedPiece) {
                model = glm::scale(model, glm::vec3(0.95, 0.95, 0.95)); 
            }
            if (!(selectedPiece.x == -1)) {
                for (glm::ivec2 _l : game.getBoard().getPiece(selectedPiece)->getPossibleLocations()) {
                    //std::cout << _l.x << _l.y << "\n";
                    if (glm::ivec2(i % 8, (i - (i % 8)) / 8) == _l) {
                        mainShader.setBool("renderPossibleMoves", true);
                        break;
                    }
                    else mainShader.setBool("renderPossibleMoves", false);  
                }
            }

            if (game.getBoard().getPiece(glm::ivec2(i % 8, (i - (i % 8)) / 8)) != nullptr) {
                mainShader.setBool("renderPiece", true);
                mainShader.setInt("pieceId", (int)game.getBoard().getPiece(glm::ivec2(i % 8, (i - (i % 8)) / 8))->getPieceID());
                if (game.getBoard().getPiece(glm::ivec2(i % 8, (i - (i % 8)) / 8))->getPieceColour() == Colour::BLACK)
                    mainShader.setVec3("pieceColour", _BLACKCOLOUR);
                else
                    mainShader.setVec3("pieceColour", _WHITECOLOUR);
            }
            else
                mainShader.setBool("renderPiece", false);
            if ((i / 8) % 2 == 0){
                if (i % 2 == 1) 
                    mainShader.setVec3("tileColour", glm::vec3(1.0f, 1.0f, 1.0f));              
                else 
                    mainShader.setVec3("tileColour", glm::vec3(0.8f, 0.8f, 0.8f));
            }
            else {
                if (i % 2 == 1) 
                    mainShader.setVec3("tileColour", glm::vec3(0.8f, 0.8f, 0.8f));             
                else 
                    mainShader.setVec3("tileColour", glm::vec3(1.0f, 1.0f, 1.0f));        
            }

            mainShader.setMat4("model", model);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            
        }

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

//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    /*std::cout << xpos << "," << ypos << "\n";*/
//    //one tile is 75x75
//    if (xpos < 600) {
//        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
//            std::cout << "grid selected:" << (int)xpos / 75 << "," << (int)ypos / 75 << "\n";
//        }
//    }
//    else {
//        std::cout << "out of grid\n";
//    }
//    
//}
