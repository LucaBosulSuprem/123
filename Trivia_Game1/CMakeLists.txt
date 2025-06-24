cmake_minimum_required(VERSION 3.20)
project(Trivia_Game1)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SRC_FILES
        src/Question.cpp
        src/Player.cpp
        src/GameSession.cpp
)

add_executable(game_engine
        game_engine/game_engine.cpp
        ${SRC_FILES}
)

add_executable(game_ui
        game_ui/game_ui.cpp
        ${SRC_FILES}
)

