#include <vector>

class Player {
private:
    std::vector<Task> tasks;
    int level;
    int coins;
    int exp;
    int nextLevel;

public:
    Player (); // Default constructor
    int getLevel() const;
    int getCoins() const;
    int getExp() const; 
    int getNextLevel() const; 
    std::vector<Task> getTasks(); 
    void addCoins(int amount);
    void addExp(int amount); 
    void levelUp(); 
    void createTask(const std::string&taskName, int rewardCoins, bool isMandatory);
    bool completeTask(const std::string& taskName);
    bool removeTask(const std::string& taskName); //TEST ME
    void displayTasks() const;

};