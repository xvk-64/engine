target_sources(engine
    PUBLIC
        PlatformDesktop.cpp
        PlatformDesktop.h

        WindowGLFW.h
        WindowGLFW.cpp
)

find_package(GLFW3 REQUIRED)
target_link_libraries(engine PRIVATE glfw)