cmake_minimum_required(VERSION 3.0.2)
project(MyProject)

set(QT_VERSION_REQ "5.2")
set(Qt5Quick_DIR "/Users/dillon/Qt/5.5/clang_64/lib/cmake/Qt5Quick/")
set(Qt5Widgets_DIR "/Users/dillon/Qt/5.5/clang_64/lib/cmake/Qt5Widgets/")

find_package(Qt5Core ${QT_VERSION_REQ} REQUIRED)
find_package(Qt5Quick ${QT_VERSION_REQ} REQUIRED)
find_package(Qt5Widgets ${QT_VERSION_REQ} REQUIRED)
set(CMAKE_AUTOMOC ON)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(MyProject main.cpp window.cpp)
target_link_libraries(MyProject
    Qt5::Core
    Qt5::Quick
    Qt5::Widgets
    ${VTK_LIBRARIES}
)

# set(Qt5_DIR "/Users/dillon/Qt/5.5/clang_64/lib/cmake/Qt5/")

# find_package(Qt5)

# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# add_executable(MyProject main.cpp)
