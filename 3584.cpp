#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int t, n;
int node1, node2;

void func (int tree[],int check[],int num){
    if(tree[num] == 0){
        if(check[num]==1){
            cout << num<<endl;
            return;
        }
        check[num]=1;
        return;
    }
    
    if(check[num] == 1){
        cout << num<<endl;
        return;
    }else{
        check[num] = 1;
        func(tree,check,tree[num]);
    }
    
   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    
    while(t--){
        int tree[10001]={0,};
        int check[10001]={0,};
        cin >> n;
        for(int i=0; i<n-1;i++){
            int a, b;
            cin >> a >> b;
            //b의 부모는 a
            tree[b] = a;
            
        }
        //찾을 노드 2개
        cin >> node1 >> node2;
        
        func(tree,check,node1);
        func(tree,check,node2);
    }
    return 0;
}
