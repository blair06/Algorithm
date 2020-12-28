#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int arr[9] = { 0, };

int main(void)
{
    int arr[50] = { 0, };
    int n;
    int count = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            count++;
            max = arr[i];
        }
    }
    cout << count <<endl;
    count = 1;
    max = arr[n-1];
    for (int i = n-1; i >= 0; i--) {
        if (max < arr[i]) {
            count++;
            max = arr[i];
        }
    }
    cout << count;
    return 0;
}
