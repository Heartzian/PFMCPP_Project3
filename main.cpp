/*
Project 3 - Part 1b / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

1)  Fill in #1 - 4 with a random UDT in plain english
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or properties and 3 things it can do
        b) remember: these properties will eventually become primitives.
        pick properties that can be represented with 'int float double bool char std::string'
*/

/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has eco-friendly cleaning supplies" as one of the properties
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    In addition to the usual primitives (covered in Project 2), you can use 'std::string' to represent strings in this project.
 */

/*
Thing 1) Market
5 properties:
    1) number of products in local inventory
    2) number of vehicles used in logistics
    3) number of people working in store
    4) amount of utilities
    5) daily income
3 things it can do:
    1) Sell daily use products
    2) Help customers with any issue
    3) Deliver products
 */

/*
Thing 2) University
5 properties:
    1) number of classrooms
    2) number of laboratories
    3) number of professors
    4) amount of semestral income
    5) classes taken per period  
3 things it can do:
    1) Teach students
    2) Do collaborate research 
    3) Perform cultural activities
 */

/*
Thing 3) Computer
5 properties:
    1) amount of used energy
    2) amount of required memory to run multiple programs
    3) amount of daily used disk space
    4) number of execution errors
    5) task executed per day
3 things it can do:
    1) Execute Programs
    2) Save Information
    3) Connect with other computers
 */

/*
Thing 4) Audio Mixer
5 properties:
    1) number of input channels
    2) number of output channels
    3) number of signal processing options
    4) number of simultaneous processing objects
    5) speed of DSP
3 things it can do:
    1) Mix multiple signals into an stereo one
    2) Split signal to be delivered at different points
    3) Process signal (EQ, Fx, Dynamics)
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
