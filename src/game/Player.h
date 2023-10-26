class Player {
private:
    int level;
    int coins;

public:
    Player (); // Default constructor
    int getLevel();
    int getCoins();
    void addCoins(int amount);
    void levelUp();

};