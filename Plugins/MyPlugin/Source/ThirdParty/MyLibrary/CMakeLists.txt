# Set minimum CMake version
cmake_minimum_required(VERSION 3.12)

# Set project name
project("MyLibrary")

# Allow the user to enable/disable tests
option(ENABLE_TESTING "Enable testing with CTest" ON)

# Include sub-projects.
add_subdirectory("MyStaticLibrary")
add_subdirectory("MySharedLibrary")
add_subdirectory("MyTest")

# Enable testing if requested
if(ENABLE_TESTING)
    enable_testing()
    add_test(NAME Test1 COMMAND MyTest)
endif()

# Install the project
install(TARGETS MyTest MyStaticLibrary MySharedLibrary
    RUNTIME DESTINATION "bin"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
)

# Package the project
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "MyLibrary")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "My library package")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "MyLibrary")
set(CPACK_GENERATOR "NSIS")
set(CPACK_NSIS_DISPLAY_NAME "My Library Installer")
set(CPACK_NSIS_PACKAGE_NAME "MyLibrary")
include(CPack)