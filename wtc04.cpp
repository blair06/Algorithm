#include <string>
#include <vector>
using namespace std;
    
struct cursor {
    int x;
    int y;
};

int solution(int n, vector<vector<int>> board) {
    cursor c = cursor{1,1};
    int num = 1;
    int answer = 0;
    while(num != n*n+1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == num){
                    int x = j+1, y = i+1;
                    int nx, mx, ny, my;
                    if (c.x <= x){
                        nx = c.x;
                        mx = x;
                    } else {
                        nx = x;
                        mx = c.x;
                    }
                    if (c.y <= y){
                        ny = c.y;
                        my = y;
                    } else {
                        ny = y;
                        my = c.y;
                    }
                    
                    if(mx - nx <= nx + n - mx){
                        answer += mx - nx;
                    } else{
                        answer += nx + n - mx;
                    }
                    if(my - ny <= ny + n - my){
                        answer += my - ny;
                    } else {
                        answer += ny + n - my;
                    }
                    answer++;
                    c.x = j+1;
                    c.y = i+1;

                    num++;
                    
                };
            }
        }
    }
    
    return answer;
}
