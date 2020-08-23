#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int t, m, n, k;
int cnt;
int var1; int var2;
queue <int> q;
int arr[50][50] = { 0, };

int bfs(int var1, int var2, queue <int>q) {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();

        if (arr[x - 1][y] == 1 && x-1 >= 0) { //인덱스가 음수가 되는 경우를 방지
            q.push(x - 1);
            q.push(y);
        }
        else if (arr[x + 1][y] == 1 && x+1<50) {
            q.push(x + 1);
            q.push(y);
        }
        else if (arr[x][y-1] == 1 && y-1 >= 0) {
            q.push(x);
            q.push(y-1);
        }
        else if (arr[x][y + 1] == 1 && y + 1 < 50) {
            q.push(x);
            q.push(y + 1);
        }

        return 0;
    }

    for (int i = var1; i < m; i++) {
        if (var2 == n) {
            var2 = 0;
        }
        for (int j= var2; j < n; j++) {
            if (arr[i][j] == 1) {
                q.push(i);
                q.push(j);
            }
            bfs(i, j+1, q);
        }
    }
}
int main(void) {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        cnt = 0;
        bfs(0, 0, q);

        cout << cnt << endl;
    }
 
    return 0;
}
