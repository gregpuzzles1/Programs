# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2_w CACHE STRING "Board type") # pico pico_w pico2 pico2_w

cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(Pico_LCD1602_Code)
pico_sdk_init()

# add compiled files subdirectory
add_subdirectory(lib/Config)
add_subdirectory(lib/LCD1602)
add_subdirectory(examples)

# add header file directory
include_directories(examples)
include_directories(./lib/Config)
include_directories(./lib/LCD1602)


# generate executable file
add_executable(Pico_LCD1602_Code 
main.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(Pico_LCD1602_Code 1)
pico_enable_stdio_uart(Pico_LCD1602_Code 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(Pico_LCD1602_Code)

target_link_libraries(Pico_LCD1602_Code examples LCD1602 Config pico_stdlib hardware_i2c)