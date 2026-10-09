#pragma once

#include "inventory.h"
#include <string>

namespace dnd {

class Character {
private:
    std::string m_name;
    int m_health;
    int m_maxHealth;
    
    Inventory m_inventory; 

public:
    Character(std::string_view name, int health);
    ~Character();

    void Attack(const Item& weapon);

    void Heal(const Item& potion);

    bool PickUpItem(const Item& item);

    [[nodiscard]] int GetHealth() const;
    [[nodiscard]] std::string_view GetName() const;

    void PrintStatus() const;
};
}