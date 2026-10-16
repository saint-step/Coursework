public class Item {
    public enum Type {
        WEAPON,
        POTION
    }

    private final String name;
    private final Type type;
    private final int damage;
    private final int heal;

    public Item(String name, Type type, int damage, int heal) {
        this.name = name;
        this.type = type;
        this.damage = damage;
        this.heal = heal;
        System.out.println("Создан предмет: " + name);
    }

    public String getName() { return name; }
    public Type getType() { return type; }
    public int getDamage() { return damage; }
    public int getHeal() { return heal; }

    public void print() {
        System.out.println("Предмет: " + name + " (Урон: " + damage + ", Лечение: " + heal + ")");
    }

    @Override
    public String toString() {
        return "Предмет: " + name + " (Урон: " + damage + ", Лечение: " + heal + ")";
    }
}