use std::{collections::HashSet, io};

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();
    let p: usize = stdin.next().unwrap().parse().unwrap();
    let t: usize = stdin.next().unwrap().parse().unwrap();

    let mut op = vec![vec!['.'; t]; p];
    while let (Some(i), Some(j)) = (stdin.next(), stdin.next()) {
        let i: usize = i.parse().unwrap();
        let j: usize = j.parse().unwrap();
        op[i - 1][j - 1] = '*';
    }

    let groups_num = op
        .iter()
        .fold(HashSet::new(), |mut acc: HashSet<String>, value| {
            acc.insert(value.iter().collect());
            acc
        })
        .len();
    println!("{}", groups_num);
}
