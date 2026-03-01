#include <utility>

//
// Created by Oliver on 2/28/2026.
//

#ifndef CP_1_SPACE_H
#define CP_1_SPACE_H
#include "Player.h"


class Space {
    public:
        void pass(Player *p) {}
        void land(Player *p) {}
};

class Space_Go : Space {
    public:
        void pass(Player *p) {
            p->go();
        }
};

class Space_Property : Space {
    std::string name;
    int cost;
    Player *owner;
    public:
        Space_Property(std::string& name, const int cost) : name(name), cost(cost), owner(nullptr) {}

        void land(Player *p) {
            if (owner == nullptr) {
                if(p->buy(cost)) {
                    owner = p;
                }
            }else if (owner != p) {
                owner->deposit(p->rent(cost));
            }
        }

        [[nodiscard]] int getCost() const {
            return cost;
        }

    ~Space_Property() {
            delete owner;
        }
};

#endif //CP_1_SPACE_H