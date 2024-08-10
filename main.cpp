#include <iostream>
#include "YourSet.h"

int main() {

    // Create a new set
    YourSet set;

    // Add some values to the set
    set.add("banana");
    set.add("apple");
    set.add("orange");

    // Check if the set contains some values
    std::cout << "Does set contain 'banana' ? " << (set.contains("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'apple' ? " << (set.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'orange' ? " << (set.contains("orange") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'watermelon' ? " << (set.contains("watermelon") ? "Yes" : "No") << std::endl;


    return 0;
}