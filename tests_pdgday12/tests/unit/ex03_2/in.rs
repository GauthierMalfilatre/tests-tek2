mod space_enigma;

use space_enigma::solve_enigma;
use space_enigma::Message;
use space_enigma::SecurityClass;
use space_enigma::Transmission;

fn main() {
    let key = 4242;

    let t1 = Transmission {
        message: Message::ClearString(String::from("bomb")),
        security: SecurityClass::Civilian,
        signal_strength: 100,
    };

    println!("--- Transmission 1 ---");
    println!("{:?}", solve_enigma(t1, key));
}
