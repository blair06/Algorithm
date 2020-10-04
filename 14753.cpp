#include <iostream>
#include <algorithm>
using namespace std;
int n;

int arr[10000] = { 0, };

int main(void) {
    cin >> n ;
    

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int result = max(arr[n - 1] * arr[n - 2], arr[n - 1] * arr[n - 2] * arr[n - 3]);
    if (arr[0] * arr[1] > 0) {
        result = max(arr[0] * arr[1], result);
        result = max(arr[0] * arr[1] * arr[n - 1], result);
    }
    cout << result;
    return 0;
}
