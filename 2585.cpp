#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int k;
int arr[1010][2] = { 0, };
int check[1001];
int BFS(int mid, int start, int canDis) {
    memset(check, 0, sizeof(check));
    int cnt=0;
    double dis = 0.0;
    double disTo = 0.0;
    int num = 0;
    int size = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        size = q.size();
        if (cnt > k) {
            return 0;
        }
        
        for (int i = 0; i < size; i++) {
            num = q.front();
            q.pop();

            if (!check[num]) {
                check[num] = true;
                for (int j = 1; j <= n; j++) {
                    dis = sqrt(pow(arr[num][0] - arr[j][0], 2) + pow(arr[num][1] - arr[j][1], 2));
                    if (dis <= canDis) {
                        disTo = sqrt(pow(10000 - arr[j][0], 2) + pow(10000 - arr[j][1], 2));
                        if (disTo <= canDis) {
                            return 1;
                        }
                        q.push(j);
                    }
                }
            }
        }
        cnt++;
    }
    return 0;
}
int main() {
    cin >> n >> k;
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int first = 0;
    int end = 10000;
    int mid=0;
    int ans =0;
    while (first <= end) {
        mid = (first + end) / 2;
        int bfs = BFS(mid, 0, mid * 10);
        if (bfs) {
            ans = mid;
            end = mid - 1;
        }
        else {
            first = mid + 1;
        }
        
    }
    cout << ans;
    
    return 0;
}
