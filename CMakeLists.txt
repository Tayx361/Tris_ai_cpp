cmake_minimum_required(VERSION 3.10)
project(TicTacToe)
add_executable(tictactoe src/main.cpp src/player.cpp src/interface src/randomAi.cpp src/smartAi.cpp)
target_include_directories(tictactoe PRIVATE include)
