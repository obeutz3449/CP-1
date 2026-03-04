#include <utility>

//
// Created by Oliver on 2/28/2026.
//

#ifndef CP_1_SPACE_H
#define CP_1_SPACE_H
#include "Player.h"


class Space {
    public:
        virtual ~Space() = default;
        virtual void pass(Player *p) {}
        virtual void land(Player *p) {}
};

class Space_Go : public Space {
    public:
        void pass(Player *p) override {
            p->go();
        }
};

class Space_Property : public Space {
    std::string name;
    int cost;
    Player *owner;
    public:
        Space_Property(std::string name, const int cost) : name(std::move(name)), cost(cost), owner(nullptr) {}

        void land(Player *p) override {
            if (owner == nullptr) {
                if(p->buy(cost)) {
                    owner = p;
                }
            }else if (&owner != &p) {
                owner->deposit(p->rent(cost));
            }
        }

        [[nodiscard]] int getCost() const {
            return cost;
        }
};

#endif //CP_1_SPACE_H