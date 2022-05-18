#pragma once
#ifndef SEARCHUNSORTED_H
#define SEARCHUNSORTED_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "input.h"

using namespace std;

class SearchUnsorted
{
private:
    string *arr;
    int SIZE;

public:
    // Constructor
    SearchUnsorted()
    {
        SIZE = 0;
        arr = new string[SIZE];
    }
    // Destructor
    ~SearchUnsorted()
    {
        delete[] arr;
    }
    // Resize Dynamic Array
    void resize()
    {
        string* arr2;
        arr2 = new string[SIZE + 1];
        for (int i = 0; i < SIZE; i++)
            arr2[i] = arr[i];

        delete[] arr;

        arr = new string[SIZE + 1];
        for (int i = 0; i < SIZE; i++)
            arr[i] = arr2[i];
        delete[] arr2;
    }

    // Precondition: arr[](string), size(int), x(string)
    // Postcondition: return the index an element in the array
    int elmntSrch(string arr[], int size, string x)
    {
        int rec;
        size--;

        if (size >= 0) {
            if (arr[size] == x)
                return size;
            else
                rec = elmntSrch(arr, size, x);
        }
        else
            return -1;

        return rec;
    }

    // Precondition: arr[](string), size(int), x(string)
    // Postcondition: return the index an element in the array
    int binarySearch(string arr[], int l, int r, string x)
    {
        for (int i = 1; i <= SIZE; i++)
        {
            cout << arr[i - 1] << " ";
            if (i % 15 == 0)
                cout << "\n\t";
        }

        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if x is present at mid
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }

        // if we reach here, then element was
        // not present
        return -1;
    }

    void mainProcess()
    {
        /* initialize random seed: */
        srand(time(NULL));
        do
        {
            switch (mainMenu())
            {
            case '0': return; break;
            case 'A': 
            {
                SIZE = inputInteger("\tEnter the size of the dynamic array: ", true);
                delete[] arr;
                arr = new string[SIZE];
                for (int i = 0; i < SIZE; i++)
                {
                    arr[i] = "str#" + to_string(rand() % SIZE + 1);
                }

                cout << "\n\tRandom elements have been populated into the array.\n";
            } break;
            case 'B':
            {
                string newElem = inputString("\tEnter a string element: ", true);
                resize();
                arr[SIZE] = newElem;
                SIZE++;

                cout << "\n\tElement \"" + newElem + "\" has been added to the array.\n";
            } break;
            case 'C':
            {
                if (SIZE > 0)
                {
                    cout << "\t";
                    for (int i = 1; i <= SIZE; i++)
                    {
                        cout << arr[i - 1] << " ";
                        if (i % 15 == 0)
                            cout << "\n\t";
                    }
                }
                else
                    cout << "\tThe array is empty.";
                
                cout << endl;
            } break;
            case 'D':
            {
                char option = inputChar("\tChoose search type (S)Serial or (B)Binary: ", 'S', 'B');
                int n = sizeof(arr) / sizeof(arr[0]);
                
                switch (option)
                {
                case 'S':
                {
                    cout << "\n\t\Recursive serial search";
                    cout << "\n\t" << string(50, char(196));
                    string find = inputString("\n\tEnter a string element to search: ", true);
                    int index = elmntSrch(arr, SIZE, find);
                    (index == -1)
                        ? cout << "\n\t\"" << find << "\" is not found in the unsorted array.\n"
                        : cout << "\n\t\"" << find << "\" is found at index " << index << " from the unsorted array.\n";

                } break;
                case 'B': 
                {
                    cout << "\n\t\Recursive binary search";
                    cout << "\n\t" << string(50, char(196));

                    string find = inputString("\n\tEnter a string element to search: ", true);

                    int index = binarySearch(arr, 0, n - 1, find);
                    (index == -1)
                        ? cout << "\n\t\"" << find << "\" is not found in the unsorted array.\n"
                        : cout << "\n\t\"" << find << "\" is found at index " << index << " from the unsorted array.\n";


                } break;
                default: cout << "\tERROR - Invalid option. Please re-enter.\n"; break;
                }
            } break;
            case 'E':
            {
                if (SIZE > 0)
                {
                    arr->clear();
                    SIZE = 0;
                    cout << "\tElements from the array have been cleared/deleted.\n";
                }
                else
                    cout << "\tThe array is empty.\n";
            } break;
            default: cout << "\tERROR - Invalid option. Please re-enter.\n"; break;
            }
            cout << '\n';
        } while (true);        
    }
    // Main Menu
	char mainMenu()
	{
        cout << "\t" << string(60, char(205));
        cout << "\n\t1> Searching unsorted dynamic arrays";
        cout << "\n\t" << string(60, char(205));
        cout << "\n\t\tA> Read data file and store into the array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";
        cout << "\n\t" << string(60, char(196));;
        cout << "\n\t\t0> Return";
        cout << "\n\t" << string(60, char(205)) << "\n";

        char option = inputChar("\t\tOption: ");
        system("cls");
        if (option == '0') return '0';

        cout << '\n';
        return option;
	}
};

#endif // !SEARCHUNSORTED_H
