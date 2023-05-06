cmake_minimum_required(VERSION 3.0.0)
project(iot1 VERSION 0.1.0)

# cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
# cmake --build [build directory]

include(CTest)
include_directories(
    # ${CMAKE_CURRENT_SOURCE_DIR}
    # ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)



# add_library(iot1  ${SRC_LIST}) 
enable_testing()


find_package(fmt CONFIG REQUIRED)
find_package(json-dto CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(PahoMqttCpp CONFIG REQUIRED)

add_executable(iot1 src/Mqtt.cpp src/main.cpp)
# add_executable(iot1 src/Sleep.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE json-dto::json-dto)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(${PROJECT_NAME} PRIVATE PahoMqttCpp::paho-mqttpp3-static)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
