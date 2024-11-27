#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
 * Hash Table class with Quadratic Probing
 */
class HashTable {
private:
    int TABLE_SIZE = 11;                 // Size of the hash table (11 slots)
    vector<int> keys;                    // Array to store keys (number of mangoes)
    vector<int> values;                  // Array to store values (category of mangoes)

public:
    // Constructor to initialize the table
    HashTable() {
        keys.resize(TABLE_SIZE, -1);     // Initialize keys to -1 (indicating empty slot)
        values.resize(TABLE_SIZE, -1);   // Initialize values to -1
    }

    /*
     * Hash Function: key mod TABLE_SIZE
     */
    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    /*
     * Insert key-value pair using Quadratic Probing
     */
    void Insert(int key, int value) {
        int hashIndex = HashFunc(key);   // Compute initial hash index
        int i = 0;                       // Quadratic probing index

        // Find an empty slot using quadratic probing
        while (keys[(hashIndex + i * i) % TABLE_SIZE] != -1) {
            i++;
            if (i >= TABLE_SIZE) {
                cout << "Hash table overflow! Unable to insert key: " << key << endl;
                return;
            }
        }

        // Insert the key and value at the computed index
        int finalIndex = (hashIndex + i * i) % TABLE_SIZE;
        keys[finalIndex] = key;
        values[finalIndex] = value;
        cout << "Inserted key " << key << " for category " << value << " at index " << finalIndex << endl;
    }

    /*
     * Display the Hash Table
     */
    void Display() {
        cout << "\nHash Table Contents:\n";
        cout << setw(10) << "Index" << setw(20) << "Number of Mangoes" << setw(20) << "Category" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << setw(10) << i << setw(20) << (keys[i] == -1 ? "EMPTY" : to_string(keys[i]))
                 << setw(20) << (values[i] == -1 ? "EMPTY" : to_string(values[i])) << endl;
        }
    }
};

/*
 * Main Function
 */
int main() {
    // Define the data
    int categories[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int mangoes[] = {25, 15, 10, 5, 11, 19, 16, 36, 42, 28, 32};
    int n = sizeof(categories) / sizeof(categories[0]);

    // Create the hash table
    HashTable hashTable;

    // Insert the data into the hash table
    for (int i = 0; i < n; i++) {
        hashTable.Insert(mangoes[i], categories[i]);
    }

    // Display the hash table
    hashTable.Display();

    return 0;
}

