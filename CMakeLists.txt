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
  target_include_directories(nanovg
    PRIVATE c:/Users/ben/Code/glew-1.13.0/include)
  target_link_libraries(nanovg
    PRIVATE c:/Users/ben/Code/glew-1.13.0/cmake-build/lib/Release/libglew32.lib)
endif()

# if(WIN32)
#   # find_package(GLEW REQUIRED)
#   # target_include_directories(nanovg PRIVATE ${GLEW_INCLUDE_DIRS})
#   # target_link_libraries(nanovg PRIVATE ${GLEW_LIBRARIES})
#   target_compile_definitions(nanovg
#     PRIVATE -DNANOVG_GLEW)
# endif()

install(TARGETS nanovg
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib)

install(FILES src/nanovg.h src/nanovg_gl.h DESTINATION include)
