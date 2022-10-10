target_sources(engine
    PRIVATE
        PlatformDesktop.h
        PlatformDesktop.cpp

        WindowDesktop.h
        WindowDesktop.cpp

        InputDesktop.h
        InputDesktop.cpp
)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

target_link_libraries(engine PRIVATE glfw)