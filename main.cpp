/*
* This program determines which resistors arrangments/configuration to use in a circuit with a given value 
*/
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "E12.h"
using namespace std;

int main()
{
	E12 e12_obj; //object for e12 and e24 series actually
	cout << "This program calculates the inputted resistor value and generates corresponding resistor arrangements based on the E12 series" << endl;
	bool is_Correct = false;
		float inVal;
		int series;
		int cmd = -1;
		do
		{
			cout << "\n\nEnter the resistor value: " << endl;
			cin >> inVal;
			e12_obj.get_resistor(inVal);
			do
			{
				cout << "\n\nChoose resistor Series: " << endl;
				cout << "\n(12) E12" << endl;
				cout << "\n(24) E24" << endl;
				cin >> series;
				if (series == 12)
				{
					e12_obj.get_lists(series);
				}
				else if (series == 24)
				{
					e12_obj.get_lists(series);
				}
				else
				{
					cout << "\nInvalid Resistor Series " << endl;
				}
			} while ((series != 12) && (series != 24));
			do
			{
				cout << "\n(1) Series" << endl;
				cout << "(2) Parallel" << endl;
				cout << "(0) Quit" << endl;
				cout << "\nEnter the command: " << endl;
				cin >> cmd;
				if (cmd == 0)
				{
					exit(0); //quit if cmd = 0
				}
			} while ((cmd != 1) && (cmd != 2));
			e12_obj.get_cmd(cmd);
			e12_obj.calculate_res();			

		} while (cmd != 0);

}