include(spider/spider.cmake)
include(./html-parser.cmake)

add_executable(data-analysis main.cpp daemon.cc daemon.h ${SPIDER_SRC} ${GUMBO_C_SRC} ${GUMBO_CXX_SRC})
target_link_libraries(data-analysis PUBLIC ${QT5_LIBRARIES} ${CHARSET_LIBRARIES})
target_include_directories(data-analysis PUBLIC ${QT5_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/app)
target_compile_options(data-analysis PRIVATE -fPIC)