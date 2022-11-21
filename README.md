# Ticket in CPP

Ticket system in cpp language.

The ticket system needs a file with flights and bookings to work.
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
