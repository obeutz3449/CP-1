//
// Created by Oliver on 2/24/2026.
//

#ifndef CP_1_LINKEDLIST_H
#define CP_1_LINKEDLIST_H
#include <iostream>

template<typename T> class Node {
    T data;
    Node<T> *next;
    public:
        Node(T data) : data(data), next(nullptr) {}
        void setNext(Node<T> *n) {
            next = n;
        }
        Node<T> *getNext() {
            return next;
        }
        T getData() {
            return data;
        }
        void setData(const T d) {
            data = d;
        }
};

template<typename T> class CircularlyLinkedList {
    Node<T> *head;
    public:
        int length;
        CircularlyLinkedList() : head(nullptr), length(0) {}
        bool insert(const T data, const int index) {
            if (length >= 40) return false;
            if (length == 0) {
                head = new Node<T>(data);
                head->setNext(head);
                length++;
                return true;
            }
            if (index == 0) {
                Node<T> *last = head;
                while (last->getNext() != head) {
                    last = last->getNext();
                }
                Node<T> *temp = head;
                head = new Node<T>(data);
                head->setNext(temp);
                last->setNext(head);
                length++;
                return true;
            }
            Node<T> *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->getNext();
            }
            Node<T> *ins = new Node<T>(data);
            ins->setNext(current->getNext());
            current->setNext(ins);
            length++;
            return true;
        }

        bool remove(const T data) {
            if (head == nullptr) return false;
            if (head->getData() == data) {
                if (length == 1) {
                    delete head;
                    head = nullptr;
                    length = 0;
                    return true;
                }
                Node<T> *last = head;
                while (last != head) {
                    last = last->getNext();
                }
                last->setNext(head->getNext());
                delete head;
                head = last->getNext();
                length--;
                return true;
            }
            Node<T> *current = head;
            while (current->getNext()->getData() != data) {
                current = current->getNext();
                if (current->getNext() == head) return false;
            }
            Node<T> *temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            length--;
            return true;
        }

        void printList() {
            std::cout << length << std::endl;
            Node<T> *current = head;
            for (int i = 0; i < length; i++) {
                std::cout << current->getData() << " ";
                current = current->getNext();
            }
        }
};


#endif //CP_1_LINKEDLIST_H