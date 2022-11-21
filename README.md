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
305,CPH,STO,2022-11-25,08:30,19,25,48,2-3-2
```

## Booking data-file structure

**Booking.csv:**
```
BookingNumber,Date,Time,Departure,Destination,SeatClass,FirstName,LastName
```
**Example of booking structure**
```
1205,2022-11-25,08:30,CPH,STO,first,Daniel,Svensson
```

## Output

### Tickets
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
FLIGHT: 305 DEPARTURE: CPH DESTINATION: STO 2022-11-25 08:30
PASSENGER: Daniel Svensson
CLASS: first
ROW: 1 SEAT: 1
```

### Cancelled Flights
The cancelled flights will all be written to a file with the name:
```
cancelled-flights.txt
```
It will have the same structure as flights file-data structure for each flight:
```
FlightNumber,Departure,Destination,Date,Time,TotalFirstClassRows,TotalBusinessClassRows,TotalEconomyClassRows,SeatingConfiguration
```
**Example of cancelled flights**
```
420,CPH,AMS,2022-11-25,09:30,30,40,55,3-3-3
550,STO,AMS,2022-11-25,10:30,15,25,35,2-2-2
```

### Seating Charts
The seating charts will all be written to a file with the name:
```
seating-report.txt
```
Each flight will have the following information in this format:
```
Flight {FlightNumber}, Departure {Departure}, Destination {Destination}, Date {Date}, Time {Time}
First Class
[1][1] [0][0][0] [0][0]
etc....
Business Class
[1][1] [0][0][0] [0][0]
etc....
Economy Class
[1][1] [0][0][0] [0][0]
etc....
```
[1] represent reserved seats and [0] represent free seats.

**Example of a seating chart**
```
Flight 305, Departure CPH, Destination STO, Date 2022-11-25, Time 08:30
First Class
[1][0] [0][0][0] [0][0]
[0][0] [0][0][0] [0][0]
etc....
Business Class
[0][0] [0][0][0] [0][0]
etc....
Economy Class
[0][0] [0][0][0] [0][0]
etc....
```
