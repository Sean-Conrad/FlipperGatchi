#include "../src/tasks/Task.h"
#include "../src/game/Player.h"
#include <iostream>
#include <cassert>


void testPlayerReward(){
    Player P;
    P.createTask("Job hunt", 50, true);
    P.createTask("Write Flippergatchi", 40, false);

    P.completeTask("Job hunt");
    assert(P.getCoins() == 50);
    P.completeTask("Write Flippergatchi");
    assert(P.getCoins() == 90);
    std::cout << "Player Reward Test Passed\n";

}

int main() {

    testPlayerReward();
    return 0;
}