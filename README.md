# Ticket in CPP

**Ticket system in cpp language**

This is a program to reserve seats on a plane and print out tickets.

The ticket system needs a file with flights and bookings to work.
The system starts by reading from the two files and sorts it into a list.

It then cross reference to check for matching booking and flight to reserve a seat and create a ticket.
After it has created all possible tickets, it will then run through the flight list to check for empty flights and cancel them.
Which mean it will take the empty flights info out of the list and put it into a txt file called cancelled-flights.txt.

Finally it will create a seating report on the remaining flights.

## Example for compiling and running program
{Nameofprogram} meaning whatever name you would like to use yourself.

**Example for compiling:**
```
g++ ticket.cpp function.cpp class.cpp -o {Nameofprogram}
```
**Example for running:**
```
./{Nameofprogram}.exe -f flights.csv -b booking.csv
```

## Flight data-file structure

**Flights.csv:**
```
FlightNumber,Departure,Destination,Date,Time,TotalFirstClassRows,TotalBusinessClassRows,TotalEconomyClassRows,SeatingConfiguration
```
**Example of flight structure**
```
305,CPH,STH,2022-11-25,08:30,19,25,48,2-3-2
```

## Booking data-file structure

**Booking.csv:**
```
BookingNumber,Date,Time,Departure,Destination,SeatClass,FirstName,LastName
```
**Example of booking structure**
```
1205,2022-11-25,08:30,CPH,STH,first,Daniel,Svensson
```

## Output

The tickets will be written to files in the format:
```
ticket-{BookingNumber}.txt
```

Each ticket will contain the following information in this format:
```
BOOKING: {BookingNumber}
FLIGHT: {FlightNumber} DEPARTURE: {Departure} DESTINATION: {Destination} {Date} {Time}
PASSENGER: {FirstName} {LastName}
CLASS: {SeatClass}
ROW: {Row} SEAT: {SeatNumber}
```
**Example of ticket filename**
```
ticket-1205.txt
```
**Example of ticket file content**
```
BOOKING: 1205
FLIGHT: 305 DEPARTURE: CPH DESTINATION: STH 2022-11-25 08:30
PASSENGER: Daniel Svensson
CLASS: First
ROW: 1 SEAT: 1
```

