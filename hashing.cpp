#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<int> table;
    int capacity;
    int size;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int tableSize) {
        capacity = tableSize;
        table.resize(capacity, -1); // Initializing all slots to -1 (indicating empty slot)
        size = 0;
    }

    bool insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full. Cannot insert." << endl;
            return false;
        }

        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % capacity; // Linear probing
        }

        table[index] = key;
        size++;
        return true;
    }

    bool search(int key) {
        int index = hashFunction(key);

        int i = index;
        while (table[i] != -1) {
            if (table[i] == key) {
                return true;
            }
            i = (i + 1) % capacity; // Linear probing
            if (i == index) {
                break; // Reached back to the starting point, key not found
            }
        }

        return false;
    }

    bool remove(int key) {
        int index = hashFunction(key);

        int i = index;
        while (table[i] != -1) {
            if (table[i] == key) {
                table[i] = -1;
                size--;
                return true;
            }
            i = (i + 1) % capacity; // Linear probing
            if (i == index) {
                break; // Reached back to the starting point, key not found
            }
        }

        return false;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1) {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(15);
    ht.insert(25);

    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not found") << endl;
    cout << "Search 40: " << (ht.search(40) ? "Found" : "Not found") << endl;

    ht.remove(15);

    ht.display();

    return 0;
}
