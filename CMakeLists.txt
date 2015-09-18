cmake_minimum_required(VERSION 3.0)

project(nanovg)

add_library(nanovg SHARED
  src/nanovg.c)

find_package(OpenGL REQUIRED)
target_link_libraries(nanovg PRIVATE ${OPENGL_gl_LIBRARY})

install(TARGETS nanovg
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib)

install(FILES nanovg.h nanovg_gl.h DESTINATION include)
