#include <iostream>
struct Arrangement{
    int carIndex;
    int goatIndex;
    int emptyIndex;
};
const int iters = 10000;
int main()
{
    //{carIndex, goatIndex, emptyIndex}
    Arrangement arrangements[6];
    arrangements[0] = { 0,1,2 };
    arrangements[1] = { 0,2,1 };
    arrangements[2] = { 1,0,2 };
    arrangements[3] = { 1,2,0 };
    arrangements[4] = { 2,0,1 };
    arrangements[5] = { 2,1,0 };

    int swapSuccess = 0;
    int swapFail = 0;
    int stickSuccess = 0;
    int stickFail = 0;
    srand(time(0));
    for (int x = 0; x < iters; x++)
    {
        int index = rand() % 6;
        Arrangement arrangement = arrangements[index];

        int choice = rand() % 3;

        //values clamped between 0 and 2
        int other1 = choice + 1;
        if (other1 == 3) { other1 = 0; }
        int other2 = choice - 1;
        if (other2 == -1) { other2 = 2; }

        int doorToSwitchTo;
        if (rand() % 2) {
            doorToSwitchTo = arrangement.carIndex == other1 ? other1 : other2;
        }
        else {
            doorToSwitchTo = arrangement.carIndex == other2 ? other2 : other1;
        }

        //50% chance to swap to other door or stick with original choice
        if (rand() % 2) {
            if (arrangement.carIndex == choice) {
                stickSuccess++;
            }
            else {
                stickFail++;
            }
        }
        else {
            if (arrangement.carIndex == doorToSwitchTo) {
                swapSuccess++;
            }
            else {
                swapFail++;
            }
        }
    }
    std::cout   << "Swap Successes " << swapSuccess << "\n"
                << "Swap Failures " << swapFail << "\n"
                << "Stick Successes " << stickSuccess << "\n"
                << "Stick Failures " << stickFail << "\n"
                << "Swap Success Rate" << (float)swapSuccess / (float)(swapSuccess + swapFail) << "\n"
                << "Stick Success Rate" << (float)stickSuccess / (float)(stickSuccess + stickFail);
}