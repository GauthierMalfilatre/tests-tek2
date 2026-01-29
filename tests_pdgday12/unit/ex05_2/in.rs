mod global_inventory;

use global_inventory::consolidate_inventory;

fn main() {
    let orders = [
        ("Sapphire", 10, 500),
        ("Iron", 100, 5),
        ("Sapphire", 5, 600),
        ("Iron", 50, 5),
        ("Pc à opti", 3, 1000),
        ("Blaster", 100, 120),
        ("Caca", 0, 18),
        ("Space Dust", 0, 1),
    ];

    let inventory = consolidate_inventory(&orders);

    println!("--- Global Inventory ---");
    
    for (name, stock) in &inventory {
        // println!("{}: Qty {}, Value {}", name, stock.quantity, stock.total_value);
    }

    if let Some(stock) = inventory.get("Pc à opti") {
        if stock.quantity == 3 && stock.total_value == 3000 {
            println!("Eliott stock is correct.");
        } else {
            println!("Eliott stock is WRONG.");
        }
    }
    if inventory.contains_key("Caca") {
         println!("Error: Space Dust should not be in the inventory.");
    }
}
