//
// Created by Beatriz Mendes on 09/11/2017.
//

#ifndef AEDA_INTERFACES_H
#define AEDA_INTERFACES_H


/**
 * @brief shows main options and redirects user to next menu according to input
 *
 */
void mainMenu();

/**
 * @brief shows options related to the search of beaches and collects input
 */
void searchMenu();

/**
 * @brief shows options related to the comparison of beaches and collects input
 */
void compareBeaches();

/**
 * @brief verifies if input given by user is between lowerL and upperL
 * @param lowest input int possible
 * @param highest input int possible
 * @param input entered by user
 * @return 0 if success, 1 otherwise
 */
bool ValidInput(int lowerL, int upperL, int input);

/**
 * gives the user 0.6 seconds to read welcome message before continuing program
 */
void timer();

#endif //AEDA_INTERFACES_H
