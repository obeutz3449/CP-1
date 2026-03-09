//
// Created by Oliver on 2/24/2026.
//

#ifndef CP_1_LINKEDLIST_H
#define CP_1_LINKEDLIST_H
#include <iostream>
#include <vector>

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
    Node<T> *tail;

    public:
        int length;
        CircularlyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

        bool insert(T data, const int index) {
            if (length >= 40) return false;
            if (length == 0) {
                head = new Node<T>(data);
                head->setNext(head);
                tail = head;
                length = 1;
                return true;
            }
            if (index%length == 0) {
                Node<T> *temp = head;
                head = new Node<T>(data);
                head->setNext(temp);
                tail->setNext(head);
                length++;
                return true;
            }
            Node<T> *current = head;
            for (int i = 0; i < (index - 1%length); i++) {
                current = current->getNext();
            }
            auto *ins = new Node<T>(data);
            ins->setNext(current->getNext());
            current->setNext(ins);
            length++;
            if (index%length == length-1) {
                tail = ins;
            }
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
                tail->setNext(head->getNext());
                delete head;
                head = tail->getNext();
                length--;
                return true;
            }
            if (tail->getData() == data) {
                auto *temp = tail;
                tail = getNode(length - 2);
                tail->setNext(head);
                delete temp;
                length--;
                return true;
            }
            Node<T> *current = head;
            while (current->getNext()->getData() != data) {
                current = current->getNext();
                if (current == head) return false;
            }
            Node<T> *temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            length--;
            return true;
        }

        bool insertMultiple(std::vector<T>* data, const int index) {
            if (length + data->size() > 40) return false;
            if (data->empty()) return true;
            std::vector<Node<T>*> dataNode(data->size());
            dataNode.push_back(new Node<T>(data->at(0)));
            for (int i = 1; i < data->size() - 1; i++) {
                auto* node = new Node<T>(data->at(i));
                dataNode[i - 1]->setNext(node);
                dataNode.push_back(node);
            }
            Node<T> *dataHead = dataNode[0];
            Node<T> *dataTail = dataNode[length - 1];
            if (length == 0) {
                head = dataHead;
                tail = dataTail;
                tail->setNext(head);
                length+=data->size();
                return true;
            }
            Node<T> *current = head;
            if (index%length == 0) {
                head = dataHead;
                dataTail->setNext(current);
                tail->setNext(dataHead);
                length+=data->size();
                return true;
            }
            for (int i = 0; i < (index - 1%length); i++) {
                current = current->getNext();
            }
            dataTail->setNext(current->getNext());
            current->setNext(dataHead);
            length+=data->size();
            if (index%length == length-1) {
                tail = dataTail;
            }
            return true;
        }

        T get(const int index) {
            auto current = head;
            for (int i = 0; i < index % length; i++) {
                current = current->getNext();
            }
            return current->getData();
        }

        Node<T>* getNode(const int index) {
            auto current = head;
            for (int i = 0; i < index % length; i++) {
                current = current->getNext();
            }
            return current;
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