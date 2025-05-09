#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, d;
    cin >> a >> d;
    vector<double> ha(a), ta(a);
    for (int i = 0; i < a; i++) {
        cin >> ha[i] >> ta[i];
    }
    vector<double> hd(d), td(d);
    for (int j = 0; j < d; j++) {
        cin >> hd[j] >> td[j];
    }

    double height = 0;
    for (const auto &h : ha) {
        height += h;
    }

    int i = 0, j = 0;
    double rem_i = ta[0], rem_j = td[0];
    double vi = (ta[0] > 0 ? ha[0] / ta[0] : 0);
    double uj = (td[0] > 0 ? hd[0] / td[0] : 0);

    double t = 0.0;
    double up = 0.0;
    double down = height;

    while (i < a && j < d) {
        double delta = min(rem_i, rem_j);
        double f0 = up - down;
        double slope = vi + uj;
        double f1 = f0 + slope * delta;

        if (f1 >= 0) {
            double tau = -f0 / slope;
            printf("%.10f\n", t + tau);
            return 0;
        }

        t += delta;
        up += vi * delta;
        down -= uj * delta;
        rem_i -= delta;
        rem_j -= delta;

        if (rem_i == 0) {
            i++;
            if (i < a) {
                rem_i = ta[i];
                vi = (ta[i] > 0 ? ha[i] / ta[i] : 0);
            }
        }
        if (rem_j == 0) {
            j++;
            if (j < d) {
                rem_j = td[j];
                uj = (td[j] > 0 ? hd[j] / td[j] : 0);
            }
        }
    }

    return 0;
}
