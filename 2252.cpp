#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
 
vector <vector<int>> v;
int visited[32001];
int m, n;
stack <int> s;

void dfs(int node){
    visited[node] = 1;
    for(auto i:v[node]){
        if(visited[i]){
            continue;
        }
        dfs(i);
    }
    s.push(node);
}
int main() {
    cin >> n >> m;
    v.resize(n+1);
   
    for(int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]){
            dfs(i);
        }
        
    }

    while(!s.empty()){
        cout <<s.top() << " ";
        s.pop();
    }

    return 0;
}
