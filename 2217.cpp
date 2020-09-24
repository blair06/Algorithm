#include <iostream>
#include <algorithm>
using namespace std;
int n;
int temp;
int MAX = 0;
int arr[100005] = { 0, };
int cnt = 1;
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = n-1; i >=0; i--) {
        temp = arr[i] * cnt;
        if (MAX < temp) {
            MAX = temp;
        }
        cnt++;
    }
    cout << MAX;
    return 0;
}
