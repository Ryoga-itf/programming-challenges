use std::{io, str::FromStr};

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut sc = Scanner::new(&stdin);

    let r: usize = sc.next();
    let c: usize = sc.next();
    let s: Vec<Vec<char>> = (0..r)
        .map(|_| sc.next::<String>().chars().collect())
        .collect();
    let mut ans = vec![0; 5];

    for i in 0..r - 1 {
        for j in 0..c - 1 {
            let mut status = 0;
            for di in 0..2 {
                for dj in 0..2 {
                    let c = s[i + di][j + dj];
                    if c == '#' {
                        status = 5;
                    } else if c == 'X' {
                        status += 1;
                    }
                }
            }
            if status < 5 {
                ans[status] += 1;
            }
        }
    }
    for e in ans {
        println!("{}", e);
    }
}

struct Scanner<'a> {
    iter: std::str::SplitWhitespace<'a>,
}

impl<'a> Scanner<'a> {
    fn new(s: &'a str) -> Self {
        Scanner {
            iter: s.split_whitespace(),
        }
    }

    fn next<T: FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        self.iter
            .next()
            .expect("No more tokens")
            .parse::<T>()
            .expect("Failed parsing token")
    }
}
