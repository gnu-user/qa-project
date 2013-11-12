FRONT-END SOURCE CODE GUIDELINE NOTES
========================================

These are basically the style/format guidelines we have for the code we are writing, this
has to be submitted as 6/10 marks for phase 2 is based on our code structure, naming conventions,
consistency, etc..


*We are using our own style guideline based slightly off of Google's with some pragmatic improvements
targeted at modern C++ development. *


File Naming Convention
-----------------------

1.  Header files are named using the C++ header file naming convention *.hpp* so that
    C++ header files are not confused with C header files

2.  Source files are named using the C++ source file naming convention *.cpp* so that
    C++ source files are not confused with C source files.


Variable Convention
-----------------------

1.  The variable naming conventional uses underscores such as like_this or
    a_long_variable_name.


Class/OOP Conventions
------------------------

1.  Similarly to google style class names must be camel-case and start with a capital letter
    e.g. MyClass, ErrorHandling, TransactionCode

2.  Multiple inheritance should never be used, just as with google's guidelines a pure interface
    should be used

3.  Dominant naming convention for c++ is not camelCase...


Code Formatting
----------------

1.  I hate the *80 character* per line limit, if you're still programming on a 80x24 monitor in 2013 then
    I will purchase you a new monitor and we can be rid of the 80 character limit!

2.  I like the convention of *aim for 80* with a hard limit ~100, for most non-C code and longer variable names
    it is very hard to cleanly meet the 80 character limit without ugly multi-line statements for everything

3.  NO TAB CHARACTERS! Tabs are evil, all indentation MUST BE SPACE CHARACTERS ONLY! Use four space characters to
    represent one tab.

4.  All code blocks/curly braces MUST ALWAYS be on the next line, no exceptions!

        class MyClass
        {
            ...
        }

        if (condition)
        {

        }

        for (...)
        {
            ...
        }

5.  A curly brace indicating a code block must not have ANY OTHER STATEMENTS on the same line, for example
    the following is *bad* style

    if (condition)
    {
        ...
    } else          // BAD
    {
        ...
    }


### Conditionals

1.  Conditional statement conditionals must always have the parenthesis one space after the "if" keyword

        if ( ... )

2.  Conditions within the parenthesis must not have a space UNLESS it enhances the readability, such as
    when you have multiple parenthesis to enforce order of operations

        if (variable <= variable2)

        if ( (variable + 5) / (variable2 - 3) )

3.  Every conditional, even if it is one line must have a curly brace to identify the code block, in keeping
    with brace convention, it must be on the next line.

        if (variable == 5)
        {
            return false;
        }

4.  An if statement followed by an else statement MUST have the else statement on the next line.

        if (variable)
        {
            ...
        }
        else
        {
            ...
        }

5.  Switch statements must have each case indented exactly 2 space characters, the code block for the case
    must be indented 4 spaces.

        switch (var)
        {
          case 0:    // 2 space indent
          {  
            ...      // 4 space indent
            break;
          }
          
          case 1:
          {
            ...
            break;
          }
          
          default: 
          {
            assert(false);
          }
        }


### Iteration

1.  Similarly to conditionals, the conditional for the iteration statement the parenthesis must be 
    one space after the keyword

        while (condition)
        {
            ...
        }

2.  Similarly to conditionals, conditions within the parenthesis must not have a space UNLESS it 
    enhances the readability

        while ( ((y_2 - y_1) / (x_2 - x_1)) >= 3 )
        {
            ...
        }

3.  Every iteration statement, even if it is one line must have a curly brace to identify the code block, 
    in keeping with brace convention, it must be on the next line.

        while (variable < 5)
        {
            ++variable;
        }
    

### Functions

1.  Function definitions and calls must have the parenthesis directly after the function name, curly 
    brace for code block must be on separate line. 

        void my_func(...)
        {

        }


        my_func(...)

2.  Function arguments must be separated by a space for definition and calling, except for the first
    and last argument.

        big_function(var_1, var_2, var_3, var_4)

3.  Function arguments can be separated by a space for the first and last argument IF it enhances readability

        math_operation( (x_1 - x_2) / 2, (y_1 - y_2) / 3 )


### Classes

1.  Public and private, the public and private fields must be aligned with the curly braces, the statements
    for each method and member are indented four spaces.


        MyClass
        {
        private:
            variable;        // 4 space indent

        public:
            get_variable();  // 4 space indent
        }
