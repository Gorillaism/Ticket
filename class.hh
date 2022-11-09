#include <iostream>
#include <string>

#ifndef FLIGHT_CLASS_INCLUDED
#define FLIGHT_CLASS_INCLUDED

class flights
{
    // Declare variables
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
    // Declare methods

    // Declare setters
    void setFlightN(int fN);
    void setFSeats(int fS);
    void setBSeats(int bS);
    void setESeats(int eS);
    void setDepart(std::string &dP);
    void setArrive(std::string &aV);
    void setDate(std::string &dT);
    void setTime(std::string &tM);
    // Increase current seats
    void increaseF();
    void increaseB();
    void increaseE();

    // Declare getters
    int getFlightN();
    int getFMax();
    int getFMaxSeat();
    int getFSeat();
    int getBMax();
    int getBMaxSeat();
    int getBSeat();
    int getEMax();
    int getEMaxSeat();
    int getESeat();
    std::string getDepart();
    std::string getArrive();
    std::string getDate();
    std::string getTime();
};
#endif

#ifndef BOOKING_CLASS_INCLUDED
#define BOOKING_CLASS_INCLUDED

class bookings
{
    // Declare variables
    int bookingN;
    std::string depart;
    std::string arrive;
    std::string date;
    std::string time;
    std::string seatType;
    std::string firstName;
    std::string lastName;

public:
    // Declare methods

    // Declare setters
    void setBookingN(int bN);
    void setDepart(std::string &dP);
    void setArrive(std::string &aV);
    void setDate(std::string &dT);
    void setTime(std::string &tM);
    void setSeatType(std::string &sT);
    void setFirstName(std::string &fstN);
    void setLastName(std::string &lstN);

    // Declare getters
    int getBookingN();
    std::string getDepart();
    std::string getArrive();
    std::string getDate();
    std::string getTime();
    std::string getSeatType();
    std::string getFirstName();
    std::string getLastName();
};
#endif