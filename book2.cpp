// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// struct Passenger
// {
//     string name;
//     string cruiseId;
//     string accomodation;
//     int waitListNumber;
// };

// struct Cruise
// {
//     string id;
//     string name;
//     int economySeats;
//     int businessSeats;
//     int regularSeats;
//     queue<Passenger> waitingList;
// };

// // Function to read cruise information from a file
// // Function to read cruise information from a file
// vector<Cruise> readCruisesFromFile(const string& filename) {
//     vector<Cruise> cruises;
//     ifstream file(filename);

//     if (file.is_open()) {
//         string line;
//         while (getline(file, line)) {
//             istringstream iss(line);
//             string id, name;
//             int economySeats, businessSeats, regularSeats;

//             if (getline(iss, id, ',') &&
//                 getline(iss, name, ',') &&
//                 (iss >> economySeats) &&
//                 (iss.ignore(), iss >> businessSeats) &&
//                 (iss.ignore(), iss >> regularSeats)) {
                
//                 Cruise cruise = {id, name, economySeats, businessSeats, regularSeats};
//                 cruises.push_back(cruise);
//             }
//         }
//         file.close();
//     }

//     return cruises;
// }


// // Function to print the status of seats in a cruise
// void printSeatStatus(const Cruise &cruise)
// {
//     cout << "Economy Seats: ";
//     for (int i = 0; i < cruise.economySeats; ++i)
//     {
//         cout << "O ";
//     }
//     for (int i = cruise.economySeats; i < 10; ++i)
//     {
//         cout << "X ";
//     }
//     cout << "\nBusiness Seats: ";
//     for (int i = 0; i < cruise.businessSeats; ++i)
//     {
//         cout << "O ";
//     }
//     for (int i = cruise.businessSeats; i < 5; ++i)
//     {
//         cout << "X ";
//     }
//     cout << "\nRegular Seats: ";
//     for (int i = 0; i < cruise.regularSeats; ++i)
//     {
//         cout << "O ";
//     }
//     for (int i = cruise.regularSeats; i < 10; ++i)
//     {
//         cout << "X ";
//     }
//     cout << "\n";
// }

// // Function to print the status of seats in a cruise
// void getCruiseStatus(const vector<Cruise> &cruises, const string &cruiseId)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         const Cruise &cruise = *cruiseIt;

//         cout << "Cruise ID: " << cruise.id << "\n";
//         cout << "Cruise Name: " << cruise.name << "\n";

//         printSeatStatus(cruise);

//         cout << "Waiting List: ";
//         queue<Passenger> tempQueue = cruise.waitingList;
//         while (!tempQueue.empty())
//         {
//             cout << tempQueue.front().name << " ";
//             tempQueue.pop();
//         }
//         cout << "\n";
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to read passenger details from a file
// vector<Passenger> readPassengersFromFile(const string &filename)
// {
//     vector<Passenger> passengers;
//     ifstream file(filename);

//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream iss(line);
//             string name, cruiseId, accomodation;
//             int waitListNumber;

//             if (getline(iss, name, ',') &&
//                 getline(iss, cruiseId, ',') &&
//                 getline(iss, accomodation, ',') &&
//                 (iss >> waitListNumber))
//             {

//                 Passenger passenger = {name, cruiseId, accomodation, waitListNumber};
//                 passengers.push_back(passenger);
//             }
//         }
//         file.close();
//     }

//     return passengers;
// }

// // Function to save passenger details to a file
// void savePassengersToFile(const vector<Passenger> &passengers, const string &filename)
// {
//     ofstream file(filename);

//     if (file.is_open())
//     {
//         for (const Passenger &passenger : passengers)
//         {
//             file << passenger.name << ',' << passenger.cruiseId << ',' << passenger.accomodation << ',' << passenger.waitListNumber << '\n';
//         }
//         file.close();
//         cout << "Passenger details saved to " << filename << " successfully." << endl;
//     }
//     else
//     {
//         cout << "Unable to open " << filename << " for writing." << endl;
//     }
// }

// // Function to schedule a passenger on a cruise
// void schedulePassenger(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, const string &passengerName, const string &accomodation)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         Cruise &cruise = *cruiseIt;

//         // Check available seats based on the accomodation
//         if (accomodation == "economy" && cruise.economySeats > 0)
//         {
//             cruise.economySeats--;
//         }
//         else if (accomodation == "business" && cruise.businessSeats > 0)
//         {
//             cruise.businessSeats--;
//         }
//         else if (accomodation == "regular" && cruise.regularSeats > 0)
//         {
//             cruise.regularSeats--;
//         }
//         else
//         {
//             // If no available seats, add to the waiting list
//             Passenger newPassenger = {passengerName, cruiseId, accomodation, static_cast<int>(cruise.waitingList.size()) + 1};
//             cruise.waitingList.push(newPassenger);
//             passengers.push_back(newPassenger);
//             cout << "Passenger added to waiting list with number: " << newPassenger.waitListNumber << endl;
//             savePassengersToFile(passengers, "passenger.txt"); // Save updated passenger details to file
//             return;
//         }

//         Passenger newPassenger = {passengerName, cruiseId, accomodation, 0};
//         passengers.push_back(newPassenger);
//         cout << "Passenger scheduled successfully." << endl;
//         savePassengersToFile(passengers, "passenger.txt"); // Save updated passenger details to file
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to cancel a passenger booking
// // Function to cancel a passenger booking
// void cancelBooking(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, const string &passengerName)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         Cruise &cruise = *cruiseIt;

//         auto passengerIt = remove_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
//                                      { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

//         if (passengerIt != passengers.end())
//         {
//             passengers.erase(passengerIt, passengers.end());

//             // Refund the seat
//             if (passengerIt->accomodation == "economy")
//             {
//                 cruise.economySeats++;
//             }
//             else if (passengerIt->accomodation == "business")
//             {
//                 cruise.businessSeats++;
//             }
//             else if (passengerIt->accomodation == "regular")
//             {
//                 cruise.regularSeats++;
//             }

//             // Check waiting list and fill the seat
//             if (!cruise.waitingList.empty())
//             {
//                 Passenger waitingPassenger = cruise.waitingList.front();
//                 cruise.waitingList.pop();
//                 passengers.erase(remove_if(passengers.begin(), passengers.end(),
//                                            [waitingPassenger](const Passenger &p)
//                                            {
//                                                return p.name == waitingPassenger.name && p.cruiseId == waitingPassenger.cruiseId;
//                                            }),
//                                  passengers.end());
//                 schedulePassenger(cruises, passengers, waitingPassenger.cruiseId, waitingPassenger.name, waitingPassenger.accomodation);
//             }

//             cout << "Booking canceled successfully." << endl;

//             // Save updated passenger details to file after cancellation
//             savePassengersToFile(passengers, "passenger.txt");
//         }
//         else
//         {
//             cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
//         }
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to get passenger status
// void getPassengerStatus(const vector<Passenger> &passengers, const string &passengerName, const string &cruiseId)
// {
//     auto passengerIt = find_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
//                                { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

//     if (passengerIt != passengers.end())
//     {
//         const Passenger &passenger = *passengerIt;

//         cout << "Passenger Name: " << passenger.name << "\n";
//         cout << "Cruise ID: " << passenger.cruiseId << "\n";
//         cout << "Accomodation: " << passenger.accomodation << "\n";

//         if (passenger.waitListNumber != 0)
//         {
//             cout << "Waiting List Number: " << passenger.waitListNumber << "\n";
//         }
//         else
//         {
//             cout << "Ticket Confirmed\n";
//         }
//     }
//     else
//     {
//         cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
//     }
// }

