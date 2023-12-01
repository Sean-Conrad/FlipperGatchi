#include "../tasks/Task.h"
#include "Player.h"
#include "iostream"

Player :: Player() : level(1) , coins(0) {}

int Player :: getLevel() const {return level;}

int Player :: getCoins() const {return coins;}

void Player :: addCoins(int amount) {
    coins+= amount;
}

void Player :: levelUp() {
    level++;
}

void Player::createTask(const std::string&taskName, int rewardCoins, bool isMandatory) {
    Task task(taskName, rewardCoins, isMandatory);
    tasks.push_back(task);
}

bool Player::completeTask(const std::string& taskName){
    for(Task& task : tasks) {
        if(task.getName() == taskName){
            int reward = task.complete();
            if(reward > 0) {
                addCoins(reward);
                tasks.erase(std::remove(tasks.begin(), tasks.end(), task), tasks.end());
                return true; //Task completed and rewarded.
            }
            return false; //Task is overdue, no reward.
        }
    }
    return false; //Task not found.
}

void Player::displayTasks() const {
    std::cout << "Current Tasks:\n";
    for (const Task& task : tasks) {
        std::cout << "- " << task.getName() << " (Reward: " << task.getRewardCoins() << " coins)";

        if(task.getIsMandatory()) {
            if(task.isOverdue()) {
                std::cout << " [Overdue]";
            } else {
                std::cout << "[Due in " << task.getHoursRemaining() << " hours]";
            }
        }
        std::cout << std::endl;
    }
}