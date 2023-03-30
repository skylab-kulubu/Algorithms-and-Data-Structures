#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == prev + 1) {
            prev = arr[i];
        }
        else if (arr[i] != prev) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