// int main()
// {
//     cout << endl;
//     cout << endl;
//     cout << "           WELCOME TO KPIT CRUISE BOOKING PORTAL               " << endl;
//     vector<Cruise> cruises = readCruisesFromFile("cruise.txt");

//     // Read existing passenger details from file
//     vector<Passenger> passengers = readPassengersFromFile("passenger.txt");

//     char choice;
//     do
//     {
//         cout << "\nOptions:\n";
//         cout << "s - Schedule passenger\n";
//         cout << "c - Cancel booking\n";
//         cout << "p - Passenger status\n";
//         cout << "f - Cruise status\n";
//         cout << "q - Quit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 's':
//         {
//             string cruiseId, passengerName, accomodation;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cout << "Select accomodation (economy/business/regular): ";
//             cin >> accomodation;
//             schedulePassenger(cruises, passengers, cruiseId, passengerName, accomodation);
//             break;
//         }
//         case 'f':
//         {
//             string cruiseId;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             getCruiseStatus(cruises, cruiseId);
//             break;
//         }
//         case 'c':
//         {
//             string cruiseId, passengerName;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cancelBooking(cruises, passengers, cruiseId, passengerName);
//             break;
//         }
//         case 'p':
//         {
//             string passengerName, cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout<<endl;
//             cout<<"The passenger details are as follows: "<<endl;
//             getPassengerStatus(passengers, passengerName, cruiseId);
//             break;
//         }
//         case 'q':
//             cout << "Exiting program.\n";
//             break;
//         default:
//             cout << "Invalid choice. Please try again.\n";
//             break;
//         }
//     } while (choice != 'q');

//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <unordered_map>

// using namespace std;

// #define RESET "\033[0m"
// #define RED "\033[31m"
// #define GREEN "\033[32m"
// #define YELLOW "\033[33m"
// #define BLUE "\033[34m"
// #define MAGENTA "\033[35m"
// #define CYAN "\033[36m"

// const string ADMIN_PASSWORD = "CRUISE123"; // Admin password for adding new cruise

// struct Passenger
// {
//     string name;
//     string cruiseId;
//     string accomodation;
//     int waitListNumber;
// };

// struct Cruise
// {
//     string id;
//     string name;
//     string departure_time;
//     string arrival_time;
//     int economySeats;
//     int businessSeats;
//     int regularSeats;
//     double economyPrice;
//     double businessPrice;
//     double regularPrice;
//     queue<Passenger> waitingList;
// };
// // Function to read cruise information from a file
// vector<Cruise> readCruisesFromFile(const string &filename)
// {
//     vector<Cruise> cruises;
//     ifstream file(filename);

//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream iss(line);
//             string id, name, departure_time, arrival_time;
//             int economySeats, businessSeats, regularSeats;

//             if (getline(iss, id, ',') &&
//                 getline(iss, name, ',') &&
//                 (iss >> economySeats) &&
//                 (iss.ignore(), iss >> businessSeats) &&
//                 (iss.ignore(), iss >> regularSeats))
//             {

//                 Cruise cruise = {id, name, departure_time, arrival_time, economySeats, businessSeats, regularSeats};
//                 cruises.push_back(cruise);
//             }
//         }
//         file.close();
//     }

//     return cruises;
// }
// using SeatOccupancy = std::unordered_map<string, int>;
// // Function to count the number of occupied seats for each accommodation type
// SeatOccupancy countOccupiedSeats(const vector<Passenger> &passengers, const Cruise &cruise) {
//     SeatOccupancy occupancy;

//     // Initialize the occupancy counts to zero
//     occupancy["economy"] = 0;
//     occupancy["business"] = 0;
//     occupancy["regular"] = 0;

//     // Count the occupied seats based on passenger data
//     for (const Passenger &passenger : passengers) {
//         if (passenger.cruiseId == cruise.id) {
//             occupancy[passenger.accomodation]++;
//         }
//     }

//     return occupancy;
// }
// void printSeatStatus(const Cruise &cruise, const SeatOccupancy &occupancy) {
//     cout << "Economy Seats: ";
//     for (int i = 0; i < cruise.economySeats; ++i) {
//         if (i < occupancy.at("economy")) {
//             cout << RED << "X " << RESET; // Occupied seat
//         } else {
//             cout << GREEN << "O " << RESET; // Available seat
//         }
//     }
//     cout << " (" << occupancy.at("economy") << " occupied, " << (cruise.economySeats - occupancy.at("economy")) << " available)\n";

//     // Repeat the same process for business and regular seats
//     // Business Seats
//     cout << "Business Seats: ";
//     for (int i = 0; i < cruise.businessSeats; ++i) {
//         if (i < occupancy.at("business")) {
//             cout << RED << "X " << RESET;
//         } else {
//             cout << GREEN << "O " << RESET;
//         }
//     }
//     cout << " (" << occupancy.at("business") << " occupied, " << (cruise.businessSeats - occupancy.at("business")) << " available)\n";

//     // Regular Seats
//     cout << "Regular Seats: ";
//     for (int i = 0; i < cruise.regularSeats; ++i) {
//         if (i < occupancy.at("regular")) {
//             cout << RED << "X " << RESET;
//         } else {
//             cout << GREEN << "O " << RESET;
//         }
//     }
//     cout << " (" << occupancy.at("regular") << " occupied, " << (cruise.regularSeats - occupancy.at("regular")) << " available)\n";
// }

// // Function to print the status of seats in a cruise
// // void printSeatStatus(const Cruise &cruise)
// // {
// //     cout << "Economy Seats: ";
// //     for (int i = 0; i < cruise.economySeats; ++i)
// //     {
// //         cout << GREEN << "O " << RESET;
// //     }
// //     for (int i = cruise.economySeats; i < 10; ++i)
// //     {
// //         cout << RED << "X " << RESET;
// //     }
// //     cout << "\nBusiness Seats: ";
// //     for (int i = 0; i < cruise.businessSeats; ++i)
// //     {
// //         cout << GREEN << "O " << RESET;
// //     }
// //     for (int i = cruise.businessSeats; i < 5; ++i)
// //     {
// //         cout << RED << "X " << RESET;
// //     }
// //     cout << "\nRegular Seats: ";
// //     for (int i = 0; i < cruise.regularSeats; ++i)
// //     {
// //         cout << GREEN << "O " << RESET;
// //     }
// //     for (int i = cruise.regularSeats; i < 10; ++i)
// //     {
// //         cout << RED << "X " << RESET;
// //     }
// //     cout << "\n";
// // }


// // Function to print the status of seats in a cruise
// // void getCruiseStatus(const vector<Cruise> &cruises, const string &cruiseId)
// // {
// //     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
// //                             { return cruise.id == cruiseId; });

// //     if (cruiseIt != cruises.end())
// //     {
// //         const Cruise &cruise = *cruiseIt;

// //         cout << "Cruise ID: " << cruise.id << "\n";
// //         cout << "Cruise Name: " << cruise.name << "\n";
// //         cout << "Departure Time: " << cruise.departure_time << "\n";
// //         cout << "Arrival Time: " << cruise.arrival_time << "\n";

// //         printSeatStatus(cruise);

// //         cout << "Waiting List: ";
// //         queue<Passenger> tempQueue = cruise.waitingList;
// //         while (!tempQueue.empty())
// //         {
// //             cout << tempQueue.front().name << " ";
// //             tempQueue.pop();
// //         }
// //         cout << "\n";
// //     }
// //     else
// //     {
// //         cout << "Cruise with ID " << cruiseId << " not found." << endl;
// //     }
// // }

// void getCruiseStatus(const vector<Cruise> &cruises, const vector<Passenger> &passengers, const string &cruiseId)

// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         const Cruise &cruise = *cruiseIt;

//         // Count occupied seats for the current cruise
//         SeatOccupancy occupancy = countOccupiedSeats(passengers, cruise);

//         // Print the status of seats
//         printSeatStatus(cruise, occupancy); // Pass both arguments

//         cout << "Waiting List: ";
//         queue<Passenger> tempQueue = cruise.waitingList;
//         while (!tempQueue.empty())
//         {
//             cout << tempQueue.front().name << " ";
//             tempQueue.pop();
//         }
//         cout << "\n";
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to read passenger details from a file
// vector<Passenger> readPassengersFromFile(const string &filename)
// {
//     vector<Passenger> passengers;
//     ifstream file(filename);

//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream iss(line);
//             string name, cruiseId, accomodation;
//             int waitListNumber;

//             if (getline(iss, name, ',') &&
//                 getline(iss, cruiseId, ',') &&
//                 getline(iss, accomodation, ',') &&
//                 (iss >> waitListNumber))
//             {

//                 Passenger passenger = {name, cruiseId, accomodation, waitListNumber};
//                 passengers.push_back(passenger);
//             }
//         }
//         file.close();
//     }

//     return passengers;
// }

// // Function to save passenger details to a file
// void savePassengersToFile(const vector<Passenger> &passengers, const string &filename)
// {
//     ofstream file(filename);

//     if (file.is_open())
//     {
//         for (const Passenger &passenger : passengers)
//         {
//             file << passenger.name << ',' << passenger.cruiseId << ',' << passenger.accomodation << ',' << passenger.waitListNumber << '\n';
//         }
//         file.close();
//         cout << "Passenger details saved to " << filename << " successfully." << endl;
//     }
//     else
//     {
//         cout << "Unable to open " << filename << " for writing." << endl;
//     }
// }

// // Function to schedule a passenger on a cruise
// void schedulePassenger(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, const string &passengerName, const string &accomodation)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         Cruise &cruise = *cruiseIt;

//         // Check available seats based on the accomodation
//         if (accomodation == "economy" && cruise.economySeats > 0)
//         {
//             cruise.economySeats--;
//         }
//         else if (accomodation == "business" && cruise.businessSeats > 0)
//         {
//             cruise.businessSeats--;
//         }
//         else if (accomodation == "regular" && cruise.regularSeats > 0)
//         {
//             cruise.regularSeats--;
//         }
//         else
//         {
//             // If no available seats, add to the waiting list
//             Passenger newPassenger = {passengerName, cruiseId, accomodation, static_cast<int>(cruise.waitingList.size()) + 1};
//             cruise.waitingList.push(newPassenger);
//             passengers.push_back(newPassenger);
//             cout << "Passenger added to waiting list with number: " << newPassenger.waitListNumber << endl;
//             savePassengersToFile(passengers, "passenger.txt"); // Save updated passenger details to file
//             return;
//         }

//         Passenger newPassenger = {passengerName, cruiseId, accomodation, 0};
//         passengers.push_back(newPassenger);
//         cout << "Passenger scheduled successfully." << endl;
//         savePassengersToFile(passengers, "passenger.txt"); // Save updated passenger details to file
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to cancel a passenger booking
// void cancelBooking(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, const string &passengerName)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         Cruise &cruise = *cruiseIt;

//         auto passengerIt = remove_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
//                                      { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

//         if (passengerIt != passengers.end())
//         {
//             passengers.erase(passengerIt, passengers.end());

//             // Refund the seat
//             if (passengerIt->accomodation == "economy")
//             {
//                 cruise.economySeats++;
//             }
//             else if (passengerIt->accomodation == "business")
//             {
//                 cruise.businessSeats++;
//             }
//             else if (passengerIt->accomodation == "regular")
//             {
//                 cruise.regularSeats++;
//             }

//             // Check waiting list and fill the seat
//             if (!cruise.waitingList.empty())
//             {
//                 Passenger waitingPassenger = cruise.waitingList.front();
//                 cruise.waitingList.pop();
//                 passengers.erase(remove_if(passengers.begin(), passengers.end(),
//                                            [waitingPassenger](const Passenger &p)
//                                            { return p.name == waitingPassenger.name && p.cruiseId == waitingPassenger.cruiseId; }),
//                                  passengers.end());
//                 schedulePassenger(cruises, passengers, waitingPassenger.cruiseId, waitingPassenger.name, waitingPassenger.accomodation);
//             }

//             cout << "Booking canceled successfully." << endl;

//             // Save updated passenger details to file after cancellation
//             savePassengersToFile(passengers, "passenger.txt");
//         }
//         else
//         {
//             cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
//         }
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to get passenger status
// void getPassengerStatus(const vector<Passenger> &passengers, const string &passengerName, const string &cruiseId)
// {
//     auto passengerIt = find_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
//                                { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

//     if (passengerIt != passengers.end())
//     {
//         const Passenger &passenger = *passengerIt;

//         cout << "Passenger Name: " << passenger.name << "\n";
//         cout << "Cruise ID: " << passenger.cruiseId << "\n";
//         cout << "Accomodation: " << passenger.accomodation << "\n";

//         if (passenger.waitListNumber != 0)
//         {
//             cout << "Waiting List Number: " << passenger.waitListNumber << "\n";
//         }
//         else
//         {
//             cout << "Ticket Confirmed\n";
//         }
//     }
//     else
//     {
//         cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
//     }
// }

// // Function to add a new cruise (admin-only operation)
// void addNewCruise(vector<Cruise> &cruises)
// {
//     string id, name, departure_time, arrival_time;
//     int economySeats, businessSeats, regularSeats;
//     double economyPrice, businessPrice, regularPrice;
//     cout << "Enter new cruise ID: ";
//     cin >> id;
//     cout << "Enter new cruise name: ";
//     cin.ignore(); // Clear the input buffer
//     getline(cin, name);
//     cout << "Enter Departure Time: " << endl;
//     cin >> departure_time;
//     cout << "Enter Arrival Time: " << endl;
//     cin >> arrival_time;
//     cout << "Enter number of economy seats: ";
//     cin >> economySeats;
//     cout << "Enter price for economy class: ";
//     cin >> economyPrice;
//     cout << "Enter number of business seats: ";
//     cin >> businessSeats;
//     cout << "Enter price for business class: ";
//     cin >> businessPrice;
//     cout << "Enter number of regular seats: ";
//     cin >> regularSeats;
//     cout << "Enter price for regular class: ";
//     cin >> regularPrice;

//     Cruise newCruise = {id, name, departure_time, arrival_time, economySeats, businessSeats, regularSeats, economyPrice, businessPrice, regularPrice};
//     cruises.push_back(newCruise);
//     cout << "New cruise added successfully." << endl;

//     // Save updated cruise details to file
//     ofstream file("cruise.txt", ios::app); // Append mode
//     if (file.is_open())
//     {
//         file << id << ',' << name << ',' << economySeats << ',' << businessSeats << ',' << regularSeats << ',' << economyPrice << ',' << businessPrice << ',' << regularPrice << '\n';
//         file.close();
//         cout << "Cruise details saved to file." << endl;
//     }
//     else
//     {
//         cout << "Unable to open file to save cruise details." << endl;
//     }
// }

// // Function to delete a cruise (admin-only operation)
// void deleteCruise(vector<Cruise> &cruises)
// {
//     string cruiseId;
//     cout << "Enter cruise ID to delete: ";
//     cin >> cruiseId;

//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         cruises.erase(cruiseIt);
//         cout << "Cruise with ID " << cruiseId << " deleted successfully." << endl;

