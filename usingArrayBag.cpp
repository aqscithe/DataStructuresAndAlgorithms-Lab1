/*
-------------------------------------------------------------------------
Name:			Leon Thompson
Date:			02/25/2024
Lab #:			Exam 1
Status: 		Completed
-------------------------------------------------------------------------
Description
	The program acts as a digital bag interface, allowing the user to 
	input values of several types, as well as remove items, clear the
	bag, sort items and search for a specific value, assuming the bag
	has been appropriately sorted.
-------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
#include "ArrayBag.h"



void greetUser();
void displayMainMenu();
void displayBagHeader();
void displayBagTypes();
char getCharData(std::string);
int getIntegerData(std::string);
void clearCin();

template <typename ItemType>
void handleBagSort(ArrayBag<ItemType>& bag);

template <typename ItemType>
void runBagProgram(ArrayBag<ItemType>& bag);

template <typename ItemType>
ItemType getGenericData(std::string& prompt);

template <>
int getGenericData(std::string& prompt);

template <>
float getGenericData(std::string& prompt);

template <>
double getGenericData(std::string& prompt);

template <>
std::string getGenericData(std::string& prompt);


int main()
{
	greetUser();
	char typeSelection;

	displayBagTypes();
	typeSelection = getCharData("What type of values would you like to hold in the bag: ");

	// ArrayBag Type Selection
	switch (typeSelection)
	{
		case 'I':
		{
			ArrayBag<int> bag;
			runBagProgram(bag);
			break;
		}
		case 'F':
		{
			ArrayBag<float> bag;
			runBagProgram(bag);
			break;
		}
		case 'S':
		{
			ArrayBag<std::string> bag;
			runBagProgram(bag);
			break;
		}
		case 'D':
		{
			ArrayBag<double> bag;
			runBagProgram(bag);
			break;
		}
		
		default:
		{
			std::cout << "Invalid selection. Exiting..." << std::endl;
			break;
		}
	} // end switch


   return 0;
   
}  // end main


/****************************************************************/
/* Function:   greetUser
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function greets the user upon app load
/****************************************************************/
void greetUser()
{
	std::cout << "WELCOME TO IONIAN BAGS INC." << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Here, you have access to a digital bag with the following capabilities: " << std::endl;
	std::cout << "\tDisplay the bag contents" << std::endl;
	std::cout << "\tAdd values to the bag" << std::endl;
	std::cout << "\tRemove values from the bag" << std::endl;
	std::cout << "\tSort the bag" << std::endl;
	std::cout << "\tSearch the bag for a value using a recursive or iterative search" << std::endl;
	std::cout << "The Fine Print:" << std::endl;
	std::cout << "\tEach state of the art bag can hold a max of 30 values" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
} // end of greetUser()


/****************************************************************/
/* Function:   displayMainMenu
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function displays the main menu options
/****************************************************************/
void displayMainMenu()
{
	displayBagHeader();
	std::cout << "Main Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "D\tDisplay the bag contents" << std::endl;
	std::cout << "A\tAdd value to bag" << std::endl;
	std::cout << "R\tRemove value from bag" << std::endl;
	std::cout << "C\tClear bag contents" << std::endl;
	std::cout << "S\tSort the bag" << std::endl;
	std::cout << "L\tSearch the bag" << std::endl;
	std::cout << "Q\tQuit" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

} // end of displayMainMenu()


/****************************************************************/
/* Function:   displayBagTypes
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function displays the types the bag holds
/****************************************************************/
void displayBagTypes()
{
	displayBagHeader();
	std::cout << "Bag Content Type" << std::endl;
	std::cout << std::endl;
	std::cout << "I\tIntegers" << std::endl;
	std::cout << "F\tFloats" << std::endl;
	std::cout << "D\tDoubles" << std::endl;
	std::cout << "S\tStrings" << std::endl;
} // end displayBagTypes


/****************************************************************/
/* Function:   displayBagTypes
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function displays the store header
/****************************************************************/
void displayBagHeader()
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "IONIAN BAG INTERFACE" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;

} // end of displayBagHeader


