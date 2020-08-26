#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int cnt = 0;
queue<int> q;
int v[101][101];
int check[101] = { 0, };

void bfs() {
    q.push(1);
    check[1] = 1;
    while (!q.empty()) {
        int pop = q.front();
        q.pop();
        for (int i = 1; i <= m; i++) {
            if (v[pop][i] != 0 && check[i] == 0) {
                q.push(i);
                check[i] = 1;
                cnt++;
            }

        }
    }
}
int main(void)
{
    cin >> n >> m;


    for (int i = 1; i <= m; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        v[num1][num2] = 1;
        v[num2][num1] = 1;
    }

    bfs();

    cout << cnt;

    return 0;
}
