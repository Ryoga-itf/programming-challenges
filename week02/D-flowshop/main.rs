use std::{cmp::max, io};

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    let n: usize = stdin.next().unwrap().parse().unwrap();
    let m: usize = stdin.next().unwrap().parse().unwrap();

    let p: Vec<Vec<i64>> = (0..n)
        .map(|_| {
            (0..m)
                .map(|_| stdin.next().unwrap().parse().unwrap())
                .collect()
        })
        .collect();

    let mut ans = vec![0; n];
    let mut wait = vec![0; m];

    for (j, w) in wait.iter_mut().enumerate() {
        for i in 0..n {
            ans[i] = max(ans[i], *w) + p[i][j];
            *w = ans[i];
        }
    }

    for e in &ans {
        print!("{} ", e);
    }
    println!()
}
