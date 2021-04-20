#include <iostream>
#include <queue>
#include<algorithm>
#include <vector>
using namespace std;
 
queue<int> q;
vector<int> v[10001];
bool check[10001];
int Min[10002];
int Max[10002];

pair<int, int> tree[10001];
pair<int, int> lev[10001];
int n,m;
int sum, maxval, depth;
int isroot[10001];
int pos = 1; // 노드의 위치
void func(int cur, int level){
    //자식이 있으면 깊이를 증가해 dfs
    if (tree[cur].first > 0){
        func(tree[cur].first, level + 1);
    }
    lev[cur].first = level;
    lev[cur].second = pos;
           
    // 현재 레벨에서 가장 왼쪽 노드 위치를 갱신
    if (Min[lev[cur].first] > lev[cur].second){
        Min[lev[cur].first] = lev[cur].second;

    }
    
   // 현재 레벨에서 가장 오른쪽 노드 위치를 갱신
   if (Max[lev[cur].first] < lev[cur].second)
       Max[lev[cur].first] = lev[cur].second;

   pos++;
    
    // 오른쪽 자식이 있다면
    if (tree[cur].second > 0){
        func(tree[cur].second, level + 1);
    }
           

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(Min, Min + 10002, INT_MAX);

    for(int i=1; i<=n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        tree[a].first=b;
        tree[a].second=c;
        isroot[a]++;
        if (b != -1){
            isroot[b]++;
        }
        if (c != -1){
            isroot[c]++;
        }
    }
    //루트노드는 증가를 한번만 했기 때문에 1인 상태
    int root=0;
    for(int i=1; i<= n; i++){
        if(isroot[i] == 1){
            root = i;
        }
    }
    func(root,1);
    for (int i = 1; i <= n; i++)
        {
            sum = Max[i] - Min[i] + 1;
            if (sum > maxval)
            {
                maxval = sum;
                depth = i;
            }
        }

    cout << depth << ' ' << maxval ;
    
    return 0;
}
