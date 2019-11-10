#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <deque>
#include <sstream>

using namespace std;


/* Author: Rodney Nedlose
 * Date: 11.2.19
 * File:   BankReception.cpp
 * Purpose: Program simulates a 3 hour bank reception
 * period.  Shows the use/knowledge of stacks, queues,
 * random, and functions/classes.  There are up to 3
 * tellers handling customers as they enter.  Tellers
 * are added and removed as needed.
 * Output: Shows randomly created customers and their
 * associated bank transactions.  Shows time of arrival
 * and average number of customers waiting in line as well
 * as average amount of time each customer waited.
 */

// Customer Class
class Customer
{
public:
	// Fields for Customer Class
	int custID;
	string fName;
	string lName;
	int transactionType;
	int transTimeTaken;
	int money;
	int timeIn;
	int timeOut;
	string transType;

	// @Overload
	// Constructor for Customer objects
	Customer(int custID, string fName, string lName, int transactionType, int money, int timeIn)
	{
		this->custID = custID;
		this->fName = fName;
		this->lName = lName;
		this->transactionType = transactionType;
		this->money = money;
		this->timeIn = timeIn;

		// Determine randomly how long specific tranactions take in minutes
		if (transactionType == 1) transTimeTaken = 10 + rand() % 10;
		else if (transactionType == 2) transTimeTaken = 10 + rand() % 5;
		else if (transactionType == 3) transTimeTaken = 1 + rand() % 4;
		else if (transactionType == 4) transTimeTaken = 2 + rand() % 8;

		// Determine how much time customer was in bank
		this->timeOut = timeIn + transTimeTaken;

		// Randomly assign transaction type to each generated customer
		if (transactionType == 1) this->transType = "Open Account";
		else if (transactionType == 2) this->transType = "Close Account";
		else if (transactionType == 3) this->transType = "Deposit";
		else if (transactionType == 4) this->transType = "Withdraw";

	}
};

// Class to format minutes into a string in time format
class FormatTime
{
public:

	// Function to take in minutes and return a string formatted in time format
	string returnTimeFormatted(int minutes)
	{
		// Stringstream used to convert int to string
		// Variables for function
		stringstream s;
		string k;
		string timeFormatted;

		// If statement to determine how to format minutes
		// Nested if statement to fix dropped leading zeroes during int to string conversion
		if (minutes <= 59)
		{
			s << minutes;
			s >> k;
			if (minutes < 10) timeFormatted = "10:0" + k;
			else
				timeFormatted = "10:" + k;
		}
		else if (minutes >= 60 && minutes < 119)
		{
			minutes = minutes - 60;
			s << minutes;
			s >> k;
			if (minutes < 10) timeFormatted = "11:0" + k;
			else
				timeFormatted = "11:" + k;
		}
		else if (minutes >= 120 && minutes < 180)
		{
			minutes = minutes - 120;
			s << minutes;
			s >> k;
			if (minutes < 10) timeFormatted = "12:0" + k;
			else
				timeFormatted = "12:" + k;
		}

		// @Return
		// Return the formatted string
		return timeFormatted;
	}
};

// Class to keep track of minutes passed during simulation
class Timer
{
public:
	int time = 0;
	void incrementTime(int minutes)
	{
		this->time = time + minutes;
	}
	void setTime(int time)
	{
		this->time = time;
	}
};

// Class to provide proper reporting numbers after simulation
class Reports
{
public:

	// Use a FormatTime object
	FormatTime formatTime;

	// Use a deque of customer type
	deque<Customer> reportingForReception;

	// Fill the deque
	void createCustList(Customer customer)
	{
		reportingForReception.push_back(customer);

	}

