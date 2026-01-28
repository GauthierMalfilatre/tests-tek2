mod survivability;

use survivability::compute_survivable_days;

fn main() {
    println!( "Survivable days : {}" , compute_survivable_days(10.0 , 1, 20.3 , 2000) );
}
