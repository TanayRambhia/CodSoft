#include <iostream>

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const double TICKET_PRICE = 10.0;

char seatMap[NUM_ROWS][NUM_COLS];

void initializeSeatMap() {
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            seatMap[row][col] = '-';
        }
    }
}

void displaySeatMap() {
    std::cout << "\n--- Seat Map ---\n";
    std::cout << "   ";
    for (int col = 0; col < NUM_COLS; ++col) {
        std::cout << col + 1 << ' ';
    }
    std::cout << '\n';

    for (int row = 0; row < NUM_ROWS; ++row) {
        std::cout << row + 1 << ' ';
        for (int col = 0; col < NUM_COLS; ++col) {
            std::cout << seatMap[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

bool isValidSeat(int row, int col) {
    return row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seatMap[row][col] == '-';
}

void bookSeat(int row, int col) {
    seatMap[row][col] = 'X';
    std::cout << "Seat booked successfully!\n";
}

double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

int main() {
    std::cout << "Welcome to the Movie Ticket Booking System!\n";
    initializeSeatMap();

    while (true) {
        std::cout << "\n--- Menu ---\n";
        std::cout << "1. View movie listings\n";
        std::cout << "2. Book tickets\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                displaySeatMap();
                break;
            case 2: {
                int row, col, numTickets;
                std::cout << "\nEnter the row and column numbers of the seat: ";
                std::cin >> row >> col;

                if (isValidSeat(row - 1, col - 1)) {
                    std::cout << "Enter the number of tickets: ";
                    std::cin >> numTickets;

                    if (numTickets > 0) {
                        bookSeat(row - 1, col - 1);
                        double totalCost = calculateTotalCost(numTickets);
                        std::cout << "Total cost: $" << totalCost << std::endl;
                    } else {
                        std::cout << "Invalid number of tickets. Please try again.\n";
                    }
                } else {
                    std::cout << "Invalid seat selection. Please try again.\n";
                }
                break;
            }
            case 3:
                std::cout << "\nThank you for using the Movie Ticket Booking System. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
