include(../app/html-parser.cmake)

add_executable(demo-gumbo-parser-find-links.run find-links.cc ${GUMBO_C_SRC})
add_executable(demo-gumbo-parser-serialize.run serialize.cc ${GUMBO_C_SRC})
add_executable(demo-gumbo-parser-prettyprint.run prettyprint.cc ${GUMBO_C_SRC})
add_executable(demo-gumbo-parser-get-title.run get-title.c ${GUMBO_C_SRC})
add_executable(demo-gumbo-parser-clean-text.run clean-text.cc ${GUMBO_C_SRC} ${GUMBO_CXX_SRC})
add_executable(demo-gumbo-parser-positions-of-class.run positions-of-class.cc ${GUMBO_C_SRC})
