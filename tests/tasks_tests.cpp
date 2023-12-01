#include "../src/tasks/Task.h"
#include "../src/game/Player.h"
#include <iostream>
#include <cassert>

void testTaskCreation() {
    Task t("Gym", 10, false);
    assert(t.getName() == "Gym");
    assert(t.getRewardCoins() == 10);
    assert(t.getIsMandatory() == false);
    std::cout << "Task creation test passed.\n";
}

void testPlayerTaskInteraction(){
    Player p;

    // create tasks
    p.createTask("Study for exam", 30, true ); //Mandatory
    p.createTask("Go to gym", 10, false); // Not Mandatory

    //display tasks
    std::cout << "Initial Tasks\n"; 
    p.displayTasks();

    //complete tasks
    bool task1Completed = p.completeTask("Study for exam");
    bool task2Completed = p.completeTask("Go to gym");

    //display update tasks
    std::cout << "Updated Tasks\n"; 
    p.displayTasks();

    //assert successful
    assert(task1Completed == true);
    assert(task2Completed == true);

    std::cout << "Player Task interaction tests passed\n";

}

int main() {
    testTaskCreation();
    testPlayerTaskInteraction();
    std::cout << "All task tests passed!\n";
    return 0;
}