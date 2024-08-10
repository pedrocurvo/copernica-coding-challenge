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
    std::cout << "Adding 'banana', 'apple' and 'orange' to the set" << std::endl;
    std::cout << "Does set contain 'banana' ? " << (set.contains("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'apple' ? " << (set.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'orange' ? " << (set.contains("orange") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'watermelon' ? " << (set.contains("watermelon") ? "Yes" : "No") << std::endl;

    // Remove some values from the set
    std::cout << "Removing 'banana' from the set" << std::endl;
    set.remove("banana");
    std::cout << "Does set contain 'banana' ? " << (set.contains("banana") ? "Yes" : "No") << std::endl;

    // Try to remove a value that is not in the set
    std::cout << "Removing 'banana' from the set : " << (set.remove("banana") ? "Yes" : "No") << std::endl;

    // Try to add a value that is already in the set
    std::cout << "Adding 'apple' to the set : " << (set.add("apple") ? "Yes" : "No") << std::endl;

    // Create a new set with an initializer list
    YourSet second_set{"raspberry", "strawberry", "blueberry"};

    // Check if the second set contains some values
    std::cout << "Does second set contain 'raspberry' ? " << (second_set.contains("raspberry") ? "Yes" : "No") << std::endl;
    std::cout << "Does second set contain 'strawberry' ? " << (second_set.contains("strawberry") ? "Yes" : "No") << std::endl;
    std::cout << "Does second set contain 'blueberry' ? " << (second_set.contains("blueberry") ? "Yes" : "No") << std::endl;



    return 0;
}