/****************************************************************/
/* Function:   handleBagSort
/* Inputs:     ArrayBag<ItemType>& bag
/* Outputs:    none
/* Purpose:    This function calls bags sorting function and 
/*			   prints related comments
/****************************************************************/
template <typename ItemType>
void handleBagSort(ArrayBag<ItemType>& bag)
{
	std::cout << "Sorting the bag..." << std::endl;
	bag.sortBag();
	std::cout << "Sorting complete." << std::endl;
} // end handleBagSort



/****************************************************************/
/* Function:   getCharData
/* Inputs:     std::string prompt
/* Outputs:    char value
/* Purpose:    This function will get a char value from the user
/****************************************************************/
char getCharData(std::string prompt)
{
	char value;

	std::cout << prompt;
	std::cin >> value;

	clearCin();

	value = toupper(value);

	return value;

} // end getCharData



/****************************************************************/
/* Function:   getCharData
/* Inputs:     std::string prompt
/* Outputs:    int value
/* Purpose:    This function will get an integer value from the user
/****************************************************************/
int getIntegerData(std::string prompt)
{
	int value;
	bool validValue = false;

	while (!validValue)
	{
		std::cout << prompt;

		// Ensures input matches type
		if (!(std::cin >> value))
		{
			std::cout << "\t\t\tError Message. Non numeric value has been entered" << std::endl;
			clearCin();
		}
		else
		{
			validValue = true;
		} // end if

	} // end while

	clearCin();

	return value;


} // end getIntegerData



/****************************************************************/
/* Function:   getCharData
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This functions clears the cin and then clears up to 120
/*				characters or hits enter.
/****************************************************************/
void clearCin()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

} // end clearCin



/****************************************************************/
/* Function:   getGenericData
/* Inputs:     const std::string& prompt
/* Outputs:    ItemType value
/* Purpose:    This templated function gets input data from the user
/****************************************************************/
template<typename ItemType>
ItemType getGenericData(const std::string& prompt) 
{
    std::cout << prompt;
    ItemType value;
    std::cin >> value;
    return value;
} // end getGenericData



/****************************************************************/
/* Function:   getGenericData
/* Inputs:     const std::string& prompt
/* Outputs:    int value
/* Purpose:    This templated function is a specialization that
/* 				int user input
/****************************************************************/
template <>
int getGenericData(std::string& prompt)
{
	int value;
	bool validValue = false;

	while (!validValue)
	{
		std::cout << prompt;

		// Ensures input matches value type
		if (!(std::cin >> value))
		{
			std::cout << "\t\t\tError Message. Non numeric value has been entered" << std::endl;
			clearCin();

		}
		else
		{
			validValue = true;
		} // end if

	}// end while

	clearCin();

	return value;
} // end getGenericData


/****************************************************************/
/* Function:   getGenericData
/* Inputs:     const std::string& prompt
/* Outputs:    float value
/* Purpose:    This templated function is a specialization that
/* 				float user input
/****************************************************************/
template <>
float getGenericData(std::string& prompt)
{
	float value;
	bool validValue = false;
	while (!validValue)
	{
		std::cout << prompt;

		// Ensures input matches value type
		if (!(std::cin >> value))
		{
			std::cout << "\t\t\tError Message. Non numeric is entered" << std::endl;
			clearCin();

			continue;

		}
		else
		{
			validValue = true;
		} // end if

		break;
	} // end while

	clearCin();

	return value;
} // end getGenericData


/****************************************************************/
/* Function:   getGenericData
/* Inputs:     const std::string& prompt
/* Outputs:    double value
/* Purpose:    This templated function is a specialization that
/* 				double user input
/****************************************************************/
template <>
double getGenericData(std::string& prompt)
{
	double value;
	bool validValue = false;
	while (!validValue)
	{
		std::cout << prompt;

		// Ensures input matches value type
		if (!(std::cin >> value))
		{
			std::cout << "\t\t\tError Message. Non numeric is entered" << std::endl;
			clearCin();

			continue;

		}
		else
		{
			validValue = true;
		} // end if

		break;
	} // end while

	clearCin();

	return value;
} // end getGenericData


