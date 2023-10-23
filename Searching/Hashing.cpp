#include <iostream>
#include <unordered_map>

int main() {
    // Create an unordered_map for storing key-value pairs (hash table)
    std::unordered_map<std::string, int> myMap;

    // Insert key-value pairs into the hash table
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 22;
    myMap["David"] = 18;

    // Access values using keys
    std::cout << "Age of Alice: " << myMap["Alice"] << std::endl;
    std::cout << "Age of Bob: " << myMap["Bob"] << std::endl;

    // Check if a key exists in the hash table
    if (myMap.find("Eve") == myMap.end()) {
        std::cout << "Eve is not in the map." << std::endl;
    } else {
        std::cout << "Age of Eve: " << myMap["Eve"] << std::endl;
    }

    // Iterate over the key-value pairs in the hash table
    for (const auto& pair : myMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    return 0;
}
