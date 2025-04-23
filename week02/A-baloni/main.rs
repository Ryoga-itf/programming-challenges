use std::io;

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    _ = stdin.next().unwrap();
    let h: Vec<usize> = stdin.map(|v| v.parse().unwrap()).collect();
    let mut arrows = vec![0; 1000001];
    let mut ans = 0;
    for h in h {
        if arrows[h] == 0 {
            ans += 1;
            arrows[h - 1] += 1;
        } else {
            arrows[h] -= 1;
            arrows[h - 1] += 1;
        }
    }
    println!("{}", ans);
}
