#include <iostream>
#include "BST.hpp" // Include the header file for the BST class
#include "timer.hpp"

void test1();

int main()
{
    MyTimer::start();
    test1();
    MyTimer::end();
    return 0;
}

void test1()
{
    // Create an instance of BST with int keys and string elements
    BST<int, std::string> bst;

    // Insert some key-value pairs into the BST
    bst.insert(5, "apple");
    bst.insert(3, "banana");
    bst.insert(7, "orange");
    bst.insert(2, "grape");
    bst.insert(4, "cherry");
    bst.insert(6, "pear");
    bst.insert(8, "kiwi");

    // Print the contents of the BST
    std::cout << "BST contents:" << std::endl;
    bst.print();

    // Find and print the element for a specific key
    int keyToFind = 4;
    std::cout << "Element for key " << keyToFind << ": " << bst.find(keyToFind) << std::endl;

    // Remove a specific key from the BST
    int keyToRemove = 3;
    std::cout << "Removing key " << keyToRemove << ": " << bst.remove(keyToRemove) << std::endl;

    // Print the contents of the BST after removal
    std::cout << "BST contents after removal:" << std::endl;
    bst.print();

    // Get the size of the BST
    std::cout << "Size of BST: " << bst.size() << std::endl;

    // Clear the BST
    bst.clear();

    // Print the contents of the BST after clearing
    std::cout << "BST contents after clearing:" << std::endl;
    bst.print();
}
