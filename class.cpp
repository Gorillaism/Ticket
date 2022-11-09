#include "class.hh"

// Declare flights method

// Declare setters
void flights::setFlightN(int fN)
{
    this->flightN = fN;
}
void flights::setFSeats(int fS)
{
    this->fMax = fS;
    this->fCurrent = 1;
}
void flights::setBSeats(int bS)
{
    this->bMax = bS;
    this->bCurrent = (this->fMax * 7) + 1;
}
void flights::setESeats(int eS)
{
    this->eMax = eS;
    this->eCurrent = (this->fMax * 7) + (this->bMax * 7) + 1;
}
void flights::setDepart(std::string &dP)
{
    this->depart = dP;
}
void flights::setArrive(std::string &aV)
{
    this->arrive = aV;
}
void flights::setDate(std::string &dT)
{
    this->date = dT;
}
void flights::setTime(std::string &tM)
{
    this->time = tM;
}
// Increase current seats
void flights::increaseF()
{
    this->fCurrent++;
}
void flights::increaseB()
{
    this->bCurrent++;
}
void flights::increaseE()
{
    this->eCurrent++;
}

// Declare getters
int flights::getFlightN()
{
    return this->flightN;
}
int flights::getFMax()
{
    return this->fMax;
}
int flights::getFMaxSeat()
{
    return (this->fMax * 7);
}
int flights::getFSeat()
{
    return this->fCurrent;
}
int flights::getBMax()
{
    return this->bMax;
}
int flights::getBMaxSeat()
{
    return (this->bMax * 7);
}
int flights::getBSeat()
{
    return this->bCurrent;
}
int flights::getEMax()
{
    return this->eMax;
}
int flights::getEMaxSeat()
{
    return (this->eMax * 7);
}
int flights::getESeat()
{
    return this->eCurrent;
}
std::string flights::getDepart()
{
    return this->depart;
}
std::string flights::getArrive()
{
    return this->arrive;
}
std::string flights::getDate()
{
    return this->date;
}
std::string flights::getTime()
{
    return this->time;
}

// Declare bookings methods

// Declare setters
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

// Declare getters
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