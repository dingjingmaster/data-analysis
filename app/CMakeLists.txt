include(spider/spider.cmake)

add_executable(data-analysis main.cpp daemon.cc daemon.h ${SPIDER_SRC})
target_link_libraries(data-analysis PUBLIC ${QT5_LIBRARIES})
target_include_directories(data-analysis PUBLIC ${QT5_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/app)
target_compile_options(data-analysis PRIVATE -fPIC)