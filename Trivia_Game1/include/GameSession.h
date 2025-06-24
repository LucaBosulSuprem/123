#ifndef GAMESESSION_H
#define GAMESESSION_H

#include "Question.h"
#include <vector>
#include <string>

class GameSession {
public:
    std::vector<Question> questions;
    int score;
    int current_question_index;

    GameSession();
    bool loadQuestions(const std::string& path);
    Question* getNextQuestion();
    bool submitAnswer(int index);
    void endSession(const std::string& playerName);
};

#endif
