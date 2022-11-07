#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

class flights
{
    int flightN;
    int fMax;
    int fCurrent;
    int bMax;
    int bCurrent;
    int eMax;
    int eCurrent;
    std::string depart;
    std::string arrive;
    std::string date;
    std::string time;

public:
    void setFlightN(int fN)
    {
        this->flightN = fN;
    }
    void setFSeats(int fS)
    {
        this->fMax = fS;
        this->fCurrent = 1;
    }
    void setBSeats(int bS)
    {
        this->bMax = bS;
        this->bCurrent = (this->fMax * 7) + 1;
    }
    void setESeats(int eS)
    {
        this->eMax = eS;
        this->eCurrent = (this->fMax * 7) + (this->bMax * 7) + 1;
    }
    void setDepart(std::string dP)
    {
        this->depart = dP;
    }
    void setArrive(std::string aV)
    {
        this->arrive = aV;
    }
    void setDate(std::string dT)
    {
        this->date = dT;
    }
    void setTime(std::string tM)
    {
        this->time = tM;
    }
    void increaseF()
    {
        this->fCurrent++;
    }
    void increaseB()
    {
        this->bCurrent++;
    }
    void increaseE()
    {
        this->eCurrent++;
    }

    int getFlightN()
    {
        return this->flightN;
    }
    int getFMax()
    {
        return this->fMax;
    }
    int getFMaxSeat()
    {
        return (this->fMax * 7);
    }
    int getFSeat()
    {
        return this->fCurrent;
    }
    int getBMax()
    {
        return this->bMax;
    }
    int getBMaxSeat()
    {
        return (this->bMax * 7);
    }
    int getBSeat()
    {
        return this->bCurrent;
    }
    int getEMax()
    {
        return this->eMax;
    }
    int getEMaxSeat()
    {
        return (this->eMax * 7);
    }
    int getESeat()
    {
        return this->eCurrent;
    }
    std::string getDepart()
    {
        return this->depart;
    }
    std::string getArrive()
    {
        return this->arrive;
    }
    std::string getDate()
    {
        return this->date;
    }
    std::string getTime()
    {
        return this->time;
    }
};

class bookings
{
    int bookingN;
    std::string depart;
    std::string arrive;
    std::string date;
    std::string time;
    std::string seatType;
    std::string firstName;
    std::string lastName;

public:
    void setBookingN(int bN)
    {
        this->bookingN = bN;
    }
    void setDepart(std::string dP)
    {
        this->depart = dP;
    }
    void setArrive(std::string aV)
    {
        this->arrive = aV;
    }
    void setDate(std::string dT)
    {
        this->date = dT;
    }
    void setTime(std::string tM)
    {
        this->time = tM;
    }
    void setSeatType(std::string sT)
    {
        this->seatType = sT;
    }
    void setFirstName(std::string fstN)
    {
        this->firstName = fstN;
    }
    void setLastName(std::string lstN)
    {
        this->lastName = lstN;
    }

    int getBookingN()
    {
        return this->bookingN;
    }
    std::string getDepart()
    {
        return this->depart;
    }
    std::string getArrive()
    {
        return this->arrive;
    }
    std::string getDate()
    {
        return this->date;
    }
    std::string getTime()
    {
        return this->time;
    }
    std::string getSeatType()
    {
        return this->seatType;
    }
    std::string getFirstName()
    {
        return this->firstName;
    }
    std::string getLastName()
    {
        return this->lastName;
    }
};

