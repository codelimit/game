cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

IF (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    find_package(sdl2 REQUIRED)
    add_definitions(-DBUILD_ENG)
    add_library(eng SHARED eng.cpp)
    target_link_libraries(eng PRIVATE SDL2::SDL2 SDL2::SDL2main)

    add_executable(main main.cpp)
    target_link_libraries(main eng)

ELSEIF (MINGW)   
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
    include_directories("C:/Program Files/mingw-w64/i686-7.2.0-posix-dwarf-rt_v5-rev0/mingw32/include")
    link_directories("C:/Program Files/mingw-w64/i686-7.2.0-posix-dwarf-rt_v5-rev0/mingw32/lib")
   
    add_definitions(-DBUILD_ENG)
  
    add_library(eng SHARED eng.cpp)
    target_link_libraries(eng mingw32 SDL2main SDL2 winmm imm32 version)
    add_executable(main main.cpp)
    target_link_libraries(main eng)

ELSEIF ()
    add_definitions(-DBUILD_ENG)
    add_library(eng SHARED eng.cpp)
    target_link_libraries(eng mingw32 SDL2main SDL2 winmm imm32 version)
    add_executable(main main.cpp)
    target_link_libraries(main eng)

ENDIF()