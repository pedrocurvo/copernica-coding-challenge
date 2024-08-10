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


/// @brief Private function to deeply clone the BST.
/// @param node The node to start the cloning.
/// @return A pointer to the new node.
std::unique_ptr<YourSet::Node> YourSet::clone(const std::unique_ptr<Node>& node) const {
    if (node == nullptr) {
        return nullptr;
    }

    std::unique_ptr<Node> newNode = std::make_unique<Node>(node->data);
    newNode->left = clone(node->left);
    newNode->right = clone(node->right);

    return newNode;
}


/// @brief Copy constructor of the "YourSet" class.
/// @param other The "YourSet" to copy.
YourSet::YourSet(const YourSet& other) : root(clone(other.root)), node_size(other.node_size) {}


/// @brief Copy assignment operator of the "YourSet" class.
/// @param other The "YourSet" to copy.
/// @return A reference to the "YourSet".
YourSet& YourSet::operator=(const YourSet& other) {
    if (this != &other) {
        clear(); // Just to make sure that the tree starts from scratch
        root = clone(other.root);
        node_size = other.node_size;
    }
    return *this;
}


/// @brief Iterator constructor of the "YourSet" class.
/// @param root The root of the BST.
YourSet::Iterator::Iterator(Node* root) : current(root) {
    while (current != nullptr) {
        stack.push(current);
        current = current->left.get();
    }
}


/// @brief Iterator dereference operator of the "YourSet" class.
/// @return The value of the current node.
std::string YourSet::Iterator::operator*() {
    // So I need to get the current node that is the top of the stack
    // and returns its data, which is a string.
    return stack.top()->data;
}


/// @brief Iterator increment operator of the "YourSet" class.
/// @return A reference to the iterator.
YourSet::Iterator& YourSet::Iterator::operator++() {
    current = stack.top();
    stack.pop();
    if (current->right != nullptr) {
        current = current->right.get();
        while (current != nullptr) {
            stack.push(current);
            current = current->left.get();
        }
    }
    return *this;
}


/// @brief Iterator inequality operator of the "YourSet" class.
/// @param other The other iterator to compare.
/// @return A boolean indicating if the iterators are different.
bool YourSet::Iterator::operator!=(const Iterator& other) {
    return stack.size() != other.stack.size();
}


/// @brief Public function to get the begin iterator of the "YourSet".
/// @return An iterator to the first element of the "YourSet".
YourSet::Iterator YourSet::begin() {
    // Just need to get the iterator with the root of the BST.
    return Iterator(root.get());
}


/// @brief Public function to get the end iterator of the "YourSet".
/// @return An iterator to the last element of the "YourSet".
YourSet::Iterator YourSet::end() {
    // Just need to get the iterator with a nullptr.
    return Iterator(nullptr);
}


