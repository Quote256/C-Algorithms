#include <iostream>
#include <string>

using namespace std;

struct DeqNode
{
    int appStartTime;
    int appEndtime;
    string custName;
    DeqNode *prevNode;
    DeqNode *nextNode;
};

void Choices();

struct DeqNode *queue;

void addApp();
int count = 0;

int main()
{
    int choice;
    bool isTrue;
    int start, end;
    string name;

    DeqNode *appt = new DeqNode();

    while (isTrue == true)
    {
        Choices();
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your start time as a float: \n";
            cin >> start;
            cout << "\n";
            cout << "Enter your end time as a float: \n";
            cin >> end;
            if ((end - start) != 1)
            {
                cout << "This is not an hour long appointment. Try again!\n";
                main();
            }
            else if ((end - start) == 1)
            {
                // check if there is an interference with another time slot
                if (start >= appt->appStartTime)
                {
                    cout << "Sorry this time is not available";
                }
                else
                {
                    DeqNode *appt = new DeqNode();
                    appt->appStartTime = start;
                    appt->appEndtime = end;
                    appt->custName = name;
                }
            }
            break;
        case 2:
            isTrue = false;
            break;
        }
    }

    return 0;
}

void Choices()
{
    cout << "Welcome to the BT Salon! Enter: \n";
    cout << "1. Add Appointment\n2. Cancel\n3. View Bookings\n4. Exit";
}