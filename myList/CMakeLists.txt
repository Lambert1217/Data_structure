add_executable(test_ArrayList test/test_ArrayList.cpp)
add_executable(test_sLinklist test/test_sLinklist.cpp)

target_include_directories(test_ArrayList PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(test_sLinklist PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)