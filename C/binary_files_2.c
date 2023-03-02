#include <stdio.h>
#include <stdlib.h>

// Define bool type with standard true/false values
typedef enum
{
    false,
    true
} bool;

typedef unsigned int uint;

// Define Seat struct
typedef struct
{
    bool isOccupied;
    uint seatNumber;
} Seat;

int resetSeats(char *fileName, uint size);
int printSeats(char *fileName, uint size);
int reserveSeat(char *fileName, uint seatNumber, uint size);
int emptySeat(char *fileName, uint seatNumber, uint size);

// Driver function
int main()
{
    // Name of binary file
    char *fileName = "seats.dat";

    // Number of seats in the file
    uint size = 10;

    // Print status of all seats
    printSeats(fileName, size);

    // Initialize binary file
    resetSeats(fileName, size);

    // Print status of all seats
    printSeats(fileName, size);

    // Reserve seat 5
    reserveSeat(fileName, 5, size);

    // Reserve seat 7
    reserveSeat(fileName, 7, size);

    // Print status of all seats
    printSeats(fileName, size);

    // Empty seat 5
    emptySeat(fileName, 5, size);

    // Print status of all seats
    printSeats(fileName, size);

    // Return success
    return 0;
}

// Function to initialize binary file with empty seats
int resetSeats(char *fileName, uint size)
{
    // Open file for writing binary data
    FILE *fp = fopen(fileName, "wb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Initialize Seat struct with isOccupied = false
    Seat seat = {false, 0};

    // Write empty seats to file
    for (uint i = 0; i < size; i++)
    {
        seat.seatNumber = i;
        fwrite(&seat, sizeof(Seat), 1, fp);
    }

    // Close file
    fclose(fp);

    // Print success message
    printf("Seats have been reset\n");

    // Return success
    return 0;
}

// Function to print the status of all seats in the binary file
int printSeats(char *fileName, uint size)
{
    // Open file for reading binary data
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Print header
    printf("Seat Status:\n");

    // Read and print each Seat struct in the file
    Seat seat;
    for (uint i = 0; i < size; i++)
    {
        fread(&seat, sizeof(Seat), 1, fp);
        printf("Seat %d: %s\n", seat.seatNumber, seat.isOccupied ? "Occupied" : "Empty");
    }

    // Print footer
    printf("-------------------------\n");

    // Close file
    fclose(fp);

    // Return success
    return 0;
}

// Function to reserve a seat in the binary file
int reserveSeat(char *fileName, uint seatNumber, uint size)
{
    // Open file for read/write binary data
    FILE *fp = fopen(fileName, "r+b");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Move file pointer to desired Seat struct
    fseek(fp, sizeof(Seat) * seatNumber, SEEK_SET);

    // Read Seat struct from file
    Seat seat;
    fread(&seat, sizeof(Seat), 1, fp);

    // Check if seat is already occupied
    if (seat.isOccupied)
    {
        printf("Seat %d is already occupied\n", seatNumber);

        // Close file
        fclose(fp);

        // Return failure
        return 1;
    }

    // Reserve seat by setting isOccupied to true
    seat.isOccupied = true;

    // Move file pointer back to desired Seat struct
    fseek(fp, sizeof(Seat) * seatNumber, SEEK_SET);

    // Write updated Seat struct to file
    fwrite(&seat, sizeof(Seat), 1, fp);

    // Close file
    fclose(fp);

    // Print success message
    printf("Seat %d has been reserved\n", seatNumber);

    // Return success
    return 0;
}

// Function to empty a reserved seat in the binary file
int emptySeat(char *fileName, uint seatNumber, uint size)
{
    // Open file for read/write binary data
    FILE *fp = fopen(fileName, "r+b");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Move file pointer to desired Seat struct
    fseek(fp, sizeof(Seat) * seatNumber, SEEK_SET);

    // Read Seat struct from file
    Seat seat;
    fread(&seat, sizeof(Seat), 1, fp);

    // Check if seat is already empty
    if (!seat.isOccupied)
    {
        printf("Seat %d is already empty\n", seatNumber);

        // Close file
        fclose(fp);

        // Return failure
        return 1;
    }

    // Empty seat by setting isOccupied to false
    seat.isOccupied = false;

    // Move file pointer back to desired Seat struct
    fseek(fp, sizeof(Seat) * seatNumber, SEEK_SET);

    // Write updated Seat struct to file
    fwrite(&seat, sizeof(Seat), 1, fp);

    // Close file
    fclose(fp);

    // Print success message
    printf("Seat %d has been emptied\n", seatNumber);

    // Return success
    return 0;
}
