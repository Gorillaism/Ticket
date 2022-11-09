#include <string>
#include <list>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include "class.hh"

void fillFlightList(std::string file, std::list<flights *> *List);
void fillBookingList(std::string file, std::list<bookings *> *List);
void printTickets(std::list<flights *> fList, std::list<bookings *> bList);
void cancelFlights(std::list<flights *> &fList);
void seatingChart(std::list<flights *> fList);