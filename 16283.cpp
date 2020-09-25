#include <iostream>
#include <algorithm>
using namespace std;
int a, b, n, w;
int arr[3];
int cnt = 0;
int main(void) {
    cin >> a >> b >> n >> w;

    for (int i = 1; i < n; i++) {
        if (a * i + b * (n - i) == w) {
            cnt++;
            arr[1] = i;
            arr[2] = n - i;
        }
    }
    if (cnt != 1) {
        cout << -1;
    }
    else {
        cout << arr[1] << " " << arr[2];
    }
    return 0;
}
