/**
 * @file ticket.cpp
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief Ticket system in C++
 * @version 1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <list>
#include <unistd.h>
#include "class.hh"
#include "function.hh"

/**
 * main entry point of the program.
 * @param[in] argc Number of command line arguments.
 * @param[in] argv An array of pointers to null terminated arrays of characters (command line arguments).
 * @param[out] returns 0 on success.
 */
int main(int argc, char **argv)
{
    /**
     * @brief Declare variables
     */
    char *flightFile = NULL;
    char *bookingFile = NULL;
    int opt;

    /**
     * @brief Get file names with getopt function
     * -f flight file name
     * -b booking file name
     */
    while ((opt = getopt(argc, argv, "f:b:?")) != -1)
    {
        switch (opt)
        {
        case 'f':
            flightFile = optarg;
            break;
        case 'b':
            bookingFile = optarg;
            break;
        case '?':
            std::cout << "Usage: " << argv[0] << "\n\t-f {Flight-file.csv}\n\t-b {Booking-file.csv}" << std::endl;
            exit(-1);
            break;
        default:
            std::cout << "Usage: " << argv[0] << "\n\t-f {Flight-file.csv}\n\t-b {Booking-file.csv}" << std::endl;
            exit(-1);
            break;
        }
    }

    /**
     * @brief Declare flight list and booking list
     */
    std::list<flights *> flightList;
    std::list<bookings *> bookingList;

    std::cout << "Checking flights...\n";
    /**
     * @brief Call funtion fillFlightList
     * @param[in] flightFile Name of flight file
     * @param[in] flightList Flight list
     */
    fillFlightList(flightFile, &flightList);
    std::cout << "Checking bookings...\n";
    /**
     * @brief Call function fillBookingList
     * @param[in] bookingFile Name of booking file
     * @param[in] bookingList Booking list
     */
    fillBookingList(bookingFile, &bookingList);
    std::cout << "Reserving seating...\nPrinting out flight tickets...\n";
    /**
     * @brief Call function printTicket
     * @param[in] flightList Flight list
     * @param[in] bookingList Booking list
     */
    printTickets(flightList, bookingList);
    std::cout << "Canceling flights with no passengers...\n";
    /**
     * @brief Call function cancelFlights
     * @param[in] flightList Flight list
     */
    cancelFlights(flightList);
    std::cout << "Printing out seating report for remaining flights...\n";
    /**
     * @brief Call function seatingChart
     * @param[in] flightList Flight list
     */
    seatingChart(flightList);

    return 0;
}