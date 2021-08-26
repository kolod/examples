cmake_minimum_required(VERSION 3.16)

project(application VERSION 0.1 LANGUAGES CXX)

set(PROJECT_SOURCES
	sample.h
	sample.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(application MANUAL_FINALIZATION ${PROJECT_SOURCES})
else()
	if(ANDROID)
		add_library(application SHARED ${PROJECT_SOURCES})
	else()
		add_executable(application ${PROJECT_SOURCES})
	endif()
endif()

if(QCUSTOMPLOT_DEBUG_ELEMENTS_RECT)
	add_compile_definitions(QCUSTOMPLOT_DEBUG_ELEMENTS_RECT)
endif()

target_include_directories(application PUBLIC ../qcustomplot)
target_link_directories(application PUBLIC ${CMAKE_BINARY_DIR}/qcustomplot)

target_link_libraries(application PUBLIC libqcustomplot.a)
target_link_libraries(application PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(application PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

add_dependencies(application qcustomplot)

if(QT_VERSION_MAJOR EQUAL 6)
	qt_finalize_executable(application)
endif()
