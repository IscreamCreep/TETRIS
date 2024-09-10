cmake_minimum_required(VERSION 3.5.0)
project(TRTRIS VERSION 0.1.0 LANGUAGES C CXX)
add_library(uftree STATIC ./src/uftree.cpp)
target_compile_features(uftree PRIVATE cxx_std_11)
target_include_directories(uftree INTERFACE ./include)
set_target_properties(uftree
    PROPERTIES
    VERSION ${PROJECT_VERSION})