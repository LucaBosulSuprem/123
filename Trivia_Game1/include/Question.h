#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
public:
    std::string category;
    std::string text;
    std::vector<std::string> options;
    int correct_index;

    Question() = default;
    Question(std::string cat, std::string txt, std::vector<std::string> opts, int correct);
    bool isCorrect(int index) const;
};

#endif