//         // Save updated cruise details to file after deletion
//         ofstream file("cruise.txt");
//         if (file.is_open())
//         {
//             for (const Cruise &cruise : cruises)
//             {
//                 file << cruise.id << ',' << cruise.name << ',' << cruise.economySeats << ',' << cruise.businessSeats << ',' << cruise.regularSeats << '\n';
//             }
//             file.close();
//             cout << "Cruise details saved to file." << endl;
//         }
//         else
//         {
//             cout << "Unable to open file to save cruise details." << endl;
//         }
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Admin menu
// void adminMenu(vector<Cruise> &cruises)
// {
//     char choice;
//     cout << "\nAdmin Menu:\n";
//     cout << "A - Add new cruise\n";
//     cout << "D - Delete cruise\n";
//     cout << "Enter choice: ";
//     cin >> choice;

//     switch (choice)
//     {
//     case 'A':
//         addNewCruise(cruises);
//         break;
//     case 'D':
//         deleteCruise(cruises);
//         break;
//     default:
//         cout << "Invalid choice. Please try again." << endl;
//         break;
//     }
// }
// int main()
// {
//     cout << BLUE << "WELCOME TO KPIT CRUISE BOOKING PORTAL" << RESET << endl;
//     // Read existing cruise details from file
//     vector<Cruise> cruises = readCruisesFromFile("cruise.txt");

//     // Read existing passenger details from file
//     vector<Passenger> passengers = readPassengersFromFile("passenger.txt");

//     char choice;
//     do
//     {
//         cout << "\nOptions:\n";
//         cout << CYAN << "s - Schedule passenger\n";
//         cout << "c - Cancel booking\n";
//         cout << "p - Passenger status\n";
//         cout << "f - Cruise status\n";
//         cout << "N - Admin\n";
//         cout << "q - Quit\n"
//              << RESET;
//         cout << "Enter choice: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 's':
//         {
//             string cruiseId, passengerName, accomodation;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cout << "Select accommodation (economy/business/regular): ";
//             cin >> accomodation;
//             schedulePassenger(cruises, passengers, cruiseId, passengerName, accomodation);
//             break;
//         }
//         case 'f':
//         {
//             string cruiseId;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             getCruiseStatus(cruises, passengers, cruiseId);
//             break;
//         }
//         case 'c':
//         {
//             string cruiseId, passengerName;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cancelBooking(cruises, passengers, cruiseId, passengerName);
//             break;
//         }
//         case 'p':
//         {
//             string passengerName, cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << endl;
//             cout << "The passenger details are as follows: " << endl;
//             getPassengerStatus(passengers, passengerName, cruiseId);
//             break;
//         }
//         case 'N':
//         {
//             string adminPassword;
//             cout << "Enter admin password: ";
//             cin >> adminPassword;
//             if (adminPassword == ADMIN_PASSWORD)
//             {
//                 adminMenu(cruises);
//             }
//             else
//             {
//                 cout << "Invalid admin password." << endl;
//             }
//             break;
//         }
//         case 'q':
//             cout << "Exiting program.\n";
//             break;
//         default:
//             cout << "Invalid choice. Please try again.\n";
//             break;
//         }
//     } while (choice != 'q');

//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <unordered_map>

// using namespace std;

// #define RESET "\033[0m"
// #define RED "\033[31m"
// #define GREEN "\033[32m"
// #define YELLOW "\033[33m"
// #define BLUE "\033[34m"
// #define MAGENTA "\033[35m"
// #define CYAN "\033[36m"

// const string ADMIN_PASSWORD = "CRUISE123"; // Admin password for adding new cruise

// struct Passenger
// {
//     string name;
//     string cruiseId;
//     string accomodation;
//     int waitListNumber;
// };

// struct Cruise
// {
//     string id;
//     string name;
//     string departure_time;
//     string arrival_time;
//     int economySeats;
//     int businessSeats;
//     int regularSeats;
//     double economyPrice;
//     double businessPrice;
//     double regularPrice;
//     queue<Passenger> waitingList;
// };
// // Function to read cruise information from a file
// vector<Cruise> readCruisesFromFile(const string &filename)
// {
//     vector<Cruise> cruises;
//     ifstream file(filename);

//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream iss(line);
//             string id, name, departure_time, arrival_time;
//             int economySeats, businessSeats, regularSeats;

//             if (getline(iss, id, ',') &&
//                 getline(iss, name, ',') &&
//                 (iss >> economySeats) &&
//                 (iss.ignore(), iss >> businessSeats) &&
//                 (iss.ignore(), iss >> regularSeats))
//             {

//                 Cruise cruise = {id, name, departure_time, arrival_time, economySeats, businessSeats, regularSeats};
//                 cruises.push_back(cruise);
//             }
//         }
//         file.close();
//     }

//     return cruises;
// }
// using SeatOccupancy = std::unordered_map<string, int>;
// // Function to count the number of occupied seats for each accommodation type
// SeatOccupancy countOccupiedSeats(const vector<Passenger> &passengers, const Cruise &cruise) {
//     SeatOccupancy occupancy;

//     // Initialize the occupancy counts to zero
//     occupancy["economy"] = 0;
//     occupancy["business"] = 0;
//     occupancy["regular"] = 0;

//     // Count the occupied seats based on passenger data
//     for (const Passenger &passenger : passengers) {
//         if (passenger.cruiseId == cruise.id) {
//             occupancy[passenger.accomodation]++;
//         }
//     }

//     return occupancy;
// }


// void printSeatStatus(const Cruise &cruise, const SeatOccupancy &occupancy, const vector<Passenger> &passengers) {
//     cout << "Economy Seats: ";
//     for (int i = 1; i <= cruise.economySeats; ++i) {
//         bool isOccupied = false;
//         for (const Passenger &passenger : passengers) {
//             if (passenger.cruiseId == cruise.id && passenger.accomodation == "economy" && passenger.waitListNumber == i) {
//                 isOccupied = true;
//                 break;
//             }
//         }
//         if (isOccupied) {
//             cout << RED << "X " << RESET; // Occupied seat
//         } else {
//             cout << GREEN << (i <= occupancy.at("economy") ? "O" : "O") << " " << RESET; // Available seat or user-selected seat
//         }
//     }
//     cout << "\n";

//     // Repeat the same process for business and regular seats
//     // Business Seats
//     cout << "Business Seats: ";
//     for (int i = 1; i <= cruise.businessSeats; ++i) {
//         bool isOccupied = false;
//         for (const Passenger &passenger : passengers) {
//             if (passenger.cruiseId == cruise.id && passenger.accomodation == "business" && passenger.waitListNumber == i) {
//                 isOccupied = true;
//                 break;
//             }
//         }
//         if (isOccupied) {
//             cout << RED << "X " << RESET;
//         } else {
//             cout << GREEN << (i <= occupancy.at("business") ? "O" : "O") << " " << RESET;
//         }
//     }
//     cout << "\n";

//     // Regular Seats
//     cout << "Regular Seats: ";
//     for (int i = 1; i <= cruise.regularSeats; ++i) {
//         bool isOccupied = false;
//         for (const Passenger &passenger : passengers) {
//             if (passenger.cruiseId == cruise.id && passenger.accomodation == "regular" && passenger.waitListNumber == i) {
//                 isOccupied = true;
//                 break;
//             }
//         }
//         if (isOccupied) {
//             cout << RED << "X " << RESET;
//         } else {
//             cout << GREEN << (i <= occupancy.at("regular") ? "O" : "O") << " " << RESET;
//         }
//     }
//     cout << "\n";
// }




// void getCruiseStatus(const vector<Cruise> &cruises, const vector<Passenger> &passengers, const string &cruiseId)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         const Cruise &cruise = *cruiseIt;

