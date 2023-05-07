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
    cout << number << endl;
    number++;
    cout << number << endl;
    bookingReferenceNumbercount = to_string(number);
    cout << bookingReferenceNumbercount << endl;
    return to_string(number);
}


//passanger class with name, age, contact info, passport no
class Passenger {
public:
    Passenger(std::string name, int age, std::string contactInfo, std::string passportNo)
            : name(name), age(age), contactInfo(contactInfo), passportNo(passportNo) {cout << "Passenger created with passport number" << endl;}

//            create a Passanger that is created with no passport number
    Passenger(std::string name, int age, std::string contactInfo)
            : name(name), age(age), contactInfo(contactInfo) {cout << "Passenger created with no passport number" << endl;}

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


    //add passenger to passenger vector
    bool addPassenger(Passenger* p) {
        passengers.push_back(p);
        return true;
    }

//    bool addPassenger(const Passenger &p) {
//        passengers.push_back(p);
//        return true;
//
//
//    }
    //remove passenger from passenger vector given passenger
    bool removePassenger(Passenger& p){
        for (int i = 0; i < passengers.size(); i++) {
            if (passengers[i]->getname() == p.getname()) {
                passengers.erase(passengers.begin() + i);
                cout << "Passenger removed" << endl;
                return true;
            }
        }
        return false;
    };

    string getflightNumber() const {
        return flightNumber;
    }

    virtual string getType() {
        return "Type of flight not defined yet";
    }

    virtual double calculateTicketPrice() = 0;



protected:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<Passenger*> passengers;
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
            flight(&f), passenger(&p), bookingReferenceNumber(getNextBookingReferenceNumber()){cout << "Booking created 098765432" << endl;}

    string getBookingReferenceNumber() const {
        return bookingReferenceNumber;
    }


    void displayBookingDetails() const {
        std::cout << "Booking Reference Number: " << bookingReferenceNumber << std::endl;
        flight->displayFlightDetails();
        passenger->displayPassengerDetails();

//        to display booking details we need to display flight details and passenger details
//        for flight in flights
//        if flight number is equal to booking flight number
//        display flight details
//        end for loop
//        for passenger in passengers
//        print error message flight not found
//        for passenger in passengers

    }

    string getBookingNumber() const {
        return bookingReferenceNumber;
    }

    Flight* getFlight() const {
        return flight;
    }

    Passenger* getPassenger() const {
        return passenger;
    }

    bool updatePassenger(Passenger& p) {
        passenger = &p;
        cout << "Passenger updated" << endl;
        return true;
    }

