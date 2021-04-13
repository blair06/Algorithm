#include <iostream>
using namespace std;
 
int pre[1001];
int in[1001];
 
 
void func(int root, int s, int e){
    for(int i = s ; i < e; i++){
        if(in[i] == pre[root]){
            //왼쪽
            func(root + 1, s, i);
            //오른쪽
            func(root + i + 1 - s, i + 1, e);
            cout<<pre[root]<<" ";
        }
    }
}
 
int main(void) {
    int t;
    cin>>t;
    while(t--){
        int n ; cin>>n;
        for(int i=0; i<n; i++){
            cin >> pre[i];
        }
        for(int i=0; i<n; i++){
            cin >> in[i];
        }
        func(0, 0, n);
        cout<<endl;
    }
    return 0;
}
