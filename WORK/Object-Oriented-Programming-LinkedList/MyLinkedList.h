// MyLinkedList.h

#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include <string>

class ListNode {
public:
    std::string data;
    ListNode* next;

    ListNode(const std::string& value);
};

class MyLinkedList {
private:
    ListNode* head;

public:
    MyLinkedList();

    MyLinkedList(const MyLinkedList& other);

    MyLinkedList& operator=(const MyLinkedList& other);

    void insertItem(const std::string& value);

    void removeAll();

    void printList();

    ~MyLinkedList();
};

#endif // MY_LINKED_LIST_H
