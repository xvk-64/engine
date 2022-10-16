add_executable(sandbox)

add_subdirectory(src)

target_link_libraries(sandbox engine)