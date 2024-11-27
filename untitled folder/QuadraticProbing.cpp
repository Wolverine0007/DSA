#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 1;
        while (table[index] != -1) {
            index = (index + i * i) % TABLE_SIZE;
            i++;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "Empty" << endl;
        }
    }
};

int main() {
    HashTable ht;
    int mangoes[] = {25, 15, 10, 5, 11, 19, 16, 36, 42, 28, 32};
    for (int key : mangoes) {
        ht.insert(key);
    }
    ht.display();
    return 0;
}
