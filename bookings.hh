/**
 * @file bookings.hh
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief 
 * @version 0.1
 * @date 2022-11-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

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