/****************************************************************/
/* Function:   getGenericData
/* Inputs:     const std::string& prompt
/* Outputs:    string value
/* Purpose:    This templated function is a specialization that
/* 				string user input
/****************************************************************/
template <>
std::string getGenericData(std::string& prompt)
{
	std::string value;

	std::cout << prompt;	

	std::getline(std::cin, value); // accepts spaces in the entry

	return value;
} // end getGenericData



/****************************************************************/
/* Function:   runBagProgram
/* Inputs:     generic array bag
/* Outputs:    string value
/* Purpose:    This templated function is a specialization that
/* 				string user input
/****************************************************************/
template <typename ItemType>
void runBagProgram(ArrayBag<ItemType> &bag)
{
	char mainSelection;
	bool showInterface = true;

	// Interface shows until user quits
	while (showInterface)
	{
		// Begin each loop by displaying Main Menu
		displayMainMenu();

		mainSelection = getCharData("Make Your Selection: ");

		// Menu choices controlled with switch
		switch (mainSelection)
		{
			// Display Bag
			case 'D':
			{
				std::cout << "Diplaying bag contents..." << std::endl;
				bag.displayBag();
				break;
			}

			// Add item
			case 'A':
			{
				ItemType value = getGenericData<ItemType>("Enter a value to be added to the bag: ");
				if (bag.add(value))
				{
					std::cout << value << " successfully added to the bag." << std::endl;
				}
				else
				{
					std::cout << value << " failed to be added to the bag." << std::endl; 
					std::cout << "The bag may be full or the value is not unique" << std::endl;
				} // end if
				
				break;
			}

			// Remove Item
			case 'R':
			{
				ItemType value = getGenericData<ItemType>("Enter a value to be removed from the bag: ");
				if (bag.remove(value))
				{
					std::cout << "One occurrence of " << value << " successfully removed from the bag." << std::endl;
				}
				else
				{
					std::cout << value << " failed to be removed from the bag." << std::endl; 
					std::cout << "Are you sure it exists?" << std::endl;
				} // end if

				break;
			}

			// Clear bag contents
			case 'C':
			{
				std::cout << "Clearing out the bag contents..." << std::endl;
				bag.clear();
				std::cout << "The bag is empty." << std::endl;
				
				break;
			}

			// Sort the bag
			case 'S':
			{
				handleBagSort(bag);
				break;
			}

			// Search bag for a value
			case 'L':
			{
				ItemType searchTarget = getGenericData<ItemType>("Enter search target: ");
				int searchType = getIntegerData("Enter type of binary search: 0 - recursive, 1 - iterative: ");
				int indexLocation = bag.searchBag(searchTarget, searchType);

				// Target Not Found
				if (indexLocation == -1)
				{
					std::cout << searchTarget << " was not found in the bag." << std::endl;
				}

				// Bag not sorted
				else if (indexLocation == -2)
				{
					std::cout << "The bag is not sorted and can not be searched effectively." << std::endl;
					char sortBagChoice = getCharData("Would you like to sort it now? Y - Yes, N - No: ");
					if (sortBagChoice == 'Y')
					{
						handleBagSort(bag);
					}
					else if (sortBagChoice != 'N')
					{
						std::cout << "Invalid response" << std::endl;
					} // end if
				} 

				// Target Found
				else
				{
					std::cout << searchTarget << " was successfully found at position " << indexLocation << std::endl;
				} // end if

				break;
			}

			// Exit the interface and program
			case 'X':
			case 'Q':
			{
				showInterface = false;
				break;
			}
				
			
			default:
			{
				std::cout << "Ionian Bags does not recognize that option. Please try again." << std::endl;
				break;
			}

		} // end switch
	} // end while

	std::cout << "I hope you have had a pleasant experience at Ionian Bags. Have an excellent day!" << std::endl;
}
