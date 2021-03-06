cmake_minimum_required(VERSION 2.8.9)
project (StreamingCC)

#Specify -O3
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")
#Specify C++11 flag
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()



# For the static library:
set ( PROJECT_LINK_LIBS libstreamingcc.a )

link_directories( ../build)

include_directories( ../src/streamingcc)

add_executable(sampling sampling_example.cc)

# check if Armadillo exists
find_package(Armadillo)
if (ARMADILLO_FOUND)
  add_definitions(-DARMA_FOUND)
  # target_link_libraries(test ${PROJECT_LINK_LIBS} armadillo)
  # target_link_libraries(sv ${PROJECT_LINK_LIBS} armadillo)
else (ARMADILLO_FOUND)
  #  target_link_libraries(sv ${PROJECT_LINK_LIBS})
endif (ARMADILLO_FOUND)

target_link_libraries(sampling ${PROJECT_LINK_LIBS})