//         // Count occupied seats for the current cruise
//         SeatOccupancy occupancy = countOccupiedSeats(passengers, cruise);

//         // Print the status of seats
//         printSeatStatus(cruise, occupancy, passengers); // Pass all three arguments

//         cout << "Waiting List: ";
//         queue<Passenger> tempQueue = cruise.waitingList;
//         while (!tempQueue.empty())
//         {
//             cout << tempQueue.front().name << " ";
//             tempQueue.pop();
//         }
//         cout << "\n";
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }


// // Function to read passenger details from a file
// vector<Passenger> readPassengersFromFile(const string &filename)
// {
//     vector<Passenger> passengers;
//     ifstream file(filename);

//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream iss(line);
//             string name, cruiseId, accomodation;
//             int waitListNumber;

//             if (getline(iss, name, ',') &&
//                 getline(iss, cruiseId, ',') &&
//                 getline(iss, accomodation, ',') &&
//                 (iss >> waitListNumber))
//             {

//                 Passenger passenger = {name, cruiseId, accomodation, waitListNumber};
//                 passengers.push_back(passenger);
//             }
//         }
//         file.close();
//     }

//     return passengers;
// }

// // Function to save passenger details to a file
// void savePassengersToFile(const vector<Passenger> &passengers, const string &filename)
// {
//     ofstream file(filename);

//     if (file.is_open())
//     {
//         for (const Passenger &passenger : passengers)
//         {
//             file << passenger.name << ',' << passenger.cruiseId << ',' << passenger.accomodation << ',' << passenger.waitListNumber << '\n';
//         }
//         file.close();
//         cout << "Passenger details saved to " << filename << " successfully." << endl;
//     }
//     else
//     {
//         cout << "Unable to open " << filename << " for writing." << endl;
//     }
// }

// // Function to schedule a passenger on a cruise
// void schedulePassenger(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, const string &passengerName, const string &accomodation)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         Cruise &cruise = *cruiseIt;

//         int selectedSeat;
//         cout << "Enter the seat number you want to book: ";
//         cin >> selectedSeat;

//         // Check if the selected seat is within the valid range
//         int maxSeats;
//         if (accomodation == "economy") {
//             maxSeats = cruise.economySeats;
//         } else if (accomodation == "business") {
//             maxSeats = cruise.businessSeats;
//         } else if (accomodation == "regular") {
//             maxSeats = cruise.regularSeats;
//         }

//         if (selectedSeat < 1 || selectedSeat > maxSeats) {
//             cout << "Invalid seat number. Please choose a seat within the valid range." << endl;
//             return;
//         }

//         // Check if the selected seat is available
//         bool seatOccupied = false;
//         for (const Passenger &passenger : passengers) {
//             if (passenger.cruiseId == cruiseId && passenger.accomodation == accomodation && passenger.waitListNumber == selectedSeat) {
//                 seatOccupied = true;
//                 break;
//             }
//         }

//         if (seatOccupied) {
//             cout << "Seat " << selectedSeat << " is already occupied. Please choose another seat." << endl;
//             return;
//         }

//         // Book the selected seat
//         Passenger newPassenger = {passengerName, cruiseId, accomodation, selectedSeat};
//         passengers.push_back(newPassenger);
//         cout << "Passenger scheduled successfully for seat " << selectedSeat << "." << endl;
//         savePassengersToFile(passengers, "passenger.txt"); // Save updated passenger details to file
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }



// // Function to cancel a passenger booking
// void cancelBooking(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, const string &passengerName)
// {
//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         Cruise &cruise = *cruiseIt;

//         auto passengerIt = remove_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
//                                      { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

//         if (passengerIt != passengers.end())
//         {
//             passengers.erase(passengerIt, passengers.end());

//             // Refund the seat
//             if (passengerIt->accomodation == "economy")
//             {
//                 cruise.economySeats++;
//             }
//             else if (passengerIt->accomodation == "business")
//             {
//                 cruise.businessSeats++;
//             }
//             else if (passengerIt->accomodation == "regular")
//             {
//                 cruise.regularSeats++;
//             }

//             // Check waiting list and fill the seat
//             if (!cruise.waitingList.empty())
//             {
//                 Passenger waitingPassenger = cruise.waitingList.front();
//                 cruise.waitingList.pop();
//                 passengers.erase(remove_if(passengers.begin(), passengers.end(),
//                                            [waitingPassenger](const Passenger &p)
//                                            { return p.name == waitingPassenger.name && p.cruiseId == waitingPassenger.cruiseId; }),
//                                  passengers.end());
//                 schedulePassenger(cruises, passengers, waitingPassenger.cruiseId, waitingPassenger.name, waitingPassenger.accomodation);
//             }

//             cout << "Booking canceled successfully." << endl;

//             // Save updated passenger details to file after cancellation
//             savePassengersToFile(passengers, "passenger.txt");
//         }
//         else
//         {
//             cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
//         }
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Function to get passenger status
// void getPassengerStatus(const vector<Passenger> &passengers, const string &passengerName, const string &cruiseId)
// {
//     auto passengerIt = find_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
//                                { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

//     if (passengerIt != passengers.end())
//     {
//         const Passenger &passenger = *passengerIt;

//         cout << "Passenger Name: " << passenger.name << "\n";
//         cout << "Cruise ID: " << passenger.cruiseId << "\n";
//         cout << "Accomodation: " << passenger.accomodation << "\n";

//         if (passenger.waitListNumber != 0)
//         {
//             cout << "Waiting List Number: " << passenger.waitListNumber << "\n";
//         }
//         else
//         {
//             cout << "Ticket Confirmed\n";
//         }
//     }
//     else
//     {
//         cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
//     }
// }

// // Function to add a new cruise (admin-only operation)
// void addNewCruise(vector<Cruise> &cruises)
// {
//     string id, name, departure_time, arrival_time;
//     int economySeats, businessSeats, regularSeats;
//     double economyPrice, businessPrice, regularPrice;
//     cout << "Enter new cruise ID: ";
//     cin >> id;
//     cout << "Enter new cruise name: ";
//     cin.ignore(); // Clear the input buffer
//     getline(cin, name);
//     cout << "Enter Departure Time: " << endl;
//     cin >> departure_time;
//     cout << "Enter Arrival Time: " << endl;
//     cin >> arrival_time;
//     cout << "Enter number of economy seats: ";
//     cin >> economySeats;
//     cout << "Enter price for economy class: ";
//     cin >> economyPrice;
//     cout << "Enter number of business seats: ";
//     cin >> businessSeats;
//     cout << "Enter price for business class: ";
//     cin >> businessPrice;
//     cout << "Enter number of regular seats: ";
//     cin >> regularSeats;
//     cout << "Enter price for regular class: ";
//     cin >> regularPrice;

//     Cruise newCruise = {id, name, departure_time, arrival_time, economySeats, businessSeats, regularSeats, economyPrice, businessPrice, regularPrice};
//     cruises.push_back(newCruise);
//     cout << "New cruise added successfully." << endl;

//     // Save updated cruise details to file
//     ofstream file("cruise.txt", ios::app); // Append mode
//     if (file.is_open())
//     {
//         file << id << ',' << name << ',' << economySeats << ',' << businessSeats << ',' << regularSeats << ',' << economyPrice << ',' << businessPrice << ',' << regularPrice << '\n';
//         file.close();
//         cout << "Cruise details saved to file." << endl;
//     }
//     else
//     {
//         cout << "Unable to open file to save cruise details." << endl;
//     }
// }

// // Function to delete a cruise (admin-only operation)
// void deleteCruise(vector<Cruise> &cruises)
// {
//     string cruiseId;
//     cout << "Enter cruise ID to delete: ";
//     cin >> cruiseId;

