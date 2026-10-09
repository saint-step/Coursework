#include "character.h"
#include <iostream>

namespace dnd {

    Character::Character(std::string_view name, int health)
        : m_name(name), m_health(health), m_maxHealth(health)
    {
        std::cout << "Создан персонаж: " << m_name << " (HP: " << m_health << ")\n";
    }

    Character::~Character() {
        std::cout << "Персонаж " << m_name << " уничтожен.\n";
    }

    void Character::Attack(const Item& weapon) {
        if (weapon.GetType() != Item::Type::eWeapon) {
            std::cout << "Ошибка: " << weapon.GetName() << " не является оружием!\n";
            return;
        }
        std::cout  << m_name << " атакует с помощью " << weapon.GetName()
            << " на " << weapon.GetDamage() << " урона!\n";
    }

    void Character::Heal(const Item& potion) {
        if (m_health >= m_maxHealth) {
            std::cout << "Ошибка: Здоровье уже максимальное (" << m_maxHealth << "). Зелье не нужно.\n";
            return;
        }

        if (potion.GetType() != Item::Type::ePotion) {
            std::cout << "Ошибка: " << potion.GetName() << " не является зельем!\n";
            return;
        }

        m_health += potion.GetHeal();
        if (m_health > m_maxHealth) m_health = m_maxHealth;
        std::cout << m_name << " выпил " << potion.GetName()
            << ". Текущее HP: " << m_health << "\n";
    }

    bool Character::PickUpItem(const Item& item) {
        return m_inventory.AddItem(item);
    }

    int Character::GetHealth() const { return m_health; }
    std::string_view Character::GetName() const { return m_name; }

    void Character::PrintStatus() const {
        std::cout << "Статус: " << m_name << " | HP: " << m_health << "/" << m_maxHealth << " \n";
        m_inventory.ShowItems();
    }
}