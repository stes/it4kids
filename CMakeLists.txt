cmake_minimum_required(VERSION 2.8.12)

project(it4kids)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

find_package(QScintilla REQUIRED)

find_package(PythonLibs 3 REQUIRED)

include_directories(src)
include_directories(${PYTHON_INCLUDE_DIRS})

file(GLOB_RECURSE sources src/*.cpp src/*.h)

add_executable(it4kids WIN32 ${sources} resources/resources.qrc)

add_custom_command(TARGET it4kids POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Assets ${PROJECT_BINARY_DIR}/Assets
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/python ${PROJECT_BINARY_DIR}/python
	)

# TODO: debug
target_link_libraries(it4kids
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	Qt5::Multimedia
	Qt5::PrintSupport
	${QSCINTILLA_LIBRARY}
	${PYTHON_LIBRARIES}
	)