	// Average the number of customers waiting at any given time
	int generateAvgWaitingCust(stack<int> numCustomers, stack<int> numCustWaiting)
	{
		int avgWaitingCust = 0;
		int totalNumCust = 0;

		for (int i = 0; i < numCustWaiting.size(); i++)
		{
			avgWaitingCust += numCustWaiting.top();
			numCustWaiting.pop();
		}

		for (int i = 0; i < numCustomers.size(); i++)
		{
			totalNumCust += numCustomers.top();
			numCustomers.pop();
		}

		return avgWaitingCust / totalNumCust;

	}

	// Reporting
	void printCustReportingData()
	{
		int avgWaitTime = 0;

		stack<int> numCustomers;
		
		for (int i = 0; i < reportingForReception.size(); i++)
		{
			cout << "\t\t\n\tCustomer ID: " << reportingForReception.front().custID << endl;
			cout << "\t\tFirst Name: " << reportingForReception.front().fName << endl;
			cout << "\t\tLast Name: " << reportingForReception.front().lName << endl;
			cout << "\t\tTime of Arrival: " << formatTime.returnTimeFormatted(reportingForReception.front().timeIn) << endl;
			cout << "\t\tTransaction Time Taken: " << reportingForReception.front().transTimeTaken << endl;
			cout << "\t\tTransaction Type: " << reportingForReception.front().transType << endl;
			cout << "\t\tMoney Involved: " << reportingForReception.front().money << endl;
			cout << endl;

			avgWaitTime += reportingForReception.front().transTimeTaken;
			numCustomers.push(1);

			reportingForReception.pop_front();
		}

		avgWaitTime = avgWaitTime / numCustomers.size();

		cout << "\n\t\tAverage Wait Time Per Customer: " << avgWaitTime << endl;
		
	}
};

