#ifndef CURRENTUSERACCOUNTS_HPP_
#define CURRENTUSERACCOUNTS_HPP_

#include "User.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

using namespace std;

/**
 * CurrentUserAccounts Class
 *
 * Used for storing the current user accounts file, and provides
 * functions for interacting with it.
 */
class CurrentUserAccounts
{

private:
	/**
	 * users The list of current users.
	 * cua_file The path to the current user accounts file.
	 */
    vector<User> users;
    string cua_file;

public:
    /* Default nullary constructor */
    CurrentUserAccounts();

    /**
     * CurrentUserAccounts The constructor for the class,
     * requires a reference to the current user accounts file path.
     * @param cua_file The path to the current user accounts file
     * on disk.
     */
    CurrentUserAccounts(string cua_file);
   
    /**
     * has_user Validates and verifies whether a user exists within
     * the current user accounts file.
     * @param username The username to check.
     * @return Returns true if the user exists, false if it does not.
     */
    bool has_user(string username);
   
    /**
     * get_user Returns a user object based on a user account stored
     * within the current user accounts file.
     * @param username The name for the user specified.
     * @return Returns a User object, containing the data for the
     * user account specified.
     */
    User get_user(string username);

    /**
     * display_users Displays the users within the current user
     * accounts file.
     */
    void display_users();

private:
    /**
     * parse Takes in the current user accounts file, and parses it.
     * The output is stored within the CurrentUserAccounts object.
     */
    void parse();
};
#endif /* CURRENTUSERACCOUNTS_HPP_ */
