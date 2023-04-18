cmake_minimum_required(VERSION 3.21)
project(LookAtCursorSFML LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(src/const)
include_directories(src/states)
include_directories(src/utils)

add_executable(LookAtCursorSFML 
    src/application.h 
    src/circle.h 
    src/const/state_identifiers.h 
    src/states/game_state.h 
    src/states/state.h 
    src/states/state_stack.h 
    src/unit.h 
    src/utils/resource_holder.h 
    src/utils/resource_identifiers.h 
    src/world.h 
    src/application.cpp 
    src/main.cpp 
    src/states/game_state.cpp 
    src/states/state.cpp 
    src/states/state_stack.cpp 
    src/world.cpp
)
target_link_libraries(LookAtCursorSFML PRIVATE sfml-window sfml-graphics sfml-system)
target_compile_features(LookAtCursorSFML PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET LookAtCursorSFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:LookAtCursorSFML> $<TARGET_FILE_DIR:Polyomino> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS LookAtCursorSFML)
