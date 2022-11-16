ticket : class.hh function.hh class.cpp function.cpp ticket.cpp
	g++ ticket.cpp class.cpp function.cpp
	
check : ticket
	./ticket -f flights.csv -b bookings.csv

dist : ticket
	gzip ticket
	
distcheck : dist
	gunzip ticket.gz
