cmake_minimum_required(VERSION 3.27)
project(Spoti_fam)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Spoti_fam
        Quiz.cpp
        Quiz.h
        Login.cpp
        Login.h
        Result.h
        Result.cpp)

target_link_libraries(Spoti_fam  PRIVATE sfml-graphics)
target_compile_features(Spoti_fam  PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET Spoti_fam
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Spoti_fam >
            VERBATIM)
endif()

install(TARGETS Spoti_fam )
