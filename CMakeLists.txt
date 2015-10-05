cmake_minimum_required(VERSION 3.0)

project(nanovg)

add_library(nanovg SHARED
  src/nanovg.c)

target_include_directories(nanovg PRIVATE src)

find_package(OpenGL REQUIRED)
target_include_directories(nanovg PRIVATE ${OPENGL_INCLUDE_DIRS})
target_link_libraries(nanovg PRIVATE ${OPENGL_LIBRARIES})

if(WIN32)
  target_sources(nanovg PRIVATE src/nanovg.def)
  find_path(GLEW_INCLUDE_DIRS GL/glew.h
    PATHS ${GLEW_DIR}/include)
  find_library(GLEW_LIBRARY libglew32
    PATHS ${GLEW_DIR}/lib)
  target_include_directories(nanovg PRIVATE ${GLEW_INCLUDE_DIRS})
  target_link_libraries(nanovg PRIVATE ${GLEW_LIBRARY})
endif()

install(TARGETS nanovg
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib)

install(FILES src/nanovg.h src/nanovg_gl.h DESTINATION include)
