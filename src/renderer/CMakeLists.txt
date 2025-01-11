add_library(renderer STATIC)

target_sources(renderer
  PRIVATE
  render.c
  layer/layer.c
  layer/manager.c
)

target_compile_features(renderer
  PRIVATE
  c_std_11
)

target_compile_options(renderer
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -g
  -Og
  -fsanitize=address,undefined
)

target_link_options(renderer
  PRIVATE
  -fsanitize=address,undefined
)

target_link_libraries(renderer
  PRIVATE
  input
  util
)

target_include_directories(renderer
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/layer
)