/**
 * Swift Ticket -- Front End Interface
 *
 * Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
 * All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FRONTEND_HPP_
#define FRONTEND_HPP_

#include <iostream>
#include <string>

using namespace std;

/**
 * A simple alternative to the getline function which provides support for
 * throwing an exception if the EOF character is found. This makes it
 * possible to support automated testing using the test harness.
 * @param input_stream The input stream
 * @param target The target string object to write the input to
 * @return A reference to the input stream
 */
istream& get_input(std::istream& input_stream, string& target);


#endif /* FRONTEND_HPP_ */
