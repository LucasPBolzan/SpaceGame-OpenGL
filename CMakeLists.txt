cmake_minimum_required(VERSION 3.12)

project(CGCube_v2)

# Adiciona o executável do projeto
add_executable(CGCube_v2 "main.cpp")

# Configuração do CMake para encontrar o GLM, o GLFW, o GLEW, o STB
target_include_directories(CGCube_v2 PRIVATE deps/glm 
                                        deps/glfw/include
                                        deps/glew/include
                                        deps/std
                                     
)
                                       

target_link_directories(CGCube_v2 PRIVATE deps/glfw/lib-vc2019
                                                   deps/glew/lib/Release/x64
                  
)

# Liga o GLFW, o GLEW e o OPENGL ao executável
target_link_libraries(CGCube_v2 PRIVATE glfw3.lib glew32.lib opengl32.lib)

add_custom_command(TARGET CGCube_v2 POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy 
                   "${CMAKE_SOURCE_DIR}/deps/glew/bin/Release/x64/glew32.dll" 
                   "${CMAKE_BINARY_DIR}/glew32.dll")
