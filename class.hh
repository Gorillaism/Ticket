/**
 * @file class.hh
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief Class header
 * @version 1.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

#ifndef FLIGHT_CLASS_INCLUDED
#define FLIGHT_CLASS_INCLUDED

class flights
{
    // Declare variables
    int flightN;        // Flight number
    int fMax;           // Max first class rows
    int fCurrent;       // Current first class seat
    int bMax;           // Max business class rows
    int bCurrent;       // Current business class seat
    int eMax;           // Max economy class rows
    int eCurrent;       // Current economy class seat
    int sec1;           // Amount seats in Section 1
    int sec2;           // Amount seats in Section 2
    int sec3;           // Amount seats in Section 3
    std::string depart; // Departure airport
    std::string arrive; // Destination airport
    std::string date;   // Date
    std::string time;   // Time

public:
    // Declare method prototypes

    // Declare setters
    /**
     * @brief Set the Flight number
     * @param[in] fN Flight number
     */
    void setFlightN(int fN);
    /**
     * @brief Set the max first class rows and current seat
     * @param[in] fS First class rows
     */
    void setFSeats(int fS);
    /**
     * @brief Set the max business class rows and current seat
     * @param[in] bS Business class rows
     */
    void setBSeats(int bS);
    /**
     * @brief Set the max economy class rows and current seat
     * @param[in] eS Economy class rows
     */
    void setESeats(int eS);
    /**
     * @brief Set the amount of seats in the first section
     * @param[in] s1 Section 1
     */
    void setSec1(int s1);
    /**
     * @brief Set the amount of seats in the second section
     * @param[in] s2 Section 2
     */
    void setSec2(int s2);
    /**
     * @brief Set the amount of seats in the third section
     * @param[in] s3 Section 3
     */
    void setSec3(int s3);
    /**
     * @brief Set the Current Seats
     */
    void setCurrentSeats();
    /**
     * @brief Set the departure airport
     * @param[in] dP Departure airport
     */
    void setDepart(std::string &dP);
    /**
     * @brief Set the destination airport
     * @param[in] aV Destination airport
     */
    void setArrive(std::string &aV);
    /**
     * @brief Set the date
     * @param[in] dT Date
     */
    void setDate(std::string &dT);
    /**
     * @brief Set the time
     * @param[in] tM Time
     */
    void setTime(std::string &tM);

    // Increase current seats
    /**
     * @brief Increase first class current seat
     */
    void increaseF();
    /**
     * @brief Increase business class current seat
     */
    void increaseB();
    /**
     * @brief Increase economy class current seat
     */
    void increaseE();

    // Declare getters
    /**
     * @brief Get the flight number
     * @return Flight number
     */
    int getFlightN();
    /**
     * @brief Get the first class max rows
     * @return First class max rows
     */
    int getFMax();
    /**
     * @brief Get the first class max seats
     * @return First class max seats
     */
    int getFMaxSeat();
    /**
     * @brief Get the first class current seat
     * @return First class current seat
     */
    int getFSeat();
    /**
     * @brief Get the business class max rows
     * @return Business class max rows
     */
    int getBMax();
    /**
     * @brief Get the business class max seats
     * @return Business class max seats
     */
    int getBMaxSeat();
    /**
     * @brief Get the business class current seat
     * @return Business class current seat
     */
    int getBSeat();
    /**
     * @brief Get the economy class max rows
     * @return Economy class max rows
     */
    int getEMax();
    /**
     * @brief Get the economy class max seats
     * @return Economy class max seats
     */
    int getEMaxSeat();
    /**
     * @brief Get the economy class current seat
     * @return Economy class current seat
     */
    int getESeat();
    /**
     * @brief Get the amount of seat in the first section
     * @return Seats in first section 
     */
    int getSec1();
    /**
     * @brief Get the amount of seat in the second section
     * @return Seats in second section 
     */
    int getSec2();
    /**
     * @brief Get the amount of seat in the third section
     * @return Seats in third section 
     */
    int getSec3();
    /**
     * @brief Get the amount of seat in each row
     * @return Seats per row 
     */
    int getSecTotal();
    /**
     * @brief Get the departure airport
     * @return Departure airport
     */
    std::string getDepart();
    /**
     * @brief Get the destination airport
     * @return Destination airport
     */
    std::string getArrive();
    /**
     * @brief Get the date
     * @return Date
     */
    std::string getDate();
    /**
     * @brief Get the time
     * @return Time
     */
    std::string getTime();
};
#endif

#ifndef BOOKING_CLASS_INCLUDED
#define BOOKING_CLASS_INCLUDED

class bookings
{
    // Declare variables
    int bookingN;          // Booking number
    std::string depart;    // Departure airport
    std::string arrive;    // Destination airport
    std::string date;      // Date
    std::string time;      // Time
    std::string seatType;  // Seat class
    std::string firstName; // First name
    std::string lastName;  // Last name

public:
    // Declare method prototypes

    // Declare setters
    /**
     * @brief Set the booking number
     * @param[in] bN Booking number
     */
    void setBookingN(int bN);
    /**
     * @brief Set the departure airport
     * @param[in] dP Departure airport
     */
    void setDepart(std::string &dP);
    /**
     * @brief Set the destination airport
     * @param[in] aV  Destination airport
     */
    void setArrive(std::string &aV);
    /**
     * @brief Set the date
     * @param[in] dT Date
     */
    void setDate(std::string &dT);
    /**
     * @brief Set the time
     * @param[in] tM Time
     */
    void setTime(std::string &tM);
    /**
     * @brief Set the seat class
     * @param[in] sT Seat class
     */
    void setSeatType(std::string &sT);
    /**
     * @brief Set the first name
     * @param[in] fstN First name
     */
    void setFirstName(std::string &fstN);
    /**
     * @brief Set the last name
     * @param[in] lstN Last name
     */
    void setLastName(std::string &lstN);

    // Declare getters
    /**
     * @brief Get the booking number
     * @return Booking number
     */
    int getBookingN();
    /**
     * @brief Get the departure airport
     * @return Departure airport
     */
    std::string getDepart();
    /**
     * @brief Get the destination airport
     * @return Destination airport
     */
    std::string getArrive();
    /**
     * @brief Get the date
     * @return Date
     */
    std::string getDate();
    /**
     * @brief Get the time
     * @return Time
     */
    std::string getTime();
    /**
     * @brief Get the seat class
     * @return Seat class
     */
    std::string getSeatType();
    /**
     * @brief Get the first name
     * @return First name
     */
    std::string getFirstName();
    /**
     * @brief Get the last name
     * @return Last name
     */
    std::string getLastName();
};
#endif