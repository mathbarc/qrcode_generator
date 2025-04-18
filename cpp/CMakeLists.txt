project(QRGen)
cmake_minimum_required(VERSION 3.4)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/form
  ${CMAKE_CURRENT_BINARY_DIR} ${Qt5Widgets_INCLUDE_DIRS})

add_library(${PROJECT_NAME} STATIC src/QrCode.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core)

# add_executable(QrCodeGeneratorDemo src/QrCodeGeneratorDemo.cpp)
# target_link_libraries(QrCodeGeneratorDemo ${PROJECT_NAME})
#
# add_executable(FileToQRCode src/FileToQRCode.cpp)
# target_link_libraries(FileToQRCode ${PROJECT_NAME})

file(GLOB QRCODEGENERATOR_FORM ${CMAKE_CURRENT_SOURCE_DIR}/form/*.ui)
file(GLOB QRCODEGENERATOR_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/form/*.hpp)
<<<<<<< HEAD
file(GLOB QRCODEGENERATOR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/form/*.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/src/QrCodeGenerator.cpp)
=======
file(GLOB QRCODEGENERATOR_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/QrCodeGenerator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/form/*.cpp
)
>>>>>>> b1cbd87fac745c9b3e60ad5e0dc6cbb17b465f06

qt5_wrap_ui(QRCODEGENERATOR_WRAPPED_IUS ${QRCODEGENERATOR_FORM})
qt5_add_resources(QRCODEGENERATOR_RESOURCE
                  ${CMAKE_CURRENT_SOURCE_DIR}/form/resource.qrc)

<<<<<<< HEAD
add_executable(
  QrCodeGenerator ${QRCODEGENERATOR_SOURCE} ${QRCODEGENERATOR_HEADER}
                  ${QRCODEGENERATOR_WRAPPED_IUS} ${QRCODEGENERATOR_RESOURCE})
=======
add_executable(QrCodeGenerator ${QRCODEGENERATOR_SOURCE} ${QRCODEGENERATOR_HEADER} ${QRCODEGENERATOR_WRAPPED_IUS} ${QRCODEGENERATOR_RESOURCE} ${QRCODEGENERATOR_FORM})
>>>>>>> b1cbd87fac745c9b3e60ad5e0dc6cbb17b465f06
target_link_libraries(QrCodeGenerator ${PROJECT_NAME} Qt5::Widgets Qt5::Core)

install(
  TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(
  DIRECTORY include/
  DESTINATION include/libQRGen
  FILES_MATCHING
  PATTERN "*.hpp")
