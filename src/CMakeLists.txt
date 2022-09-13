find_package(glm REQUIRED)
target_link_libraries(engine PRIVATE glm)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(Core)      # Core, common functionality
add_subdirectory(Event)     # Event management
add_subdirectory(Platform)  # Functionality that depends on target m_platform/OS...