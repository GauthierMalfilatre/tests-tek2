mod survivability;

use survivability::ShipAssessment;
use survivability::study_ships;
use survivability::compute_survivable_days;
use survivability::StudyResult;

fn main() {
    let nb_crew : u32 = 0;
    let needs = ShipAssessment {
        water_quantity: 600.0,
        water_cycles: 25,
        food_quantity: 3020.0,
    };
    let days = compute_survivable_days(&needs, nb_crew);
    println!("Days: {}", days);
}
