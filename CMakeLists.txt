cmake_minimum_required(VERSION 3.20)
project(CommandBlockCompilerV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CommandBlockCompilerV2 main.cpp HelperFunctions.cpp HelperFunctions.h Operations/Operation.cpp Operations/Operation.h Operations/If.cpp Operations/If.h Integer.cpp Integer.h Position.cpp Position.h)
