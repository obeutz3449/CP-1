#include <utility>

//
// Created by Oliver on 2/28/2026.
//

#ifndef CP_1_SPACE_H
#define CP_1_SPACE_H


class Space {
    public:
        void pass(Player &p) {}
        void land(Player &p) {}
};

class Space_Go : Space {
    public:
        void pass(Player &p) {
            p->go();
        }
};

class Space_Property : Space {
    std::string name;
    int cost;
    Player owner;
    public:
        Space_Property(std::string& name, const int cost) : name(name), cost(cost), owner(nullptr) {}

        void land(Player &p) {
            if (owner == nullptr) {
                p.buy(this);
            }else if (owner != p) {
                p.rent(cost);
            }
        }
};

#endif //CP_1_SPACE_H