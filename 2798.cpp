#include <iostream> 
#include<vector> 
using namespace std; 
int main() {
  vector<int> array(10);
  int n, m;
  int prev = 0;
  scanf("%d %d", &n,&m); 
  array.resize(n);
  for (int a = 0; a < n; a++) {
  scanf("%d", &array[a]); 
  } 
  for (int i = 0; i < n; i++) {
    for (int k = 1; k < n; k++) {
      for (int j = 3; j < n; j++) {
        if (array[i] != array[k] && array[k] != array[j] && array[j] != array[i]) {
          int sum = array[i] + array[k] + array[j];
          if ((m >= sum) && (m - sum < m - prev)) { prev = sum; } } } } } 
          printf("%d", prev); return 0;
          }
