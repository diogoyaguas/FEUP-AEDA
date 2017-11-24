#ifndef AEDA_INTERFACES_H
#define AEDA_INTERFACES_H

#include "Company.h"

/**
 * @brief Redirects to main menu when user enters 0.
 */
void returnMainMenu();

/**
 * @brief Tests cin.fail.
 * @tparam template class T
 * @param value
 */
template <class T>
void fail (T &value){

    while(cin.fail()){

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid value: ";
        cin >> value;
    }
}

/**
 * @brief Main menu that allows user to choose a topic to take action in.
 * @param company
 */
void mainMenu(Company &company);

/**
 * @brief Sub-menu from main menu that allows user to choose actions relating to the search of a determinate beach.
 * @param company
 */
void searchMenu(Company &company);

/**
 * @brief Sub-menu from main menu that allows user to choose actions relating altering informarion about a beach, adding or removing beaches.
 * @param company
 */
void AddAlterRemoveMenu(Company &company);

/**
 * @brief Sub-menu from Add, Alter ,Remove menu that allows user to choose which information of the beach he wishes to alter.
 * @param company
 */
void AlterBeachMenu(Company &company);

/**
 * @brief Verifies if input given by user is between lowerL and upperL.
 * @param lowest input int possible
 * @param highest input int possible
 * @param input entered by user
 * @return 0 if success, 1 otherwise
 */
bool ValidMenuInput(int lowerL, int upperL, int input);

/**
 * @brief Clears screen.
 */
void ClearScreen();

/**
 * @brief Sub-menu from Main menu that allows user to compare beaches.
 * @param company
 */
void compareMenu(Company &company);

#endif //AEDA_INTERFACES_H
