public class Character {
    private final String name;
    private int health;
    private final int maxHealth;
    private final Inventory inventory;

    public Character(String name, int health) {
        this.name = name;
        this.health = health;
        this.maxHealth = health;
        this.inventory = new Inventory();
        System.out.println("Создан персонаж: " + name + " (HP: " + health + ")");
    }

    public void attack(Item weapon) {
        if (weapon.getType() != Item.Type.WEAPON) {
            System.out.println("Ошибка: " + weapon.getName() + " не является оружием!");
            return;
        }
        System.out.println(name + " атакует с помощью " + weapon.getName()
                + " на " + weapon.getDamage() + " урона!");
    }

    public void heal(Item potion) {
        if (health >= maxHealth) {
            System.out.println("Ошибка: Здоровье уже максимальное (" + maxHealth + "). Не трать просто так, болван!");
            return;
        }
        if (potion.getType() != Item.Type.POTION) {
            System.out.println("Ошибка: " + potion.getName() + " не является зельем!");
            return;
        }
        health += potion.getHeal();
        if (health > maxHealth) {
            health = maxHealth;
        }
        System.out.println(name + " выпил " + potion.getName()
                + ". Текущее HP: " + health);
    }

    public boolean pickUpItem(Item item) {
        return inventory.addItem(item); 
    }

    public String getName() { return name; }
    public int getHealth() { return health; }

    public void printStatus() {
        System.out.println("Статус: " + name + " | HP: " + health + "/" + maxHealth + "    ");
        inventory.showItems();
    }
}