#include<iostream>
using namespace std;
#define TABLE_SIZE 6

class HashTable {
private:
    int* htable; // Array to store the keys
    int* values; // Array to store the values
    bool* isOccupied; // Array to track if a slot is occupied

public:
    HashTable() {
        htable = new int[TABLE_SIZE];
        values = new int[TABLE_SIZE];
        isOccupied = new bool[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            htable[i] = -1; // Initialize keys to -1 to indicate empty slots
            values[i] = 0; // Initialize values to 0
            isOccupied[i] = false;
        }
    }

    ~HashTable() {
        delete[] htable;
        delete[] values;
        delete[] isOccupied;
    }

    /*
     * Hash Function
     */
    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    /*
     * Insert Element
     */
    void Insert(int key, int value) {
        int hash_val = HashFunc(key);
        int original_hash = hash_val;

        // Linear probing to find an empty slot
        while (isOccupied[hash_val]) {
            hash_val = (hash_val + 1) % TABLE_SIZE;
            if (hash_val == original_hash) {
                cout << "Hash table is full. Cannot insert key " << key << endl;
                return;
            }
        }

        htable[hash_val] = key;
        values[hash_val] = value;
        isOccupied[hash_val] = true;
        cout << "Key " << key << " inserted at index " << hash_val << endl;
    }

    /*
     * Remove Element
     */
    void Remove(int key) {
        int hash_val = HashFunc(key);
        int original_hash = hash_val;

        // Linear probing to find the key
        while (isOccupied[hash_val] && htable[hash_val] != key) {
            hash_val = (hash_val + 1) % TABLE_SIZE;
            if (hash_val == original_hash) {
                cout << "Key " << key << " not found in the hash table." << endl;
                return;
            }
        }

        if (htable[hash_val] == key) {
            isOccupied[hash_val] = false;
            cout << "Key " << key << " removed from index " << hash_val << endl;
        } else {
            cout << "Key " << key << " not found in the hash table." << endl;
        }
    }

    /*
     * Search Element
     */
    int Search(int key) {
        int hash_val = HashFunc(key);
        int original_hash = hash_val;

        // Linear probing to find the key
        while (isOccupied[hash_val] && htable[hash_val] != key) {
            hash_val = (hash_val + 1) % TABLE_SIZE;
            if (hash_val == original_hash) {
                cout << "Key " << key << " not found in the hash table." << endl;
                return -1;
            }
        }

        if (htable[hash_val] == key) {
            cout << "Key " << key << " found at index " << hash_val << " with value " << values[hash_val] << endl;
            return values[hash_val];
        } else {
            cout << "Key " << key << " not found in the hash table." << endl;
            return -1;
        }
    }
};

/*
 * Main Contains Menu
 */
int main() {
    HashTable hash;
    int key, value;
    int choice;
    while (1) {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the table" << endl;
        cout << "3.Delete element from the table" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter key to be inserted: ";
            cin >> key;
            cout << "Enter value to be inserted: ";
            cin >> value;
            hash.Insert(key, value);
            break;
        case 2:
            cout << "Enter key to be searched: ";
            cin >> key;
            hash.Search(key);
            break;
        case 3:
            cout << "Enter key to be deleted: ";
            cin >> key;
            hash.Remove(key);
            break;
        case 4:
            exit(0);
        default:
            cout << "\nEnter correct option\n";
        }
    }

    return 0;
}

