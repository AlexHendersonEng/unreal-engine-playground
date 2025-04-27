# Add shared library
add_library(MySharedLibrary SHARED MySharedLibrary.cpp)

# Add include directory
target_include_directories(MySharedLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add preprocessor definitions
add_compile_definitions("SHARED_LIBRARY_EXPORT")
