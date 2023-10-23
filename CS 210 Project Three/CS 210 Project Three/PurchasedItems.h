#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

// method to lowercase a word for case sentitivity purposes.
string LowerCases(string str)
{
    transform(str.begin(), str.end(), str.begin(), tolower);
    return str;
}

// class for purchaseditems,
class PurchasedItems
{
    private:
        // creates an item object.
        struct item
        {
            string itemName = "null";
            int itemCount = 0;
            item() {}
        };
    
        // array to hold all item objects.
        item* itemList[500];
        int arraySize = 0; // take account of the "real" array size.
    
    public:
        PurchasedItems() 
        {
            // Initialize the itemList array to nullptr
            for (int i = 0; i < 500; i++) {
                itemList[i] = nullptr;
            }
        };
    
        string DisplayInputItemAmount(string input) {
    
            for (int i = 0; i < arraySize; i++) {
                if (LowerCases(input) == LowerCases(itemList[i]->itemName))
                {
                    // display the amout a item is purchased
                    return to_string(itemList[i]->itemCount);
                }
            }
            // returns 0 if the item is not in the list.
            return "0";
        }
    
        void CreateBackupFile() 
        {
            ofstream backupFile("Frequency.dat"); // creates a backup file.
    
            for (int i = 0; i < arraySize; i++) 
            {
                // prints item and frequency number.
                backupFile << itemList[i]->itemName + " " + to_string(itemList[i]->itemCount) << endl;
            }
    
            // closes the back up file.
            backupFile.close();
        }
    
        void AddItem(string name)
        {
            // adding items to our vectors, if it already exists then just add count, if it doesn't then add the new item to the vector.
            for (int i = 0; i < arraySize; i++) {
    
                if (LowerCases(name) == LowerCases(itemList[i]->itemName)) // check if name is equal to the item name if so then cancel out for loop.
                {
                    itemList[i]->itemCount += 1; // add to item's amount count.
                    return;
                }
            }
    
            item* myItem = new item(); // instantiates an item.
            myItem->itemName = name; // add name to item.
            myItem->itemCount = 1; // add a count of one to that new item.
            itemList[arraySize] = myItem; // set item in array.

            //delete myItem; // remove from heap.
    
            arraySize++; // increases the current array size.
    
        }
    
        // method used to print all items.
        void PrintAllItems()
        {
            for (int i = 0; i < arraySize; i++) {
                // print out each item name and amount in chonological order.
                cout << itemList[i]->itemName + " " + to_string(itemList[i]->itemCount) << endl;
            }
            // better organization.
            cout << endl;
        }
    
        void PrintAllHistogramForm()
        {
            // string meant to hold asterisks.
            string Asterisk;
    
            // loop
            for (int i = 0; i < arraySize; i++) {
                for (int k = 0; k < itemList[i]->itemCount; k++) {
                    Asterisk += '*'; // add asterisk to aterisk string.
                }
                // prints out item name + amount of in a histogram form.
                cout << itemList[i]->itemName + " " + Asterisk << endl;
                Asterisk = "";
            }
        }
    
        void IterateList()
        {
            // opens txt file.
            ifstream myFile("input.txt");
            vector<string> outputs;
    
            string line;
            if (myFile.is_open())
            {
                // scans each line.
                while (getline(myFile, line))
                {
                    // saves to a output vector.
                    outputs.push_back(line);
                }
    
                // closes file.
                myFile.close();
            }
    
            else
            {
                // displays that the file was not found.
                cout << "File does not exist." << endl;
            }
    
            // check to see if file was empty or not.
            if (!outputs.empty()) {
                // add item to item vector.
                for (string i : outputs) // adds all items vector list.
                {
                    this->AddItem(i);
                }
            }
    
            else
            {
                // display that the file was empty.
                cout << "File is empty.";
            }
        }
};