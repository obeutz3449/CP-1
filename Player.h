//
// Created by Oliver on 3/1/2026.
//

#ifndef CP_1_PLAYER_H
#define CP_1_PLAYER_H

class Player {
    int money;
    int timesPassedGo;
    int index;

    public:
        Player() : money(0), timesPassedGo(0), index(0) {};

        void go() {
            timesPassedGo++;
            deposit(200);
        }

        void setIndex(const int i) {
            index = i;
        }

        [[nodiscard]] int getIndex() const {
            return index;
        }

        [[nodiscard]] int getTimesPassedGo() const {
            return timesPassedGo;
        }

        bool buy(const int cost) {
            if (money >= cost) {
                money-=cost;
                return true;
            }
            return false;
        }

        void deposit(const int amount) {
            money+=amount;
        }

        int rent(const int cost) {
            if (money >= cost) {
                money-=cost;
                return cost;
            }
            const int difference = cost - money;
            money = 0;
            return difference;
        }
};

#endif //CP_1_PLAYER_H