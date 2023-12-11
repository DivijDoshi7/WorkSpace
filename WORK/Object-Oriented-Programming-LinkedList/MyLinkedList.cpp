// MyLinkedList.cpp

#include "MyLinkedList.h"
#include <iostream>

ListNode::ListNode(const std::string& value) : data(value), next(nullptr) {}

MyLinkedList::MyLinkedList() : head(nullptr) {}

MyLinkedList::MyLinkedList(const MyLinkedList& other) {
    head = nullptr;
    ListNode* current = other.head;
    while (current != nullptr) {
        insertItem(current->data);
        current = current->next;
    }
}

MyLinkedList& MyLinkedList::operator=(const MyLinkedList& other) {
    if (this == &other) {
        return *this;
    }

    removeAll();

    ListNode* current = other.head;
    while (current != nullptr) {
        insertItem(current->data);
        current = current->next;
    }

    return *this;
}

void MyLinkedList::insertItem(const std::string& value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void MyLinkedList::removeAll() {
    for (ListNode* current = head; current != nullptr;) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void MyLinkedList::printList() {
    for (ListNode* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;
}

MyLinkedList::~MyLinkedList() {
    removeAll();
}
