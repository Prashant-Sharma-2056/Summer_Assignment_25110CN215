// WAP to Create Ticket Booking System
#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 5
#define MAX_BOOKINGS 25

struct Booking {
    int ticket_id;
    char customer_name[50];
    int row;
    int col;
};

int seats[ROWS][COLS] = {0};
struct Booking history[MAX_BOOKINGS];
int booking_count = 0;
int next_ticket_id = 101;


// 1. Function to display the 2D visual seat layout
void displaySeats() {
    printf("\n      --- SCREEN THIS WAY ---      \n\n");
    printf("     ");
    for (int j = 0; j < COLS; j++) {
        printf("[Col %d] ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("[Row %d]  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                printf("  [A]   "); // [A] stands for Available
            } else {
                printf("  [X]   "); // [X] stands for Booked
            }
        }
        printf("\n");
    }
    printf("\nLegend: [A] = Available, [X] = Booked\n");
}

// 2. Function to process a new ticket reservation
void bookTicket() {
    if (booking_count >= MAX_BOOKINGS) {
        printf("\nError: House full! No further reservations can be processed.\n");
        return;
    }

    struct Booking b;
    int r, c;

    printf("\nEnter Customer Name (No spaces): ");
    scanf("%s", b.customer_name);

    displaySeats();

    // Loop for row selection validation
    while (1) {
        printf("Select Row (1-%d): ", ROWS);
        if (scanf("%d", &r) == 1 && r >= 1 && r <= ROWS) break;
        printf("Invalid Row selection.\n");
        while (getchar() != '\n');
    }

    // Loop for column selection validation
    while (1) {
        printf("Select Column (1-%d): ", COLS);
        if (scanf("%d", &c) == 1 && c >= 1 && c <= COLS) break;
        printf("Invalid Column selection.\n");
        while (getchar() != '\n');
    }

    // Adjust 1-based user choice to 0-based array index logic
    b.row = r - 1;
    b.col = c - 1;

    // Check availability constraints
    if (seats[b.row][b.col] == 1) {
        printf("\nBooking Failed: Seat at Row %d, Column %d is already taken!\n", r, c);
        return;
    }

    // Commit seat matrix allocation state change
    seats[b.row][b.col] = 1;
    
    // Finalize structural transaction records
    b.ticket_id = next_ticket_id++;
    history[booking_count] = b;
    booking_count++;

    printf("\nReservation Confirmed Successfully!\n");
    printf("Ticket ID: %d | Customer: %s | Assigned Seat: Row %d, Col %d\n", b.ticket_id, b.customer_name, r, c);
}

// 3. Function to display overall system ledger states
void viewBookings() {
    if (booking_count == 0) {
        printf("\nNo booking transactions found in system storage.\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-12s %-25s %-12s\n", "Ticket ID", "Customer Name", "Seat (Row,Col)");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < booking_count; i++) {
        printf("%-12d %-25s Row %d, Col %d\n", 
               history[i].ticket_id, 
               history[i].customer_name, 
               history[i].row + 1, 
               history[i].col + 1);
    }
    printf("------------------------------------------------------------\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("       TICKET BOOKING SYSTEM         \n");
        printf("=====================================\n");
        printf("1. View Seat Matrix Layout\n");
        printf("2. Book a Ticket\n");
        printf("3. View Reservation History\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: displaySeats(); break;
            case 2: bookTicket(); break;
            case 3: viewBookings(); break;
            case 4: printf("\nClosing reservation system. Goodbye!\n"); return 0;
            default: printf("Invalid option. Please pick between 1 and 4.\n");
        }
    }
    return 0;
}
