add_library(input STATIC)

target_sources(input
  PRIVATE
  input.c
)

target_compile_features(input
  PRIVATE
  c_std_11
)

target_compile_options(input
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -g
  -Og
  -fsanitize=address,undefined
)

find_library(threads
  NAMES pthread
  REQUIRED
)

target_link_options(input
  PRIVATE
  -fsanitize=address,undefined
  ${threads}
)

target_include_directories(input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})