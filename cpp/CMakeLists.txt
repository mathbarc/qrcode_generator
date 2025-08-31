project(QRGen)
cmake_minimum_required(VERSION 3.4)

set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

set(QT_VERSION "Qt5" CACHE STRING "Qt Version")

find_package(
  ${QT_VERSION}
  COMPONENTS Core Widgets LinguistTools
  REQUIRED)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/form)



add_library(${PROJECT_NAME} STATIC src/QrCode.cpp)
target_link_libraries(${PROJECT_NAME} Qt::Widgets Qt::Core)

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
file(GLOB QRCODEGENERATOR_TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/form/translations/*.ts)
qt_wrap_ui(QRCODEGENERATOR_WRAPPED_IUS ${QRCODEGENERATOR_FORM})
qt_add_resources(QRCODEGENERATOR_RESOURCE ${CMAKE_CURRENT_SOURCE_DIR}/form/resource.qrc)



if("${TS_FILES}" STREQUAL "")
    qt_create_translation(QM_FILES ${QRCODEGENERATOR_WRAPPED_IUS} ${QRCODEGENERATOR_SOURCE} ${QRCODEGENERATOR_HEADER}
                        ${CMAKE_CURRENT_SOURCE_DIR}/form/translations/sample.ts)
else()
    qt_create_translation(QM_FILES ${QRCODEGENERATOR_WRAPPED_IUS} ${QRCODEGENERATOR_SOURCE} ${QRCODEGENERATOR_HEADER})
    if(EXISTS ${QM_FILES})
        file(COPY ${QM_FILES}
         DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/form/translations/)
        qt_add_resources(
      VIEW_TRANSLATION_RESOURCES
      ${CMAKE_CURRENT_SOURCE_DIR}/form/translations/Translations.qrc)
    endif()
endif()


add_executable(QrCodeGenerator ${QRCODEGENERATOR_SOURCE} ${QRCODEGENERATOR_HEADER} ${QRCODEGENERATOR_WRAPPED_IUS} ${QRCODEGENERATOR_RESOURCE} ${QRCODEGENERATOR_FORM} ${VIEW_TRANSLATION_RESOURCES})
target_link_libraries(QrCodeGenerator ${PROJECT_NAME} Qt::Widgets Qt::Core)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/ DESTINATION include/libQRGen
        FILES_MATCHING PATTERN "*.hpp")
