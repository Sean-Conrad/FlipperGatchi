#include "../tasks/Task.h"
#include "Player.h"
#include "iostream"

Player :: Player() : level(1) , coins(0) , exp(0), nextLevel(50) {}

int Player :: getLevel() const {return level;}

int Player :: getCoins() const {return coins;}

int Player :: getExp() const {return exp;}

int Player :: getNextLevel() const {return nextLevel;}

std::vector<Task> Player :: getTasks() {return tasks;}

void Player :: addCoins(int amount) {
    coins+= amount;
}

void Player :: addExp(int amount) {
    exp+= amount;
}

void Player :: levelUp() {
    if(exp >= nextLevel){
        level++;
        nextLevel = nextLevel*2;
    }
    
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
                addExp(reward);
                levelUp();
                tasks.erase(std::remove(tasks.begin(), tasks.end(), task), tasks.end());
                return true; //Task completed and rewarded.
            }
            return false; //Task is overdue, no reward.
        }
    }
    return false; //Task not found.
}

bool Player::removeTask(const std::string& taskName){
    for(Task& task: tasks) {
        if(task.getName() == taskName){
            tasks.erase(std::remove(tasks.begin(), tasks.end(), task), tasks.end());
            std::cout << "Task: " << taskName << " has been removed.\n" ; 
            return true;
        }
    }
    std::cout << "Task: " << taskName << "does not exist!\n";
    return false;
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