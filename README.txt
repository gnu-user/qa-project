FRONT END README
==============================


How to Build
------------------------------

The following has been tested thoroughly on Ubuntu 12.10 64-bit.

To build the front end you will need to go to the Debug directory located
in the FrontEnd source folder (FrontEnd/Debug) and execute the make file. 
The project has been designed for Linux systems, but should also work on 
any Unix-like system such as OS X that has the GNU Compiler Collection 
(GCC) installed which supports C++11.

To build the code simply execute the following commands within the 
Debug folder.

    cd FrontEnd/Debug
    make


How to Execute
------------------------------

Please see the test framework README section for instructions on executing the
test framework which will automatically test the front end against all of the
test suites.

To execute the program you must provide a valid current user accounts file,
available tickets file, and daily transactions file. Example files have been
provided and are in the Debug/ directory. To execute the front end interface
simply execute the following commands.

    chmod +x FrontEnd
    ./FrontEnd test.cua test.atf test.dtf


Source Code Layout
------------------------------

All of the source code for the header files (*.hpp) are located in the 
FrontEnd/include directory. All of the C++ source files (*.cpp) are located
in the Frontend/src directory.

Lastly, the project uses POCO library to provide regular expression support.
The header files and library binaries for POCO library are located in the 
lib/ directory.




TEST FRAMEWORK README
==============================

Prerequisites
------------------------------

The test framework has been designed for Linux and has been thoroughly tested on
Ubuntu 12.10 64-bit and should work on any system which supports Bash and Ruby. 
If your system does not have Ruby installed by default, such as Ubuntu, you can simply 
install Ruby using the following command on most Debian-based Linux distributions.

    sudo apt-get install ruby


On RedHat based Linux distributions Ruby can be installed using the following command.

    yum install ruby


How to Execute
------------------------------

The test framework can be manually executed from the test-framework directory, the test
framework will automatically execute each of the test suites in the tests/ directory
and store the resulting console output and daily transaction files to the test-results/
directory.

To execute the test framework simply execute the following commands.

    cd test-framework
    ruby TestFramework.rb ../FrontEnd/Debug/FrontEnd ../tests ../test-results


Where the first argument to the test framework is the path to the front end binary,
the second argument is the tests directory containing the test suites, and the
final argument is the path to the directory to store the test results.


Source Code Summary
------------------------------

The following is a summary of the test framework source code, a more thorough explanation
can be found in the Test Framework Manual document.


TestCase.rb
    - Contains the main class which represents an individual test case
    - Provides a method for parsing the test case description files and dependencies

TestSuite.rb
    - Contains the main class which represents an individual test suite
    - Each test suite is made up of test cases, which is an array of TestCase objects
    - Provides a method for parsing the test suite description files and dependencies
    - Provides a method for parsing the test list and building an array of test cases
      to execute as part of the test suite.

TestFramework.rb
    - Contains the main body of the test framework which parses each of the test suites
      and their corresponding test cases and generates the corresponding objects.
    - The test framework then executes each test case for each test suite and diffs
      the exemplar output with the produced output from the test case and displays a
      status of "Passed" or "Failed" if a test case or a test suite failed.