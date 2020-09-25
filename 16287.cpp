#include <iostream>
#include <algorithm>
using namespace std;
int n,weight;
int arr[5001] = { 0, };
int w[800000] = { 0, };
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> weight >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] > weight) {
                continue;
            }

            if (w[weight - arr[i] - arr[j]]) {
                cout << "YES";
                return 0;
            }
        }

        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] < weight) {
                w[arr[i] + arr[j]] = 1;
            }
        }
    }

    cout << "NO";
    return 0;
}
