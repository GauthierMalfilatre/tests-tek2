mod venus;

mod life_struct {
    #[derive(Default)]
    pub struct Board {
        pub (super) size_x: i64,
        pub (super) size_y: i64,
        pub (super) board : Vec<char>,
    }
    pub trait GameOfLife {
        fn new(size_x: i64, size_y: i64) -> Self;
        fn next(&mut self);
        fn add_life(&mut self , x: i64 , y: i64) -> Result<(), (String)>;
    }
}

use venus::*;
use life_struct::*;

fn main() {
    let mut c: Board = Board::new(10, 10);
    let pos: [(i64, i64); 6] = [(2, 6), (1, 7), (3, 6), (3, 7), (3, 8), (3, 10)];
    let mut i: i32 = 0;

    for (x, y) in pos {
        match c.add_life(x, y) {
            Ok(()) => (),
            Err(x) => println!("{x}"),
        };
    }
    while i < 3 {
        println!("{c}\n");
        c.next();
        i += 1;
    }
}
