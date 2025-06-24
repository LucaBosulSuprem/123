#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    std::string name;
    int final_score;

    Player(std::string playerName);
    void saveScore();
    static int loadScore(const std::string& playerName);
};

#endif
