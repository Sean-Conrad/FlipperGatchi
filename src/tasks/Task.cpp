#include "Task.h"
#include <iostream>

Task::Task(std::string name, int rewardCoins, bool isMandatory) 
: name(name), rewardCoins(rewardCoins), isMandatory(isMandatory), creationTime(std::time(nullptr)) {
    if(isMandatory) {
        deadlineHours = 24;
    }
}

std::string Task::getName() const { return name;} 

int Task::getRewardCoins() const {return rewardCoins;}

bool Task::getIsMandatory() const {return isMandatory;}

bool Task::isOverdue() const {
    if(!isMandatory){
        return false;
    }
    return (std::time(nullptr) - creationTime) > (deadlineHours * 3600); // ??? 
}

int Task::complete() {
    if (isOverdue()) {
        std::cout << "You missed the deadline for this task! No reward earned.\n";
        return 0;
    }
    std::cout << "Task '" << name << "' completed! Earned " << rewardCoins << " coins.\n";
    return rewardCoins;
}

int Task::getHoursRemaining() const {
    if(!isMandatory) {
        return 0; //Non-mandatory tasks have no remaining time.
    }

    // Calculate remaining time in hours based on the deadline.
    time_t now = std::time(nullptr);
    int elapsedHours = static_cast<int>((now - creationTime) / 3600);
    int remainingHours = deadlineHours - elapsedHours;

    return std::max(remainingHours, 0);

}