#include "inventory.h"
#include <iostream>

namespace dnd {

    Inventory::Inventory() {
        std::cout << "Инвентарь создан (Композиция)\n";
    }

    Inventory::~Inventory() {
        std::cout << "Инвентарь уничтожен. Все " << m_items.size() << " предметов внутри исчезли.\n";
    }

    bool Inventory::AddItem(const Item& item) {
        if (m_items.size() >= MAX_CAPACITY) {
            std::cout << "Ошибка: Инвентарь полон! Нельзя добавить " << item.GetName() << "\n";
            return false;
        }
        m_items.push_back(item);
        std::cout << "Добавлен предмет: " << item.GetName() << "\n";
        return true;
    }

    void Inventory::ShowItems() const {
        if (m_items.empty()) {
            std::cout << "Инвентарь пуст.\n";
            return;
        }
        std::cout << "Содержимое:\n";
        for (const auto& item : m_items) {
            item.Print();
        }
    }

    size_t Inventory::GetSize() const { return m_items.size(); }
}