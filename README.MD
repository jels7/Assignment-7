Describe the way that you decide on hashing a value:

    
int hashFunction(int key) {
    return key % TABLE_SIZE;
}



An insert function that places the value at the appropriate location based on its hash value:


    
void insert(int key, int value) {  
    int index = hashFunction(key); 
    table[index].key = key; 
    table[index].value = value; 
}
 

A contains function that returns whether the value is already in the hashtable:



bool contains(int key) {
    int index = hashFunction(key); 
    return (table[index].key == key); 
}
