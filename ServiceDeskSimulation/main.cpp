#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <string>

using namespace std;

/* Author: Rodney Nedlose
 * Date: 10.10.19
 * File:   ServiceDeskSimulation.cpp
 * Purpose: Program that simulates a service ticket desk system.
 * 100 tickets are randomly assigned priority levels between 1 and 3 for High,
 * Medium, and Low respectively as well as random times to complete each
 * ticket between 5 and 8 minutes each.  Then, two different deque data structures
 * are filled based on priority.  Program simulates a single line for help as
 * well as two lines.  Reporting stats are displayed below each scenario.
 * Input: None.
 * Output: Reporting statistics on each ticket as well as averages and totals of
 * wait times and number of each priority.
 * Exceptions: None.
 */

int main() {

    // Seed a random time in order to use rand() function
    srand(time(0));

    // Deque data structures
    deque <int> servicePriorities;
    deque <int> serviceTimes;

    // Variables needed for this program
    string priHigh = "High";
    string priMed = "Medium";
    string priLow = "Low";

    int count = 1;

    int totalHigh = 0;
    int totalMed = 0;
    int totalLow = 0;
    int avgHigh = 0;
    int avgMed = 0;
    int avgLow = 0;

    // Simulate one service line using a For loop
    cout << "\tSimulating One Service Line" << endl;
    for (int i = 0; i < 100; i++)
    {
        // Random priorities and service times.
        int priority = 1 + rand() % 3;
        int svcTime = 5 + rand() % 4;

        // If else decision structure to determine where to place each ticket
        if (priority == 1)
        {
            servicePriorities.push_front(priority);
            serviceTimes.push_front(svcTime);
            totalHigh += 1;
            avgHigh += svcTime;
        }
        else if (priority == 2)
        {
            int position = servicePriorities.size() / 2;
            deque <int>:: iterator it = servicePriorities.begin();
            deque <int>:: iterator it2 = serviceTimes.begin();
            it += position;
            it2 += position;
            it = servicePriorities.insert(it, priority);
            it2 = serviceTimes.insert(it2, svcTime);
            totalMed += 1;
            avgMed += svcTime;
        }
        else if (priority == 3)
        {
            servicePriorities.push_back(priority);
            serviceTimes.push_back(svcTime);
            totalLow += 1;
            avgLow += svcTime;
        }
    }

    // Display formatted reporting on tickets and service times.
    // Using a while loop until the deques are empty
    while (!servicePriorities.empty())
    {
        if (servicePriorities.front() == 1) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priHigh << "\t\t\tService Time: " << serviceTimes.front() << endl;
        else if (servicePriorities.front() == 2) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priMed << "\t\tService Time: " << serviceTimes.front() << endl;
        else if (servicePriorities.front() == 3) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priLow << "\t\t\tService Time: " << serviceTimes.front() << endl;

        servicePriorities.pop_front();
        serviceTimes.pop_front();
        count++;
    }

    // Totals / Averages Reporting
    cout << endl << endl;
    cout << "\tReporting Numbers: " << endl;
    cout << "\t\t Number of High Priority Requests: " << totalHigh << endl;
    cout << "\t\t Number of Medium Priority Requests: " << totalMed << endl;
    cout << "\t\t Number of Low Priority Requests: " << totalLow << endl;
    cout << "\t\t Average wait time for High Priority Requests: " << avgHigh / totalHigh << endl;
    cout << "\t\t Average wait time for Medium Priority Requests: " << avgMed / totalMed << endl;
    cout << "\t\t Average wait time for Low Priority Requests: " << avgLow / totalLow << endl;
    cout << endl << endl;

    // Reset variables for use in 2 Lines simulation
    totalHigh = 0;
    totalMed = 0;
    totalLow = 0;
    avgHigh = 0;
    avgMed = 0;
    avgLow = 0;
    count = 1;

    // Simulating two service lines.
    cout << "\tSimulating Two Service Lines" << endl;
    for (int i = 0; i < 50; i++)
    {
        int priority = 1 + rand() % 3;
        int svcTime = 5 + rand() % 4;

        if (priority == 1)
        {
            servicePriorities.push_front(priority);
            serviceTimes.push_front(svcTime);
            totalHigh += 1;
            avgHigh += svcTime;
        }
        else if (priority == 2)
        {
            int position = servicePriorities.size() / 2;
            deque <int>:: iterator it = servicePriorities.begin();
            deque <int>:: iterator it2 = serviceTimes.begin();
            it += position;
            it2 += position;
            it = servicePriorities.insert(it, priority);
            it2 = serviceTimes.insert(it2, svcTime);
            totalMed += 1;
            avgMed += svcTime;
        }
        else if (priority == 3)
        {
            servicePriorities.push_back(priority);
            serviceTimes.push_back(svcTime);
            totalLow += 1;
            avgLow += svcTime;
        }
    }
    while (!servicePriorities.empty())
    {
        if (servicePriorities.front() == 1) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priHigh << "\t\t\tService Time: " << serviceTimes.front() << endl;
        else if (servicePriorities.front() == 2) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priMed << "\t\tService Time: " << serviceTimes.front() << endl;
        else if (servicePriorities.front() == 3) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priLow << "\t\t\tService Time: " << serviceTimes.front() << endl;

        servicePriorities.pop_front();
        serviceTimes.pop_front();
        count++;
    }

    cout << endl << endl;
    cout << "\tReporting Numbers: " << endl;
    cout << "\t\t Number of High Priority Requests: " << totalHigh << endl;
    cout << "\t\t Number of Medium Priority Requests: " << totalMed << endl;
    cout << "\t\t Number of Low Priority Requests: " << totalLow << endl;
    cout << "\t\t Average wait time for High Priority Requests: " << avgHigh / totalHigh << endl;
    cout << "\t\t Average wait time for Medium Priority Requests: " << avgMed / totalMed << endl;
    cout << "\t\t Average wait time for Low Priority Requests: " << avgLow / totalLow << endl;
    cout << endl << endl;


    totalHigh = 0;
    totalMed = 0;
    totalLow = 0;
    avgHigh = 0;
    avgMed = 0;
    avgLow = 0;
    count = 1;

    for (int i = 0; i < 50; i++)
    {
        int priority = 1 + rand() % 3;
        int svcTime = 5 + rand() % 4;

        if (priority == 1)
        {
            servicePriorities.push_front(priority);
            serviceTimes.push_front(svcTime);
            totalHigh += 1;
            avgHigh += svcTime;
        }
        else if (priority == 2)
        {
            int position = servicePriorities.size() / 2;
            deque <int>:: iterator it = servicePriorities.begin();
            deque <int>:: iterator it2 = serviceTimes.begin();
            it += position;
            it2 += position;
            it = servicePriorities.insert(it, priority);
            it2 = serviceTimes.insert(it2, svcTime);
            totalMed += 1;
            avgMed += svcTime;
        }
        else if (priority == 3)
        {
            servicePriorities.push_back(priority);
            serviceTimes.push_back(svcTime);
            totalLow += 1;
            avgLow += svcTime;
        }
    }

    while (!servicePriorities.empty())
    {
        if (servicePriorities.front() == 1) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priHigh << "\t\t\tService Time: " << serviceTimes.front() << endl;
        else if (servicePriorities.front() == 2) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priMed << "\t\tService Time: " << serviceTimes.front() << endl;
        else if (servicePriorities.front() == 3) cout << "\t\tService Ticket: " << count << "\t\tService Priority: " << priLow << "\t\t\tService Time: " << serviceTimes.front() << endl;

        servicePriorities.pop_front();
        serviceTimes.pop_front();
        count++;
    }

    cout << endl << endl;
    cout << "\tReporting Numbers: " << endl;
    cout << "\t\t Number of High Priority Requests: " << totalHigh << endl;
    cout << "\t\t Number of Medium Priority Requests: " << totalMed << endl;
    cout << "\t\t Number of Low Priority Requests: " << totalLow << endl;
    cout << "\t\t Average wait time for High Priority Requests: " << avgHigh / totalHigh << endl;
    cout << "\t\t Average wait time for Medium Priority Requests: " << avgMed / totalMed << endl;
    cout << "\t\t Average wait time for Low Priority Requests: " << avgLow / totalLow << endl;
    cout << endl << endl;

    return 0;
}