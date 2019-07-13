cmake_minimum_required(VERSION 3.12)

include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

set(SOURCES
    core/actor.cc
    core/component.cc
    core/engine.cc
    core/event.cc
    core/mouse_event.cc
    core/scene.cc
    graphics/camera_component.cc
    graphics/geometry_component.cc
    graphics/renderer.cc
    graphics/shader.cc
    graphics/window.cc
)

set(HEADERS
    core/actor.h
    core/component.h
    core/engine.h
    core/event.h
)

add_executable(hodhr main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(
    hodhr
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${SDL2_LIBRARIES}
)