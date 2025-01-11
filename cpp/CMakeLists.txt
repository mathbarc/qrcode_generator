project(QRGen)
cmake_minimum_required(VERSION 3.4)

set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

find_package(Qt5Widgets REQUIRED)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/form
                    ${Qt5Widgets_INCLUDE_DIRS})



add_library(${PROJECT_NAME} STATIC src/QrCode.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core)

add_executable(QrCodeGeneratorDemo src/QrCodeGeneratorDemo.cpp)
target_link_libraries(QrCodeGeneratorDemo ${PROJECT_NAME})

add_executable(FileToQRCode src/FileToQRCode.cpp)
target_link_libraries(FileToQRCode ${PROJECT_NAME})


file(GLOB QRCODEGENERATOR_FORM ${CMAKE_CURRENT_SOURCE_DIR}/form/*.ui)
file(GLOB QRCODEGENERATOR_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/form/*.hpp)
file(GLOB QRCODEGENERATOR_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/QrCodeGenerator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/form/*.cpp
)

qt5_wrap_ui(QRCODEGENERATOR_WRAPPED_IUS ${QRCODEGENERATOR_FORM})
qt5_add_resources(QRCODEGENERATOR_RESOURCE ${CMAKE_CURRENT_SOURCE_DIR}/form/resource.qrc)

add_executable(QrCodeGenerator ${QRCODEGENERATOR_SOURCE} ${QRCODEGENERATOR_HEADER} ${QRCODEGENERATOR_WRAPPED_IUS} ${QRCODEGENERATOR_RESOURCE} ${QRCODEGENERATOR_FORM})
target_link_libraries(QrCodeGenerator ${PROJECT_NAME} Qt5::Widgets Qt5::Core)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/ DESTINATION include/libQRGen
        FILES_MATCHING PATTERN "*.hpp")
