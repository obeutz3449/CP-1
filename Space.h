#include <utility>

//
// Created by Oliver on 2/28/2026.
//

#ifndef CP_1_SPACE_H
#define CP_1_SPACE_H
#include "Player.h"


class Space {
    protected:
        std::string name;
        std::string color;
    public:
        Space() : name("Space"), color("white") {}
        Space(const std::string &name) : name(name) {}
        virtual ~Space() = default;
        virtual void pass(Player *p) {}
        virtual void land(Player *p) {}

        static int f() {
            return 4;
        }

        std::string getName() {
            return name;
        }

        std::string getColor() {
            return color;
        }

        virtual std::string toString() {
            return name;
        }
};

class Space_Go : public Space {
    public:
        Space_Go() {
            name = "Go";
            color = "green";
        }
        void pass(Player *p) override {
            p->go();
        }
};

class Space_Property : public Space {
    int cost;
    Player *owner;
    public:
        Space_Property(std::string nm, const int cost) : cost(cost), owner(nullptr) {
            name = nm;
            color = "blue";
        }

        Space_Property(std::string nm, const int cost, std::string c) : cost(cost), owner(nullptr) {
            name = nm;
            color = c;
        }

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

        std::string toString() override {
            return name + " ($" + std::to_string(cost) + ")";
        }
};

#endif //CP_1_SPACE_H