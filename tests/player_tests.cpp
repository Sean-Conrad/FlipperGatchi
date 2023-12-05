#include "../src/tasks/Task.h"
#include "../src/game/Player.h"
#include <vector>
#include <iostream>
#include <cassert>


//Tests tasks completion and coin reward
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

//Tests player exp and level up
void testPlayerLevelUp(){
    Player P;
    assert(P.getExp() == 0);
    assert(P.getLevel() == 1);
    assert(P.getNextLevel() == 50);
    P.createTask("Sing", 50, false);
    P.completeTask("Sing");
    assert(P.getExp() == 50);
    assert(P.getLevel() == 2);
    assert(P.getNextLevel() == 100);
    std::cout << "Player Level Up Test Passed\n";
}

//Test player remove task
void testPlayerRemoveTask(){
    Player P;


    std::cout << "Number of tasks: " << P.getTasks().size() << std::endl;
    P.createTask("Jump", 35, false);
    std::cout << "Number of tasks: " << P.getTasks().size() << std::endl;
    assert(P.getTasks().size() == 1);
    P.removeTask("Jump");
    std::cout << "Number of tasks: " << P.getTasks().size() << std::endl;
    assert(P.getTasks().size() == 0);


    
}

int main() {

    testPlayerReward();
    testPlayerLevelUp();
    testPlayerRemoveTask();
    return 0;
}