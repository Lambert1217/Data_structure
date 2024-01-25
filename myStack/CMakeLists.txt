#test
add_executable(test_ArrayStack test/test_ArrayStack.cpp)
add_executable(test_LinkStack test/test_LinkStack.cpp)

target_include_directories(test_ArrayStack PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(test_LinkStack PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

#practice
add_executable(fact practice/fact.cpp)
add_executable(HanoiTower practice/HanoiTower.cpp)

target_include_directories(fact PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(HanoiTower PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)