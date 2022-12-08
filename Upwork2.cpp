// Upwork2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "Upwork2.h"

string day, name;


int main() {
	welcomeScreen();
}

//WELCOME SCREEN//
void welcomeScreen() {

	cout << "\t\t ===================================\n";
	cout << "\t\t(                                    )\n";
	cout << "\t\t( --^-^-^-^-^-^-^-^-^-^-^-^-^-^-^--  )\n";
	cout << "\t\t( **RAILBRO'S TRAIN BOOKING SYSTEM** )\n";
	cout << "\t\t(---------------------------------   )\n";
	cout << "\t\t(                                    )\n";
	cout << "\t\t ===================================\n\n\n";

	system("pause");

	//LOGIN
	bool success = true;
	loginScreen(success);

	if (success) {
		mainScreen();
	}
	else {
		cout << "Abort!" << endl;
	}
}

void mainScreen() {

	std::vector<train> trains = initializeTrains();
	std::vector<booking> bookings;
	

	while(1){
		cin.clear();
		cout << ("\n=================================\n");
		cout << ("**RAILBRO'S TICKET BOOKING SYSTEM**");
		cout << ("\n=================================");
		cout << ("\n1> Book a train ticket");
		cout << ("\n------------------------");
		cout << ("\n2> View all available trains");
		cout << ("\n------------------------");
		cout << ("\n3> View active bookings");
		cout << ("\n-------------------------");
		cout << ("\n4> Exit");
		cout << ("\n________________________\n");
		cout << "$$ ENTER CHOICE $$ ----->";

		char menu_choice = 0;
		cin >> menu_choice;

		if (menu_choice == 49){
			reservation(trains,bookings);
		}

		if (menu_choice == 50) {
			viewdetails(trains);
		}

		if (menu_choice == 51) {
			viewBookings(bookings);
		}
		if (menu_choice == 52) {
			break;
		}
		cin.clear();
	}
}

void viewdetails(std::vector<train> trains)
{
	cout << ("--------------------AVAILABLE TRAINS LIST-------------------------------------------------------------------\n");
	cout << ("-------------------------------------------------------------------------------------------------------------");
	cout << ("\nCoach.No\tName\t\tDestinations\t     Price($)\t\tTime\t\tSeats\n");
	cout << ("-------------------------------------------------------------------------------------------------------------\n");
	
	for (train t : trains) {
		cout << " " << t.id << "   " << compToString(t.comp) << "\t        " << t.destinations << "   	" << t.price << "		 " << typeToString(t.typ) << "\t\t"<<t.capacity<<endl;
	}
}

//MAKE THE BOOKING & SAVE FILE//

void reservation(std::vector<train>& trains, std::vector<booking>& bookings)
{
	string name, confirm;
	int seats,trainNumber;
	char day;

	cout << ("\nEnter your name:> ");
	cin >> name;
	cout << ("\nEnter number of seats:> ");
	cin >> seats;

	cout << ("\nEnter day you would like to go:> ");
	cout << ("\n -->1 MONDAY");
	cout << ("\n -->2 TUESDAY");
	cout << ("\n -->3 WEDNESDAY");
	cout << ("\n -->4 THURSDAY");
	cout << ("\n -->5 FRIDAY");
	cout << ("\n -->6 SATURDAY");
	cout << ("\n -->7 SUNDAY\n -->");

	cin >> day;
	if (day < 49 || day>55) {
		cout << "Illegal option:Abort!" << endl;
		return;
	}
	
	days day_d = charToDay(day);
	int day_i = charToInt(day);

	viewdetails(trains);

	cout << ("\n\nEnter train number:> ");
	cin >> trainNumber;

	bool trainExists = false;
	for (train& t : trains) {
		if (trainNumber == t.id) {
			trainExists = true;
			if (t.reservedSeats[day_i].second + seats > t.capacity) {
				std::cout << "----- There are only "<< t.capacity - t.reservedSeats[day_i].second <<" seats available for this train.Try again!" << endl;
				return;
			}

			cout << ("\n\nConfirm Ticket (y/n):>");
			cin >> confirm;

			if (confirm.compare("y") == 0 || confirm.compare("Y") == 0)
			{
				booking b = booking(name, trainNumber, seats, day_d);
				int cost = costOfReservation(trains, b);

				cout << ("******************");
				cout << ("\nBooking complete\n");
				cout << ("******************\n");
				cout << "Username:		" << name << endl;
				cout << "Number of Seats:	" << seats << endl;
				cout << "Train route:		" << t.destinations << endl;
				cout << "Day:			" << daysToString(day_d) << " at " << typeToString(t.typ) << endl;
				cout << "Total cost:		" << cost << "$" << endl;


				t.reservedSeats[day_i].second = t.reservedSeats[day_i].second + seats;
				
				bookings.push_back(b);
			}
			else
			{
				if (confirm.compare("n") == 0 || confirm.compare("N") == 0) {
					cout << "Booking not complete!\n" << endl;
				}
				else {
					cout << "Option non-recognisable " << endl;
				}
			}
			
		}
	}
	
	if (!trainExists) {
		cout << "Train number does not exist!" << endl;
	}
	
}

