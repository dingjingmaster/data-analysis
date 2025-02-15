include(${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/gumbo-parser.cmake)

add_executable(demo-gumbo-parser-find-links.run find-links.cc ${GUMBO_PARSER_SRC})