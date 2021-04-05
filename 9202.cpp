#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
int w,b;
int maxScore,maxLength,maxIdx,cnt;
int found[300001];

vector <string> dic(300000);
char board[5][5];
int visited[4][4];
string temp = "";
int dx[8] = {1,0,0,-1,-1,1,1,-1};
int dy[8] = {0,1,-1,0,-1,1,-1,1};


void DFS (int word, int idx, int x,int y) {
    if(dic[word].length()==idx && found[word]==0){
            found[word] = 1;
            if(idx == 3 || idx == 4) maxScore += 1;
            else if(idx == 5) maxScore += 2;
            else if(idx == 6) maxScore += 3;
            else if(idx == 7) maxScore += 5;
            else if(idx == 8) maxScore += 11;
            if(idx>maxLength){
                maxLength = idx;
                maxIdx = word;
            }
        cnt++;
        }
        else{
            for(int k = 0 ; k < 8 ; k++){
                int next_x = x + dx[k];
                int next_y = y + dy[k];
     
                if(next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4 && !visited[next_x][next_y] && board[next_x][next_y] == dic[word][idx]){
                    visited[next_x][next_y] = 1;
                    DFS(word,idx+1,next_x,next_y);
                    visited[next_x][next_y] = 0;
                }
            }
        }
        visited[x][y] = 0;

  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> w;
    dic.resize(w);

    for(int i=0; i<w; i++) {
        cin >> dic[i];
  
    }
    sort(dic.begin(),dic.end());

    cin >> b;
    while(b--){
        //보드 만들기
        for(int i=0; i<4; i++){
            cin>>temp;
            for(int j=0; j<4; j++){
                board[i][j] = temp[j];
                
            }
        }
        //초기화
        memset(found,0,w * sizeof(int));

        maxScore = 0;
        maxLength = -1;
        maxIdx = 0;
        cnt = 0;
        //단어찾기
        for(int t = 0 ; t < w ; t++){
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j < 4 ; j++){
                    if(board[i][j]==dic[t][0] && found[t]==0) {
                        visited[i][j] = 1;
                        DFS(t,1,i,j);
                    }
                }
            }
            

        }
        cout << maxScore << " " << dic[maxIdx] << " " << cnt << "\n";

    }
    return 0;
}
