// SaturnComputingGameEngine.cpp

#include "SaturnComputingGameEngine.h"
#include <iostream>

// Initialize all systems (GLFW, window, GLAD, Havok)
bool SaturnComputingGameEngine::initialize() {
    if (!glfwInit()) {
        std::cerr << "[INFO] GLFW initialization failed!" << std::endl;
        return false;
    }

    // Create OpenGL window
    window = glfwCreateWindow(800, 600, "Game", nullptr, nullptr);
    if (!window) {
        std::cerr << "[INFO] Window creation failed!" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    // Load OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "[INFO] GLAD initialization failed!" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return false;
    }

    std::cout << "[INFO] OpenGL initialized successfully." << std::endl;

    initializeHavok(); // Stub function, can integrate real Havok

    return true;
}

// Set window title
void SaturnComputingGameEngine::SetWindowTitle(const std::string& title) {
    if (window) {
        glfwSetWindowTitle(window, title.c_str());
    } else {
        std::cerr << "[INFO] SetWindowTitle failed: Window not initialized.\n";
    }
}

// Main game loop
void SaturnComputingGameEngine::run() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();          // Handle inputs/events
        render();                  // Draw frame
        glfwSwapBuffers(window);   // Present frame
    }
}

// Cleanup resources
void SaturnComputingGameEngine::cleanup() {
    cleanupHavok();              // Stop physics if used
    glfwDestroyWindow(window);   // Destroy window
    glfwTerminate();             // Clean up GLFW
    std::cout << "[SaturnEngine] Cleanup completed." << std::endl;
}

// Stub: Initialize physics
void SaturnComputingGameEngine::initializeHavok() {
    // TODO: Integrate Havok SDK (or use Bullet as fallback)
    std::cout << "[SaturnEngine] Havok initialized." << std::endl;
}

// Stub: Cleanup physics
void SaturnComputingGameEngine::cleanupHavok() {
    std::cout << "[SaturnEngine] Havok cleaned up." << std::endl;
}

// Frame rendering
void SaturnComputingGameEngine::render() {
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);  // Dark background
    glClear(GL_COLOR_BUFFER_BIT);         // Clear screen
}
