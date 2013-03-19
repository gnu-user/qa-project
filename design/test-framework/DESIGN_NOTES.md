Test Framework Design Notes
=================================

Basic Requirements
--------------------

1.  Test inputs organized into directories

2.  Organize the execpected output files corresponding to the input files

3.  Create an output directory to store the outputs from test files, must follow
    the same folder heriarchy and naming scheme as the input files.

    --> Essential that the output file layout, naming scheme same as input

4.  Program must take the current user accounts file, avail tickets, dtf as
    arguments (done)

5.  Script must automatically execute all test cases and store console output 
    and daily transaction file (if created as part of test)

6.  Must display the result of each test suite, test case, etc.



Test Framework Design Notes
-------------------------------

1.  Program must take the following arguments

    - the full path and filename of the binary to be executed (ie. bin/FrontEnd)
    - the full path to the root directory of master testsuite (contains master.lst)
    - the root directory of the output folder to store results of test

2.  If the output directory does not exist the program will create one, if the
    other arguments are invalid error is thrown

3.  Before any tests are executed the program must validate that each test suite,
    test case, test case description, etc.. exists if there are ANY errors the
    test framework halts and an error is thrown.

4.  For all *.lst files (master and test suite testcase list) any line starting
    with # is skipped (comment) and any line starting with @ the test suite/case
    is skipped.

5.  Test suites must have a test case list file with the same name as the test
    suite (ie. login test suite has login.lst)

6.  Test suites must have a description file with the same name as the test
    suite that contains a TITLE, DESCRIPTION, and DEPENDENCIES section.

7.  Each test case must also have a description file with the same name as
    the test case that contains a TITLE, DESCRIPTION, and DEPENDENCIES section.

8.  Each test case must have a *.inp, *.out *.cua, *.atf, and *.dtf file with
    the same name for the prefix.

9.  All of the output files as a result of executing the test case have the
    final extension *.test* (e.g. login_1.out would have login_1.out.test).

10. After all of the test suites and test cases have been parsed and created
    as objects test suites and test cases are then executed in the order they
    are listed in the *.lst files.

    --> Any test suites/cases that have depenedencies on suites/cases that are
        ordered after them in the *.lst files cannot be resolved without causing
        circular dependencies.

    --> Tests are executed in the order they appear in the *.lst files, tests
        cannot have dependencies on tests that are listed after them in the *.lst
        files.

12. If a test suite has any test case which has failed the entire test suite is
    considered as having failed. Any individual test case that fails is simply
    that test case, since test cases are atomic tests.

13. If a test suite has dependencies and any test suite dependencies fails then
    the test suite is identified as "Skipped, test suite dependnecies .... not met"

14. If a test case has any dependencies and any test case dependency fails then
    the test case is identified as "Skipped, test case dependnecies .... not met"

15. Each test case is executed, a test case is determined as having passed or failed
    by performing a diff of the *.test files and the expected result files in
    for the test case. Any difference between the two files is marked as a failure

    --> It must output a *.diff file


