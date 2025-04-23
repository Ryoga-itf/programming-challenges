use std::{cmp::max, io};

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    let n: usize = stdin.next().unwrap().parse().unwrap();

    let mut a = vec![0; 101];
    let mut b = vec![0; 101];
    for i in 1..=n {
        let p: usize = stdin.next().unwrap().parse().unwrap();
        let q: usize = stdin.next().unwrap().parse().unwrap();
        a[p] += 1;
        b[q] += 1;

        let mut left = 1;
        let mut right = 100;
        let mut ans = 0;
        let mut count = 0;
        let mut s = a.clone();
        let mut t = b.clone();
        while count < i {
            if s[left] == 0 {
                left += 1;
                continue;
            }
            if t[right] == 0 {
                right -= 1;
                continue;
            }
            if s[left] >= t[right] {
                s[left] -= t[right];
                count += t[right];
                t[right] = 0;
            } else {
                t[right] -= s[left];
                count += s[left];
                s[left] = 0;
            }
            ans = max(ans, left + right);
        }
        println!("{}", ans);
    }
}
