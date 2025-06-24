#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int c;
    cin >> c;
    vector<ll> x(c), y(c);
    for (int i = 0; i < c; i++) {
        cin >> x[i] >> y[i];
    }
    ll d2 = 0;
    for (int i = 0; i < c; i++) {
        for (int j = i + 1; j < c; j++) {
            d2 = max(d2, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    printf("%.10f\n", sqrt(d2));
}
