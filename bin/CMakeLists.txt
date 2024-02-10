add_executable(main main.cpp)

target_link_libraries(main PUBLIC array)
target_link_libraries(main PUBLIC segment)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR})
