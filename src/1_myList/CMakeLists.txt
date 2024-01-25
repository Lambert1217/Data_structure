add_executable(test_ArrayList ${CMAKE_CURRENT_LIST_DIR}/test/test_ArrayList.cpp)
add_executable(test_sLinklist ${CMAKE_CURRENT_LIST_DIR}/test/test_sLinklist.cpp)
add_executable(test_UALdict ${CMAKE_CURRENT_LIST_DIR}/test/test_UALdict.cpp)

target_include_directories(test_ArrayList PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(test_sLinklist PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(test_UALdict PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)