//
// Created by Oliver on 2/24/2026.
//

#ifndef CP_1_LINKEDLIST_H
#define CP_1_LINKEDLIST_H

template<typename T> class Node {
    T data;
    Node<T> *next;
    public:
        Node(T data) {
            this->data = data;
        }
        void setNext(Node<T> *n) {
            next = n;
        }
        T getData() {
            return data;
        }
        void setData(T data) {
            this->data = data;
        }
        ~Node() {
            delete next;
            delete data;
        }
};

template<typename T> class circularlyLinkedList {
    Node<T> *head;
    public:
    int length;
    circularlyLinkedList() {
        length = 0;
    }
    bool insert(T data, int index) {
        if (length >= 40) return false;
        if (length == 0) {
            head = new Node<T>(data);
            head->setNext(head);
            return true;
        }
        if (index == 0) {
            Node<T> *last = head;
            while (last->next != head) {
                last = last->next;
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
            current = current->next;
        }
        Node<T> *ins = new Node<T>(data);
        ins->setNext(current->getNext());
        current->setNext(ins);
        length++;
        return true;
    }

    bool remove(T data) {
        if (head->getData() == data) {
            Node<T> *last = head;
            while (last->next != head) {
                last = last->next;
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
        }
        Node<T> *temp = current->getNext();
        current->setNext(temp->getNext());
        delete temp;
        length--;
        return true;
    }
};


#endif //CP_1_LINKEDLIST_H