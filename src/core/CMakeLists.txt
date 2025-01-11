add_library(core STATIC)

target_sources(core
  PRIVATE
  tick.c
)

target_compile_features(core
  PRIVATE
  c_std_11
)

target_compile_options(core
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -g
  -Og
  -fsanitize=address,undefined
)

target_link_options(core
  PRIVATE
  -fsanitize=address,undefined
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})