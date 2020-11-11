#include <iostream>
using namespace std;
int main(void) {
    int ham ,soda;
    int max1 = 2000;
    int max2 = 2000;
    for (int i = 0; i < 3; i++) {
        cin >> ham;
        if (ham < max1) {
            max1 = ham;
        }
    }
    for (int i = 0; i < 2; i++) {
        cin >> soda;
        if (soda < max2) {
            max2 = soda;
        }
    }
    cout << max1 + max2 - 50;
    return 0;
}
