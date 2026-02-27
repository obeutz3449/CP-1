#include <iostream>

#include "circularlyLinkedList.h"
using namespace std;

int main() {
    CircularlyLinkedList<int> list;
    list.insert(0, 0);
    list.printList();
    list.insert(67, 0);
    cout << "\n";
    list.printList();
    list.remove(0);
    cout << "\n";
    list.printList();
    list.insert(13, 0);
    list.insert(123, 0);
    list.insert(6, 0);
    list.insert(7, 0);
    cout << "\n";
    list.printList();
    return 0;
}