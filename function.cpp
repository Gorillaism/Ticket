/**
 * @file function.cpp
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief Functions definition
 * @version 1.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "function.hh"
#include "class.hh"

/**
 * @brief Function to fill flight list
 * @param[in] file Name of flight file
 * @param[in] List Flight list to fill
 */
void fillFlightList(std::string file, std::list<flights *> *List)
{
    // Open file to read from
    std::ifstream flightFile(file);
    // Declare string
    std::string filedata;

    if (flightFile.is_open())
    {
        // Get line from file to string
        while (getline(flightFile, filedata) && !filedata.empty())
        {
            // Declare new object
            flights *newFlight = new flights;
            // Stringstream string
            std::stringstream data(filedata);
            // Declare temp string
            std::string temp;
            // Get line from stringstream up to a comma
            getline(data, temp, ',');
            // Declare int and convert string to int
            int tempN = atoi(temp.c_str());
            // Call method
            newFlight->setFlightN(tempN);

            getline(data, temp, ',');
            newFlight->setDepart(temp);
            getline(data, temp, ',');
            newFlight->setArrive(temp);
            getline(data, temp, ',');
            newFlight->setDate(temp);
            getline(data, temp, ',');
            newFlight->setTime(temp);

            getline(data, temp, ',');
            tempN = atoi(temp.c_str());
            newFlight->setFSeats(tempN);

            getline(data, temp, ',');
            tempN = atoi(temp.c_str());
            newFlight->setBSeats(tempN);

            getline(data, temp, ',');
            tempN = atoi(temp.c_str());
            newFlight->setESeats(tempN);

            getline(data,temp, '-');
            tempN = atoi(temp.c_str());
            newFlight->setSec1(tempN);
            getline(data,temp, '-');
            tempN = atoi(temp.c_str());
            newFlight->setSec2(tempN);
            getline(data,temp);
            tempN = atoi(temp.c_str());
            newFlight->setSec3(tempN);

            newFlight->setCurrentSeats();
            // Add to the list
            List->push_back(newFlight);
        }
        // Close file
        flightFile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

/**
 * @brief Function to fill booking list
 * @param[in] file Name of file
 * @param[in] List Booking list to fill
 */
void fillBookingList(std::string file, std::list<bookings *> *List)
{
    // Open file to read from
    std::ifstream bookingFile(file);
    // Declare sting
    std::string filedata;

    if (bookingFile.is_open())
    {
        // Get line from file to string
        while (getline(bookingFile, filedata) && !filedata.empty())
        {
            // Declare new object
            bookings *newBooking = new bookings;
            // Stringstream string
            std::stringstream data(filedata);
            // Declare temp string
            std::string temp;
            // Get line from stringstream up to a comma
            getline(data, temp, ',');
            // Declare int and convert string to int
            int tempN = atoi(temp.c_str());
            // Call method
            newBooking->setBookingN(tempN);

            getline(data, temp, ',');
            newBooking->setDate(temp);
            getline(data, temp, ',');
            newBooking->setTime(temp);
            getline(data, temp, ',');
            newBooking->setDepart(temp);
            getline(data, temp, ',');
            newBooking->setArrive(temp);
            getline(data, temp, ',');
            newBooking->setSeatType(temp);
            getline(data, temp, ',');
            newBooking->setFirstName(temp);
            getline(data, temp);
            newBooking->setLastName(temp);

            // Add to list
            List->push_back(newBooking);
        }
        // Close file
        bookingFile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

/**
 * @brief Function to print out tickets
 * @param[in] fList Flight list
 * @param[in] bList Booking list
 */
void printTickets(std::list<flights *> fList, std::list<bookings *> bList)
{
    // Declare iterators
    std::list<bookings *>::iterator it;
    std::list<flights *>::iterator that;
    // Loop though both lists
    for (it = bList.begin(); it != bList.end(); ++it)
    {
        for (that = fList.begin(); that != fList.end(); ++that)
        {
            // Declare pointers to work with
            bookings *bptr = *it;
            flights *fptr = *that;

            // Check for matching conditions
            if (bptr->getDate() == fptr->getDate() && bptr->getTime() == fptr->getTime() && bptr->getDepart() == fptr->getDepart() && bptr->getArrive() == fptr->getArrive())
            {
                // Declare ticket name
                char ticketName[20];
                sprintf(ticketName, "ticket-%d.txt", bptr->getBookingN());
                // Declare variables
                int seat;
                int row = 1;
                // Open file to write to
                std::ofstream ticketFile(ticketName);

                // Check for class and set seat to corresponding class
                if (bptr->getSeatType() == "first")
                {
                    seat = fptr->getFSeat();
                    fptr->increaseF();
                }
                else if (bptr->getSeatType() == "business")
                {
                    seat = fptr->getBSeat();
                    fptr->increaseB();
                }
                else if (bptr->getSeatType() == "economy")
                {
                    seat = fptr->getESeat();
                    fptr->increaseE();
                }
                // Increase row to corresponding seat
                while (seat > (fptr->getSecTotal() * row))
                {
                    row++;
                }

                if (ticketFile.is_open())
                {
                    // Write info into ticket
                    ticketFile << "BOOKING: " << bptr->getBookingN() << "\nFLIGHT: " << fptr->getFlightN() << " DEPARTURE: " << bptr->getDepart() << " DESTINATION: " << bptr->getArrive() << " " << bptr->getDate() << " " << bptr->getTime() << "\nPASSENGER: " << bptr->getFirstName() << " " << bptr->getLastName() << "\nCLASS: " << bptr->getSeatType() << "\nROW: " << row << " SEAT: " << seat;
                }
                else
                {
                    std::cerr << "Unable to open file" << std::endl;
                }
                // Close file
                ticketFile.close();
            }
        }
    }
}

/**
 * @brief Function to cancel flights with no passengers
 * @param[in] fList Flight list
 */
void cancelFlights(std::list<flights *> &fList)
{
    // Declare iterator
    std::list<flights *>::iterator it;
    // Open file to write to
    std::ofstream cancel("cancelled-flights.txt");
    // Set iterator to the begining of list
    it = fList.begin();
    // Loop through until end of list
    while (it != fList.end())
    {
        // Declare pointer to work with
        flights *fptr = *it;
        // Check if any seats are taken
        if (fptr->getFSeat() == 1 && fptr->getBSeat() == fptr->getFMaxSeat() + 1 && fptr->getESeat() == fptr->getFMaxSeat() + fptr->getBMaxSeat() + 1)
        {
            // Write info to file
            cancel << fptr->getFlightN() << "," << fptr->getDepart() << "," << fptr->getArrive() << "," << fptr->getDate() << "," << fptr->getTime() << "," << fptr->getFMax() << "," << fptr->getBMax() << "," << fptr->getEMax() << "\n";
            // Remove object from list
            fList.remove(fptr);
            // Free object
            delete fptr;
            // Set iterator to begining to loop through again
            it = fList.begin();
        }
        else
        {
            // Move iterator to next in the list
            it++;
        }
    }
    // Close file
    cancel.close();
}

/**
 * @brief Function to print out seating report
 * @param[in] fList Flight list
 */
void seatingChart(std::list<flights *> fList)
{
    // Declare iterator
    std::list<flights *>::iterator it;
    // Open file to write to
    std::ofstream seating("seating-report.txt");
    // Loop though list
    for (it = fList.begin(); it != fList.end(); it++)
    {
        // Declare pointer to work with
        flights *fptr = *it;
        // Declare variables
        int row = 1;
        int count = 0;
        // Write flight info to file
        seating << "Flight " << fptr->getFlightN() << ", Departure " << fptr->getDepart() << ", Destination " << fptr->getArrive() << ", Date " << fptr->getDate() << ", Time " << fptr->getTime() << "\n";
        // Write first class seats
        seating << "First Class\n";
        for (int seat = 1; seat <= fptr->getFMaxSeat(); seat++)
        {
            // Check for row
            if (seat > (fptr->getSecTotal() * row))
            {
                row++;
                seating << "\n";
                count = 0;
            }

            // Write [1] if seat is taken and [0] if not
            if (seat < fptr->getFSeat())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            // increase count each loop
            count++;
            // Write space if conditions met
            if (count == fptr->getSec1() || count == fptr->getSec1() + fptr->getSec2())
            {
                seating << " ";
            }
        }
        // Write business class seats
        seating << "\nBusiness Class";
        for (int seat = fptr->getFMaxSeat() + 1; seat <= fptr->getFMaxSeat() + fptr->getBMaxSeat(); seat++)
        {
            if (seat > (fptr->getSecTotal() * row))
            {
                row++;
                seating << "\n";
                count = 0;
            }

            if (seat < fptr->getBSeat())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            count++;
            if (count == fptr->getSec1() || count == fptr->getSec1() + fptr->getSec2())
            {
                seating << " ";
            }
        }
        // Write economy class seats
        seating << "\nEconomy Class";
        for (int seat = fptr->getFMaxSeat() + fptr->getBMaxSeat() + 1; seat <= fptr->getFMaxSeat() + fptr->getBMaxSeat() + fptr->getEMaxSeat(); seat++)
        {
            if (seat > (fptr->getSecTotal() * row))
            {
                row++;
                seating << "\n";
                count = 0;
            }

            if (seat < fptr->getESeat())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            count++;
            if (count == fptr->getSec1() || count == fptr->getSec1() + fptr->getSec2())
            {
                seating << " ";
            }
        }
        seating << "\n\n";
    }
    // Close file
    seating.close();
}