void fillFlightList(std::string file, std::list<flights *> *List)
{
    std::ifstream flightFile(file);
    std::string filedata;

    if (flightFile.is_open())
    {
        while (getline(flightFile, filedata) && !filedata.empty())
        {
            flights *newFlight = new flights;
            std::stringstream data(filedata);
            std::string temp;
            getline(data, temp, ',');
            int tempN = atoi(temp.c_str());
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

            getline(data, temp);
            tempN = atoi(temp.c_str());
            newFlight->setESeats(tempN);

            List->push_back(newFlight);
        }
        flightFile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

void fillBookingList(std::string file, std::list<bookings *> *List)
{
    std::ifstream bookingFile(file);
    std::string filedata;

    if (bookingFile.is_open())
    {
        while (getline(bookingFile, filedata) && !filedata.empty())
        {
            bookings *newBooking = new bookings;
            std::stringstream data(filedata);
            std::string temp;
            getline(data, temp, ',');
            int tempN = atoi(temp.c_str());
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

            List->push_back(newBooking);
        }
        bookingFile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

void printTickets(std::list<flights *> fList, std::list<bookings *> bList)
{
    std::list<bookings *>::iterator it;
    std::list<flights *>::iterator that;
    for (it = bList.begin(); it != bList.end(); ++it)
    {
        for (that = fList.begin(); that != fList.end(); ++that)
        {
            bookings *bptr = *it;
            flights *fptr = *that;

            if (bptr->getDate() == fptr->getDate() && bptr->getTime() == fptr->getTime() && bptr->getDepart() == fptr->getDepart() && bptr->getArrive() == fptr->getArrive())
            {
                char ticketName[20];
                sprintf(ticketName, "ticket-%d.txt", bptr->getBookingN());
                int seat;
                int row = 1;
                std::ofstream ticketFile(ticketName);

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
                while (seat > 7 * row)
                {
                    row++;
                }

                if (ticketFile.is_open())
                {
                    ticketFile << "BOOKING: " << bptr->getBookingN() << "\nFLIGHT: " << fptr->getFlightN() << " DEPARTURE: " << bptr->getDepart() << " DESTINATION: " << bptr->getArrive() << " " << bptr->getDate() << " " << bptr->getTime() << "\nPASSENGER: " << bptr->getFirstName() << " " << bptr->getLastName() << "\nCLASS: " << bptr->getSeatType() << "\nROW: " << row << " SEAT: " << seat;
                }
                else
                {
                    std::cerr << "Unable to open file" << std::endl;
                }
                ticketFile.close();
            }
        }
    }
}

void cancelFlights(std::list<flights *> &fList)
{
    std::list<flights *>::iterator it;
    std::ofstream cancel("cancelled-flights.txt");
    it = fList.begin();
    while (it != fList.end())
    {
        flights *fptr = *it;
        if (fptr->getFSeat() == 1 && fptr->getBSeat() == fptr->getFMaxSeat() + 1 && fptr->getESeat() == fptr->getFMaxSeat() + fptr->getBMaxSeat() + 1)
        {
            cancel << fptr->getFlightN() << "," << fptr->getDepart() << "," << fptr->getArrive() << "," << fptr->getDate() << "," << fptr->getTime() << "," << fptr->getFMax() << "," << fptr->getBMax() << "," << fptr->getEMax() << "\n";
            fList.remove(fptr);
            delete fptr;
            it = fList.begin();
        }
        else
        {
            it++;
        }
    }
    cancel.close();
}

void seatingChart(std::list<flights *> fList)
{
    std::list<flights *>::iterator it;
    std::ofstream seating("seating-report.txt");
    for (it = fList.begin(); it != fList.end(); it++)
    {
        flights *fptr = *it;
        int row = 1;
        int count = 0;
        seating << "Flight " << fptr->getFlightN() << ", Departure " << fptr->getDepart() << ", Destination " << fptr->getArrive() << ", Date " << fptr->getDate() << ", Time " << fptr->getTime() << "\n";
        seating << "First Class\n";
        for (int seat = 1; seat <= fptr->getFMaxSeat(); seat++)
        {
            if (seat > 7 * row)
            {
                row++;
                seating << "\n";
                count = 0;
            }

            if (seat < fptr->getFSeat())
            {
                seating << "[1]";
            }
            else
            {
                seating << "[0]";
            }
            count++;
            if (count == 2 || count == 5)
            {
                seating << " ";
            }
        }
        seating << "\nBusiness Class";
        for (int seat = fptr->getFMaxSeat() + 1; seat <= fptr->getFMaxSeat() + fptr->getBMaxSeat(); seat++)
        {
            if (seat > 7 * row)
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
            if (count == 2 || count == 5)
            {
                seating << " ";
            }
        }
        seating << "\nEconomy Class";
        for (int seat = fptr->getFMaxSeat() + fptr->getBMaxSeat() + 1; seat <= fptr->getFMaxSeat() + fptr->getBMaxSeat() + fptr->getEMaxSeat(); seat++)
        {
            if (seat > 7 * row)
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
            if (count == 2 || count == 5)
            {
                seating << " ";
            }
        }
        seating << "\n\n";
    }
    seating.close();
}

int main(int argc, char **argv)
{
    char *flightFile = NULL;
    char *bookingFile = NULL;
    int opt;

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

    std::list<flights *> flightList;
    std::list<bookings *> bookingList;

    std::cout << "Checking flights...\n";
    fillFlightList(flightFile, &flightList);
    std::cout << "Checking bookings...\n";
    fillBookingList(bookingFile, &bookingList);
    std::cout << "Reserving seating...\nPrinting out flight tickets...\n";
    printTickets(flightList, bookingList);
    std::cout << "Canceling flights with no passengers...\n";
    cancelFlights(flightList);
    std::cout << "Printing out seating report for remaining flights...\n";
    seatingChart(flightList);

    return 0;
}