add_library(util STATIC)

target_sources(util
  PRIVATE
  file.c
  log.c
)

target_compile_features(util
  PRIVATE
  c_std_11
)

target_compile_options(util
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -g
  -Og
  -fsanitize=address,undefined
)

target_link_options(util
  PRIVATE
  -fsanitize=address,undefined
)

target_include_directories(util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})