
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item(string n, int q) : name(n), quantity(q) {}
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(string name, int quantity) {
        items.push_back(Item(name, quantity));
        cout << "Item added: " << name << " (Quantity: " << quantity << ")\n";
    }

    void displayInventory() {
        cout << "\nInventory:\n";
        for (const auto& item : items) {
            cout << "Name: " << item.name << ", Quantity: " << item.quantity << "\n";
        }
    }

    void searchItem(string name) {
        for (const auto& item : items) {
            if (item.name == name) {
                cout << "Found: " << item.name << " (Quantity: " << item.quantity << ")\n";
                return;
            }
        }
        cout << "Item not found: " << name << "\n";
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int quantity;
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item quantity: ";
                cin >> quantity;
                inventory.addItem(name, quantity);
                break;
            }
            case 2:
                inventory.displayInventory();
                break;
            case 3: {
                string name;
                cout << "Enter item name to search: ";
                cin >> name;
                inventory.searchItem(name);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

