find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(engine PRIVATE glfw)

target_sources(engine
    PUBLIC
        WindowGLFW.cpp
        WindowGLFW.h
)