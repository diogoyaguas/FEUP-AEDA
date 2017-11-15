#ifndef AEDA_INTERFACES_H
#define AEDA_INTERFACES_H

#include "Company.h"

/**
 * @brief shows main options and redirects user to next menu according to input
 *
 */
void mainMenu(Company &company);

/**
 * @brief shows options related to the search of beaches and collects input
 */
void searchMenu(Company &company);


void AddAlterRemoveMenu(Company &company);

void AlterBeachMenu(Company &company);

/**
 * @brief verifies if input given by user is between lowerL and upperL
 * @param lowest input int possible
 * @param highest input int possible
 * @param input entered by user
 * @return 0 if success, 1 otherwise
 */
bool ValidMenuInput(int lowerL, int upperL, int input);


/**
 * gives the user 0.6 seconds to read welcome message before continuing program
 */
void timer();

#endif //AEDA_INTERFACES_H
