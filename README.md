- The `ParkingLot` class follows the `Singleton` pattern to ensure only one instance of the parking lot exists. It maintains a list of levels and provides methods to park and unpark vehicles.
- The `Level` class represents a level in the parking lot and contains a list of parking spots. It handles parking and unparking of vehicles within the level.
- The `ParkingSpot` class represents an individual parking spot and tracks the availability and the parked vehicle.
- The `Vehicle` class is an abstract base class for different types of vehicles. It is extended by `Car`, `Motorcycle`, and `Truck classes.
- The `VehicleType` enum defines the different types of vehicles supported by the parking lot.
- Multi-threading is achieved through the use of synchronized keyword on critical sections to ensure thread safety.
- The `Main` class demonstrates the usage of the parking lot system.
