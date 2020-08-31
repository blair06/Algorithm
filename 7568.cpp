#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[51][2] = { 0, };
int check[51];

int main() {
    int n;
    cin >> n;
    fill_n(check, 51, 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >>x;
        cin >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]) {
                check[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << check[i] << " ";
    }


    
    return 0;
}
