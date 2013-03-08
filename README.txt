FRONT END README
====================


How to Build
--------------------


    To build the front end you will need to go to the Debug directory located
    in the source folder and execute the make file. The project has been designed
    for Linux systems, but should also work on any Unix-like system such as OS X
    that has the GNU Compiler Collection (GCC) installed which supports C++11.

    To build the code simply execute the following commands within the Debug
    folder.

    cd source/Debug
    make



How to Execute
--------------------


    To execute the program you must provide a valid current user accounts file,
    available tickets file, and daily transactions file. Example files have been
    provided and are in the Debug/ directory. To execute the front end interface
    simply execute the follow commands which executes the binary, please note
    on some systems you may need to set the binary as executable.

    chmod +x FrontEnd 
    ./FrontEnd test.cua test.atf test.dtf
    


Source Code Layout
---------------------

    All of the source code for the header files (*.hpp) are located in the 
    source/include directory. All of the C++ source files (*.cpp) are located
    in the source/src directory.

    Lastly, the project uses POCO library to provide regular expression support.
    The header files and library binaries for POCO library are located in the 
    lib/ directory.
