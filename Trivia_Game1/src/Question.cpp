#include "Question.h"

Question::Question(std::string cat, std::string txt, std::vector<std::string> opts, int correct)
    : category(cat), text(txt), options(std::move(opts)), correct_index(correct) {}

bool Question::isCorrect(int index) const {
    return index == correct_index;
}