void viewBookings(std::vector<booking> bookings) {
	cout << "-------------------Bookings -------------------------------------" << endl;
	cout << "Reservation name\tDay\t\tTrain No\t\tSeats\n";
	cout << "-----------------------------------------------------------------" << endl;
	for (booking b : bookings) {
		cout << b.name << "\t\t\t"<<daysToString(b.day) << "\t\t"<<b.train_num << "\t"<<b.num_of_seats << endl;
	}
}

void loginScreen(bool& successfulLogin)
{
	string uname, pword;
	cout << ("\n   ======================= LOGIN  =======================\n  ");
	while (1) {
		cout << (" \n                       USERNAME:-");
		cin >> (uname);
		if (uname.compare("railbros") != 0) {
			cout << "				The Userame is incorrect" << endl;
		}
		else {
			break;
		}
	}

	int attempts = 0;
	while (pword.compare("pass") != 0) {
		attempts++;
		if (attempts >= 5) {
			cout << ("\nYou have entered the password incorrectly to many times!");
			successfulLogin = false;
			break;
		}
		cout << (" \n                       PASSWORD:-");
		cin >> (pword);
		if (pword.compare("pass") != 0) {
			cout << "					Wrong password!" << endl;
		}
		else {
			break;
		}
	}

}


std::vector<train> initializeTrains() {
	std::vector<train> trains;
	trains.push_back(train(1001, VIRGIN_TRAINS, "London to Birmingham", 30, MORNING,80));
	trains.push_back(train(1002, VIRGIN_TRAINS, "London to Birmingham", 15, AFTERNOON,80));
	trains.push_back(train(1003, VIRGIN_TRAINS, "London to Birmingham", 30, EVENING,80));
	trains.push_back(train(1004, VIRGIN_TRAINS, "Birmingham to London", 30, MORNING,80));
	trains.push_back(train(1005, VIRGIN_TRAINS, "Birmingham to London", 15, AFTERNOON,80));
	trains.push_back(train(1006, VIRGIN_TRAINS, "Birmingham to London", 30, EVENING,80));
	trains.push_back(train(1007, VIRGIN_TRAINS, "London to Bradford", 40, MORNING,95));
	trains.push_back(train(1008, VIRGIN_TRAINS, "London to Bradford", 30, AFTERNOON,95));
	trains.push_back(train(1009, VIRGIN_TRAINS, "London to Bradford", 40, EVENING,95));
	trains.push_back(train(1010, VIRGIN_TRAINS, "Bradford to London", 40, MORNING,95));
	trains.push_back(train(1011, VIRGIN_TRAINS, "Bradford to London", 30, AFTERNOON,95));
	trains.push_back(train(1012, VIRGIN_TRAINS, "Bradford to London", 40, EVENING,95));
	trains.push_back(train(1013, LNWR, "London to Manchester", 45, MORNING,220));
	trains.push_back(train(1014, LNWR, "London to Manchester", 35, AFTERNOON,220));
	trains.push_back(train(1015, LNWR, "London to Manchester", 45, EVENING,220));
	trains.push_back(train(1016, LNWR, "Manchester to London", 45, MORNING,220));
	trains.push_back(train(1017, LNWR, "Manchester to London", 35, AFTERNOON,220));
	trains.push_back(train(1018, LNWR, "Manchester to London", 45, EVENING,220));
	trains.push_back(train(1019, SCOTRAIL, "London to Glasgow", 80, MORNING,270));
	trains.push_back(train(1020, SCOTRAIL, "London to Glasgow", 40, AFTERNOON,270));
	trains.push_back(train(1021, SCOTRAIL, "London to Glasgow", 80, EVENING,270));
	trains.push_back(train(1022, SCOTRAIL, "Glasgow to London", 80, MORNING,270));
	trains.push_back(train(1023, SCOTRAIL, "Glasgow to London", 40, AFTERNOON,270));
	trains.push_back(train(1024, SCOTRAIL, "Glasgow to London", 80, EVENING,270));
	trains.push_back(train(1025, VIRGIN_TRAINS, "London to Leeds", 40, MORNING,160));
	trains.push_back(train(1026, VIRGIN_TRAINS, "London to Leeds", 30, AFTERNOON,160));
	trains.push_back(train(1027, VIRGIN_TRAINS, "London to Leeds", 40, EVENING,160));
	trains.push_back(train(1028, VIRGIN_TRAINS, "Leeds to London", 40, MORNING,160));
	trains.push_back(train(1029, VIRGIN_TRAINS, "Leeds to London", 30, AFTERNOON,160));
	trains.push_back(train(1030, VIRGIN_TRAINS, "Leeds to London", 40, EVENING,160));
	trains.push_back(train(1031, VIRGIN_TRAINS, "London to Cambridge", 25, MORNING,65));
	trains.push_back(train(1032, VIRGIN_TRAINS, "London to Cambridge", 15, AFTERNOON,65));
	trains.push_back(train(1033, VIRGIN_TRAINS, "London to Cambridge", 25, EVENING,65));
	trains.push_back(train(1034, VIRGIN_TRAINS, "Cambridge to London", 25, MORNING,65));
	trains.push_back(train(1035, VIRGIN_TRAINS, "Cambridge to London", 15, AFTERNOON,65));
	trains.push_back(train(1036, VIRGIN_TRAINS, "Cambridge to London", 25, EVENING,65));

	return trains;
}

