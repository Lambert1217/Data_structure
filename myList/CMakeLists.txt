add_executable(test_ArrayList ${CMAKE_CURRENT_LIST_DIR}/test/test_ArrayList.cpp)
add_executable(test_sLinklist ${CMAKE_CURRENT_LIST_DIR}/test/test_sLinklist.cpp)

target_include_directories(test_ArrayList PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(test_sLinklist PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)