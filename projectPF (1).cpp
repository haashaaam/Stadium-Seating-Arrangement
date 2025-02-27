#include <iostream>
#include <string>
using namespace std;

// Constants for seat types and total seats
const int VIP_SEATS = 10;
const int REGULAR_SEATS = 15;
const int ECONOMY_SEATS = 20;

// Structure to hold ticket holder details
struct TicketHolder 
{
    string name;      // Name of the ticket holder
    int age;          // Age of the ticket holder
    string uid;       // Unique identifier for the ticket holder
    bool isFamily;    // Whether the ticket holder is coming with family
};

// Arrays to represent seating arrangements for different seat types
TicketHolder vipSeats[VIP_SEATS];
TicketHolder regularSeats[REGULAR_SEATS];
TicketHolder economySeats[ECONOMY_SEATS];

// Function declarations
void displaySeatingArrangements();
void bookSeat();
void displaySeatDetails();

int main() 
{
    int choice;
    do {
        // Display the menu options
        cout << "\n--- Stadium Seating Management ---\n";
        cout << "1. Book a Seat\n";
        cout << "2. Display Seating Arrangements\n";
        cout << "3. Display Seat Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) 
        {
            case 1:
                bookSeat();  // Call function to book a seat
                break;
            case 2:
                displaySeatingArrangements();  // Call function to display seating arrangements
                break;
            case 3:
                displaySeatDetails();  // Call function to display seat details
                break;
            case 4:
                cout << "Exiting program.\n";  // Exit the program
                break;
            default:
                cout << "Invalid choice! Please try again.\n";  // Invalid input
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}

// Function to book a seat
void bookSeat() 
{
    int type;
    cout << "\nSelect Seat Type:\n";
    cout << "1. VIP\n2. Regular\n3. Economy\n";
    cout << "Enter your choice: ";
    cin >> type;

    int seatIndex = -1;
    TicketHolder *seats;
    int totalSeats;

    // Determine the seat type and total seats based on user input
    switch (type)
    {
        case 1:
            seats = vipSeats;
            totalSeats = VIP_SEATS;
            break;
        case 2:
            seats = regularSeats;
            totalSeats = REGULAR_SEATS;
            break;
        case 3:
            seats = economySeats;
            totalSeats = ECONOMY_SEATS;
            break;
        default:
            cout << "Invalid seat type!\n";  // Invalid seat type input
            return;
    }

    // Find the first available seat
    for (int i = 0; i < totalSeats; i++) 
    {
        if (seats[i].name.empty()) 
        {
            seatIndex = i;
            break;
        }
    }

    // If no seat is available, inform the user
    if (seatIndex == -1) 
    {
        cout << "No available seats in the selected category.\n";
        return;
    }

    // Collect ticket holder details
    TicketHolder holder;
    cout << "Enter ticket holder name: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, holder.name);
    cout << "Enter age: ";
    cin >> holder.age;
    cout << "Enter UID: ";
    cin >> holder.uid;
    cout << "Is the ticket holder coming with family? (1 for Yes, 0 for No): ";
    cin >> holder.isFamily;

    // Book the seat by assigning the details to the selected seat
    seats[seatIndex] = holder;
    cout << "Seat booked successfully at index " << seatIndex + 1 << "!\n";
}

// Function to display seating arrangements
void displaySeatingArrangements() 
{
    cout << "\n--- Seating Arrangements ---\n";

    // Display VIP seat status
    cout << "VIP Seats:\n";
    for (int i = 0; i < VIP_SEATS; i++) 
    {
        cout << (vipSeats[i].name.empty() ? "[Empty]" : "[Booked]") << " ";
        if ((i + 1) % 5 == 0) cout << "\n";  // Format output in rows of 5 seats
    }

    // Display Regular seat status
    cout << "\nRegular Seats:\n";
    for (int i = 0; i < REGULAR_SEATS; i++) 
    {
        cout << (regularSeats[i].name.empty() ? "[Empty]" : "[Booked]") << " ";
        if ((i + 1) % 5 == 0) cout << "\n";  // Format output in rows of 5 seats
    }

    // Display Economy seat status
    cout << "\nEconomy Seats:\n";
    for (int i = 0; i < ECONOMY_SEATS; i++) 
    {
        cout << (economySeats[i].name.empty() ? "[Empty]" : "[Booked]") << " ";
        if ((i + 1) % 5 == 0) cout << "\n";  // Format output in rows of 5 seats
    }
    cout << "\n";
}

// Function to display details of a specific seat
void displaySeatDetails() 
{
    int type, index;
    cout << "\nSelect Seat Type:\n";
    cout << "1. VIP\n2. Regular\n3. Economy\n";
    cout << "Enter your choice: ";
    cin >> type;

    cout << "Enter seat index (1-based): ";
    cin >> index;
    index--; // Convert to 0-based index

    TicketHolder *seats;
    int totalSeats;

    // Determine the seat type and total seats based on user input
    switch (type) 
    {
        case 1:
            seats = vipSeats;
            totalSeats = VIP_SEATS;
            break;
        case 2:
            seats = regularSeats;
            totalSeats = REGULAR_SEATS;
            break;
        case 3:
            seats = economySeats;
            totalSeats = ECONOMY_SEATS;
            break;
        default:
            cout << "Invalid seat type!\n";  // Invalid seat type input
            return;
    }

    // Check if the provided seat index is valid
    if (index < 0 || index >= totalSeats) 
    {
        cout << "Invalid seat index!\n";  // Invalid seat index input
        return;
    }

    // Display seat details if the seat is booked
    if (seats[index].name.empty()) 
    {
        cout << "Seat is empty.\n";  // If the seat is empty, inform the user
    } 
    else 
    {
        cout << "\n--- Seat Details ---\n";
        cout << "Name: " << seats[index].name << "\n";
        cout << "Age: " << seats[index].age << "\n";
        cout << "UID: " << seats[index].uid << "\n";
        cout << "Family: " << (seats[index].isFamily ? "Yes" : "No") << "\n";
    }
}
