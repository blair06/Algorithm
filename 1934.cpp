#include <iostream>
using namespace std;
int t;
int arr[1000][3] = { 0, };
int func(int a, int b) {
    if (b == 0) { return a; }
    else return func(b, a % b);
}
int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> arr[i][1] >> arr[i][2];
        if (arr[i][1] < arr[i][2]) {
            int temp = arr[i][1];
            arr[i][1] = arr[i][2];
            arr[i][2] = temp;
        }
    }
    for (int i = 0; i < t; i++) {
        int g = func(arr[i][1], arr[i][2]);
        cout << arr[i][1] * arr[i][2] / g <<endl;
    }
    

    return 0;
}