//     auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
//                             { return cruise.id == cruiseId; });

//     if (cruiseIt != cruises.end())
//     {
//         cruises.erase(cruiseIt);
//         cout << "Cruise with ID " << cruiseId << " deleted successfully." << endl;

//         // Save updated cruise details to file after deletion
//         ofstream file("cruise.txt");
//         if (file.is_open())
//         {
//             for (const Cruise &cruise : cruises)
//             {
//                 file << cruise.id << ',' << cruise.name << ',' << cruise.economySeats << ',' << cruise.businessSeats << ',' << cruise.regularSeats << '\n';
//             }
//             file.close();
//             cout << "Cruise details saved to file." << endl;
//         }
//         else
//         {
//             cout << "Unable to open file to save cruise details." << endl;
//         }
//     }
//     else
//     {
//         cout << "Cruise with ID " << cruiseId << " not found." << endl;
//     }
// }

// // Admin menu
// void adminMenu(vector<Cruise> &cruises)
// {
//     char choice;
//     cout << "\nAdmin Menu:\n";
//     cout << "A - Add new cruise\n";
//     cout << "D - Delete cruise\n";
//     cout << "Enter choice: ";
//     cin >> choice;

//     switch (choice)
//     {
//     case 'A':
//         addNewCruise(cruises);
//         break;
//     case 'D':
//         deleteCruise(cruises);
//         break;
//     default:
//         cout << "Invalid choice. Please try again." << endl;
//         break;
//     }
// }
// int main()
// {
//     cout << BLUE << "WELCOME TO KPIT CRUISE BOOKING PORTAL" << RESET << endl;
//     // Read existing cruise details from file
//     vector<Cruise> cruises = readCruisesFromFile("cruise.txt");

//     // Read existing passenger details from file
//     vector<Passenger> passengers = readPassengersFromFile("passenger.txt");

//     char choice;
//     do
//     {
//         cout << "\nOptions:\n";
//         cout << CYAN << "s - Schedule passenger\n";
//         cout << "c - Cancel booking\n";
//         cout << "p - Passenger status\n";
//         cout << "f - Cruise status\n";
//         cout << "N - Admin\n";
//         cout << "q - Quit\n"
//              << RESET;
//         cout << "Enter choice: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 's':
//         {
//             string cruiseId, passengerName, accomodation;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cout << "Select accommodation (economy/business/regular): ";
//             cin >> accomodation;
//             schedulePassenger(cruises, passengers, cruiseId, passengerName, accomodation);
//             break;
//         }
//         case 'f':
//         {
//             string cruiseId;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             getCruiseStatus(cruises, passengers, cruiseId);
//             break;
//         }
//         case 'c':
//         {
//             string cruiseId, passengerName;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cancelBooking(cruises, passengers, cruiseId, passengerName);
//             break;
//         }
//         case 'p':
//         {
//             string passengerName, cruiseId;
//             cout << "Enter passenger name: ";
//             cin >> passengerName;
//             cout << "Enter cruise ID: ";
//             cin >> cruiseId;
//             cout << endl;
//             cout << "The passenger details are as follows: " << endl;
//             getPassengerStatus(passengers, passengerName, cruiseId);
//             break;
//         }
//         case 'N':
//         {
//             string adminPassword;
//             cout << "Enter admin password: ";
//             cin >> adminPassword;
//             if (adminPassword == ADMIN_PASSWORD)
//             {
//                 adminMenu(cruises);
//             }
//             else
//             {
//                 cout << "Invalid admin password." << endl;
//             }
//             break;
//         }
//         case 'q':
//             cout << "Exiting program.\n";
//             break;
//         default:
//             cout << "Invalid choice. Please try again.\n";
//             break;
//         }
//     } while (choice != 'q');

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

const string ADMIN_PASSWORD = "CRUISE123"; // Admin password for adding new cruise

struct Passenger
{
    string name;
    string cruiseId;
    string accomodation;
    int waitListNumber;
};

struct Cruise
{
    string id;
    string name;
    string departure_time;
    string arrival_time;
    string departure_city; 
    string arrival_city;
    int economySeats;
    int businessSeats;
    int regularSeats;
    double economyPrice;
    double businessPrice;
    double regularPrice;
    queue<Passenger> waitingList;
};

vector<Cruise> readCruisesFromFile(const string &filename)
{
    vector<Cruise> cruises;
    ifstream file(filename);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            string id, name, departure_time, arrival_time, departure_city, arrival_city;
            int economySeats, businessSeats, regularSeats;
            double economyPrice, businessPrice, regularPrice;

            if (getline(iss, id, ',') &&
                getline(iss, name, ',') &&
                getline(iss, departure_time, ',') &&
                getline(iss, arrival_time, ',') &&
                getline(iss, departure_city, ',') && 
                getline(iss, arrival_city, ',') &&   
                (iss >> economySeats) &&
                (iss.ignore(), iss >> businessSeats) &&
                (iss.ignore(), iss >> regularSeats) &&
                (iss.ignore(), iss >> economyPrice) &&
                (iss.ignore(), iss >> businessPrice) &&
                (iss.ignore(), iss >> regularPrice))
            {

                Cruise cruise = {id, name, departure_time, arrival_time, departure_city, arrival_city, economySeats, businessSeats, regularSeats, economyPrice, businessPrice, regularPrice};
                cruises.push_back(cruise);
            }
        }
        file.close();
    }

    return cruises;
}

using SeatOccupancy = std::unordered_map<string, int>;
// Function to count the number of occupied seats for each accommodation type
SeatOccupancy countOccupiedSeats(const vector<Passenger> &passengers, const Cruise &cruise)
{
    SeatOccupancy occupancy;

    // Initialize the occupancy counts to zero
    occupancy["economy"] = 0;
    occupancy["business"] = 0;
    occupancy["regular"] = 0;

    // Count the occupied seats based on passenger data
    for (const Passenger &passenger : passengers)
    {
        if (passenger.cruiseId == cruise.id)
        {
            occupancy[passenger.accomodation]++;
        }
    }

    return occupancy;
}

void printSeatStatus(const Cruise &cruise, const SeatOccupancy &occupancy, const vector<Passenger> &passengers)
{
    cout << "Departure City: " << cruise.departure_city << endl;
    cout << "Arrival City: " << cruise.arrival_city << endl;
    cout << "Departure Time: " << cruise.departure_time << endl;
    cout << "Arrival Time: " << cruise.arrival_time << endl;
    cout << "Economy Seats: ";
    for (int i = 1; i <= cruise.economySeats; ++i)
    {
        bool isOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == cruise.id && passenger.accomodation == "economy" && passenger.waitListNumber == i)
            {
                isOccupied = true;
                break;
            }
        }
        if (isOccupied)
        {
            cout << RED << "X " << RESET;
        }
        else
        {
            cout << GREEN << i << " " << RESET; // Print seat number directly
        }
    }
    cout << "\n";

    // Repeat the same process for business and regular seats
    // Business Seats
    cout << "Business Seats: ";
    for (int i = 1; i <= cruise.businessSeats; ++i)
    {
        bool isOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == cruise.id && passenger.accomodation == "business" && passenger.waitListNumber == i)
            {
                isOccupied = true;
                break;
            }
        }
        if (isOccupied)
        {
            cout << RED << "X " << RESET;
        }
        else
        {
            cout << GREEN << i << " " << RESET; // Print seat number directly
        }
    }
    cout << "\n";

    // Regular Seats
    cout << "Regular Seats: ";
    for (int i = 1; i <= cruise.regularSeats; ++i)
    {
        bool isOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == cruise.id && passenger.accomodation == "regular" && passenger.waitListNumber == i)
            {
                isOccupied = true;
                break;
            }
        }
        if (isOccupied)
        {
            cout << RED << "X " << RESET;
        }
        else
        {
            cout << GREEN << i << " " << RESET; // Print seat number directly
        }
    }
    cout << "\n";
}

