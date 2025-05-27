#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int root(int *par, const int x) { return par[x] < 0 ? x : (par[x] = root(par, par[x])); }

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *par = (int *)malloc(sizeof(int) * n);
    memset(par, -1, sizeof(int) * n);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        a = root(par, --a);
        b = root(par, --b);
        if (a == b) {
            continue;
        }
        if (par[a] > par[b]) {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
        par[a] += par[b];
        par[b] = a;
    }
    const int r0 = root(par, 0);
    if (-par[r0] == n) {
        printf("Connected\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (r0 != root(par, i)) {
                printf("%d\n", i + 1);
            }
        }
    }
    free(par);
    return 0;
}
