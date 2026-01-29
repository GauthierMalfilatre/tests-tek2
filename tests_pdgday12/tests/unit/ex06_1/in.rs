mod flight_log;

use flight_log::FlightStatus;
use flight_log::parse_flight;

fn main() {
    let mut caca: bool;

    // Valid
    let result = parse_flight("TR-55,Venus,1200,ONTIME");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("TR-55") && n.destination == String::from("Venus") && n.time == 1200 && n.status == FlightStatus::OnTime,
        Err(_e) => {println!() ; caca = false},
    }
    println!("Should be true, is {}", caca);

    let result = parse_flight("TR-55,Venus,1200,CANCELLED Caca fault");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("TR-55") && n.destination == String::from("Venus") && n.time == 1200 && n.status == FlightStatus::Cancelled(String::from("Caca fault")),
        Err(_e) => {println!() ; caca = false},
    }
    println!("Should be true, is {}", caca);

    let result = parse_flight("TR-55,Venus,1200,DELAYED 60");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("TR-55") && n.destination == String::from("Venus") && n.time == 1200 && n.status == FlightStatus::Delayed(60),
        Err(_e) => {println!() ; caca = false},
    }
    println!("Should be true, is {}", caca);

    // Invalid 1
    let result = parse_flight("ZZ-99,Pluto,invalid,ONTIME");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("ZZ-99") && n.destination == String::from("Pluto") && n.time == 0 && n.status == FlightStatus::OnTime,
        Err(_e) => {println!("{_e}") ; caca = false},
    }
    println!("Should be false, is {}", caca);

    // Invalid date1
    let result = parse_flight("ZZ-99,Pluto,1565,ONTIME");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("ZZ-99") && n.destination == String::from("Pluto") && n.time == 0 && n.status == FlightStatus::OnTime,
        Err(_e) => {println!("{_e}") ; caca = false},
    }
    println!("Should be false, is {}", caca);

    // Invalid date 2
    let result = parse_flight("ZZ-99,Pluto,6734,ONTIME");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("ZZ-99") && n.destination == String::from("Pluto") && n.time == 0 && n.status == FlightStatus::OnTime,
        Err(_e) => {println!("{_e}") ; caca = false},
    }
    println!("Should be false, is {}", caca);

    let result = parse_flight("ZZ-99,Pluto,0010,DELAYED");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("ZZ-99") && n.destination == String::from("Pluto") && n.time == 10 && n.status == FlightStatus::OnTime,
        Err(_e) => {println!("{_e}") ; caca = false},
    }
    println!("Should be false, is {}", caca);

    let result = parse_flight("ZZ-99,Pluto,0010,DELAYED caca");
    match result {
        Ok(n)   =>
            caca = n.id == String::from("ZZ-99") && n.destination == String::from("Pluto") && n.time == 10 && n.status == FlightStatus::OnTime,
        Err(_e) => {println!("{_e}") ; caca = false},
    }
    println!("Should be false, is {}", caca);
}
