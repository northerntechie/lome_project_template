cmake_minimum_required(VERSION 3.21)

# This template attempts to be "fetch_content"-able
# so that it works well with tools like CPM or other
# manual dependency management

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20") # Sometimes needed for older CMake versions

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name and language
project(
  myproject
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "%%myurl%%"
  LANGUAGES CXX C)

set(GIT_SHA
    "Unknown"
    CACHE STRING "SHA this build was generated from")

set(PROJECT_SOURCE_DIR "src")

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/*.hpp")

set(SOURCES_FILE "${CMAKE_CURRENT_SOURCE_DIR}/sources.py")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/sources.template.py"
    ${SOURCES_FILE}
    @ONLY
)

file(WRITE ${SOURCES_FILE} "SOURCES = [\n")
foreach(source ${SOURCES})
  file(APPEND ${SOURCES_FILE} "    \"${source}\",\n")
endforeach()
foreach(header ${HEADERS})
  file(APPEND ${SOURCES_FILE} "    \"${header}\",\n")
endforeach()
file(APPEND ${SOURCES_FILE} "]\n")

message(STATUS "Sources list written to ${SOURCES_FILE}")

string(
  SUBSTRING "${GIT_SHA}"
            0
            8
            GIT_SHORT_SHA)

# Copy test assets
set(DESTINATION_DIR ${CMAKE_BINARY_DIR})
file(MAKE_DIRECTORY ${DESTINATION_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${DESTINATION_DIR})

# Include directories
include_directories(src-external/json/include)

# Adding the src:
add_subdirectory(src)