    bool updateFlight(Flight& f) {
        flight = &f;
        cout << "Flight updated" << endl;
        return true;
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

    string getType() {
        return "Domestic";
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

    string getType() {
        return "International";
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
            // booking(Flight& f, Passenger& p);
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
                cout << "flight number not found" << endl;
                return false;
            }
            else
            {
                for (auto f : flights) {
                    if (f->getflightNumber() == flightNumber) {

                        flightRef = f;
                        cout << "[VALID FLIGHT]" << endl;
                    }
                }
            }

            //return a flight* object from a flight number from inside of the flights vector
//            for (auto f : flights) {
//                if (f->getflightNumber() == flightNumber) {
//                    flightRef = f;
//                }
//            }

//          get passenger details to create a passenger object
//          there are 2 constructors for passenger
//          Passenger(std::string name, int age, std::string contactInfo) or Passenger(std::string name, int age, std::string contactInfo, std::string passportNo = "")
//          if the flight is international then we need to ask for passport number and create a passenger object with the passport number
//          if the flight is domestic then we do not need to ask for passport number and create a passenger object without the passport number as it is optional

            cout << "Enter passenger name: ";
            string name;
            cin >> name;

            cout << "(Integer Number) enter age: ";
            int age;
            cin >> age;

            cout << "enter contact info: ";
            string contactinfo;
            cin >> contactinfo;

            string passportNumber;
            Passenger* passengerRef;

//            gets if flightRef is created with domestic or international flight
//            if flightRef is created with domestic flight then assume international flight bookings have not entered their passport number
//            if flightRef is created with international flight then assume international flight bookings have entered their passport number

           if (flightRef->getType() == "International"){
               cout << "[INTERNATIONAL FLIGHT] Enter passenger passport number: ";
               cin >> passportNumber;
               passengerRef = new Passenger(name, age, contactinfo, passportNumber);
               flightRef->addPassenger(passengerRef);
//             cout << "[VALID PASSENGER for International flight]" << endl;
           }else {
               passengerRef = new Passenger(name, age, contactinfo);
               flightRef->addPassenger(passengerRef);
//            cout << "[VALID PASSENGER for Domestic flight]" << endl;
           };


//          assume international flight bookings have entered their passport number
//            cout << "Enter passenger passport number (Must enter if International flight!): ";
            //if flight is international then ask for passport number
//            if (flightRef->getOrigin() != flightRef->getDestination()) {
//                cout << "Enter passenger passport number: ";
//            }
//            this assumes that a flight is international if the origin and destination are not the same but did not implement this as it is not in the specification



//            Passenger* passengerRef = new Passenger(name, age, contactinfo, passportNumber);

            if (flightRef == nullptr || passengerRef == nullptr) {
                cout << "flight or passenger not found" << endl;
                return false;
            }
            //create a booking object
            Booking* bookingRef = new Booking(*flightRef, *passengerRef);
            bookings.push_back(bookingRef);
            //need to display the booking reference number  for the booking just created
            cout << "[BOOKING CREATED] Your booking reference number is: " << bookingRef->getBookingNumber() << endl;

//            test if booking is actually in the bookings vector
            for (auto b : bookings) {
                if (b->getBookingNumber() == bookingRef->getBookingNumber()) {
                    cout << "[BOOKING IS in bookings vector]" << endl;
                    b->displayBookingDetails();
                }
            }
            return true;
        }

        bool cancelBooking() {
            // Cancel booking
            // get booking number from user
            string bookingno;
            cout << "Enter booking number: ";
            cin >> bookingno;
            // find booking number in bookings vectore

            for (auto b : bookings) {
                if (b->getBookingNumber() == bookingno) {
                    Passenger* passengerRef = b->getPassenger();
                    // if booking number is found then delete booking from bookings vector
                    // to delete a booking we need to remove the passenger from the flight and then remove the booking from the bookings vector
                    bool removeP = b->getFlight()->removePassenger(*passengerRef);
                    if (removeP) {
                        bookings.erase(std::remove(bookings.begin(), bookings.end(), b), bookings.end());
                        cout << "[BOOKING CANCELLED]" << endl;
                    }

                }
            }

            return false;
            // if booking number is found then delete booking from bookings vector
            // to delete a booking we need to remove the passenger from the flight and then remove the booking from the bookings vector


            //test display bookings vector
//            for (auto b : bookings) {
//                b->displayBookingDetails();
//            }
//            return true;
        }

        bool updateBookingDetails() {
            // Update booking details will return true if booking is updated to a new flight
            // else return false if booking is not updated
//            get booking number from user
            string bookingno;
            cout << "Enter booking reference number: ";
            cin >> bookingno;
            // find booking number in bookings vector
            // to update a booking in flight booking systems we use "updateBooking(newFlight: Flight): bool" in booking class to change the flight
            Booking *bookingRef;
            bool validBooking = false;
            for (auto b : bookings) {
                if (b->getBookingNumber() == bookingno) {
                    bookingRef = b;
                    validBooking = true;
                    cout << "[VALID BOOKING]" << endl;
                    Flight* originalFlightRef = b->getFlight();

                    for (auto f : flights){
                        f->displayFlightDetails();
                    }
                    cout << "Enter the flight number you would like to update to: ";
                    string flightno;
                    cin >> flightno;

                    Flight* newFlightRef;
                    //check if flight number entered is in flihts vector
                    for (auto f : flights) {
                        if (f->getflightNumber() == flightno) {
                            for (auto f : flights) {
                                if (f->getflightNumber() == flightno) {
                                    newFlightRef = f;
                                }
                            }
                            if (newFlightRef == nullptr) {
                                cout << "[INVALID FLIGHT]" << endl;
                                return false;
                            }
                            return b->updateFlight(*newFlightRef);
                            // this will return true if booking is updated to a new flight
                        }
                    }
                }
            }
            if (validBooking == false) {
                cout << "[INVALID BOOKING]" << endl;
                return false;
            }
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
            if (bookings.empty()) {
                cout << "No bookings found" << endl;
            }
            else{
                string bookingno;
                cout << "Enter booking number: " ;
                cin >> bookingno;

                for (auto b : bookings) {
                    if (b->getBookingNumber() == bookingno) {
                        b->displayBookingDetails();
                    }
                }



//                for (auto b : bookings) {
//                    b->displayBookingDetails();
//                }
            };
        }

        void addFlight(Flight* f) {
            flights.push_back(f);
        }


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
            flightbookingsystem.cancelBooking();
            break;
        case 3:
            cout << "Update Booking Details" << endl;
            flightbookingsystem.updateBookingDetails();
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