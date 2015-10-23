#ifndef __JACE_GRAPHICS_H__
#define __JACE_GRAPHICS_H__

// OpenGL Includes by Platform
#ifdef __linux__

#include <GL/freeglut.h>

#elif __APPLE__

#include <OpenGL/gl.h>

#elif _WIN32

#include <GL/glew.h>

#endif

#include <SDL.h>
#include <SDL_opengl.h>

#endif