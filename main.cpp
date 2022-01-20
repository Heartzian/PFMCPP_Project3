/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/

/*
Thing 6)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
Thing 7)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */

/*
Thing 8)
5 properties:
    1)
    2)
    3)
    4)
    5)
3 things it can do:
    1)
    2)
    3)
 */




/*
Thing 1) Market
5 properties:
    1) number of products in local inventory (float)
    2) number of vehicles used in logistics (int)
    3) number of people working in store (int)
    4) amount of utilities (float)
    5) daily income (float)
3 things it can do:
    1) Sell daily use products
    2) Help customers with any issue
    3) Deliver products
 */

/*
Thing 2) University
5 properties:
    1) number of classrooms (int)
    2) number of laboratories (int)
    3) number of professors (int)
    4) amount of semestral income (float)
    5) classes taken per period (int)
3 things it can do:
    1) Teach students
    2) Do collaborate research 
    3) Perform cultural activities
 */

/*
Thing 3) Computer
5 properties:
    1) amount of used energy (float)
    2) amount of required memory to run multiple programs (float)
    3) amount of daily used disk space (float)
    4) number of execution errors (int)
    5) task executed per day (int)
3 things it can do:
    1) Execute Programs 
    2) Save Information
    3) Connect with other computers
 */

/*
Thing 4) Audio Mixer
5 properties:
    1) number of input channels (int)
    2) number of output channels (int)
    3) number of signal processing options (int)
    4) number of simultaneous processing objects (int)
    5) speed of DSP (float)
3 things it can do:
    1) Mix multiple signals into an stereo one
    2) Split signal to be delivered at different points
    3) Process signal (EQ, Fx, Dynamics)
 */

/*
Thing 5) Synthetizer
5 properties:
    1) ADSR (float)
    2) Type of signal (bool)
    3) Oscillator (float)
    4) Filters (int)
    5) Effects (int)
3 things it can do:
    1) Generate a signal
    2) Modify the generated signal
    3) Process the modified signal
 */

/*
Thing 9) Synthetizer
5 properties:
    1) ADSR (float)
    2) Type of signal (bool)
    3) Oscillator (float)
    4) Filters (int)
    5) Effects (int)
3 things it can do:
    1) Generate a signal
    2) Modify the generated signal
    3) Process the modified signal
 */

/*
Thing 10) Synthetizer
5 properties:
    1) ADSR
    2) Type of signal
    3) Oscillator
    4) Filters
    5) Effects
3 things it can do:
    1) Generate a signal
    2) Modify the generated signal
    3) Process the modified signal
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
