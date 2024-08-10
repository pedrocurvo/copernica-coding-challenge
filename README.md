# Copernica Coding Challenge - Custom Set

## My approach
My first taught was to implement a set using a hash table, due to the O(1) time complexity for insertions, deletions and
searches. However, when the data (strings) start to grow in number, the hash table would have a lot of collisions, 
which would make the time complexity O(n) for all operations. Besides that, when iterating over the set, the order of the
elements would not be guaranteed, the hash table would not be a good choice for sorting. 
I looked for the internal on the std::set and they use kinda a binary seearch tree, balanced, to store the elements.
At it makes sense, because the time complexity for insertions, deletions and searches is average O(log n),
so it wont degraded so fast, we can count on a steady complexity and the order of the elements is guaranteed.
My implementation is based on a binary search tree, not with the balancing feature, to keep it simple and straight forward.
For this, I created a structure Node, which has a left and right pointers, and a value. With this structure, I can create
the BST. 
Because of this architecture, I needed private functions to deal directly with the BST and the public functions to deal 
with the set operations. I dont want the user to have access to the BST. Basically, the public functions are wrappers for
the private functions. 
For the constructors, I created a empty constructor, a constructor that receives a initializer list and a copy constructor.
The destructor is implemented to deallocate the memory used by the BST, I used unique_ptr, so I just need to delete the
root node and the BST will be deallocated. The choice for the unique_ptr was to avoid memory leaks and to avoid
deallocation of the BST by mistake in some steps. 
Then I added the add, remove, contains methods. The add and remove make use of the contain method because I dont want to
add the same element twice or remove an element that is not in the set.
I also added the size method, which returns the number of elements in the set, just need to add a variable to keep 
track of the number of elements, that is, the number of nodes in the BST.
The clear method is used by the destructor and is also used in some copy operations.
The isEmpy method is used to check if the set is empty or not and just check if the number of elements is zero.
Then I added an iterator that allows to iterator with auto over the elements of the set or with a range-based for loop.
For this, I created the Iterator class inside the YourSet class, with the begin and end methods, that return the first and
last elements of the set, respectively. The Iterator class has the overloaded operators ++, --, *, == and !=, to allow the
iterator to move through the elements of the set and to compare iterators.
I also taught that would be useful to add some algebraic opeartions to the set, like union, intersection, difference and 
is_subset. This would be interesting, otherwise sets would be just a list of elements, with no special operations.
The union, intersection and difference just make use of the iterators to iterate over the elements of the sets and add the
elements to the new set, if they are not already there or are depending on the operation. The is_subset method just check
if all elements of the set are in the other set, using the contains method and the iterator.
I also wanted to print the set directly in a way like {'banana', 'watermelon', 'apple'},
so I overloaded the << operator to print the set in that way, instead of only being able to print the using the iterator.
I also added the comparison operators == and !=, to compare two sets and check if they are equal or not, can be useful in 
some situations. 

## File structure
- YourSet.h: Header file with the class definition
- YourSet.cpp: Implementation file with the class implementation
- main.cpp: Main file with the tests

```
├── src/
│   ├── YourSet.cpp     # Implementation of the YourSet class or functions
│   ├── YourSet.h       # Header file for the YourSet class or functions
├── main.cpp            # File with some tests for the YourSet class (some prints to check the results, not a real test) 
└── README.md           # Project documentation
```

## How to run
To run the tests, just compile the main.cpp file with the YourSet.cpp file. You can use the following command:
```
g++ -std=c++11 main.cpp YourSet.cpp -o main
```
And then run the executable:
```
./main
```



