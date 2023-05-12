cmake_minimum_required(VERSION 3.19) # Lower versions should also be supported
project(chat)

# Add target to build iostream module
add_custom_target(std_modules ALL
	#COMMAND ${CMAKE_COMMAND} -E echo "Building standard library modules"
    COMMAND g++ -fmodules-ts -std=c++20 -g -c -x c++-system-header iostream typeinfo vector cstring 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Function to set up modules in GCC
function (prepare_for_module TGT)
    target_compile_options(${TGT} PUBLIC -fmodules-ts)
    target_compile_options(${TGT} PUBLIC -fpermissive)
    target_compile_options(${TGT} PUBLIC -g)
    set_property(TARGET ${TGT} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${TGT} PROPERTY CXX_EXTENSIONS OFF)
    add_dependencies(${TGT} std_modules)
endfunction()

# Program name and sources
set (TARGET chat)
set (SOURCES main.cpp)
set (MODULES client.cxx
	server.cxx
	ipscan.cxx
	message.cxx)

# Setup program modules object library
set (MODULE_TARGET chat_modules)
add_library(${MODULE_TARGET} OBJECT ${MODULES})
prepare_for_module(${MODULE_TARGET})

# Setup executable
add_executable(${TARGET} ${SOURCES})
prepare_for_module(${TARGET})

# Add modules to application using object library
target_link_libraries(${TARGET} PRIVATE ${MODULE_TARGET})

# ... above cmake code for one console application creation
# below code that I add:

#install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "bin" COMPONENT applications)

# pack
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "MyOrg")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CPack Component Installation Example")
set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_GENERATOR "ZIP")

include(CPack)

