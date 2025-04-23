use std::{collections::HashSet, io, mem::swap};

fn main() {
    let stdin = io::read_to_string(io::stdin()).unwrap();
    let mut stdin = stdin.split_whitespace();

    while let (Some(n), Some(m)) = (stdin.next(), stdin.next()) {
        let n: usize = n.parse().unwrap();
        let m: usize = m.parse().unwrap();
        let mut entries: Vec<HashSet<usize>> =
            (0..n).map(|i| vec![i].into_iter().collect()).collect();
        let mut sums: Vec<usize> = (1..=n).collect();
        let mut indexes: Vec<usize> = (0..n).collect();

        for _ in 0..m {
            let t: usize = stdin.next().unwrap().parse().unwrap();
            match t {
                1 => {
                    let mut p = indexes[stdin.next().unwrap().parse::<usize>().unwrap() - 1];
                    let mut q = indexes[stdin.next().unwrap().parse::<usize>().unwrap() - 1];
                    if p == q {
                        continue;
                    }
                    if entries[p].len() < entries[q].len() {
                        swap(&mut p, &mut q);
                    }
                    // p <- q
                    for &e in &entries[q].clone() {
                        entries[p].insert(e);
                        indexes[e] = p;
                    }
                    sums[p] += sums[q];
                }
                2 => {
                    let p = stdin.next().unwrap().parse::<usize>().unwrap() - 1;
                    let q = stdin.next().unwrap().parse::<usize>().unwrap() - 1;
                    let rp = indexes[p];
                    let rq = indexes[q];
                    if rp == rq {
                        continue;
                    }
                    entries[rp].remove(&p);
                    entries[rq].insert(p);
                    sums[rp] -= p + 1;
                    sums[rq] += p + 1;
                    indexes[p] = rq;
                }
                3 => {
                    let p = indexes[stdin.next().unwrap().parse::<usize>().unwrap() - 1];
                    println!("{} {}", entries[p].len(), sums[p]);
                }
                _ => unreachable!(),
            }
        }
    }
    println!()
}
