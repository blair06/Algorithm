#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long cnt = 0;
long long arr[1000][1000] = { 0, };
bool check[1000][1000];

int main(void) {
    cin >> n >>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int max1 = -1;//최대 높이
        int maxh = -1;//최대 높이를 가진 인덱스
        for (int j = 0; j < m; j++) {
            if (arr[i][j] >= max1) {
                maxh = j;
                max1 = arr[i][j];
            }
        }

        for (int k = 0; k < m; k++) {
            if (k == maxh) {
                check[i][k] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int max1 = -1;//최대 높이
        int maxh = -1;//최대 높이를 가진 인덱스
        for (int j = 0; j < n; j++) {
            if (arr[j][i] >= max1) {
                maxh = j;
                max1 = arr[j][i];
            }
        }

        for (int k = 0; k < n; k++) {
            if (k == maxh) {
                check[k][i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == 0) {
                cnt += arr[i][j];
            }
        }
    }
    cout << cnt;

    return 0;
}
