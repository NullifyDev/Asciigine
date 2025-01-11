cmake_minimum_required(VERSION 3.20)
project(asciingine VERSION 0.0.1 LANGUAGES C)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
  src/init.c
  src/main.c
)

target_compile_features(${PROJECT_NAME}
  PRIVATE
  c_std_11
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -g
  -Og
  -fsanitize=address,undefined
)

target_link_options(${PROJECT_NAME}
  PRIVATE
  -fsanitize=address,undefined
)

add_subdirectory(src/core)
add_subdirectory(src/input)
add_subdirectory(src/utils)
add_subdirectory(src/renderer)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  core
  renderer
  input
  util
)
