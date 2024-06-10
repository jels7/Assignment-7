#include <iostream>
#include <vector>

// Define the size of the hashtable
const int TABLE_SIZE = 10;

// Define the structure for each hashtable entry
struct HashEntry {
    int key;
    int value;
};

// Define the hashtable class
class HashTable {
private:
    std::vector<HashEntry> table;  // Vector to store the hashtable entries

public:
    HashTable() {
        // Initialize the hashtable with empty entries
        table.resize(TABLE_SIZE);
    }

    // Hash function to determine the index for a given key
    int hashFunction(int key) {
        return key % TABLE_SIZE;  // Use the modulo operator to get the index
    }

    // Insert a value into the hashtable
    void insert(int key, int value) {  
        int index = hashFunction(key); // Get the index for the key
        table[index].key = key;  // Insert the key
        table[index].value = value;  // Insert the value
    }

    // Check if a value is already in the hashtable
    bool contains(int key) {
        int index = hashFunction(key); 
        return (table[index].key == key && table[index].value != 0);  // Check if the key is in the hashtable and the value is not 0
    }
};

int main() {
    // Create a hashtable object
    HashTable hashtable;

    // Insert values into the hashtable
    hashtable.insert(1, 100);
    hashtable.insert(2, 200);
    hashtable.insert(11, 1100);

    // Check if a value is in the hashtable
    std::cout << "Contains key 11: " << (hashtable.contains(11) ? "true" : "false") << std::endl;  // Should return true
    std::cout << "Contains key 3: " << (hashtable.contains(3) ? "true" : "false") << std::endl;  // Should return false

    return 0;
}