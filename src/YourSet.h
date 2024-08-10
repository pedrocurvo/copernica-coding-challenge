#ifndef YOUR_SET_H
#define YOUR_SET_H

#include <iostream>
#include <initializer_list>
#include <stack>

class YourSet
{
    private:
        // Firstly, my first taught was to use a Hash Table for the internal acrhitecture
        // of the set, due to O(1) time complexity for insertion, deletion and search operations.
        // However, when the data starts to grow, the hash table performance will start to degrade.
        // And the complexity could start to be O(n) due to the hash collisions and resizing.
        // Hence, and after some research, I have checked the internal architecture of the std::set
        // and they use a BST to tackle this proble. Which makes sense, since if the BST is 
        // balanced, the time complexity for insertion, deletion and search operations is
        // remains O(log n). Hence, I have decided to implement my own BST for the internal
        // architecture of the set.
        struct Node
        {
            std::string data;
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;

            // Node Constructor to inject the data (string) into the node
            // and initialize the left and right pointers to nullptr
            Node(const std::string& data) : data(data), left(nullptr), right(nullptr) {}
        };

        // This will be the root of the BST, used a unique_ptr to avoid memory leaks or maybe when copying the set
        // two pointers pointing to the same node, which could lead to wrongly deleting the node.
        std::unique_ptr<Node> root;

        // I will need a size variable to keep track of the number of elements in the set
        size_t node_size;

        // I will need some "helpers" to interact with the Tree but dont want to expose them to the user
        // hence, I will make them private, starting with contain method that needs to be used recursively
        // and inside add and remove methods.
        bool contains(const Node* node, const std::string& data) const;
        std::unique_ptr<Node> add(std::unique_ptr<Node> node, const std::string& value);
        std::unique_ptr<Node> remove(std::unique_ptr<Node> node, const std::string& value);

        // Helper function to deeply "clone" the tree, used in the copy constructor
        std::unique_ptr<Node> clone(const std::unique_ptr<Node>& node) const;
    

    public:
        // Constructors and Destructors
        YourSet();
        YourSet(std::initializer_list<std::string> init_list);
        ~YourSet();

        // Copy Constructor
        YourSet(const YourSet& other);

        // Copy Assignment Operator
        YourSet& operator=(const YourSet& other);

        // Some methods to interact with the set
        bool add(const std::string& data);
        bool remove(const std::string& data);
        bool contains(const std::string& data) const;

        // Methods for size 
        size_t size() const;
        bool isEmtpy() const;

        // Method to clear and use in the destructor
        void clear();

        // Iterator to iterate over the set
        // I am using a BST so I can use a in order to iterate over the set and get it sorted
        // The tree is already arranged in a way that is "sorted". I used a stack to keep track of the nodes
        // that I have visited and the current node that I am visiting.
        class Iterator
        {
            private:
                Node* current;
                std::stack<Node*> stack;

            public:
                Iterator(Node* root);
                std::string operator*(); // This is needed to get the value of the current node,e.g, printing the value
                Iterator& operator++(); // This is needed to move to the next element (node) in the set (BST)
                bool operator!=(const Iterator& other); // This is needed to check if the iterator is at the end of the set
        };

        Iterator begin() const;
        Iterator end() const;


        // Algebraic Operations with set (Union, Intersection, Difference, IsSubset)
        YourSet union_with(const YourSet& other) const;
        YourSet intersection_with(const YourSet& other) const;
        YourSet difference_with(const YourSet& other) const;
        bool is_subset_of(const YourSet& other) const;

        // I want to be able to print the set, so I will overload the << operator
        friend std::ostream& operator<<(std::ostream& os, const YourSet& set);

        // Comparison operators
        bool operator==(const YourSet& other) const;
        bool operator!=(const YourSet& other) const;


};


#endif // YOUR_SET_H