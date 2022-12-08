#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

enum type {
	MORNING,
	AFTERNOON,
	EVENING
};

enum companies {
	VIRGIN_TRAINS,
	LNWR,
	SCOTRAIL
};

enum days {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

void login();

class booking {
public:
	string name;
	int train_num;
	int num_of_seats;
	days day;

	booking(string name, int train_num, int num_of_seats, days day) :name(name), train_num(train_num),
		num_of_seats(num_of_seats),day(day) {
		
	}
};

class train {
public:
	unsigned int id;
	companies comp;
	string destinations;
	double price;
	type typ;
	int capacity;
	vector<pair<days,int>> reservedSeats;

	train() = default;
	train(unsigned int id, companies comp, string destinations, double price, type typ,int capacity) :
		id(id), comp(comp), destinations(destinations), price(price), typ(typ),capacity(capacity) {
		reservedSeats = { make_pair(MONDAY,0),make_pair(TUESDAY,0),make_pair(WEDNESDAY,0),
			make_pair(THURSDAY,0),make_pair(FRIDAY,0),
			make_pair(SATURDAY,0),make_pair(SUNDAY,0)};
	
	}

	void reserve() {

	}
};



void welcomeScreen();
void mainScreen();
void loginScreen(bool& successfulLogin);

void reservation(std::vector<train>& trains, std::vector<booking>& bookings);
void viewdetails(std::vector<train> trains);
void viewBookings(std::vector<booking> bookings);

void cancel(void);
void printticket(vector<train>,char name[], int, int, float);
void specifictrain(vector<train>,int);

std::vector<train> initializeTrains();
std::vector<booking> initializeBookings();


std::string typeToString(type typ);
std::string compToString(companies comp);
std::string daysToString(days day);

int costOfReservation(vector<train> trains, booking b);

days charToDay(char c);
int charToInt(char c);