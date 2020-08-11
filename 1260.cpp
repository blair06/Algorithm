#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void dfs(vector <int> a[],int v, bool check[]) {
    check[v] = true;
    cout << v << " ";
    
    for (int i = 0; i < a[v].size(); i++) {
        int next = a[v][i];
        if (check[next] == false) {
            dfs(a, next, check);
        }
    }  
}

void bfs(vector <int> a[],int v, bool check[]) {
    int cur;
    queue<int> q;
    check[v] = true;
    q.push(v);

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int k = 0; k < a[cur].size(); k++) {
            int next = a[cur][k];
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
            }
        }
    }
   

}
int main(void) {
    
    int n, m, v;
    bool check[1001] = { false };
    
    cin >> n >> m >> v;
    vector<int>* a = new vector<int>[n+1];

    for (int i = 0; i < m; i++) {
        int s_node,e_node;
        cin >> s_node>>e_node;
        a[s_node].push_back(e_node);
        a[e_node].push_back(s_node);

    }
    for (int i = 0; i < n + 1; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(a, v, check);
    for (int i = 0; i < n + 1; i++) {
        check[i] = false;
    }
    cout << endl;
    bfs(a, v, check);



    return 0;
}
