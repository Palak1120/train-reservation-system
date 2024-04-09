#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class TrainReservationSystem {
private:
    map<int, int> availableSeats; // Map to store available seats for each train

public:
    TrainReservationSystem() {
        // Initialize available seats for each train
        availableSeats[1] = 50;
        availableSeats[2] = 50;
        availableSeats[3] = 50;
    }

    void displayAvailableSeats() {
        cout << "Available Seats:" << endl;
        for (const auto& pair : availableSeats) {
            cout << "Train " << pair.first << ": " << pair.second << " seats" << endl;
        }
    }

    void bookTicket(int trainNumber, int numTickets) {
        if (availableSeats.find(trainNumber) != availableSeats.end()) {
            if (availableSeats[trainNumber] >= numTickets) {
                availableSeats[trainNumber] -= numTickets;
                cout << numTickets << " ticket(s) booked successfully for Train " << trainNumber << endl;
            } else {
                cout << "Insufficient seats available for Train " << trainNumber << endl;
            }
        } else {
            cout << "Invalid Train Number" << endl;
        }
    }

    void cancelTicket(int trainNumber, int numTickets) {
        if (availableSeats.find(trainNumber) != availableSeats.end()) {
            availableSeats[trainNumber] += numTickets;
            cout << numTickets << " ticket(s) canceled successfully for Train " << trainNumber << endl;
        } else {
            cout << "Invalid Train Number" << endl;
        }
    }
};

int main() {
    TrainReservationSystem trainSystem;

    int choice, trainNumber, numTickets;

    do {
        cout << "\nTrain Reservation System" << endl;
        cout << "1. Display Available Seats" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Cancel Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                trainSystem.displayAvailableSeats();
                break;
            case 2:
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cout << "Enter Number of Tickets: ";
                cin >> numTickets;
                trainSystem.bookTicket(trainNumber, numTickets);
                break;
            case 3:
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cout << "Enter Number of Tickets: ";
                cin >> numTickets;
                trainSystem.cancelTicket(trainNumber, numTickets);
                break;
            case 4:
                cout << "Exiting Program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
