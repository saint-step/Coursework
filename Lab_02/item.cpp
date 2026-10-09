#include "item.h"
#include <iostream>

namespace dnd {

    Item::Item(std::string_view name, Type type, int damage, int heal)
        : m_name(name), m_type(type), m_damage(damage), m_heal(heal)
    {
        std::cout << "Создан предмет: " << m_name << "\n";
    }

    Item::Item() : m_name("Empty"), m_type(Type::eWeapon), m_damage(0), m_heal(0)
    {
        std::cout << "Создан пустой предмет\n";
    }

    Item::~Item() {}

    std::string_view Item::GetName() const { return m_name; }
    int Item::GetDamage() const { return m_damage; }
    int Item::GetHeal() const { return m_heal; }
    Item::Type Item::GetType() const { return m_type; }

    void Item::Print() const {
        std::cout << "Предмет: " << m_name << " (Урон: " << m_damage << ", Лечение: " << m_heal << ")\n";
    }
}