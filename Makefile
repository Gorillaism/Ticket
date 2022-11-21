ticket : flights.hh bookings.hh function.hh flights.cpp bookings.cpp function.cpp ticket.cpp
	g++ ticket.cpp flights.cpp bookings.cpp function.cpp -o ticket
	
check : ticket
	./ticket -f flights.csv -b bookings.csv

dist : ticket
	gzip ticket
	
distcheck : dist
	gunzip ticket.gz
