# Copernica Coding Challenge - Custom Set

## Index
- [Copernica Coding Challenge - Custom Set](#copernica-coding-challenge---custom-set)
  - [Index](#index)
  - [My approach](#my-approach)
  - [File structure](#file-structure)
  - [How to run](#how-to-run)

## My approach

Initially, my first thought was to implement a set using a hash table due to its O(1) time complexity for insertions, deletions, and searches. However, as the number of data elements (strings) grows, hash tables often experience an increase in collisions. This could degrade the time complexity to O(n) for all operations. Moreover, a hash table does not maintain the order of elements, making it unsuitable for situations where ordered iteration or sorting is required.

I looked up the internal on the std::set and found that it uses a balanced binary search tree (BST) to store elements.
This approach makes sense, as it ensures a time complexity of O(log n) for insertions, deletions, and searches on average,
so it won't be degraded so fast, we can count on a steady complexity and the order of the elements is guaranteed.

My implementation is based on a binary search tree, not with the balancing feature, to keep it simple and straightforward.
For this, I created a structure Node with a left and right pointer and a value. With this structure, I can create
the BST. 

Due to this architecture, I implemented private functions that interact directly with the BST and public functions that provide set operations. I encapsulated the BST within the private scope to prevent users from accessing it directly and messing it up. Essentially, the public functions serve as wrappers around these private functions.


For the constructors, I created an empty constructor, a constructor that receives an initializer list, and a copy constructor.

The destructor is implemented to deallocate the memory used by the BST, I used unique_ptr, so I just need to delete the
root node and the BST will be deallocated. The choice for the unique_ptr was to avoid memory leaks and to avoid
deallocation of the BST by mistake in some steps. 

Then I added the add, remove, and contains methods. The add and remove make use of the contain method because I don’t want to
add the same element twice or remove an element that is not in the set.

I also added the size method, which returns the number of elements in the set, just need to add a variable to keep 
track of the number of elements, that is, the number of nodes in the BST.

The clear method is used by the destructor and is also used in some copy operations.

The isEmpty method is used to check if the set is empty or not and just check if the number of elements is zero.

Then I added an iterator that allows to iterator auto over the elements of the set or with a range-based for loop.

For this, I created the Iterator class inside the YourSet class, with the begin and end methods, that return the first and
last elements of the set, respectively. The Iterator class has the overloaded operators ++, --, *, ==, and !=, to allow the
iterator to move through the set’s elements and compare iterators.

I also thought that would be useful to add some algebraic opeartions to the set, like union, intersection, difference and 
is_subset. This would be interesting, otherwise sets would be just a list of elements, with no special operations.
The union, intersection, and difference just make use of the iterators to iterate over the elements of the sets and add the
elements to the new set, if they are not already there or are depending on the operation. The is_subset method just checks
if all elements of the set are in the other set, using the contains method and the iterator.

I also wanted to print the set directly in a way like {'banana', 'watermelon', 'apple'},
so I overloaded the << operator to print the set in that way, instead of only being able to print the using the iterator.

I also added the comparison operators == and !=, to compare two sets and check if they are equal or not, which can be useful in 
some situations. 

## File structure
- YourSet.h: Header file with the class definition
- YourSet.cpp: Implementation file with the class implementation
- main.cpp: Main file with the tests
- main_copernica.cpp: Main file with the tests provided by Copernica

```
├── src/
│   ├── YourSet.cpp     # Implementation of the YourSet class or functions
│   ├── YourSet.h       # Header file for the YourSet class or functions
├── main.cpp            # File with some tests for the YourSet class (some prints to check the results, not a real test) 
├── main_copernica.cpp  # File with the tests provided by Copernica
└── README.md           # Project documentation
```

## How to run
To run the tests, just compile the main.cpp file with the YourSet.cpp file. You can use the following command:
```
g++ -std=c++17 -Wall -I src/ src/YourSet.cpp main.cpp -o main
```
And then run the executable:
```
./main
```

For the ```main_copernica.cpp``` replace the ```main.cpp``` in the command above.

You can also use the Makefile to compile the files, for that you need to have a ```bin``` folder in the root directory, then you can use the following command:
```
make bin/yourfile.exe
```
And then run the executable:
```
./bin/yourfile.exe
```





