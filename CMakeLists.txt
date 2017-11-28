cmake_minimum_required(VERSION 3.1)

project(nanovg)

find_package(OpenGL REQUIRED)

add_library(nanovg SHARED
  src/xtmnanovg.c)

target_include_directories(nanovg PRIVATE src)

# this is dangerous - it would be much better to use dynamic lookup for
# llvm_zone_malloc_from_current_zone *only* but I can't find the magic
# cmake flags for that
if(APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
endif(APPLE)

if(WIN32)
  if(NOT EXTEMPORE_LIB_PATH)
    message(FATAL_ERROR "EXTEMPORE_LIB_PATH not set\n\nThis should point to extempore.lib, e.g. -DEXTEMPORE_LIB_PATH=c:/Users/ben/Code/extempore/libs/platform-shlibs/extempore.lib")
  endif()
  target_sources(nanovg
    PRIVATE src/glew.c
    PRIVATE src/nanovg.def)
  target_compile_definitions(nanovg
    PRIVATE -DGLEW_STATIC)
  target_link_libraries(nanovg PRIVATE "${EXTEMPORE_LIB_PATH}")
endif()

target_include_directories(nanovg PRIVATE ${OPENGL_INCLUDE_DIRS})
target_link_libraries(nanovg PRIVATE ${OPENGL_LIBRARIES})

install(TARGETS nanovg
  RUNTIME DESTINATION lib
  ARCHIVE DESTINATION lib # for .lib files on Windows
  LIBRARY DESTINATION lib)

install(FILES src/nanovg.h src/nanovg_gl.h DESTINATION include)
