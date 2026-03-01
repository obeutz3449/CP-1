//
// Created by Oliver on 3/1/2026.
//

#ifndef CP_1_PLAYER_H
#define CP_1_PLAYER_H

class Player {
    int money = 0;
    int timesPassedGo = 0;

    public:
        Player();

        void go() {
            timesPassedGo++;
            deposit(200);
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
            int difference = cost - money;
            money = 0;
            return difference;
        }
};

#endif //CP_1_PLAYER_H