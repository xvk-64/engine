target_sources(engine
    PUBLIC
        Platform.h
        Platform.cpp
)

add_subdirectory(Window)

add_subdirectory(GLFW)