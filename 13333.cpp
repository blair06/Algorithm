#include <iostream>
#include <algorithm>
int n;
int arr[1000];
using namespace std;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = n; i >=0 ; i--) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i) {
                count++;
            }
        }
        if (count >= i) {
            cout << i;
            break;
        }
    }

    return 0;
}
