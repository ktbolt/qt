
# Ensure cmake version is at least 3.0
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

# Adds the source and build location to the include path 
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set Qt intallation.
if(UNIX AND NOT APPLE)
    set(Qt5_DIR "/opt/Qt5.6.3/5.6.3/gcc_64/lib/cmake/Qt5")
endif()

# Get Qt5 modules
find_package(Qt5 COMPONENTS Core Gui Widgets)

# Qt's MOC tool shall be automatically invoked 
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Get VTK modules
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# Set source files.
set(HEADER_FILES window.h) 
set(SOURCES main.cpp readvtu.cpp window.cpp ${HEADER_FILES})

# create excutable helloworld using main.cpp 
add_executable(file-explorer ${SOURCES}) 

# links against Qt5Core 
target_link_libraries(file-explorer Qt5::Core Qt5::Gui Qt5::Widgets ${VTK_LIBRARIES})


