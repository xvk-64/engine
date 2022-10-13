find_package(glm REQUIRED)
target_link_libraries(engine PRIVATE glm)

target_link_libraries(engine PRIVATE GLAD)

find_package(EnTT REQUIRED)
target_link_libraries(engine PRIVATE EnTT::EnTT)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(Core)      # Core, common functionality
add_subdirectory(ECS)       # ECS functionality
add_subdirectory(Input)     # Input handling
add_subdirectory(Platform)  # Functionality that depends on target m_platform/OS...
add_subdirectory(Utils)