#include<iostream>
#define swap(a,b){int t = a; a = b; b = t;}

using namespace std;

int arr[201];
int level[201];
int find(int u) {
	if (arr[u] == u) {
		return u;
	}
	return arr[u] = find(arr[u]);
}
void merge(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if (n1 == n2) {
		return;
	}
	else if (level[n1] > level[n2]) {
		swap(n1, n2);
	}
	arr[n1] = n2;

	if (level[n1] == level[n2]) {
		++level[n2];
	}

}
int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (j > i && num == 1) {
				merge(i, j);
			}
		}
	}
	bool ck = true;
	int val;
	cin >> val;
	int u = find(val);
	for (int i = 1; i < m; i++) {
		cin >> val;
		if (u != find(val)) {
			ck = false;
			break;
		}

	}
	if (ck == true) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
