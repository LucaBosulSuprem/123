#include "GameSession.h"
#include "Player.h"
#include <iostream>

GameSession session;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./game_engine <command> [args...]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "load_questions" && argc == 3) {
        if (session.loadQuestions(argv[2]))
            std::cout << "\033[32mQuestions loaded successfully!\033[0m\n";
        else
            std::cerr << "\033[31mFailed to load questions.\033[0m\n";
    } else if (command == "start_game" && argc == 3) {
        session = GameSession();  // reset session
        std::cout << "\033[34mGame started for " << argv[2] << "\033[0m\n";
    } else if (command == "show_score" && argc == 3) {
        int score = Player::loadScore(argv[2]);
        if (score >= 0)
            std::cout << "\033[33mScore for " << argv[2] << ": " << score << "\033[0m\n";
        else
            std::cout << "\033[31mPlayer not found.\033[0m\n";
    } else {
        std::cerr << "Unknown command.\n";
    }

    return 0;
}
