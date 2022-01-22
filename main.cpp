/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

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

struct Market
{
    //number of products in local inventory
    float numProdLocalInv = 215.3f;
    //number of vehicles used in logistics
    int numLogisticVehicles = 5; 
    //number of people working in store
    int numPeopleWorkingAtStore =32; 
    //amount of utilities
    float basicUtilities = 320.53f;  
    //daily income
    float dailyIncome = 2750; 

    struct Customer
    {
        int age = 38;
        bool member = true;
        int visitsPerWeek = 7;
        std::string gender = "Male";
        std::string transportation = "Scooter";

        void eatFood(int Frequency = 5);
        float calculateWorkedTime(bool atHome = true, 
                                  float time = 8.5f); 
        float paymonthlyShould(float rent = 1500,  
        float food = 450, 
        float fun = 120,
        float other = 230);
    };

    //Sell daily use products
    void sellProducts(Customer Nick); 
    //Help customers with any issue
    void solveCustomerNeeds(Customer Jack, bool solved = true, bool quest = false); 
    //Deliver products
    void deliverProducts(Customer Phil, bool success = true, int time = 35);
};

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

struct University
{
    //number of classrooms
    int numClassrooms = 80; 
    //number of laboratories
    int numLabs = 36; 
    //number of professors
    int numProfessors = 95; 
    //amount of semestral income
    float semIncome = 5'000'000; 
    //classes taken per period
    int classesPerSemester = 8362; 

    struct Professor
    {
        int age = 58;
        std::string profession = "Engineer";
        std::string postgraduateStudies = "MsC";
        std::string teachingRank = "Band 4";
        int yearsExperience = 15;

        float work(int research = 28, int teaching = 16);
        float monthlyPay(float rent = 1800, 
                         float food = 550, 
                         float fun = 120,
                         float other = 150);
    };

    struct Student
    {
        int age = 18;
        std::string department = "Engineer";
        std::string career = "AgroIndustrial Engineer";
        std::string hobby = "Play Bass";
        int semestralCredits = 9;

        float weekstudyTime(int research = 28, int teaching = 16);
        float monthlyExpenses(float food = 250, 
        float fun = 220,
        float other = 350);
    };

    //Teach students
    float teachStudents(Professor Frank); 
    //Do collaborate research 
    int doCollaborateResearch(std::string organization = "UCLA", 
                              std::string department = "Chemistry",
                              std::string projectName = "influence of fertilizer on plant cultivation");
    //Perform cultural activities
    int performCulturalActivities(Student Peter, 
                           std::string category = "Arts",
                           std::string activity = "Museum Visit");
    };

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
 
struct Computer
{
    //amount of used energy
    float energyConsumption = 35.5f; 
    //amount of required memory to run multiple programs
    float requiredRAM = 6.9f; 
    //amount of daily used disk space
    float diskSpace = 89.5f; 
    //number of execution errors
    int execErrors = 48; 
    //task executed per day
    int execTask = 25; 

    //Computer Hardware Specs
    struct Hardware 
    {
      //[Gb] Total RAM
      float RAM = 16;
      //[Gb] Total Disk space
      float disk = 1024; 
      //[GHz] CPU Speed
      float CPU = 4.5;
      //[Gb] Total GPU 
      float GPU = 16; 
      //[Inches] Screen Size
      float screen = 24;
        
      bool playGames(bool specs = true);
      bool trainAI(std::string softwareReq = "Keras");
      bool workAtOffice(std::string mostlyUsedTask = "Accounting");
    };

    //Execute Programs 
    void executePrograms(Computer officeDesktop, 
                         std::string todayTask = "Programming"); 
    //Save Information
    bool saveInfo(bool diskAvailable = true);
    //Connect with other computers
    void connectToPCs(Computer Server, bool LANavailable = true);
};

/*
Thing 4) Audio Mixer
5 properties:
    1) number of input channels (int)
    2) number of output channels (int)
    3) number of signal processing options (int)
    4) number of simultaneous processing objects (int)
    5) speed of DSP (float)
3 things it can do:
    1) mix multiple signals into an stereo one
    2) split signal to be delivered at different points
    3) process signal (EQ, Fx, Dynamics)
 */
 
struct AudioMixer
{
    //number of input channels
    int inputCh = 64; 
    //number of output channels
    int outputCh = 16; 
    //number of signal processing options
    int DSPRacks = 8; 
    //number of simultaneous processing objects
    int parallelProcessingCH = 24; 
    //speed of DSP 
    float DSPspeed = 800; 
    //[MHz] 

    //Which connections are available
    struct ExpandableProtocols
    {
        bool MADI = true;
        bool waves = true;
        bool AVR = false;
        bool aviom = true;
        bool AES = true;

        void sends(std::string application = "Recording");
        void sync(std::string clockSource = "External",
                  float frequency = 96'000); 
    };

