# For `--parallel` flag in CLI.
cmake_minimum_required(VERSION 3.12)

project(PocoPlay)

message("Entering subdirectory 3rdparty/poco")
add_definitions(-DENABLE_DATA=OFF -DENABLE_DATA_ODBC=OFF -DENABLE_MONGODB=OFF -DENABLE_REDIS=OFF)
add_subdirectory(3rdparty/poco)
message("Leaving subdirectory 3rdparty/poco")

add_executable(main source/main.cpp)
