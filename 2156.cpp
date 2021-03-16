#include <iostream>
#include <vector>

using namespace std;

int n;
int max(int a, int b, int c) {
    return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}
int main() {
    cin >> n;
    int v[10001];
    int DP[10001];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    DP[0] = v[0];
    DP[1] = v[0] + v[1];

    for (int i = 2; i < n; i++) {
        DP[i] = max(DP[i - 1], DP[i - 2] + v[i], DP[i - 3] + v[i] + v[i - 1]);
    }
    cout << DP[n - 1];
    return 0;
}
