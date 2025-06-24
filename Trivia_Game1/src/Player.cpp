#include "Player.h"
#include <fstream>

Player::Player(std::string playerName) : name(std::move(playerName)), final_score(0) {}

void Player::saveScore() {
    std::ofstream out("players.txt", std::ios::app);
    out << name << " " << final_score << "\n";
}

int Player::loadScore(const std::string& playerName) {
    std::ifstream in("players.txt");
    std::string name;
    int score;
    while (in >> name >> score) {
        if (name == playerName) return score;
    }
    return -1;
}
