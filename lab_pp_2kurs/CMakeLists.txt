cmake_minimum_required(VERSION 4.1)


project("lab_pp_2kurs")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weffc++ -Wextra -Wpedantic")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /W4")
endif()

add_subdirectory("laba1")