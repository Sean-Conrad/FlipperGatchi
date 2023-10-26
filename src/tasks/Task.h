#include <string>
#include <ctime>

class Task {
private:
    std::string name;
    int rewardCoins;
    bool isMandatory;
    time_t creationTime;
    int deadlineHours;

public:
    Task(std::string name, int rewardCoins, bool isMandatory);

    std::string getName() const;
    int getRewardCoins() const;
    bool getIsMandatory() const;
    bool isOverdue() const;
    int complete();

};