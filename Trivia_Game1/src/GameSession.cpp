#include "GameSession.h"
#include <fstream>
#include <sstream>
#include <iostream>

GameSession::GameSession() : score(0), current_question_index(0) {}

bool GameSession::loadQuestions(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "❌ Failed to open file: " << path << "\n";
        return false;
    }

    int num;
    file >> num;
    file.ignore();

    std::cout << "📄 Loading " << num << " questions...\n";

    questions.clear();
    for (int i = 0; i < num; ++i) {
        std::string category, text, opts_line;
        int correct;
        std::getline(file, category);
        std::getline(file, text);
        std::getline(file, opts_line);
        file >> correct;
        file.ignore();

        std::vector<std::string> options;
        std::stringstream ss(opts_line);
        std::string option;
        while (std::getline(ss, option, ';')) {
            options.push_back(option);
        }

        std::cout << "✅ Question " << (i + 1) << ": " << text << " (" << category << ")\n";

        questions.emplace_back(category, text, options, correct);
    }

    return true;
}

Question* GameSession::getNextQuestion() {
    if (current_question_index < questions.size())
        return &questions[current_question_index];
    return nullptr;
}

bool GameSession::submitAnswer(int index) {
    if (current_question_index >= questions.size()) return false;
    if (questions[current_question_index].isCorrect(index)) score++;
    current_question_index++;
    return true;
}

void GameSession::endSession(const std::string& playerName) {
    std::ofstream log("session_log.txt", std::ios::app);
    log << playerName << " " << score << "\n";
}
