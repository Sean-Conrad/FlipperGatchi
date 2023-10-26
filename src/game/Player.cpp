#include "Player.h"

Player :: Player() : level(1) , coins(0) {}

int Player :: getLevel() const {return level;}

int Player :: getCoins() const {return coins;}

void Player :: addCoins(int amount) {
    coins+= amount;
}

void Player :: levelUp() {
    level++;
}