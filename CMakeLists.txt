cmake_minimum_required(VERSION 3.5.0)
project(TRTRIS VERSION 0.1.0 LANGUAGES C CXX)

add_executable(TRTRIS main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(C:/DxLib/12_2_0_x86_64_release_win32_seh_ucrt_rt_v10_rev2)
link_directories(C:/DxLib/12_2_0_x86_64_release_win32_seh_ucrt_rt_v10_rev2)
