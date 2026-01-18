cmake_minimum_required(VERSION 3.10)
project(ProvinceCountCalculator)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含头文件目录
include_directories(include)

# 编译核心库
add_library(province_counter STATIC src/ProvinceCounter.cpp)

# 编译测试程序
add_executable(test_province_counter test/test_province_counter.cpp)
target_link_libraries(test_province_counter province_counter)

# 编译优化与警告配置
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(province_counter PRIVATE -Wall -Wextra -O2)
    target_compile_options(test_province_counter PRIVATE -Wall -Wextra -O2)
endif()

if (MSVC)
    target_compile_options(province_counter PRIVATE /W4 /O2)
    target_compile_options(test_province_counter PRIVATE /W4 /O2)
endif()