# Add static library
add_library(MyStaticLibrary STATIC MyStaticLibrary.cpp)

# Add include directory
target_include_directories(MyStaticLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
