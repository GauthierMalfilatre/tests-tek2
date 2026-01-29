mod flight_log;

// use flight_log::FlightStatus;
// use flight_log::parse_flight;
use flight_log::build_schedule;

fn main() {
    let logs = vec![
        "SA-202,Mars,1430,ONTIME",
        "XF-99,Jupiter,1800,DELAYED 60",
        "BAD-LINE,Nowhere,0000",
        "ER-01,Earth,2359,CANCELLED Engine Failure",
        "TR-55,Venus,1200,ONTIME",
        "ZZ-99,Pluto,invalid,ONTIME",
    ];

    let schedule = build_schedule(logs);

    println!("--- Flight Schedule ---");
    for f in schedule {
        println!("{} to {} at {} is {:?}", f.id, f.destination, f.time, f.status);
    }
}
