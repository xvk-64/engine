target_sources(engine
    PRIVATE
        PlatformDesktop.h
        PlatformDesktop.cpp

        WindowDesktop.h
        WindowDesktop.cpp

        InputDesktop.h
        InputDesktop.cpp
)

find_package(glfw3 REQUIRED)

target_link_libraries(engine PRIVATE glfw)