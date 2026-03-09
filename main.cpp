#include <iostream>
#include <memory>

#include "CircularlyLinkedList.h"
#include "Space.h"

using namespace std;

int main() {
    CircularlyLinkedList<Space*> list = CircularlyLinkedList<Space*>();
    auto go = new Space_Go();
    list.insert(go, 0);
    auto fifty = new vector<Space*>(50, new Space());
    cout << list.insertMultiple(fifty, 1);
    return 0;
}

void movePlayer(const int spaces, Player* p, CircularlyLinkedList<Space*>* board) {
    for (int i = 0; i < spaces; i++) {
        board->get(p->getIndex())->pass(p);
        p->setIndex((p->getIndex() + 1) % board->length);
    }
    board->get(p->getIndex())->land(p);
}