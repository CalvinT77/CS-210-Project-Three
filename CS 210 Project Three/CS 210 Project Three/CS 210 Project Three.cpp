// CS 210 Project Three.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PurchasedItems.h"

using namespace std;



void DisplayMenu()
{
    // displays menu option 1
    cout << "\n1: Gets your input, and then print out number of items." << endl;
    // displays menu option 2
    cout << "2: Displays all items name's and amount purchased as numbers." << endl;
    // displays menu option 3
    cout << "3: Displays all items name's and amount purchased as a histogram." << endl;
    // displays menu option 4
    cout << "4: Closes the program." << "\n\n";
}

void MenuOptionOne(PurchasedItems items)
{
    string userInput;
    // get users input
    cout << "Enter Item Name: ";
    cin >> userInput;

    // return item name and amount found, if none is found it will return 0.
    cout << userInput + " " + items.DisplayInputItemAmount(userInput) << endl;
}

void MenuOptionTwo(PurchasedItems items)
{
    // prints a list with numbers that represent the frequency of all items purchased.
    items.PrintAllItems();

}

void MenuOptionThree(PurchasedItems items) 
{
    // prints list of items in chonological order with frequency being displayed as a histogram.
    items.PrintAllHistogramForm();
}

void SwitchFunction( PurchasedItems items) 
{
    int switchnum = 1; // user's number input
    
    DisplayMenu(); // display menu.
    cin.exceptions(istream::failbit); // fail check.

    try
    {
        cout << "Please input a number: "; // displays to the user to input a number.
        cin >> switchnum; // get user's number input.
    }

    catch (ios_base::failure)
    {
        // warn the user by changing number to 5.
        switchnum = 5;

        // Clear cin
        cin.clear();

        // Ignore the rest of the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // switch that uses the user's input to choose from display menu.
    switch (switchnum) {
        case 1:
            MenuOptionOne(items);
            break;
        case 2:
            MenuOptionTwo(items);
            break;
        case 3:
            MenuOptionThree(items);
            break;
        case 4:
            exit(0);
        default:
            // warning.
            cout << "\nNot a choice in the menu, please try again." << endl;
    }
}

int main()
{
    // instantiates the main item class.
    PurchasedItems purchasedItems;

    //iterates over the txt files and add them to array.

    purchasedItems.IterateList(); // gets list of all items in input file.
    purchasedItems.CreateBackupFile(); // creates frequency.dat file.

    // keeps the program running until user's exit.
    while (true) 
    {
        SwitchFunction(purchasedItems);
    }

    return 0;
}