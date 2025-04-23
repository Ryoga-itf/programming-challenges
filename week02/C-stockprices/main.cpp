#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    using pr = pair<int, int>;
    using max_heap = priority_queue<pr>;
    using min_heap = priority_queue<pr, vector<pr>, greater<pr>>;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        max_heap buy_orders;
        min_heap sell_orders;
        int last_price = -1;

        for (int i = 0; i < n; ++i) {
            string type, dummy, at;
            int shares, price;

            cin >> type >> shares >> dummy >> at >> price;

            if (type == "buy") {
                buy_orders.push({price, shares});
            } else {
                sell_orders.push({price, shares});
            }

            while (!buy_orders.empty() && !sell_orders.empty() && buy_orders.top().first >= sell_orders.top().first) {
                const auto [buy_price, buy_qty] = buy_orders.top();
                const auto [sell_price, sell_qty] = sell_orders.top();
                buy_orders.pop();
                sell_orders.pop();

                const int trade_qty = min(buy_qty, sell_qty);
                last_price = sell_price;

                if (buy_qty > trade_qty) {
                    buy_orders.push({buy_price, buy_qty - trade_qty});
                }
                if (sell_qty > trade_qty) {
                    sell_orders.push({sell_price, sell_qty - trade_qty});
                }
            }

            const string sell_out = sell_orders.empty() ? "-" : to_string(sell_orders.top().first);
            const string buy_out = buy_orders.empty() ? "-" : to_string(buy_orders.top().first);
            const string price_out = last_price == -1 ? "-" : to_string(last_price);

            cout << sell_out << " " << buy_out << " " << price_out << "\n";
        }
    }
    return 0;
}

