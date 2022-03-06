# MKRent - Car Rental System
The aim of the project was to create a car rental system in the form of the console app. Application was built on purpose of Obejct-oriented programming laboratories at the university.
## Implementation
The application was written in C ++ according to its paradigms such as inheritance, polymorphism and encapsulation.
## Running the project
Download the Release directory and run the .exe file just as any other application. Make sure that all necessary sources - .txt files - are in the same directory with .exe file.
## Functionalities
MKRent allows to manage the rental fleet by performing CRUD operations - Creade, Read, Update, Delete. User can modify data justified from the rental company's point of view, such as mileage, cost and availability. It is also possible to rent a car and return the rented car.
## Project tree
1. `CarRental.cpp` - main file, logic of forming the window, draws whole menu, manages the main menu options
2. `Car.cpp` - an abstract superclass for each type of car, contains general fields and pure virtual functions
3. `PassengerCar.cpp`, `Truck.cpp`, `Bus.cpp` - sublasses of a Car class, each of them contains field specific for its type and definitions of functions from superclass
4. `Fleet.cpp` - class stores vector of a whole fleet, allows to read and save data to .txt file so that entered data are not lost after exiting the application
## Class diagram
![MKRent UML Diagram](https://github.com/mariakax3/CarRentalSystem/blob/main/CarRental.jpg?raw=true)
## How the app could look
Due to limited time presented project is a simple console app allowing for basic operations. Its functionalities could be developed by introducing version for an admin - authorised by login and password - and for a client. The client's contact information could be stored along with the rented car informations which could be enhanced by registration number.