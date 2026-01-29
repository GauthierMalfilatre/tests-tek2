mod float_recognition;

use float_recognition::is_number;

fn main() {
    println!("Is \"0\" a number ? {}", is_number("0"));
    println!("Is \"000.0000\" a number ? {}", is_number("000.0000"));
    println!("Is \"martin\" a number ? {}", is_number("martin"));
    println!("Is \" -78..89 \" a number ? {}", is_number(" -78..89 "));
    println!("Is \"6-7\" a number ? {}", is_number("6-7"));
    println!("Is \"-0\" a number ? {}", is_number("-0"));
    println!("Is \".8.6\" a number ? {}", is_number(".8.6"));
    println!("Is \" 8671\" a number ? {}", is_number("  \t 8671"));
    println!("Is \"-67.86\" a number ? {}", is_number("-67.86"));
}
