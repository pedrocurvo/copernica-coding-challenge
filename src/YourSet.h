#ifndef YOUR_SET_H
#define YOUR_SET_H

#include <iostream>

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
    

    public:
        // Constructors and Destructors
        YourSet();
        ~YourSet();
};


#endif // YOUR_SET_H