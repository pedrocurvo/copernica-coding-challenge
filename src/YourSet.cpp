#include "YourSet.h"


/// @brief Private function to evaluate if the BST contains the value. 
/// @param node The node to start the search.
/// @param value The value to search for.
/// @return A boolean indicating if the value is in the BST.
bool YourSet::contains(const Node* node, const std::string& value) const {
    if (node == nullptr) {
        return false;
    }

    if (node->data == value) {
        return true;
    }

    if (value < node->data) { // < in strings? Yes, it compares the strings alphabetically
        return contains(node->left.get(), value);
    } else {
        return contains(node->right.get(), value);
    }
}


/// @brief Public function to evaluate if the "YourSet" contains the value.
/// @param value The value to search for.
/// @return A boolean indicating if the value is in the "YourSet".
bool YourSet::contains(const std::string& value) const {
    // Dont need to pass the root, since the private function will start the search from the root.
    return contains(root.get(), value);
}