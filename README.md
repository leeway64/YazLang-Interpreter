# YazLang Interpreter

This project created an interpreter for the programming language YazLang. YazLang is an extremely simple programming language created by Ayaz Latif, a Computer Science instructor at the University of Washington Seattle.

This program is able to interpret files written in YazLang. Since YazLang is a very simple programming language created for educational purposes, it only has three commands: CONVERT, RANGE, and REPEAT.

CONVERT: converts a temperature from Celsius to Fahrenheit or vice versa.

RANGE: prints numbers from the first argument to the second argument, incrementing by the third argument.

REPEAT: repeats a string a certain number of times. Will always accept a pair of arguments; the first argument is the string to be repeated, and the second is how many times to repeat the string.

The program prompts the user to choose a YazLang file to intepret, then prompts the user for the name of an output file to print the results to. The YazLang interpreter also allows the user to view a previously interpreted YazLang file. Consider this example, from the original assignment specifications:

![Sample Execution](https://github.com/leeway64/YazLang-Interpreter/blob/main/Sample%20Execution.jpg)

I would like to give credit to the UWS CSE 142 summer 2020 course website for providing the specifications for this project. For more information on this project, the original assignment specifications can be found here: [CSE 142 HW page](https://courses.cs.washington.edu/courses/cse142/20su/homework.html#a6). The original assignment was meant to be written in Java, but I completed the assignment using C++.
