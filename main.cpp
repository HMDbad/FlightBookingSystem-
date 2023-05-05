#include <iostream>
#include <vector>
#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-extensions"
using namespace std;
class Passenger;
class Flight;
class Booking;



static string bookingReferenceNumbercount = "0000000000";
string getNextBookingReferenceNumber() {
    // Generate booking reference number
    int number = stoi(bookingReferenceNumbercount);
    number++;
    bookingReferenceNumbercount = to_string(number);
    return to_string(number);
}


//passanger class with name, age, contact info, passport no
class Passenger {
public:
    Passenger(std::string name, int age, std::string contactInfo, std::string passportNo = "")
            : name(name), age(age), contactInfo(contactInfo), passportNo(passportNo) {}

    void displayPassengerDetails() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Contact Info: " << contactInfo;
        if (!passportNo.empty()) {
            std::cout << ", Passport No: " << passportNo;
        }
        std::cout << std::endl;
    }

    string getname() const {
        return name;
    }

private:
    std::string name;
    int age;
    std::string contactInfo;
    std::string passportNo;
};




//flight class with flight number, origin, destination, departure time, arrival time
class Flight {
public:
    Flight(std::string flightNumber, std::string origin, std::string destination,
           std::string departureTime, std::string arrivalTime)
            : flightNumber(flightNumber), origin(origin), destination(destination),
              departureTime(departureTime), arrivalTime(arrivalTime) {}

    virtual void displayFlightDetails() const {
//        had to make this virual to make it work in the international and domestic flight classes
//        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
//                  << ", Destination: " << destination << ", Departure Time: " << departureTime
//                  << ", Arrival Time: " << arrivalTime << std::endl;
    }

    bool addPassenger(const Passenger &p) {
        passengers.push_back(p);
        return true;


    }

    bool removePassenger(const Passenger &p){
        for (int i = 0; i < passengers.size(); i++) {
            if (passengers[i].getname() == p.getname()) {
                passengers.erase(passengers.begin() + i);
                return true;
            }
        }
        return false;
    };

    string getflightNumber() const {
        return flightNumber;
    }

    virtual double calculateTicketPrice() = 0;



protected:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<Passenger> passengers;
};

//Booking: A class representing a booking, including attributes such as booking reference
//number, flight details, and passenger details.
class Booking  {
private:
    string bookingReferenceNumber;
    Flight* flight;
    Passenger* passenger;

public:
//    create booking with flight and passenger ?
    Booking(Flight& f, Passenger& p ):
            flight(&f), passenger(&p), bookingReferenceNumber(getNextBookingReferenceNumber()){}

    string getBookingReferenceNumber() const {
        return bookingReferenceNumber;
    }


    void displayBookingDetails() const {
        std::cout << "Booking Reference Number: " << bookingReferenceNumber << std::endl;
        flight->displayFlightDetails();
//        passenger->displayPassengerDetails();

//        to display booking details we need to display flight details and passenger details
//        for flight in flights
//        if flight number is equal to booking flight number
//        display flight details
//        end for loop
//        for passenger in passengers
//        print error message flight not found
//        for passenger in passengers

    }

};

//domestic flight class inherits from flight class
class DomesticFlight : public Flight {
private:
    double domesticDiscount;

public:
    DomesticFlight(std::string flightNumber, std::string origin, std::string destination,
                   std::string departureTime, std::string arrivalTime, double domesticDiscount):
            Flight(flightNumber,origin, destination,departureTime,arrivalTime), domesticDiscount(domesticDiscount) {}

    double calculateTicketPrice() {
        // Calculate ticket price:
//        double price = 0;
//        if (passengers.size() < 100) {
//            price = 100;
//        } else {
//            price = 200;
//        }
        return 0;
    }

    double applyDomesticDiscount() {
        // Apply domestic discount
        return 0;
    }

    void displayFlightDetails() const {
        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
                  << ", Destination: " << destination << ", Departure Time: " << departureTime
                  << ", Arrival Time: " << arrivalTime << ", Domestic Discount: " << domesticDiscount << std::endl;
    }

};

//international flight class inherits from flight class
class InternationalFlight : public Flight {
private:
//    std::string passportNo; // (extra information for international flights)
    double internationalSurcharge; // International surcharge for international flights
public:
    InternationalFlight(std::string flightNumber, std::string origin, std::string destination,
                        std::string departureTime, std::string arrivalTime, double internationalSurcharge) :
            Flight(flightNumber, origin, destination, departureTime, arrivalTime),
            internationalSurcharge(internationalSurcharge) {}

