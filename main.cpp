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

    // Try copy constructor
    YourSet set_to_copy{"apple", "banana", "orange"};
    YourSet copied_set(set_to_copy);
    std::cout << "Does copied set contain 'apple' ? " << (copied_set.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Does copied set contain 'banana' ? " << (copied_set.contains("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Does copied set contain 'orange' ? " << (copied_set.contains("orange") ? "Yes" : "No") << std::endl;

    // Check the size of the copied set
    std::cout << "Size of the copied set : " << copied_set.size() << std::endl;

    // Remove some values from the copied set and check if the original set is still the same
    std::cout << "Removing 'apple' from the copied set" << std::endl;
    copied_set.remove("apple");
    std::cout << "Does copied set contain 'apple' ? " << (copied_set.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'apple' ? " << (set_to_copy.contains("apple") ? "Yes" : "No") << std::endl;

    // Remove some values from the original set and check if the copied set is still the same
    std::cout << "Removing 'banana' from the original set" << std::endl;
    set_to_copy.remove("banana");
    std::cout << "Does set contain 'banana' ? " << (set_to_copy.contains("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Does copied set contain 'banana' ? " << (copied_set.contains("banana") ? "Yes" : "No") << std::endl;

    // Try copy assignment operator
    YourSet set_to_assign{"apple", "banana", "orange"};
    YourSet assigned_set;
    assigned_set = set_to_assign;
    std::cout << "Does assigned set contain 'apple' ? " << (assigned_set.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Does assigned set contain 'banana' ? " << (assigned_set.contains("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Does assigned set contain 'orange' ? " << (assigned_set.contains("orange") ? "Yes" : "No") << std::endl;

    // Check the size of the assigned set
    std::cout << "Size of the assigned set : " << assigned_set.size() << std::endl;

    // Remove some values from the assigned set and check if the original set is still the same
    std::cout << "Removing 'apple' from the assigned set" << std::endl;
    assigned_set.remove("apple");
    std::cout << "Does assigned set contain 'apple' ? " << (assigned_set.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Does set contain 'apple' ? " << (set_to_assign.contains("apple") ? "Yes" : "No") << std::endl;



    return 0;
}