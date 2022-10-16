target_sources(engine
    PRIVATE
        Renderer.h
        Renderer.cpp


        Shader.h
        Shader.cpp

        ShaderUnit.h
        ShaderUnit.cpp

        VertexBuffer.h
        VertexBuffer.cpp

        VertexArray.h
        VertexArray.cpp
)

target_link_libraries(engine PRIVATE GLAD)