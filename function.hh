/**
 * @file function.hh
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief Functions header
 * @version 1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <string>
#include <list>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include "flights.hh"
#include "bookings.hh"

/**
 * @brief Function prototype to fill flight list
 * @param[in] file Flight file name
 * @param[in] List Flight list
 */
void fillFlightList(std::string file, std::list<flights *> *List);
/**
 * @brief Function prototype to fill booking list
 * @param[in] file Booking file name
 * @param[in] List Booking list
 */
void fillBookingList(std::string file, std::list<bookings *> *List);
/**
 * @brief Function prototype to print out tickets
 * @param[in] fList Flight list
 * @param[in] bList Booking list
 */
void printTickets(std::list<flights *> fList, std::list<bookings *> bList);
/**
 * @brief Function prototype to cancel flights with no passengers
 * @param[in] fList Flight list
 */
void cancelFlights(std::list<flights *> &fList);
/**
 * @brief Function prototype to print out seating report
 * @param[in] fList Flight list
 */
void seatingChart(std::list<flights *> fList);