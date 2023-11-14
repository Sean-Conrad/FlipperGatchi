#include <vector>
#include <Task.h>

class Player {
private:
    std::vector<Task> tasks;
    int level;
    int coins;

public:
    Player (); // Default constructor
    int getLevel() const;
    int getCoins() const;
    void addCoins(int amount);
    void levelUp();
    void createTask(const std::string&taskName, int rewardCoins, bool isMandatory);
    bool completeTask(const std::string& taskName);
    void displayTasks() const;

};