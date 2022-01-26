 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

struct Market
{
    float numProdLocalInv = 215.3f;
    int numLogisticVehicles = 5; 
    int numPeopleWorkingAtStore =32; 
    float basicUtilities = 320.53f;  
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
        float computeMonthlyExpenses(float rent = 1500,  
                                     float food = 450, 
                                     float fun = 120,
                                     float other = 230);
    };

    void sellProducts(Customer Nick); 
    void solveCustomerNeeds(Customer Jack, bool solved = true, bool quest = false); 
    void deliverProducts(Customer Phil, bool success = true, int time = 35);
};

struct University
{
    int numClassrooms = 80;
    int numLabs = 36;
    int numProfessors = 95;
    float semIncome = 5'000'000;
    int classesPerSemester = 8362;

    struct Professor
    {
        int age = 58;
        std::string profession = "Engineer";
        std::string postgraduateStudies = "MsC";
        std::string teachingRank = "Band 4";
        int yearsExperience = 15;

        float work(int research = 28, int teaching = 16);
        float computeMonthlyExpenses(float rent = 1800,
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
        float computeMonthlyExpenses(float food = 250, 
                                     float fun = 220, 
                                     float other = 350);
    }; 

    float teachStudents(Professor Frank); 
    int doCollaborativeResearch(std::string organization = "UCLA", 
                                std::string department = "Chemistry",
                                std::string projectName = "influence of fertilizer on plant cultivation"); 
    int performCulturalActivities(Student Peter,  
                                  std::string category = "Arts",
                                  std::string activity = "Museum Visit"); 
};

struct Computer
{
    float energyConsumption = 35.5f;
    float requiredRAM = 6.9f;
    float diskSpace = 89.5f;
    int execErrors = 48;
    int execTask = 25;

    struct Hardware  
    { 
        float RAM = 16; 
        float disk = 1024; 
        float CPU = 4.5;
        float GPU = 16;
        float screen = 24; 

        bool playGames(bool specs = true); 
        bool trainAI(std::string softwareReq = "Keras"); 
        bool workAtOffice(std::string mostlyUsedTask = "Accounting"); 
    };

    void executePrograms(Computer officeDesktop,  
    std::string todayTask = "Programming");  
    bool saveInfo(bool diskAvailable = true); 
    void connectToPCs(Computer Server, bool LANavailable = true);
};

struct AudioMixer
{
    int inputCh = 64; 
    int outputCh = 16; 
    int DSPRacks = 8; 
    int parallelProcessingCH = 24; 
    float DSPspeed = 800; 

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

struct ADSR
{
    float attackTime = 0.01f;
    float holdTime = 0.001f;
    float decayTime = 0.05f;
    float sustainLevel = 0.5f;
    float releaseTime = 0.5f;

    void modifyLoudness(float attackTime, float sustainLevel);
    void modOscillatorPitch(float oscFreq = 440.0f,float pitch = 0.35f,float pitchMod = 0.35f);
    void modFilterFrequency(int cutoff = 2'500, float cutoffMod = 0.35f);
};

struct LFO
{
    float rate = 20.0f; 
    int phaseOffset  = 0.0f; 
    float amount = 48; 
    std::string shapeWaveform  = "Sine"; 
    bool bypassState = false; 

    void modulateSignal(std::string routeAssign = "Oscillator");
    void toggleONOFF(bool LFO = true);
    void changeSignalsInteraction(float amount, int phaseOffset);
};

struct Oscillator
{
    float frequency = 440; 
    float finetune = 0.01f; 
    std::string waveformShape = "Square"; 
    float pulseWidth = 0.3f; 
    int octave = 2; 

    void generateSignal(Oscillator Square);
    void loadROMSamples(std::string selectStorageDevice = "SD",
                        bool isAudioFormat = true);
    void playbackROMSamples(bool anyKeyPressed = false);
};

struct Filters 
{
    float gain = 0.0f; 
    float bandwidth = 0.7f; 
    float frequency = 100.0f; 
    std::string type = "Low Pass"; 
    float drive = 0.0f; 

    void boostCutFreq(Filters LowPass);
    void overDriveSignal(float drive); 
    void giveSonority(std::string instrument = "piano");
};

struct Reverb
{
    float time = 0.1f; 
    float mix = 20.0f; 
    std::string type = "Plate";
    float preDelay = 0.1f; 
    float size = 0.1f; 
    
    void simulateSpace(Reverb Plate);
    void giveBetterSound(std::string instrument = "Trumpets"); 
    void giveDepth(Reverb depth, 
                   float pan = 75, 
                   bool stereo = true); 
};

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
