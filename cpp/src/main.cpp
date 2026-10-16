#include <windows.h>
#include <iostream>
#include <memory>
#include "character.hpp"
#include "item.hpp"

using namespace dnd;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << "    Создание предметов (Агрегация)\n";
    std::unique_ptr<Item> sword = std::make_unique<Item>("Стальной меч", Item::Type::eWeapon, 15, 0);
    std::unique_ptr<Item> potion = std::make_unique<Item>("Зелье лечения", Item::Type::ePotion, 0, 20);

    std::cout << "\n    Динамический массив предметов\n";
    std::unique_ptr<Item[]> items_massiv = std::make_unique<Item[]>(2);
    items_massiv[0] = Item("Кинжал", Item::Type::eWeapon, 8, 0);
    items_massiv[1] = Item("Большое зелье", Item::Type::ePotion, 0, 30);
    for (int i = 0; i < 2; ++i) {
        items_massiv[i].Print();
    }

    std::cout << "\n    Создание персонажа (Композиция)\n";
    {
        Character hero("Сир Степан", 100);

        std::cout << "\n    Проверка правил\n";
        hero.Attack(*potion);
        hero.Heal(*potion);

        std::cout << "\n    Подбор предметов\n";
        hero.PickUpItem(*sword);
        hero.PickUpItem(*potion);

        Item spear("Копьё", Item::Type::eWeapon, 10, 0);
        Item knife("Нож", Item::Type::eWeapon, 5, 0);
        Item axe("Топор", Item::Type::eWeapon, 12, 0);
        Item saber("Сабля", Item::Type::eWeapon, 8, 0);
        hero.PickUpItem(spear);
        hero.PickUpItem(knife);
        hero.PickUpItem(axe);
        hero.PickUpItem(saber);

        std::cout << "\n    Статус персонажа\n";
        hero.PrintStatus();

        std::cout << "\n    Выход из блока (уничтожение Персонажа и Инвентаря)\n";
    }

    std::cout << "\n    Проверка Агрегации: Предметы не удалены   \n";
    std::cout << "Меч существует: " << sword->GetName() << "\n";
    std::cout << "Зелье существует: " << potion->GetName() << "\n";


    std::cout << "\n    Демонстрация shared_ptr\n";
    std::shared_ptr<Item> sharedSword = std::make_shared<Item>("Общий меч", Item::Type::eWeapon, 20, 0);
    std::cout << "Владельцев: " << sharedSword.use_count() << "\n";

    {
        std::shared_ptr<Item> copy = sharedSword;
        std::cout << "Владельцев после копии: " << sharedSword.use_count() << "\n";
    }

    std::cout << "Владельцев после выхода из блока: " << sharedSword.use_count() << "\n";

    std::cout << "\n    Демонстрация weak_ptr\n";
    std::weak_ptr<Item> weakSword = sharedSword;

    if (std::shared_ptr<Item> locked = weakSword.lock()) {
        std::cout << "weak_ptr: объект жив, имя = " << locked->GetName() << "\n";
    }
    else {
        std::cout << "weak_ptr: объект уничтожен\n";
    }

    sharedSword.reset();

    if (std::shared_ptr<Item> locked = weakSword.lock()) {
        std::cout << "weak_ptr: объект жив, имя = " << locked->GetName() << "\n";
    }
    else {
        std::cout << "weak_ptr: объект уничтожен\n";
    }

    return 0;
}