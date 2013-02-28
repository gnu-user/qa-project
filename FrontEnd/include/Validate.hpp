#ifndef VALIDATE_HPP_
#define VALIDATE_HPP_

#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Validate Class
 *
 * Provides functions to validate acceptable inputs and outputs for various
 * other classes.
 */
class Validate
{

public:
    /**
     * username Validates user names, and determines if they conform to the
     * correct format and constraints.
     * @param username The user name to validate.
     * @return Returns true if the user name is valid, false if not.
     */
    static bool username(string username);
   
    /**
     * title Validates event titles, and determines if they conform to the
     * correct format and constraints.
     * @param event The event title to validate.
     * @return Returns true if the event title is valid, false if not.
     */
    static bool title(string event);
   
    /**
     * cua_entry Validates current user accounts file entries, and
     * determines if they conform to the correct format and constraints.
     * @param entry An entry in the current user accounts file.
     * @return Returns true if the entry is valid, false if not.
     */
    static bool cua_entry(string entry);
   
    /**
     * atf_entry Validates available tickets file entries, and
     * determines if they conform to the correct format and constraints.
     * @param entry An entry in the available tickets file.
     * @return Returns true if the entry is valid, false if not.
     */
    static bool atf_entry(string entry);
   
    /**
     * dollars Accepts a price amount input as a string, validates it, and determines
     * if it conforms to the correct format and constraints, then sets
     * the converted parameter into the converted dollar amount.
     * @param amount The amount specified, unformatted, in dollars.
     * @param converted The variable memory space to output the formatted
     * dollar amount to.
     * @return Returns true if the amount specified is a valid amount,
     * false if not.
     */
    static bool dollars(string amount, double& converted);
   
    /**
     * volume Accepts a ticket buy or sell amount as a string, validates it, and
     * determines if it conforms to the correct format and constraints, then sets
     * the converted parameter into the converted volume amount.
     * @param amount The amount of tickets for buy/sell.
     * @param converted The variable memory space to output the formatted volume to.
     * @return Returns true if the amount specified is a valid amount, false if not.
     */
    static bool volume(string amount, int& converted);
};
#endif /* VALIDATE_HPP_ */
