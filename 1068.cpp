#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 

int n;
int root;
int del;
int totalCnt = 0;
int cnt =0;
bool hasleaf = true;
vector<int> v(51);
bool haschild[51];
bool visited[51]={0,};
void func(int idx){
    for(int i=0; i<n; i++){
        if(v[i] == idx ){
            haschild[idx] = true;
            func(i);
        }
    }
    if(haschild[idx] == false){
        cnt++;
    }
}
int main() {
    
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] == -1){
            root = i;
        }
    }
    cin >> del;
    //root이면 0 출력
    if(v[del] == -1){
        cout << 0;
        return 0;
    }
    //지우려는 노드의 부모가 다른자식이 있는지 판별
    for(int i=0;i<n;i++){
        //v[del]->부모인덱스
        if(v[del] == v[i]){
            if(del != i){
                hasleaf = false;
            }
        }
    }
    for(int i=0; i<n; i++){
        int isthere = 0;
        for(int j=0; j<n; j++){
            if(v[j] == i){
                isthere = 1;
                break;
            }
        }
        if(isthere == 0){
            totalCnt++;
        }
    }
  
    //부모노드가 삭제할 노드이외의 자식노드를 보유하지않을 경우
    if(hasleaf){
        func(del);
        totalCnt = totalCnt - cnt + 1 ;
    }else{
        func(del);
        totalCnt = totalCnt - cnt;
    }
  
    cout << totalCnt << endl;
    return 0;
}
