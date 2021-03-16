#include <iostream>

using namespace std;

int n;
long long DP[100];

int main() {
    cin >> n;

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;
    for (int i = 3; i <= n; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    cout << DP[n];

    return 0;
}
