include(spider/spider.cmake)
include(${CMAKE_SOURCE_DIR}/3thrd/gumbo-query/gumbo-query.cmake)
include(${CMAKE_SOURCE_DIR}/3thrd/gumbo-parser/gumbo-parser.cmake)

add_executable(data-analysis main.cpp daemon.cc daemon.h ${SPIDER_SRC} ${GUMBO_QUERY_SRC} ${GUMBO_PARSER_SRC})
target_link_libraries(data-analysis PUBLIC ${QT5_LIBRARIES})
target_include_directories(data-analysis PUBLIC ${QT5_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/app)
target_compile_options(data-analysis PRIVATE -fPIC)