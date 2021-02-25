project("caesargui")
cmake_minimum_required(VERSION "3.7")

# include OpenCL
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})

# include clhelper
add_subdirectory(clhelper)
include_directories(clhelper/include)

# include wxWidgets
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} src/main.cpp src/window.cpp src/caesarify.cpp)

# link clhelper
target_link_libraries(${PROJECT_NAME} clhelper)

# link OpenCL
target_link_libraries(${PROJECT_NAME} ${OpenCL_LIBRARY})

# link wxWidgets
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

configure_file(src/caesar.cl ${CMAKE_CURRENT_BINARY_DIR}/caesar.cl COPYONLY)
