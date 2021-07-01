#include <bits/stdc++.h>
using namespace std;

int nodes[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, W;
    cin >> N >> W;
    memset(nodes, 0, sizeof(nodes));

    for (int i = 0; i < N-1; i++) {
        int U, V;
        cin >> U >> V;
        nodes[U]++;
        nodes[V]++;
    }

    int n =0;
    for (int i = 2; i <= N; i++) {
        if (nodes[i] == 1) n++;
    }
    
    cout.precision(11);
    cout << fixed << (double) W / n << "\n";   
    return 0;
}
