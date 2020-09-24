#include <iostream>
#include <algorithm>
using namespace std;
int n, temp=0, result=0;
int arr[1000] = { 0, };
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        temp += arr[i];
        result += temp;
    }
    cout << result;
    return 0;
}