std::string typeToString(type typ) {
	if (typ == MORNING) {
		return "MORNING";
	}

	if (typ == AFTERNOON) {
		return "AFTERNOON";
	}

	if (typ == EVENING) {
		return "EVENING";
	}

	return " ";
}

std::string compToString(companies comp) {
	if (comp == VIRGIN_TRAINS) {
		return "VIRGIN TRAINS";
	}

	if (comp == SCOTRAIL) {
		return "SCOTRAIL";
	}

	if (comp = LNWR) {
		return "L.N.W.R.";
	}

	return " ";
}

std::string daysToString(days day) {
	if (day == MONDAY) {
		return "MONDAY";
	}

	if (day == TUESDAY) {
		return "TUESDAY";
	}

	if (day == WEDNESDAY) {
		return "WEDNESDAY";
	}
	if (day == THURSDAY) {
		return "THURSDAY";
	}

	if (day == FRIDAY) {
		return "FRIDAY";
	}

	if (day == SATURDAY) {
		return "SATURDAY";
	}

	if (day == SUNDAY) {
		return "SATURDAY";
	}
}

int costOfReservation(vector<train> trains, booking b) {
	for (train t : trains) {
		if (t.id == b.train_num) {
			return b.num_of_seats * t.price;
		}
	}
}

days charToDay(char c) {
	if (c == '1') {
		return MONDAY;
	}
	if (c == '2') {
		return TUESDAY;
	}
	if (c == '3') {
		return WEDNESDAY;
	}
	if (c == '4') {
		return THURSDAY;
	}
	if (c == '5') {
		return FRIDAY;
	}
	if (c == '6') {
		return SATURDAY;
	}
	if (c == '7') {
		return SUNDAY;
	}
}

int charToInt(char c) {
	return c - '0';
}