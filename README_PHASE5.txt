BACK END README
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