void getCruiseStatus(const vector<Cruise> &cruises, const vector<Passenger> &passengers, const string &cruiseId)
{
    auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
                            { return cruise.id == cruiseId; });

    if (cruiseIt != cruises.end())
    {
        const Cruise &cruise = *cruiseIt;

        // Count occupied seats for the current cruise
        SeatOccupancy occupancy = countOccupiedSeats(passengers, cruise);

        // Print the status of seats
        printSeatStatus(cruise, occupancy, passengers); // Pass all three arguments

        cout << "Waiting List: ";
        queue<Passenger> tempQueue = cruise.waitingList;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front().name << " ";
            tempQueue.pop();
        }
        cout << "\n";
    }
    else
    {
        cout << "Cruise with ID " << cruiseId << " not found." << endl;
    }
}

// Function to read passenger details from a file
vector<Passenger> readPassengersFromFile(const string &filename)
{
    vector<Passenger> passengers;
    ifstream file(filename);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            string name, cruiseId, accomodation;
            int waitListNumber;

            if (getline(iss, name, ',') &&
                getline(iss, cruiseId, ',') &&
                getline(iss, accomodation, ',') &&
                (iss >> waitListNumber))
            {

                Passenger passenger = {name, cruiseId, accomodation, waitListNumber};
                passengers.push_back(passenger);
            }
        }
        file.close();
    }

    return passengers;
}

// Function to save passenger details to a file

void savePassengersToFile(const vector<Passenger> &passengers, const string &filename)
{
    ofstream file(filename);

    if (file.is_open())
    {
        for (const Passenger &passenger : passengers)
        {
            file << passenger.name << ',' << passenger.cruiseId << ',' << passenger.accomodation << ',' << passenger.waitListNumber << '\n';
        }
        file.close();
        cout << "Passenger details saved to " << filename << " successfully." << endl;
    }
    else
    {
        cout << "Unable to open " << filename << " for writing." << endl;
    }
}

void schedulePassenger(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &passengerName, const string &accommodation)
{
    string departureCity, arrivalCity;

    cout << "Enter departure city: ";
    cin >> departureCity;
    cout << "Enter arrival city: ";
    cin >> arrivalCity;

    vector<Cruise> matchingCruises;
    for (const Cruise &cruise : cruises)
    {
        if (cruise.departure_city == departureCity && cruise.arrival_city == arrivalCity)
        {
            matchingCruises.push_back(cruise);
        }
    }

    if (matchingCruises.empty())
    {
        cout << "No cruises available for the specified route." << endl;
        return;
    }

    cout << "Available Cruises:" << endl;
    for (const Cruise &cruise : matchingCruises)
    {
        cout << "Cruise ID: " << cruise.id << ", Name: " << cruise.name << ", Departure Time: " << cruise.departure_time << ", Arrival Time: " << cruise.arrival_time <<", Business: Rs."<<cruise.businessPrice<<", Economy: Rs."<<cruise.economyPrice<<", Regular: Rs."<<cruise.regularPrice<< endl;
    }

    string selectedCruiseId;
    cout << "Enter the Cruise ID to schedule the passenger: ";
    cin >> selectedCruiseId;

    auto cruiseIt = find_if(matchingCruises.begin(), matchingCruises.end(), [selectedCruiseId](const Cruise &cruise)
                            { return cruise.id == selectedCruiseId; });

    if (cruiseIt != matchingCruises.end())
    {
        Cruise &cruise = *cruiseIt;

        cout << "Economy Seats: ";
    for (int i = 1; i <= cruise.economySeats; ++i)
    {
        bool isOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == cruise.id && passenger.accomodation == "economy" && passenger.waitListNumber == i)
            {
                isOccupied = true;
                break;
            }
        }
        if (isOccupied)
        {
            cout << RED << "X " << RESET;
        }
        else
        {
            cout << GREEN << i << " " << RESET; // Print seat number directly
        }
    }
    cout << "\n";

    // Repeat the same process for business and regular seats
    // Business Seats
    cout << "Business Seats: ";
    for (int i = 1; i <= cruise.businessSeats; ++i)
    {
        bool isOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == cruise.id && passenger.accomodation == "business" && passenger.waitListNumber == i)
            {
                isOccupied = true;
                break;
            }
        }
        if (isOccupied)
        {
            cout << RED << "X " << RESET;
        }
        else
        {
            cout << GREEN << i << " " << RESET; // Print seat number directly
        }
    }
    cout << "\n";

    // Regular Seats
    cout << "Regular Seats: ";
    for (int i = 1; i <= cruise.regularSeats; ++i)
    {
        bool isOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == cruise.id && passenger.accomodation == "regular" && passenger.waitListNumber == i)
            {
                isOccupied = true;
                break;
            }
        }
        if (isOccupied)
        {
            cout << RED << "X " << RESET;
        }
        else
        {
            cout << GREEN << i << " " << RESET; // Print seat number directly
        }
    }
    cout << "\n";

        int selectedSeat;
        cout << "Enter the seat number you want to book: ";
        cin >> selectedSeat;

        
        // Check if the selected seat is within the valid range
        int maxSeats;
        if (accommodation == "economy")
        {
            maxSeats = cruise.economySeats;
        }
        else if (accommodation == "business")
        {
            maxSeats = cruise.businessSeats;
        }
        else if (accommodation == "regular")
        {
            maxSeats = cruise.regularSeats;
        }

        if (selectedSeat < 1 || selectedSeat > maxSeats)
        {
            cout << "Invalid seat number. Please choose a seat within the valid range." << endl;
            return;
        }

        // Check if the selected seat is available
        bool seatOccupied = false;
        for (const Passenger &passenger : passengers)
        {
            if (passenger.cruiseId == selectedCruiseId && passenger.accomodation == accommodation && passenger.waitListNumber == selectedSeat)
            {
                seatOccupied = true;
                break;
            }
        }

        if (seatOccupied)
        {
            cout << "Seat " << selectedSeat << " is already occupied. Please choose another seat." << endl;
            return;
        }

        // Book the selected seat
        Passenger newPassenger = {passengerName, selectedCruiseId, accommodation, selectedSeat};
        passengers.push_back(newPassenger);
        cout << "Passenger scheduled successfully for seat " << selectedSeat << " on Cruise ID: " << selectedCruiseId << "." << endl;
        savePassengersToFile(passengers, "passenger.txt"); // Save updated passenger details to file
    }
    else
    {
        cout << "Invalid Cruise ID. Please try again." << endl;
    }
}



