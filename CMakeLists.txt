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

find_package(QScintilla)

find_package(PythonLibs 3 REQUIRED)

include_directories(src)
include_directories(${PYTHON_INCLUDE_DIRS})

if(QSCINTILLA_FOUND)
	add_definitions(-DCONF_CODE_EDITOR)
	include_directories(${QSCINTILLA_INCLUDE_DIR})
endif()

file(GLOB_RECURSE sources src/*.cpp src/*.h)

add_executable(it4kids WIN32 ${sources} resources/resources.qrc)

add_custom_command(TARGET it4kids POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Assets ${PROJECT_BINARY_DIR}/Assets
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/python ${PROJECT_BINARY_DIR}/python
	)

set(LIBS ${LIBS}
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	Qt5::Multimedia
	Qt5::PrintSupport
	${PYTHON_LIBRARIES})

if(QSCINTILLA_FOUND)
	set(LIBS ${LIBS} ${QSCINTILLA_LIBRARY})
endif()

target_link_libraries(it4kids ${LIBS})
