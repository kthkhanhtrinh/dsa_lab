void put(int key, int value) {
    //TODO: Compute the index using the hash function
    size_t index = hashFunction(key, capacity);

    //TODO: Check if the key exists in the linked list at the index, update if found
    Entry* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            // Key found, update the value
            current->value = value;
            return; // Exit the method
        }
        current = current->next; // Move to the next entry
    }
    //TODO: If the key doesn't exist, create and insert a new entry
    Entry* newEntry = new Entry(key, value);
    newEntry->next = table[index]; // Insert at the head of the linked list
    table[index] = newEntry; // Update the head of the list

    count++;
    //TODO: Increment the count and ensure load factor by resizing if needed
    ensureLoadFactor(count);

}

void ensureLoadFactor(int current_size) {
    //TODO: Calculate the maximum allowed size based on the load factor (0.75 * capacity)
    size_t maxAllowedSize = (capacity * 0.75);

    //TODO: If the current size exceeds or equals the max allowed size, trigger rehashing

    //TODO: Calculate the new capacity (1.5 times the old capacity)
    if (current_size >= maxAllowedSize) {
        size_t newCapacity = (capacity * 1.5);
        rehash(newCapacity);
    }
    //TODO: Call the rehash function with the new capacity
}


void rehash(int newCapacity) {
        Entry** oldTable = table; 
        size_t oldCapacity = capacity;

        capacity = newCapacity;

        table = new Entry*[capacity]; 
        for (size_t i = 0; i < capacity; ++i) {
            table[i] = nullptr; 
        }

        for (size_t i = 0; i < oldCapacity; ++i) {
            Entry* entry = oldTable[i]; 
            while (entry != nullptr) {
                size_t newIndex = hashFunction(entry->key, capacity);

                Entry* newEntry = new Entry(entry->key, entry->value); 
                newEntry->next = table[newIndex]; 
                table[newIndex] = newEntry; 

                Entry* temp = entry; 
                entry = entry->next; 
                delete temp; 
            }
        }

        // Step 7: Delete the old table array
        delete[] oldTable; // Free the memory allocated for the old table
    }
//////////////
V& get(K key) {
    size_t index = hashFunction(key, capacity); // Correctly calculate the index using hashFunction
    Entry* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value; // Return the value if the key matches
        }
        current = current->next; // Move to the next entry
    }
    throw std::out_of_range("Key not found"); // Key not found
}

/////////////////
V remove(int key) {
        size_t index = hashFunction(key, capacity);
        Entry* current = table[index];
        Entry* previous = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                // Key found; remove the entry
                V value = current->value; // Store the value to return
                if (previous) {
                    previous->next = current->next; // Bypass the current entry
                } else {
                    table[index] = current->next; // Move head
                }
                delete current; // Free memory
                return value; // Return the removed value
            }
            previous = current;
            current = current->next; // Move to the next entry
        }
    // return V();
        // If we reach here, the key was not found
        // std::cout << "Key not found" << std::endl;
        throw std::out_of_range("Key not found");
}
/////////////////
long int midSquare(long int seed) {
    // Square the seed
    seed = pow(seed, 2);
    
    // Remove the outer two digits by dividing by 100
    seed /= 100;
    
    // Return the middle four digits using modulo
    return seed % 10000;
}

long int moduloDivision(long int seed, long int mod) {
    return seed % mod;
}

long int digitExtraction(long int seed, int* extractDigits, int size) {
    string str_seed = to_string(seed);
    string str_result = "";

    for (int i = 0; i < size; i++) {
        if (extractDigits[i] < (int)str_seed.length()) {
            str_result += str_seed.substr(extractDigits[i], 1);
        }
    }

    return stoll(str_result);
}
////////////////////////
int foldShift(long long key, int addressSize) {
    long long b = 1;
    
    // Calculate the highest power of 10 less than or equal to `key`
    while ((key / b) != 0) {
        b *= 10;
    }
    
    int fold = 0;

    // Process each segment of the key
    while (key != 0) {
        for (int i = 0; i < addressSize; i++) {
            b /= 10;
            if (b == 1)
                break;
        }
        
        int split = key / b;
        key -= split * b;
        fold += split;
    }

    // Calculate 10^addressSize for modular reduction
    int c = 1;
    for (int i = 0; i < addressSize; i++) {
        c *= 10;
    }

    return fold % c;
}


int rotation(long long key, int addressSize) {
    long long b = 1;
    
    // Find the largest power of 10 less than `key`
    while (key / b != 0) {
        b *= 10;
    }
    b /= 10;  // Adjust `b` to be just below the `key`'s length in digits
    
    int lastDigit = key % 10;
    key /= 10;
    key = lastDigit * b + key;  // Rotate by moving the last digit to the front

    return foldShift(key, addressSize);
}

///////////////////

#include <vector>
#include <algorithm>

int pairMatching(std::vector<int>& nums, int target) {
    int res = 0;
    
    std::sort(nums.begin(), nums.end());
    
    int start = 0;
    int end = nums.size() - 1;
    
    while (start < end) {
        int sum = nums[start] + nums[end];
        
        if (sum > target) {
            end--;
        } else if (sum < target) {
            start++;
        } else {
            res++;
            start++;
            end--;
        }
    }
    
    return res;
}
