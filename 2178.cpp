#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int maze[101][101] = {0,};
int check[101][101] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int cnt[101][101] = { 0, };
int n, m;
queue<pair<int,int>> q;
void bfs(int num, int num2) {
    q.push(make_pair(num,num2));
    check[num][num2] = 1;
    cnt[num][num2] = 1;
    while (!q.empty()) {
        int val1 = q.front().first;
        int val2 = q.front().second;

        q.pop();
        if (val1 == n - 1 && val2 == m - 1) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (val1 + dx[i] >= 0 && val2 + dy[i] >= 0 && (val1 + dx[i] < n) && (val2 + dy[i] < m)) {
                if (check[val1 + dx[i]][val2 + dy[i]] == 0 && maze[val1 + dx[i]][val2 + dy[i]] == 1) {

                    check[val1 + dx[i]][val2 + dy[i]] = 1;
                    cnt[val1 + dx[i]][val2 + dy[i]] = cnt[val1][val2] + 1;

                    q.push(make_pair(val1 + dx[i], val2 + dy[i]));
                }
                
            }
        }

    }
}
int main()
{
  
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &maze[i][j]);
        }
    }
    bfs(0,0);
    cout << cnt[n-1][m-1];
    return 0;
}
