use std::io;

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    loop {
        let n: usize = stdin.next().unwrap().parse().unwrap();
        if n == 0 {
            break;
        }

        let mut s: Vec<String> = stdin.by_ref().take(n).map(|s| s.to_string()).collect();
        s.sort_by_key(|s| s.get(0..2).unwrap_or("").to_owned());

        for name in s {
            println!("{}", name);
        }
        println!();
    }
}
