#include "bookings.hh"

// Define bookings methods

// Define setters
void bookings::setBookingN(int bN)
{
    this->bookingN = bN;
}
void bookings::setDepart(std::string &dP)
{
    this->depart = dP;
}
void bookings::setArrive(std::string &aV)
{
    this->arrive = aV;
}
void bookings::setDate(std::string &dT)
{
    this->date = dT;
}
void bookings::setTime(std::string &tM)
{
    this->time = tM;
}
void bookings::setSeatType(std::string &sT)
{
    this->seatType = sT;
}
void bookings::setFirstName(std::string &fstN)
{
    this->firstName = fstN;
}
void bookings::setLastName(std::string &lstN)
{
    this->lastName = lstN;
}

// Define getters
int bookings::getBookingN()
{
    return this->bookingN;
}
std::string bookings::getDepart()
{
    return this->depart;
}
std::string bookings::getArrive()
{
    return this->arrive;
}
std::string bookings::getDate()
{
    return this->date;
}
std::string bookings::getTime()
{
    return this->time;
}
std::string bookings::getSeatType()
{
    return this->seatType;
}
std::string bookings::getFirstName()
{
    return this->firstName;
}
std::string bookings::getLastName()
{
    return this->lastName;
}