    double calculateTicketPrice() {
        // Calculate ticket price
        return 0;
    }

//    returns void takes a surcharge double as a parameter
    void  appllyInternationalSurcharge() {
        // Apply international surcharge
    }

    void displayFlightDetails() const {
        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
                  << ", Destination: " << destination << ", Departure Time: " << departureTime
                  << ", Arrival Time: " << arrivalTime << ", International Surcharge: " << internationalSurcharge
                  << std::endl;
    }

};


//interfaces:
//Create an interface class (abstract class) called IBookingSystem that includes pure virtual
//functions for the following operations:
//a. Create booking
//b. Cancel booking
//c. Update booking details
//d. Display available flights
//e. Display flight details
//f. Display booking details


class IBookingSystem {
public:
    virtual bool createBooking() = 0;
    virtual bool cancelBooking() = 0;
    virtual bool updateBookingDetails() = 0;
    virtual void displayAvailableFlights() = 0;
    virtual void displayFlightDetails() = 0;
    virtual void displayBookingDetails() = 0;
};

//Implement this interface in a concrete class called FlightBookingSystem, which manages the flight booking operations.
class FlightBookingSystem : public IBookingSystem {
    public:

        bool createBooking() {
            // Create booking:
//            booking(Flight& f, Passenger& p);
            //to do this we need
            //get flight details from user to create a flight object
           std::cout << "Enter flight number: ";
           std::string flightNumber;
           Flight* flightRef; // flightRef is a pointer to a flight object based on the flight number entered by the user
           std::cin >> flightNumber;

//           if the flight number dose not exist return false
//           all flight numbers are stored in a vector of flights
            vector<string> flightNoVector;
            for (auto f : flights) {
                flightNoVector.push_back(f->getflightNumber());
            }
//          if the flightnNumber dose not exist in flightNoVector return false as booking cannot be created else add that flight to flightRef and continue
            if (std::find(flightNoVector.begin(), flightNoVector.end(), flightNumber) == flightNoVector.end()) {
                return false;
            }
            else
            {
                for (auto f : flights) {
                    if (f->getflightNumber() == flightNumber) {

                        flightRef = f;
                        cout << "flight found " << endl;
                    }
                }
            }
            //get passenger details to create a passenger object
//

            //return a flight* object from a flight number from inside of the flights vector



            for (auto f : flights) {
                if (f->getflightNumber() == flightNumber) {
                    flightRef = f;
                }
            }
            //get passenger details to create a passenger object
//            Passenger(std::string name, int age, std::string contactInfo, std::string passportNo = "")
            cout << "Enter passenger name: ";
            string name;
            cin >> name;

            cout << "enter age: ";
            int age;
            cin >> age;

            cout << "enter contact info: ";
            string contactinfo;
            cin >> contactinfo;


            cout << "Enter passenger passport number: ";
            string passportNumber;
            cin >> passportNumber;

            Passenger* passengerRef = new Passenger(name, age, contactinfo, passportNumber);

            if (flightRef == nullptr || passengerRef == nullptr) {
                return false;
            }
            //create a booking object
            Booking bookingRef(*flightRef, *passengerRef);
            bookings.push_back(&bookingRef);
            return true;
        }

        bool cancelBooking() {
            // Cancel booking
            return true;
        }

        bool updateBookingDetails() {
            // Update booking details
            return true;
        }

        void displayAvailableFlights() {
            // Display all flights from the list of flights
            for (auto f : flights) {
                f->displayFlightDetails();
           }

        }

        void displayFlightDetails() {
            // Display flight details based on flight number
            string flightno;
            cout << "Enter flight number: ";
            cin >> flightno;
            for (auto f : flights) {
                if (f->getflightNumber() == flightno) {
                    f->displayFlightDetails();
                }
            }

        }

        void displayBookingDetails() {
            // Display booking details based on booking number
            string bookingno;
            cout << "Enter booking reference number: ";
            cin >> bookingno;
            for (auto b : bookings) {
                if (b->getBookingReferenceNumber() == bookingno) {
                    cout << "Booking found" << endl;
//                    call the bookingDisplay function
                    b->displayBookingDetails();
                }
            }
            cout << "Booking not found" << endl;

        }