    void mixSignals(AudioMixer Digico,
                    std::string application = "Touring Live Sound");
    void splitSignal(std::string destination = "Broadcast");
    void processSignal(AudioMixer AllenHeath,
                       int paramEQ = 64,
                       int graphEQ = 16,
                       int expansionPorts = 8);
};

/*
Thing 5) ADSR
5 properties:
    1) attack time (float)
    2) hold time (float)
    3) decay time (float)
    4) sustain level (float)
    5) release time (float)
3 things it can do:
    1) modify the loudness of a sound 
    2) modify the oscillator pitch
    3) modify the filter frequency
 */

struct ADSR
{
    //attack time 
    float attackTime = 0.01f;
    //hold time
    float holdTime = 0.001f;
    //decay time
    float decayTime = 0.05f;
    //sustain level
    float sustainLevel = 0.5f;
    //release time
    float releaseTime = 0.5f;

    //modify the loudness of a sound 
    void modifyLoudness(float attackTime, float sustainLevel);
    //modify the oscillator pitch
    void modOscillatorPitch(float oscFreq = 440.0f,float pitch = 0.35f,float pitchMod = 0.35f);
    //modify the filter frequency
    void modFilterFrequency(int cutoff = 2'500, float cutoffMod = 0.35f);
};

/*
Thing 6) LFO
5 properties:
    1) rate (float)
    2) phase offset (int)
    3) amount (float)
    4) waveform shape (std::string) 
    5) bypass state (bool) 
3 things it can do:
    1) modulate an audio signal
    2) toggle ON and OFF
    3) change the interaction time between signals
 */

struct LFO
{
    //rate
    float rate = 20.0f; 
    //phase offset [Hz]
    int phaseOffset  = 0.0f; 
    //amount [Semitones] 
    float amount = 48; 
    //waveform shape 
    std::string shapeWaveform  = "Sine"; 
    //bypass state
    bool bypassState = false; 

    void modulateSignal(std::string routeAssign = "Oscillator");
    void toggleONOFF(bool LFO = true);
    void signalsInteraction(float amount, int phaseOffset);
};

/*
Thing 7) oscillator
5 properties:
    1) frequency (float)
    2) finetune (float)
    3) waveform shape (std::string)  
    4) pulse width (float) 
    5) octave (int)  
3 things it can do:
    1) generate audio signals
    2) load samples from ROM
    3) playback samples from ROM
 */

struct Oscillator
{
    //frequency [Hz]
    float frequency = 440; 
    //Frequency fine tune variation
    float finetune = 0.01f; 
    //waveform shape (Signal shape)
    std::string waveformShape = "Square"; 
    //pulse width (% of the positive/negative signal amplitude to be wider or smaller )
    float pulseWidth = 0.3f; 
    //octave (n times the original frequency )
    int octave = 2; 

    //generate audio signals
    void generateSignal(Oscillator Square);
    //load samples from ROM
    void loadROMSamples(std::string selectStorageDevice = "SD",                        bool isAudioFormat = true);
    //playback samples from ROM
    void playbackROMSamples(bool anyKeyPressed = false);
};

/*
Thing 8) filters
5 properties:
    1) gain (float)
    2) bandwidth (float)
    3) frequency (float)
    4) type (std::string)
    5) drive (float)
3 things it can do:
    1) boost or cut frequencies on a signal
    2) overDrive the signal
    3) give a better sonority to an instrument 
 */

struct Filters 
{
    //gain [dB] pow(10.0, (gain / 20.0))
    float gain = 0.0f; 
    // bandwidth [0 -10] 0.7=1 Oct
    float bandwidth = 0.7f; 
    //frequency [Hz] Selected center frequency
    float frequency = 100.0f; 
    //type (LP HP LSh HSh BP)
    std::string type = "Low Pass"; 
    //drive (Adds distortion to the signal)
    float drive = 0.0f; 

    //boost or cut frequencies on a signal
    void boostCutFreq(Filters LowPass);
    //overDrive the signal
    void overDriveSignal(float drive); 
    //give a better sonority to an instrument 
    void giveSonority(std::string instrument = "piano");
};

/*
Thing 9) reverb 
5 properties:
    1) time (float) 
    2) mix (float)
    3) type (std::string)
    4) pre-delay (float)
    5) size (float)
3 things it can do:
    1) simulate an space to a soun
    2) give a better sound to an instrument
    3) give depth to a band
 */

struct Reverb
{
    //time [sec] 
    float time = 0.1f; 
    //mix [%] (Wet/Dry)
    float mix = 20.0f; 
    //type 
    std::string type = "Plate";
    //Pre-delay (First audible reflections time)
    float preDelay = 0.1f; 
    //size [sec] (Reflections time)
    float size = 0.1f; 
    
    //simulate an space to a sound
    void simulateSpace(Reverb Plate);
    //give a better sound to an instrument
    void giveBetterSound(std::string instrument = "Trumpets"); 
    //give depth to a band
    void giveDepth(reverb depth, 
                   float pan = 75, 
                   bool stereo = true); 
};

/*
Thing 10) synthesizer
5 properties:
    1) ADSR
    2) LFO
    3) oscillator
    4) filters
    5) reverb
3 things it can do:
    1) generate a signal
    2) modify the generated signal
    3) process the modified signal
 */

struct Synthesizer
{
    ADSR UserADSR;
    LFO UserLFO;
    Oscillator UserOscillator;
    Filters UserFilter;
    Reverb UserReverb;

    void generateSignal(ADSR UserADSR);
    void modifySignal(ADSR UserADSR, LFO UserLFO);
    void processSignal(Filters UserFilters, Reverb UserLFO);
};

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
