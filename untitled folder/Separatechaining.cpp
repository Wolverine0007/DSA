#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 20;

class HashTable {
private:
    list<int> table[TABLE_SIZE];

public:
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            for (int x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int data[] = {33, 56, 78, 12, 10, 67, 89, 99, 100, 23, 45, 71, 39, 62, 59, 90, 91, 20, 75, 66};
    for (int key : data) {
        ht.insert(key);
    }
    ht.display();
    return 0;
}
