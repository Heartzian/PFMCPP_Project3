/*
Project 3 - Part 1c / 5
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

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  

2) write the name of the primitive type you'll be using after each property in UDTs 1-4:
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)

3) Move the Thing 10 pseudo-code to after your Thing1-4 in the project.
*/

/*
Thing 1) Market
5 properties:
    1) inventory
      Local store (int)
      Other brands (int)
      food classification (int)
      expiration date (std::string)
    2) vehicles
      brand (std::string)
      daily traveled distance (float)
      days since last mainteinance (int)
      consumed fuel (float)
      detected problems (std::string)
    3) workers
      position (std::string)
      department (std::string)
      salary (float)
      health insurance (std::string)
      accumulative bonus (float)
    4) utilities
      month water bill (float)
      month electricity bill (float)
      month phone bill (float)
      month recollection (float)
      month maintenance (float)
    5) income
      received (float)
      cost (float)
      paid (float)
      taxes (float)
      donations (float)
3 things it can do:
    1) Sell daily use products
    2) Help customers with any issue
    3) Deliver products
 */

/*
Thing 2) University
5 properties:
    1) classrooms
      size (float)
      air conditioner (bool)
      computers (bool)
      multimedia (bool)
      automation (bool)
    2) laboratories
      size (float)
      equipment (std::string)
      security (bool)
      emergency system (bool)
      multimedia (bool)
    3) professors
      profession (std::string)
      studies (std::string)
      rank (std::string)
      research (std::string)
      salary (float)
    4) written research
      student thesis (int)
      student papers (int)
      collaborated papers (int)
      patents (int)
      books (int)
    5) ludical activities
      musical (int)
      language (int)
      sports (int)
      humanities (int)
      arts (int)
3 things it can do:
    1) Teach students
    2) Do collaborate research 
    3) Perform cultural activities
 */

/*
Thing 3) Server
5 properties:
    1) QoS
      reveived data (float)
      transmitted data (float)
      processed data (float)
      bugs (int)
      speed (float)
    2) memory
      size (float)
      speed (float)
      slots (int)
      used RAM (float)
      cache (float)
    3) disk
      space (float)
      read speed (float)
      write speed (float)
      partitions (int)
      used space (float)
    4) execution errors
      system (int)
      user (int)
      components (int)
      application (int)
      logs (int)
    5) maintenance
      used days (int)
      elapsed days without maintenance (int)
      last reported bug (int)
      last day offline (int)
      next preventive maintenance (int)
3 things it can do:
    1) Execute Programs
    2) Save Information
    3) Connect with other computers
 */

/*
Thing 4) Audio Mixer
5 properties:
    1) input channels
      quantity (int)
      impedance (float)
      nominal level (int)
      THD (float)
      SNR (float)
    2) output channels
      quantity (int)
      impedance (float)
      noise level (int)
      Max. Level (float)
      Dynamic Range (float)
    3) signal processing options
      sampling rate (float)
      bit depth (float)
      I/O latency (float)
      processing engines (int)
      floating point (int)
    4) effects
      reverbs (int)
      compressors (int)
      preAmps (int)
      delays (int)
      adsr (int)
    5) connectivity
      dante (bool)
      avr (bool)
      a-net (bool)
      madi (bool)
      waves (bool)
3 things it can do:
    1) Mix multiple signals into an stereo one
    2) Split signal to be delivered at different points
    3) Process signal (EQ, Fx, Dynamics)
 */

/*
Thing 10) 
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
