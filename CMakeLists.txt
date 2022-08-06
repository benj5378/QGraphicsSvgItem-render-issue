project(QTISSUE)

cmake_minimum_required(VERSION 3.22)

set(src
    main.cpp
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(source STATIC ${src} )
target_link_libraries(source Qt5::Widgets Qt5::Core Qt5::Svg Qt::PrintSupport)

add_executable(main main.cpp)
target_link_libraries(main source)