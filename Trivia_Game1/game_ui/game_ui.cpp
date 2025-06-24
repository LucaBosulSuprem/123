#include "GameSession.h"
#include "Player.h"
#include <iostream>

GameSession session;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./game_ui <command> [args...]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "load_questions" && argc == 3) {
        if (session.loadQuestions(argv[2])) {
            std::cout << "\033[32mQuestions loaded successfully (UI)!\033[0m\n";
        } else {
            std::cerr << "\033[31mFailed to load questions in UI.\033[0m\n";
        }
        return 0;
    }

    if (command == "next_question") {
        Question* q = session.getNextQuestion();
        if (q) {
            std::cout << q->text << "\n";
            for (size_t i = 0; i < q->options.size(); ++i) {
                std::cout << i << ": " << q->options[i] << "\n";
            }
        } else {
            std::cout << "\033[33mNo more questions.\033[0m\n";
        }
    }

    else if (command == "answer" && argc == 3) {
        int index = std::stoi(argv[2]);
        if (session.submitAnswer(index)) {
            std::cout << "\033[32mAnswer recorded.\033[0m\n";
        } else {
            std::cout << "\033[31mInvalid or late answer.\033[0m\n";
        }
    }

    else if (command == "end_game") {
        std::string player = "default";
        session.endSession(player);
        std::cout << "\033[36mGame session ended.\033[0m\n";
    }

    else {
        std::cerr << "Unknown command.\n";
    }

    return 0;
}
