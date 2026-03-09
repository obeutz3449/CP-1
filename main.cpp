#include <iostream>
#include <memory>
#include <random>

#include "CircularlyLinkedList.h"
#include "Space.h"

using namespace std;

void movePlayer(const int spaces, Player* p, CircularlyLinkedList<Space*>* board) {
    for (int i = 0; i < spaces; i++) {
        board->get(p->getIndex())->pass(p);
        p->setIndex((p->getIndex() + 1) % board->length);
    }
    board->get(p->getIndex())->land(p);
}

int main() {
    CircularlyLinkedList<Space*> list = CircularlyLinkedList<Space*>();
    auto go = new Space_Go();
    list.insert(go, 0);
    string colors[] = {"yellow", "purple", "red", "orange"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            list.insert(new Space_Property("Property", 100*i+100, colors[i]), list.length);
        }
        list.insert(new Space(), list.length);
        vector<Space*> s = {new Space_Property("House", 100), new Space_Property("House", 100), new Space_Property("House", 100), new Space_Property("Mansion", 500*i + 500)};
        list.insertMultiple(&s, list.length);
        list.insert(new Space(), list.length);
    }
    cout << endl;

    list.printList();
    cout << endl << "\nMatching Colors: ";

    auto res = list.findByColor("white");
    for (const auto & re : res) {
        cout << re << ", ";
    }
    cout << endl;
    cout << endl;

    list.printListFrom(10,20);
    cout << endl;

    Player *o = new Player();
    while (o->getTimesPassedGo() < 3) {
        int dice = rand() % 6 + rand() % 6 + 2;
        movePlayer(dice, o, &list);
        cout << "o rolled a " << dice << " and has passed go " << o->getTimesPassedGo() << " time(s) and just landed on " << list.get(o->getIndex())->toString() << endl;
    }

    return 0;
}
