#include "MyLinkedList.h"
#include <iostream>

int main() {
    MyLinkedList originalList;
    originalList.insertItem("OOPS");
    originalList.insertItem("IS");
    originalList.insertItem("AWESOME");

    MyLinkedList copiedList(originalList);

    std::cout << "Original Linked List: ";
    originalList.printList();
    std::cout << "List which has been copied from the Original Linked List: ";
    copiedList.printList();

    originalList.insertItem("AND ALSO AMAZING");

    std::cout << "Original Linked List after adding item: ";
    originalList.printList();
    std::cout << "Copied List after adding an item from the original linked list: ";
    copiedList.printList();

    MyLinkedList assignedList;
    assignedList = originalList;

    std::cout << "Original Linked List after Specific assignment of the Linked list: ";
    originalList.printList();
    std::cout << "The Assigned Linked List final: ";
    assignedList.printList();

    return 0;
}
