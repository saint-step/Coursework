#pragma once

#include "item.h"
#include <vector>

namespace dnd {

class Inventory {
private:
    std::vector<Item> m_items;
    static constexpr int MAX_CAPACITY = 5;

public:
    Inventory();
    ~Inventory();

    bool AddItem(const Item& item);

    void ShowItems() const;

    [[nodiscard]] size_t GetSize() const;
};
}