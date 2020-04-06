cmake_minimum_required(VERSION 3.12)

project(PocoPlay)

message("[3rdparty/Poco]")
add_definitions(
    -DENABLE_DATA=OFF 
    -DENABLE_DATA_ODBC=OFF
    -DENABLE_MONGODB=OFF
    -DENABLE_REDIS=OFF
)
add_subdirectory(3rdparty/poco)

message("[main]")
add_executable(main source/main.cpp)
target_link_libraries(main Poco::Net)
