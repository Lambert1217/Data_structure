include_directories(include)
include_directories(../include_shared)

#test
add_executable(test_ArrayStack test/test_ArrayStack.cpp)
add_executable(test_LinkStack test/test_LinkStack.cpp)

#practice
add_executable(fact practice/fact.cpp)
add_executable(HanoiTower practice/HanoiTower.cpp)