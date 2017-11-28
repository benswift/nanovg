#include "nanovg.h"

// for Extempore, we require the GL3 implementation - this stuff is
// here to link against the OpenGL headers on each platform and make
// sure it gets built into the shared lib

#ifdef _WIN32
#include <GL/glew.h>

int nvgInit(void){
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		printf("Could not init glew.\n");
		return GL_FALSE;
	}
	// GLEW generates GL error because it calls glGetString(GL_EXTENSIONS), we'll consume it here.
	glGetError();
  return GL_TRUE;
}

#elif __APPLE__
#include <OpenGL/gl3.h>

int nvgInit(void){
  // we don't use GLEW on OSX, so init doesn't do anything
  return GL_TRUE;
}

#elif __linux__
#include <GL/gl.h>

int nvgInit(){
  // we don't use GLEW on Linux, so init doesn't do anything
  return GL_TRUE;
}

#endif

#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"
#include "nanovg_gl_utils.h"
