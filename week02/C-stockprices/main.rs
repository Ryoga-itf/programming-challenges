use std::{
    cmp::{min, Reverse},
    collections::BinaryHeap,
    io,
};

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    let t: usize = stdin.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = stdin.next().unwrap().parse().unwrap();

        let mut buy_orders = BinaryHeap::new();
        let mut sell_orders = BinaryHeap::new();
        let mut last_price = -1;

        for _ in 0..n {
            let order_type = stdin.next().unwrap();
            let shares: i32 = stdin.next().unwrap().parse().unwrap();
            _ = (stdin.next(), stdin.next()); // "shares" "at"
            let price: i32 = stdin.next().unwrap().parse().unwrap();

            if order_type == "buy" {
                buy_orders.push((price, shares));
            } else {
                sell_orders.push(Reverse((price, shares)));
            }

            while let (Some(buy), Some(sell)) = (buy_orders.peek(), sell_orders.peek()) {
                let (buy_price, buy_qty) = *buy;
                let (sell_price, sell_qty) = sell.0;
                if buy_price >= sell_price {
                    buy_orders.pop();
                    sell_orders.pop();

                    let trade_qty = min(buy_qty, sell_qty);
                    last_price = sell_price;

                    if buy_qty > trade_qty {
                        buy_orders.push((buy_price, buy_qty - trade_qty));
                    }
                    if sell_qty > trade_qty {
                        sell_orders.push(Reverse((sell_price, sell_qty - trade_qty)));
                    }
                } else {
                    break;
                }
            }

            println!(
                "{} {} {}",
                sell_orders
                    .peek()
                    .map_or(String::from("-"), |v| v.0 .0.to_string()),
                buy_orders
                    .peek()
                    .map_or(String::from("-"), |v| v.0.to_string()),
                if last_price == -1 {
                    "-".to_string()
                } else {
                    last_price.to_string()
                }
            );
        }
    }
}
