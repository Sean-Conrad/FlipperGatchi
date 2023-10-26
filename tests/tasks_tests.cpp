#include "../src/tasks/Task.h"
#include <iostream>
#include <cassert>

void testTaskCreation() {
    Task t("Gym", 10, false);
    assert(t.getName() == "Gym");
    assert(t.getRewardCoins() == 10);
    assert(t.getIsMandatory() == false);
    std::cout << "Task creation test passed.\n";
}

int main() {
    testTaskCreation();
    std::cout << "All task tests passed!\n";
    return 0;
}