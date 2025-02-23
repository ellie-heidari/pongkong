
cmake_minimum_required(VERSION 3.10)
project(PongKong C)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include your project headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Gather all C source files from the src directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Create the executable target
add_executable(pongkong ${SOURCES})

# Link SDL2 libraries
target_link_libraries(pongkong ${SDL2_LIBRARIES})

# Optionally copy assets to the build output directory after building
#add_custom_command(TARGET pongkong POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_directory
#          ${PROJECT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:my_game>/assets)
