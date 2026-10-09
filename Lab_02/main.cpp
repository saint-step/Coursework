#include <windows.h>
#include <iostream>
#include "character.h"
#include "item.h"

using namespace dnd;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "    Создание предметов (Агрегация)    \n";
    Item* sword = new Item("Стальной меч", Item::Type::eWeapon, 15, 0);
    Item* potion = new Item("Зелье лечения", Item::Type::ePotion, 0, 20);

    Item* items_massiv = new Item[2];
    items_massiv[0] = Item("Кинжал", Item::Type::eWeapon, 8, 0);
    items_massiv[1] = Item("Большое зелье", Item::Type::ePotion, 0, 30);

    for (int i = 0; i < 2; ++i) {
        items_massiv[i].Print();
    }
    delete[] items_massiv;

    std::cout << "\n    Создание персонажа (Композиция)    \n";
    {
        Character hero("Сир Степан", 100);

        std::cout << "\n    Проверка правил    \n";
        hero.Attack(*potion);
        hero.Heal(*potion);

        std::cout << "\n    Подбор предметов    \n";
        hero.PickUpItem(*sword);
        hero.PickUpItem(*potion);

        // Проверка вместимости инвентаря
        Item spear("Копьё", Item::Type::eWeapon);
        Item knife("Нож", Item::Type::eWeapon);
        Item axe("Топор", Item::Type::eWeapon);
        Item saber("Сабля", Item::Type::eWeapon);
        hero.PickUpItem(spear);
        hero.PickUpItem(knife);
        hero.PickUpItem(axe);
        hero.PickUpItem(saber); // Возникает ошибка

        std::cout << "\n    Статус персонажа    \n";
        hero.PrintStatus();

        std::cout << "\n    Выход из блока (уничтожение Персонажа и Инвентаря)    \n";
    }

    std::cout << "\n    Проверка Агрегации: Предметы не удалены   \n";
    std::cout << "Меч существует: " << sword->GetName() << "\n";
    std::cout << "Зелье существует: " << potion->GetName() << "\n";

    delete sword;
    delete potion;

    return 0;
}