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

struct Market
{
  float numProdLocalInv = 215.3f; //Display the total available products at store
  int numLogisticVehicles = 5; //Show the total of vehicles used to deliver products
  int numPeopleWorkingAtStore =32; //Available workers at store
  float basicUtilities = 320.53f;  //Display the daily utilities in $ 
  float dailyIncome = 2750; //Indicate the daily net received money after sales

  struct Customer
  {
    int age = 38;
    bool member = true;
    int visitsPerWeek = 7;
    std::string gender = "Male";
    std::string transportation = "Scooter";

    void dailyFood(int Frequency = 5);
    float workRoutine(bool atHome = true, float time = 8.5f);
    float monthlyExpenses(float rent = 1500, 
                         float food = 450, 
                         float fun = 120,
                         float other = 230);
  };

  void prodCat(Customer Nick);
  //The Market register customer sale information 
  void customerNeeds(bool solved = true, bool quest = false);
  //The Market helps customer solving their needs, has a department which recolects the information to do feedback
  void delivery(Customer Phil, bool success = true, int time = 35);
  //The Market uses the customer info with delivery info
};

struct University
{
  int numClassrooms = 80; //Available total classrooms 
  int numLabs = 36; //Specialized available practice labs 
  int numProfessors = 95; //Available professors to teach
  float semIncome = 5'000'000; //Semestral Received tuitions Money 
  int classesPerSemester = 8362; //Accumulated classes per Semester

  struct Professor
  {
    int age = 58;
    std::string profession = "Engineer";
    std::string postgraduateStudies = "MsC";
    std::string teachingRank = "Band 4";
    int yearsExperience = 15;

    float weekWorkTime(int research = 28, int teaching = 16);
    float monthlyExpenses(float rent = 1800, 
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

  float impartedClasses(Professor Frank); //Returns semestral classes time by professor 
  int collaborativeResearch(std::string organization = "UCLA",                               std::string department = "Chemistry",                            std::string projectName = "influence                             of fertilizer on plant cultivation");
  //Returns the quantity of collaborated projects per semester
  int culturalActivities(Student Peter,
                         std::string category = "Arts",
                         std::string activity = "Museum Visit");
  //Returns the cultural activities per semester by Student
};

struct Computer
{
  float energyConsumption = 35.5; //KW per month
  float requiredRAM = 6.9; //Min. required [Gb] for usually tasks
  float diskSpace = 89.5; //Min. required [Gb] for OS and Apps
  int execErrors = 48; //Daily reported system reported issues
  int execTask = 25; //Daily executed programmed tasks

  struct Hardware //Computer Hardware Specs
  {
    float RAM = 16; //[Gb]
    float disk = 1024; //[Gb]
    float CPU = 4.5; //[GHz]
    float GPU = 16; //[GHz]
    float screen = 24; //[Inches]

    bool playGames(bool specs = true);
    bool trainAI(std::string softwareReq = "Keras");
    bool officeWork(std::string mostlyUsedTask = "Accounting");
  };

  void programExecution(Computer officeDesktop,
                        std::string todayTask = "Programming"); 
  bool saveInfo(bool diskAvailable = true);
  void connectToPCs(Computer Server, bool LANavailable = true);
};

struct AudioMixer
{
  int inputCh = 64; //Analog balanced inputs
  int outputCh = 16; //Analog balanced outputs
  int DSPRacks = 8; //Internal Available Processing Capacity
  int parallelProcessingCH = 24; //Procesable simultaneous channels
  float DSPspeed = 800; //[MHz] 

  struct expandableProtocols //Which connections are available
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

struct ADSR
{
  float attackTime = 0.01f;
  float holdTime = 0.001f;
  float decayTime = 0.05f;
  float sustainLevel = 0.5f;
  float releaseTime = 0.5f;

  void loudness(float attackTime, float sustainLevel); 
  void oscillatorPitch(float oscFreq = 440.0f, //Original Frequency
                       float pitch = 0.35f, //Var. % from Freq.
                       float pitchMod = 0.35f); //Var. % from pitch
  void filterFrequency(int cutoff = 2'500, //LPF Frequency [Hz]
                       float cutoffMod = 0.35f); //Var. % from LPF
};

struct LFO
{
  float rate = 20.0f; //LFO Speed variation [Hz]
  int phaseOffset  = 0.0f; //Phase for polyphonic notes played at different time (gives independency to the LFO at every note)
  float amount = 48; //How much the pitch/filter will change [Semitones] 
  std::string shapeWaveform  = "Sine"; //Osc. shape direction
  bool bypassState = false; //Let bypass the signal

  void modulateSignal(std::string routeAssign = "Oscillator");
  void toggleONOFF(bool LFO = true);
  void signalsInteraction(float amount, int phaseOffset);
};

struct oscillator
{
  float frequency = 440; //[Hz]
  float finetune = 0.01f; //Frequency fine variation
  std::string waveformShape = "Square"; //Signal shape
  float pulseWidth = 0.3f; //% of the positive/negative signal amplitude to be wider or smaller 
  int octave = 2; //n times the original frequency 

  void generateSignal(std::string waveformShape, float frequency);
  void loadROMSamples(std::string selectStorageDevice = "SD",
                      bool isAudioFormat = true);
  void playbackROMSamples(bool anyKeyPressed = false);
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
    1) mix multiple signals into an stereo one
    2) split signal to be delivered at different points
    3) process signal (EQ, Fx, Dynamics)
 */

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

/*
Thing 10) synthetizer
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
