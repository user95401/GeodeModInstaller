# CMakeList.txt: проект CMake для geodeModsInstaller; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}/geode")

project ("GeodeModInstaller")

# Добавьте источник в исполняемый файл этого проекта.
file(GLOB_RECURSE "SOURCE" src/*)
add_executable (${PROJECT_NAME} ${SOURCE}  )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
