#include "inventory.hpp"
#include <iostream>

namespace dnd {

    Inventory::Inventory()
        : m_items(std::make_unique<Item[]>(5))
        , m_count(0)
        , m_capacity(5)
    {
        std::cout << "Инвентарь создан (Композиция)\n";
    }

    Inventory::~Inventory() {
        std::cout << "Инвентарь уничтожен. Все предметы исчезли.\n";
    }

    bool Inventory::AddItem(const Item& item) {
        if (m_count >= m_capacity) {
            std::cout << "Ошибка: Инвентарь полон! Нельзя добавить " << item.GetName() << "\n";
            return false;
        }
        m_items[m_count] = item;
        m_count++;
        std::cout << "Добавлен предмет: " << item.GetName() << "\n";
        return true;
    }

    void Inventory::ShowItems() const {
        if (m_count == 0) {
            std::cout << "Инвентарь пуст.\n";
            return;
        }
        std::cout << "Содержимое:\n";
        for (int i = 0; i < m_count; ++i) {
            m_items[i].Print();
        }
    }

    int Inventory::GetSize() const { return m_count; }
}