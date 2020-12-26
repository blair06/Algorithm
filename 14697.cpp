#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int arr[9] = { 0, };

int main(void)
{
    int a, b, c, n, check = 0;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    for (int k = 0; k < (n / c + 1); k++) {
        for (int i = 0; i < (n / b + 1); i++) {
            for (int j = 0; j < (n / a + 1); j++) {
                if ((k * c) + (i * b) + (j * a) == n)
                    check = 1;
            }
        }
    }
    printf("%d", check);
    return 0;
}
