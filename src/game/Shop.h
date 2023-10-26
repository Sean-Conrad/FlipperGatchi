#include <vector>
#include <string>

class ShopItem {
public:
    std::string name;
    int price;
    ShopItem(std::string name, int price) : name(name) , price(price) {};
};

class Shop {
private:
    std::vector<ShopItem> items;
public:
    Shop();
    void displayItems() const;
    bool purchaseItem(const std::string &itemName, Player& player);

};