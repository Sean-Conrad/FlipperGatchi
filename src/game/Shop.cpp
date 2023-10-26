#include "Shop.h"
#include "Player.h"
#include <iostream>

Shop::Shop() {
    items.push_back(ShopItem("Golden Hat", 50));
    items.push_back(ShopItem("Special Badge", 100));
}   

void Shop::displayItems() const {
    std::cout << "Available items:\n";
    for (const auto &e : items){
        std::cout << "- " << e.name << " (Cost: " << e.price << ") coins\n";
    }
}

bool Shop::purchaseItem(const std::string &itemName, Player &player){
    for(auto &e : items) {
        if(e.name == itemName) {
            if (player.getCoins() >= e.price){
                player.addCoins(-e.price);
                return true;
            } else {
                std::cout << "Not enough coins.\n";
                return false;
            }
        }
    }
    std::cout << "Item not found.\n";
    return false; 
}