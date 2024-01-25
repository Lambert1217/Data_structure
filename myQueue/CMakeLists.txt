add_executable(test_ArrayQueue test/test_ArrayQueue.cpp)
add_executable(test_LinkQueue test/test_LinkQueue.cpp)

target_include_directories(test_ArrayQueue PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(test_LinkQueue PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)