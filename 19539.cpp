#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int array[100001];
    int count = 0;
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        count += array[i];
    }

    if (count % 3 != 0) {
        cout << "NO";
    }
    else {
        for (int j = 0; j < n; j++) {
            num1 += array[j] / 2;
            num2 += array[j] - (array[j] / 2) * 2;

        }
        if (num1 >= num2) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }

    return 0;
}
