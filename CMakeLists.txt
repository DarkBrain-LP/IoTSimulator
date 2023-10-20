cmake_minimum_required(VERSION 3.24)
project(Code)

set(CMAKE_CXX_STANDARD 17)

add_executable(Code main.cpp Scheduler.h Scheduler.cpp Scheduler.cpp Server.h Server.cpp Sensor.cpp Temperature.h Humidity.h Light.h Sound.h TSensor.cpp)
