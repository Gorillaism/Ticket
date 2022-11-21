# Ticket in CPP

**Ticket system in cpp language**
This is a program to reserve seats on a plane and print out tickets.

The system starts by reading from the two files and sorts it into a list.
It then cross reference to check for matching booking and flight to reserve a seat and create a ticket.
After it has created all possible tickets, it will then run through the flight list to check for empty flights and cancel them.
Which mean it will take the empty flights info out of the list and put it into a txt file called cancelled-flights.txt.
Finally it will create a seating report on the remaining flights.
The ticket system needs a file with flights and bookings to work.

## Examples for compiling and running program
**Example for compiling:**
```
g++ ticket.cpp function.cpp class.cpp -o (nameofprogram)
```
**Example for running:**
``````
./(nameofprogram).exe -f flights.csv -b booking.csv
```

The system starts by reading from the two files and sorts it into a list.
It then cross reference to check for matching booking and flight to reserve a seat and create a ticket.
After it has 
