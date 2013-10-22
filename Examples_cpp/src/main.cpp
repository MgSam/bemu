#include <iostream>
#include <stdio.h>
#include "api_selector.h"
#include "examples.h"

void main()
{
	cout << "Bloomberg API Emulator Examples" << endl;
    cout << "http://bemu.codeplex.com/" << endl;
    cout << "By: Robinson664" << endl;
    cout << endl;
    cout << "To send a reference data request, push 1" << endl;
    cout << "To send a market data request, push 2" << endl;
    cout << "To send a historical data request, push 3" << endl;
    cout << "To send a intraday tick data request, push 4" << endl;
    cout << "To send a intraday bar data request, push 5" << endl;

	int input = readInteger();
	cout << endl << endl;
	bool informationReturned = true;

	switch(input)
	{
		case 1:
			cout << "Reference data request not yet implemented." << endl;
			informationReturned = false;
			break;
		case 2:
			cout << "Market data request not yet implemented." << endl;
			informationReturned = false;
			break;
		case 3:
			cout << "Historical data request not yet implemented." << endl;
			informationReturned = false;
			break;
		case 4:
			Examples::RunIntradayTickExample();
			break;
		case 5:
			cout << "Intraday bar data not yet implemented." << endl;
			informationReturned = false;
			break;
		default:
			informationReturned = false;
			break;
	}

    if (informationReturned)
    {
        cout << endl;
        cout << "Please note that the data in this request is completely random: it is not real data." << endl;
        cout << "Do not make any trading or investment decisions using the data shown here." << endl;
		cout << endl;
    }

	pressEnterToQuit();
}

int readInteger()
{
	int result = 0;

	cin >> result;
	cin.clear();
	cin.ignore(10000,'\n');

	return result;
}

void pressEnterToQuit()
{
    // wait for enter key to exit application
    cout << endl << endl << "Push enter to quit the application.." << endl;
    char dummy[2];
    cin.getline(dummy, 2);
}