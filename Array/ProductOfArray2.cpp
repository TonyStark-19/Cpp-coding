#include <iostream>
using namespace std;
// Optimized

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    int ans[n];

    ans[0] = 1;

    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * arr[i - 1];
    }

    int suffix = 1;

    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}