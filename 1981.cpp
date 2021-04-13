#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
 
int map[101][101];
bool visited[101][101];
int n;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool bfs(int s, int e){
    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1][1] = true;
    
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        if(y ==n && x ==n){
            return true;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n || visited[ny][nx]){
                continue;
            }
            if(map[ny][nx] < s || map[ny][nx] > e){
                continue;
            }
            visited[ny][nx] = true;
            q.push({ny,nx});
        }
    }
    return false;
}
int main() {
    
    cin >> n;
    int MAX = 0;
    int MIN = 1000000000;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j] > MAX) {
                MAX = map[i][j];
            }
            if(map[i][j] < MIN){
                MIN = map[i][j];
            }
        }
    }
        int start =0;
        int end = MAX - MIN;
        int mid;
        int result = 1000000000;
        while( start <= end){
            mid = (start + end)/2;
            bool suc = false;
            
            for(int i=MIN; i<= MAX; i++){
                if(i <= map[1][1] && map[1][1] <= i + mid) {
                    bool check = bfs(i, i+ mid);
                    memset(visited, false, sizeof(visited));
                    if(check) {
                        suc = true;
                        break;
                    }
                }
            }
            
            if(suc) {
                if(result > mid){
                    result = mid;
                    end = mid -1;
                }
            }else {
                start = mid + 1;
            }
        }
    cout << result;
    return 0;
}
