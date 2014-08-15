#include <iostream>
#include <cstdio>
#define GLEW_STATIC
#include <GL/glxew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

/*
    A small program following the OpenGL tutorial found at http://open.gl
*/

int main(int argc, char *argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //GLEW shit
    typedef void (*GENBUFFERS) (GLsizei, GLuint*);
    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
    GLuint buffer;
    glGenBuffers(1, &buffer);

    glewExperimental = GL_TRUE;
    glewInit();

    // no idea what this does:
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    printf("%u\n", vertexBuffer);

    // make sure to use the correct OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    // create the OpenGL Window using SDL
    SDL_Window* window = SDL_CreateWindow("such window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);


    // create a vertex buffer object (something about GPU memory being allocated or used)
    GLuint vbo;
    glGenBuffers(1, &vbo); // Generate 1 buffer

    // a few vertices for to form a triangle
    float vertices[] = {
        0.0f,  0.5f, // Vertex 1 (X, Y)
        0.5f, -0.5f, // Vertex 2 (X, Y)
        -0.5f, -0.5f  // Vertex 3 (X, Y)
    };

    // make the VBO we just created the active array buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // write our vertices to the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // at this point, we have written a bunch of vertices to GPU memory

    // creat the OpenGL context using SDL
    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_Event windowEvent;

    // the main loop
    while (true){
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) break;
            if (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
        }

        SDL_GL_SwapWindow(window);
    }

    // destroy the context to free up ressources
    SDL_GL_DeleteContext(context);

    // quit.
    SDL_Quit();
    return 0;
}
