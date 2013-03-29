BACK END README
==============================

Please note, javadoc documentation has been included in the BackEnd/doc/ 
folder.


How to Build
------------------------------

To build the back end you will need to go to the BackEnd directory located
and execute the make file. The project has been tested on Linux systems, but 
should also work on any Unix-like system such as OS X that has at least Java
1.6 or higher installed.

To build the code simply execute the following commands.

    cd BackEnd
    make

How to Execute
------------------------------

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