// Main function
// Driver code
int main() 
{

	// Seed for rand()
	srand(time(0));

	// Timer object to track time
	Timer timer;

	// Reports object to generate reports
	Reports reports;

	// Some variables needed
	int numCust = 0;
	int timePassed = 0;

	// Names to be pulled from for random generation of customers
	string fNames[] = { "Cymone","Courtney","Porter","Walton","Davin","Tobin","Elihu","Sandy","Darcie","JoBeth",
						"Darius","Sherwood","Sharmaine","Katheryne","Ulysses","Milton","Meriwether","Sally","Gwenevere",
						"Aaron","Jezza","Leroy","Zoe","Syd","Briana","Kelsie","Fitz","Shawnee","Carlisle","Constant" };
	string lNames[] = { "Graves","Aguilar","Mccann","Knight","Curry","Reyes","Jordan","Sherman","Christensen","Mills",
						"Graham","King","Tucker","Jenkins","Johnson","Carpenter","Fields","Castaneda","Daniel",
						"French","Wyatt","Byrne","Ward","Moody","Montgomery","Todd","Parker","Reid","Wright","Bradley" };

	// Deques needed for program functionality
	// Every customer added to customers deque
	// Then, depending on how many customers are
	// in the queue, customers are pulled and
	// added to correct number of tellers, either
	// one, two, or three
	deque<Customer> customers;
	deque<Customer> teller1;
	deque<Customer> teller2;
	deque<Customer> teller3;

	// Some stacks for generating reporting numbers
	stack<int> numCustomers;
	stack<int> numCustWaiting;

	// Program title message
	cout << "\t\tBank Reception runs from 10:00am until 1:00pm." << endl;
	

		// Outer loop to simulate three hours of reception time
		for (int outerCount = 1; outerCount <= 3; outerCount++)
		{

			// Loop to simulate one hour of reception time
			// in 20 minute increments
			for (int count = 1; count <= 3; count++)
			{
				// Set time passed to 20 minutes
				timePassed += 20;

				// Random number of customers generated
				numCust = 1 + rand() % 9;

				// Populate the queue with customers
				// and generate their respective
				// fields
				for (int i = 1; i <= numCust; i++)
				{
					// Generate customer information as well as
					// increment time
					int custID = 1 + rand() % 5000;
					string fName = fNames[0 + rand() % 29];
					string lName = lNames[0 + rand() % 29];
					int transactionType = 1 + rand() % 4;
					int money = 100 + rand() % 9900;
					int minutes = 1 + rand() % 3;
					timer.incrementTime(minutes);
					int timeIn = timer.time;

					// Create a customer object
					Customer customer(custID, fName, lName, transactionType, money, timeIn);

					// Store customer objects in the queue
					customers.push_back(customer);
					reports.createCustList(customer);
					numCustomers.push(1);

				}

				// Loop to process customers using 1, 2, or 3 Teller lines
				// depending on number of customers in line.  Loop runs
				// until main line is empty, or time passes a certain point
				// and the program breaks out of the loop to start again
				for (int i = 0; i <= customers.size(); i++)
				{
					// One teller
					if (customers.size() <= 4)
					{
						// Number of customers waiting for reporting purposes
						numCustWaiting.push(customers.size());

						// Add customer to teller line
						teller1.push_front(customers.front());

						// Remove customer from main line
						customers.pop_front();

						// Increment time taken to help customer
						timer.incrementTime(teller1.front().timeOut - teller1.front().timeIn);

						// Remove customer from teller line
						teller1.pop_front();

					}
					// Two tellers
					else if (customers.size() > 4 && customers.size() < 9)
					{
						// Number of customers waiting for reporting purposes
						numCustWaiting.push(customers.size());

						// Add customer to teller1 line
						teller1.push_front(customers.front());

						// Remove customer from main line
						customers.pop_front();

						// Add customer to teller2 line
						teller2.push_front(customers.front());

						// Remove customer from main line
						customers.pop_front();

						// Increment time taken to help customers
						if (teller1.front().timeOut - teller1.front().timeIn > teller2.front().timeOut - teller2.front().timeIn)
							timer.incrementTime(teller1.front().timeOut - teller1.front().timeIn);
						else
							timer.incrementTime(teller2.front().timeOut - teller2.front().timeIn);

						// Remove customers from teller lines
						teller1.pop_front();
						teller2.pop_front();

					}
					// Three tellers
					else if (customers.size() >= 9)
					{
						// Number of customers waiting for reporting purposes
						numCustWaiting.push(customers.size());

						// Add customer to teller1 line
						teller1.push_front(customers.front());

						// Remove customer from main line
						customers.pop_front();

						// Add customer to teller2 line
						teller2.push_front(customers.front());

						// Remove customer from main line
						customers.pop_front();

						// Add customer to teller3 line
						teller3.push_front(customers.front());

						// Remove customer from main line
						customers.pop_front();

						// Increment time taken to help customers
						if (teller1.front().timeOut - teller1.front().timeIn > teller2.front().timeOut - teller2.front().timeIn &&
							teller1.front().timeOut - teller1.front().timeIn > teller3.front().timeOut - teller3.front().timeIn)
							timer.incrementTime(teller1.front().timeOut - teller1.front().timeIn);
						else if (teller2.front().timeOut - teller2.front().timeIn > teller1.front().timeOut - teller1.front().timeIn &&
							teller2.front().timeOut - teller2.front().timeIn > teller3.front().timeOut - teller3.front().timeIn)
							timer.incrementTime(teller2.front().timeOut - teller2.front().timeIn);
						else
							timer.incrementTime(teller3.front().timeOut - teller3.front().timeIn);

						// Remove customers from teller lines
						teller1.pop_front();
						teller2.pop_front();
						teller3.pop_front();

					}
					if (timer.time >= timePassed) break;

				}


			}

		}	
	

	// Generate reporting
	cout << "\n\t\tHere are the reporting numbers: " << endl;
	cout << "\t\tCustomers served: " << endl;
	reports.printCustReportingData();
	cout << "\n\t\tAverage Number of Customers Waiting: " << reports.generateAvgWaitingCust(numCustomers, numCustWaiting);

	return 0;
}