#ifndef SATURN_COMPUTING_GAME_ENGINE_H
#define SATURN_COMPUTING_GAME_ENGINE_H

#include <string>
#include <OpenGL/glfw3.h>
#include <OpenGL/glad.h>

class SaturnComputingGameEngine {
public:
    bool initialize();
    void run();
    void cleanup();
    void SetWindowTitle(const std::string& title);

private:
    void initializeHavok();
    void cleanupHavok();
    void render();
    GLFWwindow* window = nullptr;
};

#endif
