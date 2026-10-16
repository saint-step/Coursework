#pragma once

#include "item.hpp"
#include <memory>

namespace dnd {

    class Inventory {
    private:
        std::unique_ptr<Item[]> m_items;
        int m_count;
        int m_capacity;

    public:
        Inventory();
        ~Inventory();

        bool AddItem(const Item& item);
        void ShowItems() const;
        [[nodiscard]] int GetSize() const;
    };

} 