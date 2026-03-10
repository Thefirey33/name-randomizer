cmake_minimum_required(VERSION 3.10.0)
project(name-randomizer VERSION 0.1.0 LANGUAGES C CXX)
set(CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(include include/gui)
if(WIN32)
	add_executable(${PROJECT_NAME} WIN32 src/main.cpp src/gui/mainGui.cpp include/gui/mainGui.h applicationIcon.rc)
else()
	add_executable(${PROJECT_NAME} src/main.cpp src/gui/mainGui.cpp include/gui/mainGui.h)
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)