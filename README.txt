README FILE FOR QA PROJECT
========================================


CONTENTS
----------------------------------------

1.      FRONT END README
  1.1     How to Build
  1.2     How to Execute
  1.3     Source Code Layout
2.      TEST FRAMEWORK README
  2.1     Prerequisites
  2.2     How to Execute
  2.3     Source Code Summary
3.      BACK END README
  3.1     How to Build
  3.2     How to Execute
4.      BACK END UNIT TESTS README
  4.1     How to Execute Tests
  4.2     Executing the Tests with Eclipse
  4.3     Executing the Tests Using the JAR File




FRONT END README
========================================


How to Build
----------------------------------------

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
----------------------------------------

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
----------------------------------------

All of the source code for the header files (*.hpp) are located in the 
FrontEnd/include directory. All of the C++ source files (*.cpp) are located
in the Frontend/src directory.

Lastly, the project uses POCO library to provide regular expression support.
The header files and library binaries for POCO library are located in the 
lib/ directory.




TEST FRAMEWORK README
========================================

Prerequisites
----------------------------------------

The test framework has been designed for Linux and has been thoroughly tested on
Ubuntu 12.10 64-bit and should work on any system which supports Bash and Ruby. 
If your system does not have Ruby installed by default, such as Ubuntu, you can simply 
install Ruby using the following command on most Debian-based Linux distributions.

    sudo apt-get install ruby


On RedHat based Linux distributions Ruby can be installed using the following command.

    yum install ruby


How to Execute
----------------------------------------

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
----------------------------------------

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




BACK END README
========================================

Please note, javadoc documentation has been included in the BackEnd/doc/ 
folder.


How to Build
----------------------------------------

To build the back end you will need to go to the BackEnd directory located
and execute the make file. The project has been tested on Linux systems, but 
should also work on any Unix-like system such as OS X that has at least Java
1.6 or higher installed.

To build the code simply execute the following commands.

    cd BackEnd
    make

How to Execute
----------------------------------------

To execute the program you must provide a valid current user accounts file,
available tickets file, and daily transactions file. Example files have been
provided and are in the bin/ directory. To execute the back end simply execute 
the following commands, which specifies the classpath for the Google library
dependency.

    java -cp .:../lib/guava-14.0-rc2.jar BackEnd

Alternatively, the program can be executed from the precompiled .jar file,
in instances where make does not work (such as in cygwin), or for your
own convenience.

    cd BackEnd/bin/
    java -jar Backend.jar

Test files have been provided in the bin/ folder, should you desire to use
the back end on sample input. These can be executed as follows:

    cd BackEnd/bin/
    java -jar Backend.jar test.atf test.cua .

For reference, executing the back end without any arguments will output
usage information to the console.




BACK END UNIT TESTS README
========================================

*** PLEASE NOTE ***
JUnit 4 and Eclipse Juno (which is the current version of Eclipse) are required
in order to execute the test suites.

JavaDoc documentation has been included in the BackEnd/doc/ folder.


How to Execute Tests
----------------------------------------

To execute the tests there are two approaches you can take, the easiest is
to import the project in Eclipse and to launch the test runner. This will 
display the results of executing all of the test suites with JUnit in Eclipse 
and provide a detailed summary of the results. However you can also execute
the included JAR file which will execute the tests from the console and display
the results of executing the test suites.
 

Executing the Tests with Eclipse
----------------------------------------

1.  To execute the test suites using Eclipse launch Eclipse and select the menu
    option File --> Import --> Existing Projects into Workspace. Then for the
    entry "Select root directory" select the BackEnd directory to import and
    click finish to import the project.

2.  To execute all of the test suites using JUnit open the source file AllTests.java
    in the test/ directory, then run the source file with Eclipse and use JUnit 4
    to execute the tests.

3.  All of the test suites should now execute and the detailed results of which 
    will be displayed in the JUnit tab in Eclipse.  



Executing the Tests Using the JAR File
----------------------------------------

1.  Alternatively, all of the tests can be executed from the precompiled .jar 
    file. Simply navigate to the main BackEnd/ directory and execute the 
    TestRunner jar file which executes all of the test suites using the 
    following commands.

    cd BackEnd/
    java -jar bin/TestRunner.jar

        
    *** Please note ****
    You MUST execute the Test Runner from the main BackEnd/ directory NOT the
    bin/ directory otherwise the tests will fail because the files/ directory
    which contains input files used for the tests is not located within the 
    bin/ directory.


