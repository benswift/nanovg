cmake_minimum_required(VERSION 3.1)

project(nanovg)

add_library(nanovg SHARED
  src/nanovg.c)

target_include_directories(nanovg PRIVATE src)

if(WIN32)
  target_sources(nanovg
    PRIVATE src/glew.c)
  target_compile_definitions(nanovg
    PRIVATE -DGLEW_STATIC)
endif()

find_package(OpenGL REQUIRED)
target_include_directories(nanovg PRIVATE ${OPENGL_INCLUDE_DIRS})
target_link_libraries(nanovg PRIVATE ${OPENGL_LIBRARIES})

install(TARGETS nanovg
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib)

install(FILES src/nanovg.h src/nanovg_gl.h DESTINATION include)
