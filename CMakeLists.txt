cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp one_way_list/OneWayList.cpp one_way_list/OneWayList.h one_way_list/ElementOne.cpp one_way_list/ElementOne.h two_way_list/ElementTwo.cpp two_way_list/ElementTwo.h two_way_list/TwoWayList.cpp two_way_list/TwoWayList.h binary_heap/BinaryHeap.cpp binary_heap/BinaryHeap.h dynamic_array/DynamicArray.cpp dynamic_array/DynamicArray.h red_black_tree/RedBlackTree.cpp red_black_tree/RedBlackTree.h red_black_tree/Node.cpp red_black_tree/Node.h)