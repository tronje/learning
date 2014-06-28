#include <iostream>
#include <cstdio>
#define GLEW_STATIC
#include <GL/glxew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    typedef void (*GENBUFFERS) (GLsizei, GLuint*);
    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");

    GLuint buffer;
    glGenBuffers(1, &buffer);

    glewExperimental = GL_TRUE;
    glewInit();

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    printf("%u\n", vertexBuffer);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_Window *win = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    float vertices[] = {
        0.0f,  0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);

    SDL_GLContext context = SDL_GL_CreateContext(win);
    SDL_Event windowEvent;

    while (true){
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) break;
            if (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
        }

        SDL_GL_SwapWindow(win);
    }

    SDL_GL_DeleteContext(context);

    SDL_DestroyWindow(win);
    SDL_Quit();
}