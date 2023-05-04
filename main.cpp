#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Booking;
class Passenger;
class Flight;

string bookingReferenceNumbercount = "0000000000";
string getNextBookingReferenceNumber() {
    // Generate booking reference number
    int number = stoi(bookingReferenceNumbercount);
    number++;
    bookingReferenceNumbercount = to_string(number);
    return to_string(number);
}
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
            //to do this we need
            //get flight details from user to create a flight object
//           std::cout << "Enter flight number: ";

            //get passenger details to create a passenger object

//            Booking booking(Flight f, Passenger p );
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
            // Display available flights
        }

        void displayFlightDetails() {
            // Display flight details
        }

        void displayBookingDetails() {
            // Display booking details
            }



    private:
        vector<Flight> flights;
        vector<Booking> bookings;
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

//        Flight getFlight() const {
//            return flight;
//        }

//        Passenger getPassenger() const {
//            return passenger;
//        }

        string getBookingReferenceNumber() const {
            return bookingReferenceNumber;
        }
};

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

    void displayFlightDetails() const {
        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
                  << ", Destination: " << destination << ", Departure Time: " << departureTime
                  << ", Arrival Time: " << arrivalTime << std::endl;
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

    virtual double calculateTicketPrice() = 0;



protected:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<Passenger> passengers;
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

//main loop class maybe ?


int main() {
    // Create a flight booking system
    FlightBookingSystem flightbookingsystem;

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
            break;
        case 5:
            cout << "Display Flight Details" << endl;
            break;
        case 6:
            cout << "Display Booking Details" << endl;
//            flightbookingsystem.displayBookingDetails();
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

