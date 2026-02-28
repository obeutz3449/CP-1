#include <iostream>

#include "CircularlyLinkedList.h"
#include "Space.h"

using namespace std;

int main() {
    CircularlyLinkedList<int> list;
    list.insert(0, 0);
    list.printList();
    cout << "\n";
    list.insert(67, 0);
    list.printList();
    cout << "\n";
    list.remove(0);
    list.printList();
    cout << "\n";
    list.insert(13, 0);
    list.insert(123, 0);
    list.insert(6, 0);
    list.insert(7, 0);
    list.printList();
    cout << "\n";
    return 0;
}