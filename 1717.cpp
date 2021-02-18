#include<iostream>
#include <cstdio>
#define swap(a,b){int t = a; a = b; b = t;}

using namespace std;

int v[1000001];
int level[1000001];



int findNum(int u) {
	if (v[u] == u) {
		return u;
	}
	return v[u] = findNum(v[u]);
}
void merge(int n1, int n2) {
	n1 = findNum(n1);
	n2 = findNum(n2);

	if (n1 == n2) {
		return;
	}
	if (level[n1] > level[n2]) {
		swap(n1, n2);
	}
	v[n1] = n2;
	if (level[n1] == level[n2]) {
		++level[n2];
	}
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n+1; i++) {
		v[i] = i;
		level[i] = 1;
	}
	while (m--) {
		int a;
		scanf("%d", &a);
		
		if (a == 0) {
			int num1, num2;
			scanf("%d %d", &num1, &num2);
			merge(num1, num2);

		}
		else if (a == 1) {
			int num1, num2;
			scanf("%d %d", &num1, &num2);
			if (findNum(num1) == findNum(num2)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		
	}
	return 0;
}
