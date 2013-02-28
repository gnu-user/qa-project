#include "../include/Validate.hpp"
#include "Poco/String.h"
#include "Poco/Exception.h"
#include "Poco/NumberParser.h"
#include "Poco/RegularExpression.h"

using Poco::toLower;
using Poco::NumberParser;
using Poco::SyntaxException;
using Poco::RegularExpression;

bool Validate::username(string username)
{
    /* Verify the username length */
    if (username.length() > 15)
    {
        throw Exception(INVALID_USER_LENGTH);
    }

    /* Verify the username is not END */
    if (toLower(username).compare("end") == 0)
    {
        throw Exception(INVALID_USER_RESERVED);
    }

    /* Verify the username matches the format */
    RegularExpression re("^[A-Za-z0-9_]{1,15}$");

    return re.match(username);
}

bool Validate::title(string title)
{
    /* Verify the title length */
    if (title.length() > 19)
    {
        throw Exception(INVALID_TITLE_LENGTH);
    }

    /* Verify the title does not have and of the following instances of "END":
     * END (one word)
     * The END (last word)
     * END of world (END with space on right)
     * The END of fun (END with spaces)
     */
    RegularExpression re_end("(^END$)|(^END\\s.*$)|(^.*?\\sEND$)|(^.*?\\sEND\\s.*$)");
    if (re_end.match(title))
    {
        throw Exception(INVALID_TITLE_RESERVED);
    }

    /* Verify the event matches the format */
    RegularExpression re("^.{1,19}$");

    return re.match(title);
}

bool Validate::cua_entry(string entry)
{
    /* Verify that the current user accounts entry matches format */
    RegularExpression re("^[A-Za-z0-9_]{15}_(AA|FS|BS|SS)_[0-9]{6}\\.[0-9]{2}$");

    return re.match(entry);
}

bool Validate::atf_entry(string entry)
{
    /* Verify that the available tickets file entry matches format */
    RegularExpression re("^.{19}_[A-Za-z0-9_]{15}_[0-9]{3}_[0-9]{3}\\.[0-9]{2}$");

    return re.match(entry);
}

bool Validate::dollars(string amount, double& converted)
{
    /* Verify the amount provided can be converted to float */
    try
    {
        converted = NumberParser::parseFloat(amount);
    }
    catch (SyntaxException& s)
    {
        throw Exception(INVALID_SALE_PRICE);
    }

    /* Verify the amount is not negative */
    if (converted < 0.0)
    {
        throw Exception(SALE_PRICE_NEGATIVE);
    }

    return true;
}

bool Validate::volume(string amount, int& converted)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
