mod survivability;

use survivability::ShipAssessment;
use survivability::study_ships;
use survivability::compute_survivable_days;
use survivability::StudyResult;

fn main() {
    let nb_crew : u32 = 3;
    let ship1 = ShipAssessment {
        water_quantity: 16.0,
        water_cycles: 270,
        food_quantity: 230.0,
    };
    let ship2 = ShipAssessment {
        water_quantity: 100.0,
        water_cycles: 50,
        food_quantity: 250.0,
    };
    let ship3 = ShipAssessment {
        water_quantity: 600.0,
        water_cycles: 25,
        food_quantity: 3020.0,
    };
    let ship4 = ShipAssessment {
        water_quantity: 600000000.0,
        water_cycles: 2500,
        food_quantity: 3020000.0,
    };
    let ships = [
        ship1,
        ship3,
        ship2,
        ship4,
    ];
    let rocks_to_visit = [(String::from("Venus"), 137), (String::from("Mars"), 154), (String::from("Europa"), 2007), (String::from("Gargantua"), 10000)];
    let to_visit = String::from("Gargantua");
    let study: StudyResult = study_ships(&ships, &rocks_to_visit, to_visit, nb_crew);
    println!("Rock: {}, Reachable: {}, Index: {}", study.rock_name, study.reachable, study.ship_index);
}
