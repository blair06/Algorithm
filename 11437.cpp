#include <iostream>
#include <queue>
#include<algorithm>
#include <vector>
using namespace std;
 
queue<int> q;
vector<int> v[50001];
bool check[50001];
int parent[50001];
int depth[50001];

int n,m;


int func(int node1, int node2){
    if(depth[node1]> depth[node2]){
        //깊이가 더 큰것이 node2가 된다.
        swap(node1,node2);
    }
    while(depth[node1] != depth[node2]){
        //두 깊이가 같아질때까지 부모노드를 점점 거슬러 올라간다
        node2 = parent[node2];
    }
    while(node1 != node2){
        node1 = parent[node1];
        node2 = parent[node2];
    }
    return node1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    check[1] = true;
    q.push(1);
    //트리 만들기
    while(!q.empty()){
        int mama = q.front();
        q.pop();
        for (int i = 0; i < v[mama].size(); i++) {
            if (!check[v[mama][i]]) {
                depth[v[mama][i]] = depth[mama] + 1;
                check[v[mama][i]] = true;
                parent[v[mama][i]] = mama;
                q.push(v[mama][i]);
            }
        }
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        cout <<func(x,y) << endl;
    }
    
    return 0;
}
