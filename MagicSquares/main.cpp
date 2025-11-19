#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> siamese_magic(int n) {
    vector<vector<int>> a(n, vector<int>(n, 0));
    int num = 1;
    int i = 0, j = n/2; // start at top middle
    while (num <= n*n) {
        a[i][j] = num++;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        if (a[ni][nj] != 0) {    // occupied
            i = (i + 1) % n;     // move down from original
            // j stays the same
        } else {
            i = ni; j = nj;
        }
    }
    return a;
}

int main() {
    int n;
    cout << "Enter odd n: ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "This program handles odd n only.\n";
        return 0;
    }
    auto m = siamese_magic(n);
    long long magic = 1LL * n * (n*n + 1) / 2;
    cout << "Magic sum = " << magic << "\n";
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << m[r][c] << (c+1==n?'\n':'\t');
        }
    }
    return 0;
}
