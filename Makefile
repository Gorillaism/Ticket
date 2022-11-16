ticket : class.hh function.hh class.cpp function.cpp ticket.cpp
	g++ ticket.cpp class.cpp function.cpp -o ticket
	
check : ticket
	./ticket -f flights.csv

dist : ticket
	gzip ticket
	
distcheck : dist
	gunzip ticket.gz
