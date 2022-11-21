/**
 * @file flights.cpp
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief Flights class definition
 * @version 1
 * @date 2022-11-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "flights.hh"

// Define flights methods

// Define setters
void flights::setFlightN(int fN)
{
    this->flightN = fN;
}
void flights::setFSeats(int fS)
{
    this->fMax = fS;
}
void flights::setBSeats(int bS)
{
    this->bMax = bS;
}
void flights::setESeats(int eS)
{
    this->eMax = eS;
}
void flights::setSec1(int s1)
{
    this->sec1 = s1;
}
void flights::setSec2(int s2)
{
    this->sec2 = s2;
}
void flights::setSec3(int s3)
{
    this->sec3 = s3;
}
void flights::setCurrentSeats()
{
    this->fCurrent = 1;
    this->bCurrent = (this->fMax * (this->sec1 + this->sec2 + this->sec3)) + 1;
    this->eCurrent = (this->fMax * (this->sec1 + this->sec2 + this->sec3)) + (this->bMax * (this->sec1 + this->sec2 + this->sec3)) + 1;
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

// Define getters
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
    return (this->fMax * (this->sec1 + this->sec2 + this->sec3));
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
    return (this->bMax * (this->sec1 + this->sec2 + this->sec3));
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
    return (this->eMax * (this->sec1 + this->sec2 + this->sec3));
}
int flights::getESeat()
{
    return this->eCurrent;
}
int flights::getSec1()
{
    return this->sec1;
}
int flights::getSec2()
{
    return this->sec2;
}
int flights::getSec3()
{
    return this->sec3;
}
int flights::getSecTotal()
{
    return (this->sec1 + this->sec2 + this->sec3);
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
