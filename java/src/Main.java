import java.lang.ref.WeakReference;

/* По хорошему в Жабе один класс = один файл, но в задании сказано 
продемонстрировать освобождение ресурса без деструктора и чтобы не выносить 
этот лишний класс в другой файл я написал его здесь, но отдельно от main*/
class Journal implements AutoCloseable {
    private final String title;

    public Journal(String title) {
        this.title = title;
        System.out.println("Журнал открыт: " + title);
    }

    public void write(String line) {
        System.out.println(line);
    }

    @Override
    public void close() {
        System.out.println("Журнал закрыт: " + title);
    }
}

public class Main {
    public static void main(String[] args) {

        System.out.println("    Создание предметов (Агрегация)");
        Item sword = new Item("Стальной меч", Item.Type.WEAPON, 15, 0);
        Item potion = new Item("Зелье лечения", Item.Type.POTION, 0, 20);

        System.out.println("\n    Создание персонажа (Композиция)");
        Character hero = new Character("Сир Степан", 100);

        System.out.println("\n    Проверка правил");
        hero.attack(potion); 
        hero.heal(potion);  

        System.out.println("\n    Подбор предметов");
        hero.pickUpItem(sword);
        hero.pickUpItem(potion);

        hero.pickUpItem(new Item("Копьё", Item.Type.WEAPON, 10, 0));
        hero.pickUpItem(new Item("Нож", Item.Type.WEAPON, 5, 0));
        hero.pickUpItem(new Item("Топор", Item.Type.WEAPON, 12, 0));
        hero.pickUpItem(new Item("Сабля", Item.Type.WEAPON, 8, 0));

        System.out.println("\n    Статус персонажа");
        hero.printStatus();

        System.out.println("\n    Ссылки и копии");
        Item first = new Item("Свиток", Item.Type.POTION, 0, 5);
        Item second = first;
        System.out.println("first == second? " + (first == second));

        Character hero2 = hero;
        System.out.println("hero == hero2? " + (hero == hero2));

        System.out.println("\n    Освобождение ресурса (try-with-resources)");
        try (Journal zapisat = new Journal("Подарочные свитки")) {
            zapisat.write("Выдан свиток лечения!");
            zapisat.write("Выдан свиток силы!");
        }

        System.out.println("\n    Сборщик мусора");
        Item temp = new Item("Старый свиток", Item.Type.POTION, 0, 1);
        WeakReference<Item> watcher = new WeakReference<>(temp);
        System.out.println("Объект жив? " + (watcher.get() != null));
        temp = null;  
        System.gc();
        System.out.println("Объект жив после сборки? " + (watcher.get() != null));
    }
}