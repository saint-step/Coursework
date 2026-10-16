public class Inventory {
    private final Item[] items; 
    private int count;         
    private final int capacity; 

    public Inventory() {
        this.capacity = 5;
        this.items = new Item[capacity];
        this.count = 0;
        System.out.println("Инвентарь создан (Композиция)");
    }

    public boolean addItem(Item item) {
        if (count >= capacity) {
            System.out.println("Ошибка: Инвентарь полон! Нельзя добавить " + item.getName());
            return false;
        }
        items[count] = item; 
        count++;             
        System.out.println("Добавлен предмет: " + item.getName());
        return true;
    }

    public void showItems() {
        if (count == 0) {
            System.out.println("Инвентарь пуст.");
            return;
        }
        System.out.println("Содержимое:");
        for (int i = 0; i < count; i++) {
            items[i].print(); 
        }
    }

    public int getSize() {
        return count;
    }
}