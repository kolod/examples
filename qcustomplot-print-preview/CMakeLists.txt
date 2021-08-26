cmake_minimum_required(VERSION 3.16)

project(qcustomplot-sample VERSION 0.1 LANGUAGES CXX)

option(QCUSTOMPLOT_DRAW_RECTS "Debug code to draw all layout element rects" OFF)

set(CMAKE_CXX_STANDARD 14)           # Use C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Require (at least) it
set(CMAKE_CXX_EXTENSIONS OFF)        # Don't use e.g. GNU extension (like -std=gnu++11) for portability

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 Qt6      COMPONENTS Widgets PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)

message(STATUS "Qt Version: ${QT_VERSION}")

if(QCUSTOMPLOT_DRAW_RECTS)
	add_compile_definitions(PUBLIC QCUSTOMPLOT_DRAW_RECTS)
endif()

add_subdirectory(qcustomplot)
add_subdirectory(src)
