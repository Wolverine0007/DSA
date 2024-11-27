const int TABLE_SIZE = 6;
 
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
       while (table[index] != -1) {
           index = (index + 1) % TABLE_SIZE;
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
   int n, key;
   cout << "Enter number of flavors to insert: ";
   cin >> n;
   for (int i = 0; i < n; i++) {
       cout << "Enter flavor key: ";
       cin >> key;
       ht.insert(key);
   }
   ht.display();
   return 0;
}