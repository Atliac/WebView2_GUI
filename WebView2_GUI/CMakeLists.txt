add_library(WebView2_GUI STATIC "WebView2_GUI.cpp")
add_library(Atliac::WebView2_GUI ALIAS WebView2_GUI)

target_include_directories(WebView2_GUI
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    PUBLIC "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_definitions(WebView2_GUI PUBLIC UNICODE _UNICODE)
target_compile_definitions(WebView2_GUI PRIVATE NOMINMAX) # Exclude min/max macros from Windows headers
target_compile_definitions(WebView2_GUI PRIVATE WIN32_LEAN_AND_MEAN) # Exclude rarely-used stuff from Windows headers
target_precompile_headers(WebView2_GUI PRIVATE <windows.h> <iostream> <winrt/base.h>)

find_package(atliac-minitest CONFIG REQUIRED)
minitest_discover_tests(WebView2_GUI)

target_link_libraries(WebView2_GUI
    PUBLIC windowsapp)

if(BUILD_TESTING AND (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME))
    add_subdirectory(test.main)
else()
    target_compile_definitions(WebView2_GUI PRIVATE MINITEST_CONFIG_DISABLE)
endif()