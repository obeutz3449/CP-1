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
        const int CAPACITY = 40;
        int length;
        CircularlyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

        bool insert(T data, const int index) {
            if (length >= CAPACITY) return false;
            if (length == 0) {
                head = new Node<T>(data);
                head->setNext(head);
                tail = head;
                length = 1;
                return true;
            }
            if (index%(length+1) == 0) {
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

    bool remove(Node<T>* node) {
            if (head == nullptr) return false;
            if (head == node) {
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
            if (tail == node) {
                auto *temp = tail;
                tail = getNode(length - 2);
                tail->setNext(head);
                delete temp;
                length--;
                return true;
            }
            Node<T> *current = head;
            while (current->getNext() != node) {
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
            std::vector<Node<T>*> dataNode;
            if (length + data->size() > CAPACITY){
                dataNode = std::vector<Node<T>*>(data->size() + length - CAPACITY);
            }else {
                dataNode = std::vector<Node<T>*>(data->size());
            }
            if (data->empty()) return false;
            dataNode[0] = new Node<T>(data->at(0));
            for (int i = 1; i < dataNode.size(); i++) {
                auto node = new Node<T>(data->at(i));
                dataNode[i - 1]->setNext(node);
                dataNode[i] = node;
            }
            Node<T> *dataHead = dataNode[0];
            Node<T> *dataTail = dataNode[dataNode.size() - 1];
            if (length == 0) {
                head = dataHead;
                tail = dataTail;
                tail->setNext(head);
                length+=dataNode.size();
                return true;
            }
            Node<T> *current = head;
            if (index%(length+1) == 0) {
                head = dataHead;
                dataTail->setNext(current);
                tail->setNext(dataHead);
                length+=dataNode.size();
                return true;
            }
            for (int i = 0; i < (index - 1%length); i++) {
                current = current->getNext();
            }
            dataTail->setNext(current->getNext());
            current->setNext(dataHead);
            length+=dataNode.size();
            if (index%length == length-1) {
                tail = dataTail;
            }
            return true;
        }

        bool removeByName(const std::string name) {
            Node<T> *current = head;
            for (int i = 0; i < length; i++) {
                if (current->getData()->getName() == name) {
                    return remove(current);
                }
                current = current->getNext();
            }
            return false;
        }

        std::vector<std::string> findByColor(std::string name) {
            std::vector<std::string> result;
            Node<T> *current = head;
            for (int i = 0; i < length; i++) {
                if (current->getData()->getColor() == name) {
                    result.push_back(current->getData()->toString());
                }
                current = current->getNext();
            }
            return result;
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
            Node<T> *current = head;
            for (int i = 0; i < length; i++) {
                std::cout << current->getData()->toString() <<  " ";
                current = current->getNext();
            }
        }

        void printListFrom(int start, int end) {
            Node<T> *current = head;
            for (int i = 0; i < start%length; i++) {
                current = current->getNext();
            }
            for (int i = 0; i < (end - start)%length; i++) {
                std::cout << current->getData()->toString() <<  " ";
                current = current->getNext();
            }
        }
};


#endif //CP_1_LINKEDLIST_H