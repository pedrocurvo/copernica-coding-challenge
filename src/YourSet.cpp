#include "YourSet.h"

/// @brief Empty onstructor of the "YourSet" class.
YourSet::YourSet() : root(nullptr), node_size(0) {}

/// @brief Constructor of the "YourSet" class.
/// @param init_list The list of strings to initialize the "YourSet".
YourSet::YourSet(std::initializer_list<std::string> init_list) : root(nullptr), node_size(0) {
    for (const std::string& value : init_list) {
        add(value);
    }
}

/// @brief Destructor of the "YourSet" class.
YourSet::~YourSet() {
    clear();
}


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


/// @brief Private function to add a value to the BST.
/// @param node The node to start the insertion.
/// @param value The value to insert.
/// @return A pointer to the new node.
std::unique_ptr<YourSet::Node> YourSet::add(std::unique_ptr<Node> node, const std::string& value) {
    if (node == nullptr) {
        return std::make_unique<Node>(value);
    }

    if (value < node->data) {
        node->left = add(std::move(node->left), value);
    } else if (value > node->data) {
        node->right = add(std::move(node->right), value);
    }

    return node;
}


/// @brief Public function to add a value to the "YourSet".
/// @param value The value to insert.
/// @return A boolean indicating if the value was inserted.
bool YourSet::add(const std::string& value) {
    if (contains(value)) {
        return false;
    }
    // Need to move the root, since the add function will modify the tree.
    root = add(std::move(root), value);
    node_size++;
    return true;
}


/// @brief Private function to remove a value from the BST.
/// @param node The node to start the removal.
/// @param value The value to remove.
/// @return A pointer to the new node.
std::unique_ptr<YourSet::Node> YourSet::remove(std::unique_ptr<Node> node, const std::string& value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(std::move(node->left), value);
    } else if (value > node->data) {
        node->right = remove(std::move(node->right), value);
    } else {
        if (node->left == nullptr) {
            return std::move(node->right);
        } else if (node->right == nullptr) {
            return std::move(node->left);
        } else {
            Node* minNode = node->right.get();
            while (minNode->left != nullptr) {
                minNode = minNode->left.get();
            }
            node->data = minNode->data;
            node->right = remove(std::move(node->right), minNode->data);
        }
    }

    return node;
}


/// @brief Public function to remove a value from the "YourSet".
/// @param value The value to remove.
/// @return A boolean indicating if the value was removed.
bool YourSet::remove(const std::string& value) {
    if (!contains(value)) {
        return false;
    }
    // Need to move the root, since the remove function will modify the tree.
    root = remove(std::move(root), value);
    node_size--;
    return true;
}


/// @brief Public function to get the size of the "YourSet".
/// @return The number of elements in the "YourSet".
size_t YourSet::size() const {
    return node_size;
}


/// @brief Public function to check if the "YourSet" is empty.
/// @return A boolean indicating if the "YourSet" is empty.
bool YourSet::isEmtpy() const {
    return node_size == 0;
}


/// @brief Public function to clear the "YourSet".
void YourSet::clear() {
    root.reset();
    node_size = 0;
}