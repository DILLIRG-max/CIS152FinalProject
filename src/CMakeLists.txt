cmake_minimum_required(VERSION 3.5)

project(AppointmentManager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)


set(TS_FILES AppointmentManager_en_US.ts)

add_executable(AppointmentManager
    main.cpp
    customerlistdelegate.cpp
    customerlistdelegate.h
    customerlistmodel.cpp
    customerlistmodel.h
    appointmentException.h
    customer.cpp
    customer.h
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
)


target_link_libraries(AppointmentManager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
