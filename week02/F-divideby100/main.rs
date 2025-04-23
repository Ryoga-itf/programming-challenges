use std::io;

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    let s = stdin.next().unwrap().to_string();
    let t = stdin.next().unwrap().to_string();

    if s.len() >= t.len() {
        let m = s.len() - t.len() + 1;
        print!("{}", s.get(0..m).unwrap());
        let s = s.get(m..).unwrap_or("").trim_end_matches('0');
        if !s.is_empty() {
            print!(".{}", s);
        }
    } else {
        let m = t.len() - s.len() - 1;
        print!("0.{}{}", "0".repeat(m), s.trim_end_matches('0'));
    }
    println!();
}
