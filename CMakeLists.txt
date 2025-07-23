# CPACSGen cmake project
# author: Bernhard Manfred Gruber

cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CPACSGen)

# cache variables
set(TIXI_PATH  "" CACHE PATH "Tixi installation prefix")
set(TIGL_PATH  "" CACHE PATH "Tigl installation prefix")

# special handling for enforcing old c++ ABI on RHEL7 (required when using a self-built gcc without 
string (REGEX MATCH "\\.el7\\." SYSTEM_RHEL7 ${CMAKE_SYSTEM})
if (SYSTEM_RHEL7)
    OPTION(ENFORCE_OLD_CXX_ABI "Enforce old CXX ABI (_GLIBCXX_USE_CXX11_ABI=0)" ON)
    if (ENFORCE_OLD_CXX_ABI)
        add_definitions("-D_GLIBCXX_USE_CXX11_ABI=0")
    endif()
endif()

# find tixi
set(CMAKE_PREFIX_PATH "${TIXI_PATH};${CMAKE_PREFIX_PATH}")
find_package(tixi3 3.0.3 REQUIRED)

# lib
file(GLOB LIB_INPUTS src/lib/*.cpp *src/lib/*.h *src/lib/runtime/*.h)
add_library(lib${PROJECT_NAME} ${LIB_INPUTS})
target_link_libraries(lib${PROJECT_NAME} PUBLIC tixi3)
source_group(" " FILES ${LIB_INPUTS})

target_compile_definitions(lib${PROJECT_NAME} PUBLIC
	-DCPACS_GEN
)


# driver
file(GLOB DRIVER_INPUTS src/driver/*.cpp *src/driver/*.h *.md)
add_executable(${PROJECT_NAME} ${DRIVER_INPUTS})
source_group(" " FILES ${DRIVER_INPUTS})

target_link_libraries(${PROJECT_NAME}
	lib${PROJECT_NAME}
)

# tests
message(STATUS "Build gtest Testsuite")

enable_testing()
option(gtest_force_shared_crt "" ON)
mark_as_advanced(gtest_force_shared_crt gtest_build_tests gtest_build_samples gtest_disable_pthreads)

set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
add_subdirectory(thirdparty/googletest)

set(DATA_DIR ${CMAKE_SOURCE_DIR}/test/data)
configure_file(test/paths.h.in ${CMAKE_BINARY_DIR}/test/paths.h)

file(GLOB TEST_INPUTS test/*.cpp test/*.h)
list(APPEND TEST_INPUTS ${CMAKE_BINARY_DIR}/test/paths.h)
add_executable(tests ${TEST_INPUTS})
target_link_libraries(tests PRIVATE gtest gtest_main libCPACSGen)
target_include_directories(tests PUBLIC
	${CMAKE_BINARY_DIR}/test
)
add_test(NAME tests COMMAND tests)

# generate target
if(TIGL_PATH)
	set(GENERATOR_INPUT_DIR  ${TIGL_PATH}/cpacs_gen_input CACHE PATH "Generator input files (Tigl cpacs_gen_input directory)")
	set(GENERATOR_OUTPUT_DIR ${TIGL_PATH}/src/generated   CACHE PATH "Output directory for the generated CPACS classes (Tigl src/generated directory)")

	# add custom target to generate files side by side to TIGL source
	add_custom_target(
		generate
		COMMAND ${PROJECT_NAME} ${GENERATOR_INPUT_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/runtime ${GENERATOR_OUTPUT_DIR}
		COMMENT Running CPACSGen
		VERBATIM
	)
else()
	message(WARNING "TIGL_PATH is not specified. Target generate will not be created")
endif()

# copy shared library to ouput directory
if (WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:tixi3>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
endif (WIN32)
