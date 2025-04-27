# Add source to this project's executable.
add_executable(MyTest "MyTest.cpp" )

# Link against both libraries
target_link_libraries(MyTest PRIVATE MyStaticLibrary MySharedLibrary)

# Add include directories
target_include_directories(MyTest PRIVATE
    "${CMAKE_SOURCE_DIR}/MyStaticLibrary"
    "${CMAKE_SOURCE_DIR}/MySharedLibrary"
)

# Post-build step to copy the DLL next to the executable
add_custom_command(TARGET MyTest POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   "${CMAKE_BINARY_DIR}/MySharedLibrary/MySharedLibrary.dll"
                   "${CMAKE_BINARY_DIR}/MyTest")