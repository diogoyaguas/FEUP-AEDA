#ifndef PROJAEDA_USEFULFUNCTION_H
#define PROJAEDA_USEFULFUNCTION_H

#include <string>

using namespace std;

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
 *
 * @return Actual date.
 */
string getActualDate();


string divideString(char char_to_find, string & line);

#endif //PROJAEDA_USEFULFUNCTION_H
