add_library(GLAD src/glad.c include/glad/glad.h)
target_include_directories(GLAD PRIVATE include)