void cancelBooking(vector<Cruise> &cruises, vector<Passenger> &passengers, const string &cruiseId, int seatNumber)
{
    auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
                            { return cruise.id == cruiseId; });

    if (cruiseIt != cruises.end())
    {
        Cruise &cruise = *cruiseIt;

        auto passengerIt = remove_if(passengers.begin(), passengers.end(), [cruiseId, seatNumber](const Passenger &passenger)
                                     { return passenger.cruiseId == cruiseId && passenger.waitListNumber == seatNumber; });

        if (passengerIt != passengers.end())
        {
            passengers.erase(passengerIt, passengers.end());

            // Refund the seat
            if (passengerIt->accomodation == "economy")
            {
                cruise.economySeats++;
            }
            else if (passengerIt->accomodation == "business")
            {
                cruise.businessSeats++;
            }
            else if (passengerIt->accomodation == "regular")
            {
                cruise.regularSeats++;
            }

            // Check waiting list and fill the seat
            if (!cruise.waitingList.empty())
            {
                Passenger waitingPassenger = cruise.waitingList.front();
                cruise.waitingList.pop();
                passengers.erase(remove_if(passengers.begin(), passengers.end(),
                                           [waitingPassenger](const Passenger &p)
                                           { return p.name == waitingPassenger.name && p.cruiseId == waitingPassenger.cruiseId; }),
                                 passengers.end());
                schedulePassenger(cruises, passengers, waitingPassenger.name, waitingPassenger.accomodation);
            }

            cout << "Booking canceled successfully." << endl;

            // Save updated passenger details to file after cancellation
            savePassengersToFile(passengers, "passenger.txt");
        }
        else
        {
            cout << "No passenger found with the given seat number on cruise " << cruiseId << "." << endl;
        }
    }
    else
    {
        cout << "Cruise with ID " << cruiseId << " not found." << endl;
    }
}

// Function to get passenger status
void getPassengerStatus(const vector<Passenger> &passengers, const string &passengerName, const string &cruiseId)
{
    auto passengerIt = find_if(passengers.begin(), passengers.end(), [passengerName, cruiseId](const Passenger &passenger)
                               { return passenger.name == passengerName && passenger.cruiseId == cruiseId; });

    if (passengerIt != passengers.end())
    {
        const Passenger &passenger = *passengerIt;

        cout << "Passenger Name: " << passenger.name << "\n";
        cout << "Cruise ID: " << passenger.cruiseId << "\n";
        cout << "Accomodation: " << passenger.accomodation << "\n";

        if (passenger.waitListNumber != 0)
        {
            cout << "Waiting List Number: " << passenger.waitListNumber << "\n";
        }
        else
        {
            cout << "Ticket Confirmed\n";
        }
    }
    else
    {
        cout << "Passenger " << passengerName << " not found on cruise " << cruiseId << "." << endl;
    }
}

void addNewCruise(vector<Cruise> &cruises)
{
    string id, name, departure_time, arrival_time, departure_city, arrival_city;
    int economySeats, businessSeats, regularSeats;
    double economyPrice, businessPrice, regularPrice;

    cout << "Enter new cruise ID: ";
    cin >> id;
    cout << "Enter new cruise name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter Departure Time: ";
    cin >> departure_time;
    cout << "Enter Arrival Time: ";
    cin >> arrival_time;
    cout << "Enter Departure City: ";
    cin >> departure_city;
    cout << "Enter Arrival City: ";
    cin >> arrival_city;
    cout << "Enter number of economy seats: ";
    cin >> economySeats;
    cout << "Enter price for economy class: ";
    cin >> economyPrice;
    cout << "Enter number of business seats: ";
    cin >> businessSeats;
    cout << "Enter price for business class: ";
    cin >> businessPrice;
    cout << "Enter number of regular seats: ";
    cin >> regularSeats;
    cout << "Enter price for regular class: ";
    cin >> regularPrice;

    Cruise newCruise = {id, name, departure_time, arrival_time, departure_city, arrival_city, economySeats, businessSeats, regularSeats, economyPrice, businessPrice, regularPrice};
    cruises.push_back(newCruise);

    // Save the new cruise details to the file
    ofstream file("cruise.txt", ios::app);
    if (file.is_open())
    {
        file << id << ',' << name << ',' << departure_time << ',' << arrival_time << ',' << departure_city << ',' << arrival_city << ',' << economySeats << ',' << businessSeats << ',' << regularSeats << ',' << economyPrice << ',' << businessPrice << ',' << regularPrice << '\n';
        file.close();
        cout << "Cruise details saved to file." << endl;
    }
    else
    {
        cout << "Unable to open file to save cruise details." << endl;
    }
}

// Function to delete a cruise (admin-only operation)
void deleteCruise(vector<Cruise> &cruises)
{
    string cruiseId;
    cout << "Enter cruise ID to delete: ";
    cin >> cruiseId;

    auto cruiseIt = find_if(cruises.begin(), cruises.end(), [cruiseId](const Cruise &cruise)
                            { return cruise.id == cruiseId; });

    if (cruiseIt != cruises.end())
    {
        cruises.erase(cruiseIt);
        cout << "Cruise with ID " << cruiseId << " deleted successfully." << endl;

        // Save updated cruise details to file after deletion
        ofstream file("cruise.txt");
        if (file.is_open())
        {
            for (const Cruise &cruise : cruises)
            {
                file << cruise.id << ',' << cruise.name << ',' << cruise.economySeats << ',' << cruise.businessSeats << ',' << cruise.regularSeats << '\n';
            }
            file.close();
            cout << "Cruise details saved to file." << endl;
        }
        else
        {
            cout << "Unable to open file to save cruise details." << endl;
        }
    }
    else
    {
        cout << "Cruise with ID " << cruiseId << " not found." << endl;
    }
}

// Admin menu
void adminMenu(vector<Cruise> &cruises)
{
    char choice;
    cout << "\nAdmin Menu:\n";
    cout << "A - Add new cruise\n";
    cout << "D - Delete cruise\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 'A':
        addNewCruise(cruises);
        break;
    case 'D':
        deleteCruise(cruises);
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}
int main()
{
    cout << BLUE << "WELCOME TO KPIT CRUISE BOOKING PORTAL" << RESET << endl;
    // Read existing cruise details from file
    vector<Cruise> cruises = readCruisesFromFile("cruise.txt");

    // Read existing passenger details from file
    vector<Passenger> passengers = readPassengersFromFile("passenger.txt");

    char choice;
    do
    {
        cout << "\nOptions:\n";
        cout << CYAN << "s - Schedule passenger\n";
        cout << "c - Cancel booking\n";
        cout << "p - Passenger status\n";
        cout << "f - Cruise status\n";
        cout << "N - Admin\n";
        cout << "q - Quit\n"
             << RESET;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 's':
        {
            string cruiseId, passengerName, accomodation;
            // cout << "Enter cruise ID: ";
            // cin >> cruiseId;
            cout << "Enter passenger name: ";
            cin >> passengerName;
            cout << "Select accommodation (economy/business/regular): ";
            cin >> accomodation;
            // schedulePassenger(cruises, passengers, cruiseId, passengerName, accomodation);
            schedulePassenger(cruises, passengers, passengerName, accomodation);

            break;
        }
        case 'f':
        {
            string cruiseId;
            cout << "Enter cruise ID: ";
            cin >> cruiseId;
            getCruiseStatus(cruises, passengers, cruiseId);
            break;
        }
        case 'c':
        {
            string cruiseId;
            int seatNumber;
            cout << "Enter cruise ID: ";
            cin >> cruiseId;
            cout << "Enter seat number: ";
            cin >> seatNumber;
            cancelBooking(cruises, passengers, cruiseId, seatNumber);
            break;
        }
        case 'p':
        {
            string passengerName, cruiseId;
            cout << "Enter passenger name: ";
            cin >> passengerName;
            cout << "Enter cruise ID: ";
            cin >> cruiseId;
            cout << endl;
            cout << "The passenger details are as follows: " << endl;
            getPassengerStatus(passengers, passengerName, cruiseId);
            break;
        }
        case 'N':
        {
            string adminPassword;
            cout << "Enter admin password: ";
            cin >> adminPassword;
            if (adminPassword == ADMIN_PASSWORD)
            {
                adminMenu(cruises);
            }
            else
            {
                cout << "Invalid admin password." << endl;
            }
            break;
        }
        case 'q':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 'q');

    return 0;
}