        void addFlight(Flight* f) {
            flights.push_back(f);
        }

//        Flight* getflightNumber() {
//
//        }


    private:
        vector<Flight*> flights;
        vector<Booking*> bookings;
};



//main loop class maybe ?


int main() {
    // Create a flight booking system
    FlightBookingSystem flightbookingsystem;

//    domestic flights:
//domestic flight takes flight number, origin, destination, departure time, arrival time, domestic discount
//international flight takes flight number, origin, destination, departure time, arrival time, international surcharge
    DomesticFlight flight1("QF401", "SYD", "MEL", "10:00", "11:00", 0.25);
    DomesticFlight flight2("QF402", "MEL", "SYD", "12:00", "13:00", 0.25);
    DomesticFlight flight3("QF403", "SYD", "BNE", "14:00", "15:00", 0.25);

//    international flights:
    InternationalFlight flight4("QF404", "SYD", "LAX", "16:00", "17:00", 0.5);
    InternationalFlight flight5("QF405", "LAX", "SYD", "18:00", "19:00", 0.5);

//    add flights to flight booking system
    flightbookingsystem.addFlight(&flight1);
    flightbookingsystem.addFlight(&flight2);
    flightbookingsystem.addFlight(&flight3);
    flightbookingsystem.addFlight(&flight4);
    flightbookingsystem.addFlight(&flight5);

//test main loop
int choice;
while(true){
    cout << "1. Create Booking" << endl;
    cout << "2. Cancel Booking" << endl;
    cout << "3. Update Booking Details" << endl;
    cout << "4. Display Available Flights" << endl;
    cout << "5. Display Flight Details" << endl;
    cout << "6. Display Booking Details" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "Create Booking" << endl;
            //create a booking in flightbookingsystem
            flightbookingsystem.createBooking();

            break;
        case 2:
            cout << "Cancel Booking" << endl;
//            modifying flightbookingsystem
            break;
        case 3:
            cout << "Update Booking Details" << endl;
            break;
        case 4:
            cout << "Display Available Flights" << endl;
//            use flightbookingsystem to display all available flights
            flightbookingsystem.displayAvailableFlights();
            break;
        case 5:
            cout << "Display Flight Details" << endl;
            flightbookingsystem.displayFlightDetails();
//            uses a flight number to display flight details
            break;
        case 6:
            cout << "Display Booking Details" << endl;
            flightbookingsystem.displayBookingDetails();
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }
    if(choice == 7){
        break;
    }

}

//   main loop test
//    mainloop mainloop;
//    mainloop.mainloop();


    // Create flights


//    DomesticFlight flight1("F1", "New York", "Los Angeles", "09:00", "14:00", 10.0);
//    flight1.displayFlightDetails();
//
//    InternationalFlight flight2("F2", "New York", "London", "19:00", "07:00", 100.0);
//    flight2.displayFlightDetails();
//    Flight flight3("F3", "New York", "Paris", "23:00", "11:00");


    // Create passengers
//    Passenger passenger1("John Doe", 35, "1234567890");
//    Passenger passenger2("Jane Doe", 29, "0987654321");
//    Passenger passenger3("John Smith", 45, "1234567890", "123456789");
//
//    // Add passengers to flights
//    flight1.addPassenger(passenger1);
//    flight2.addPassenger(passenger2);
//    flight3.addPassenger(passenger3);
//
//    // Display flight details
//    flight1.displayFlightDetails();
//    flight2.displayFlightDetails();
//    flight3.displayFlightDetails();
//
//    // Display passenger details
//    std::cout << "Passengers on flight F1:" << std::endl;
//    passenger1.displayPassengerDetails();
//
//    std::cout << "Passengers on flight F2:" << std::endl;
//    passenger2.displayPassengerDetails();
//
//    std::cout << "Passengers on flight F3:" << std::endl;
//    passenger3.displayPassengerDetails();
//
//    cout << "Removing passenger from flight 1" << endl;
//    flight1.removePassenger(passenger1);
//    cout << "Passengers on flight F1:" << endl;

//    Flight flight4("F4", "New York", "Los Angeles", "09:00", "14:00");
//    internationalFlight1.addPassenger(passenger1);

    return 0;
};


#pragma clang diagnostic pop