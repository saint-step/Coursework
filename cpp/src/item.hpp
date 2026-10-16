#pragma once

#include <string>
#include <string_view>

namespace dnd {

class Item {
public:
    enum class Type {
        eWeapon,
        ePotion,
    };

private:
    std::string m_name;
    Type m_type;
    int m_damage;
    int m_heal;

public:
    Item(std::string_view name, Type type, int damage = 0, int heal = 0);

    Item();

    ~Item();

    [[nodiscard]] std::string_view GetName() const;
    [[nodiscard]] int GetDamage() const;
    [[nodiscard]] int GetHeal() const;
    [[nodiscard]] Type GetType() const;

    void Print() const;
};
}