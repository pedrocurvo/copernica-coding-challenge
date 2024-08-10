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

    // Check the size of the set
    std::cout << "Size of the set : " << set.size() << std::endl;

    // Remove some values from the set
    std::cout << "Removing 'banana' from the set" << std::endl;
    set.remove("banana");
    std::cout << "Does set contain 'banana' ? " << (set.contains("banana") ? "Yes" : "No") << std::endl;

    // Check the size of the set
    std::cout << "Size of the set : " << set.size() << std::endl;

    // Try to remove a value that is not in the set
    std::cout << "Removing 'banana' from the set : " << (set.remove("banana") ? "Yes" : "No") << std::endl;

    // Check the size of the set
    std::cout << "Size of the set : " << set.size() << std::endl;

    // Try to add a value that is already in the set
    std::cout << "Adding 'apple' to the set : " << (set.add("apple") ? "Yes" : "No") << std::endl;

    // Create a new set with an initializer list
    YourSet second_set{"raspberry", "strawberry", "blueberry"};

    // Check if the second set contains some values
    std::cout << "Does second set contain 'raspberry' ? " << (second_set.contains("raspberry") ? "Yes" : "No") << std::endl;
    std::cout << "Does second set contain 'strawberry' ? " << (second_set.contains("strawberry") ? "Yes" : "No") << std::endl;
    std::cout << "Does second set contain 'blueberry' ? " << (second_set.contains("blueberry") ? "Yes" : "No") << std::endl;

    // Check the size of the second set
    std::cout << "Size of the second set : " << second_set.size() << std::endl;

    // Try check sizes with empty sets
    YourSet empty_set;
    std::cout << "Size of the empty set : " << empty_set.size() << std::endl;
    YourSet another_empty_set{};
    std::cout << "Size of the another empty set : " << another_empty_set.size() << std::endl;



    return 0;
}