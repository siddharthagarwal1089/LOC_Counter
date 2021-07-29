# LOC_Counter
LOC -> Lines of Code

DOCUMENTATION of software/product development projects, including several logs and conceptual design analytics, is made easier with the help of this program.

It is developed for object-oriented language code files that contain classes(also called proxies) and functions/methods.

The program outputs each proxy name with its LOCs and method count, and the total LOC in the source code file. Check example for more clarity.

----------------------------------------------------------------------------------------------------------------------------
Please note the points while entering the input program/file name:

1. The input file/program must be in the same folder else enter the correct path of the input file/program.
2. Do NOT provide the input file name by command line argument. It is asked to enter in the program itself.
3. Enter the complete input file name with enxtension and it should be less than 50 characters.
4. If wrong file name is entered, this code will terminate with a message to run the code again.
----------------------------------------------------------------------------------------------------------------------------


Please note the points regarding the input program/file content and the output:

1. The input file MUST have 4 tags:
	1. //PROXY BEGIN class_name    -> Before the starting of every class. (CLASS NAME is required)
	2. //PROXY END class_name      -> After the ending of every class. (CLASS NAME is required)
	3. //PROXY FN BEGIN            -> Before the starting of every method/fucntion in class. (METHOD NAME is not required)
	4. //PROXY FN END              -> After the ending of every method/fucntion in class. (METHOD NAME is not required)

2. These 4 specified tags should NOT be INDENTED, i.e any of them should NOT begin with tabs or spaces.
3. Program counts the commented lines also but does not count blank lines.
4. Proxy Name should NOT exceed 100 characters.
5. Proxy LOC considers //PROXY BEG....... and //PROXY EN....... also in the count.
6. Only Total LOC will be shown if the input file does not contain the specified tags.

7. Consider this program itself to get more familiar with the input file type.

----------------------------------------------------------------------------------------------------------------------------
EXAMPLE: Source Code Name as input (loc_counter.cpp) ->

    Enter the name of the program/file: loc_counter.cpp

    Proxy Name: InstructMsg
    Number of Methods: 1
    Proxy LOC: 11

    Proxy Name: CodeAnalysis
    Number of Methods: 5
    Proxy LOC: 93

    Proxy Name: Main
    Number of Methods: 1
    Proxy LOC: 19

    Total LOC: 126
    
----------------------------------------------------------------------------------------------------------------------------
