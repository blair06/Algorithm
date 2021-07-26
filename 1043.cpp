#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, t;
int parent[51];
int party[51][51];
int can;

vector<int> knowTrue;

int find (int x) {
    if(x == parent[x]){
        return x;
    }
    return x = find(parent[x]);
}

void unionset (int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}
//진실을 아는 사람이 있는지 체크
int check(int i) {
    for (int j = 0; j < t; j++) {
        if (find(party[i][0]) == find(knowTrue[j])) {
            can--;
            return 0;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;

    //진실을 알고있는 사람들
    if(t == 0){
        //진실을 아는사람이 없을때
        cout << m;
        
        return 0;
    } else {
        for(int i=0; i<t; i++){
            int a;
            cin >> a;
            
            knowTrue.push_back(a);
        }
    }
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        //몇명올지
        int p;
        cin >> p;
        cin >> party[i][0];
        for(int j=1; j<p; j++){
            cin >> party[i][j];
            unionset(party[i][0],party[i][j]);
        }
    }
    
    can = m;
    for (int i = 0; i < m; i++) {
        check(i);
    }
    cout << can << '\n';

    return 0;
}
