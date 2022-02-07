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
 struct Person
 {
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    float distanceTraveled;

    struct Steps
    {
        float footSize = 0.3f;
        float footStepLength = 0.4f;
        float totalSteps = 0;

        void stepForward(); 
        float stepSize(); 
    };

    Steps leftFoot;
    Steps rightFoot;

    void run(int howFast, bool startWithLeftFood);
 };

void Person::Steps::stepForward()
{
totalSteps++; FIXME indentation
}

float Person::Steps::stepSize()
{
    return footSize + footStepLength;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    
    if (startWithLeftFoot == true) 
    { 
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();

    std::cout << "Actual traveled distance= " << distanceTraveled << std::endl;
    std::cout << "Average Speed= " << howFast;
}

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
    double numProdLocalInv = 215.3;
    int numLogisticVehicles = 5; 
    int numPeopleWorkingAtStore =32; 
    double basicUtilities = 320.53;  
    double dailyIncome = 2750; 
    bool deliveryRequired = false;

    struct Customer
    {
        int age = 38;
        bool member = true;
        int visitsPerWeek = 7;
        float orderedProducts;
        std::string gender = "Male";
        std::string transportation = "Scooter";

        int eatFood(int Frequency = 5); FIXME: variable name capitalization
        void calculateWorkedTime(bool atHome = true, 
                                 int startTime = 800, 
                                 int finishTime = 1800); 
        float computeMonthlyExpenses(float rent = 1500,  
                                     float food = 450, 
                                     float fun = 120,
                                     float other = 230);
    };

    void sellProducts(Customer); 
    void solveCustomerNeeds(bool solved = true, bool quest = false); 
    void deliverProducts(Customer Phil, int time = 35); FIXME: variable name capitalization
};

int Market::Customer::eatFood(int Frequency) FIXME: variable name capitalization
{
    int breakfastProds = 5;
    int morningBreakProds = 2;
    int lunchProds = 5;
    int coffeeBreakProds = 2;
    int dinnerProds = 3;
    int dailyProds;
    if (Frequency == 5)
    {
        dailyProds = breakfastProds + morningBreakProds + lunchProds + coffeeBreakProds + dinnerProds;
    }
    else
    {
        dailyProds = breakfastProds + lunchProds + dinnerProds;
    }
        
    return dailyProds;
}

void Market::Customer::calculateWorkedTime(bool atHome, 
                                           int startTime, 
                                           int finishTime)
{
    std::string place;
    std::cout << "Please enter actual time in 24 hrs" << std::endl;
    std::cout << "Please enter actual time in 24 hrs" << std::endl;
    float workedTime = startTime - finishTime;
    if (atHome == true)
    {
        place = "at Home";
    }
    else
    {
        place = "at Office";
    }
    std::cout << "Today you worked " << workedTime << place;
}

float Market::Customer::computeMonthlyExpenses(float rent, 
                                               float food, 
                                               float fun,
                                               float other)
{
    return rent + food + fun + other;
}

void Market::sellProducts(Customer Nick) FIXME: variable name capitalization
{
    double subTotal;
    double totalSell = 0;
    double taxes = 1.19;
    bool requiredDelivery = false;
    double deliveryCharge = 0;
    
    double orderedProducts = Nick.eatFood(5);
    subTotal = orderedProducts * 1.25;
    if (Nick.member == true)
    {
        subTotal = subTotal * 0.9;
    }
    
    std::cout << "Delivery is required? (true/false)" << std::endl;
    if (requiredDelivery == true)
    {
        if (totalSell > 20)
        {
            deliveryCharge = 0;
        }
        else
        {
            deliveryCharge = 5;
        }
    }

    totalSell = (subTotal * taxes) + deliveryCharge;
    numProdLocalInv = numProdLocalInv - orderedProducts;
    dailyIncome = dailyIncome + totalSell;
    std::cout << "Today sold to Nick: " << std::endl;
    std::cout << "Number of Products: " << orderedProducts << std::endl;
    std::cout << "Total sold to Nick: " << totalSell << std::endl;
}

void Market::solveCustomerNeeds(bool solved, 
                                bool quest)
{
    std::string question;
    std::string whoAttended = "Samuel";
    std::string call;
    std::string rememberWhoAttended = "Please remember to answer the customer";
    std::cout << "Please write your questions:" << std::endl;
    std::cout << "Dear Customer, our staff I'll be answering your questions, when we finish please fill the questionaire" << std::endl;
    solved = false;
    quest = false;
    while (solved == false)
    {
        call = whoAttended + rememberWhoAttended;
    }
}

void Market::deliverProducts(Customer Nick, int time) FIXME: variable name capitalization
{
    float deliveryProducts = Nick.orderedProducts;
    bool shipped = false;
    bool prepareProducts = false;
    if (shipped == false && prepareProducts == false)
    {
        std::string assignedPerson = "Steve";
        numPeopleWorkingAtStore = numPeopleWorkingAtStore - 1;
    }
    if (deliveryProducts > 10)
    {
        numLogisticVehicles = numLogisticVehicles - 1; 
        time = 15;
    }
    else
    {
        time = 30;
    }
}

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
        int teachedClasses;

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

        float weekStudyTime(int research = 28, int teaching = 16);
        float computeMonthlyExpenses(float food, 
                                     float fun = 220, 
                                     float other = 350);
    }; 

    float teachStudents(Professor Jack);  FIXME: variable name capitalization
    void doCollaborativeResearch(std::string organization = "UCLA",
                                std::string department = "Chemistry",
                                std::string projectName = "influence of fertilizer on plant cultivation"); 
    void performCulturalActivities(Student Peter,  
                                  std::string category = "Arts",
                                  std::string activity = "Music Museum Visit"); 
};

float University::Professor::work(int research, int teaching)
{
    return research + teaching;
}

float University::Professor::computeMonthlyExpenses(float rent,
                                                    float food,
                                                    float fun, 
                                                    float other)
{
    return rent + food + fun + other;
}

float University::Student::weekStudyTime(int research, int teaching)
{
    return research + teaching;
}

float University::Student::computeMonthlyExpenses(float food = 350,
                                                  float fun, 
                                                  float other)
{
    return food + fun + other;
}

float University::teachStudents(Professor Jack) FIXME: variable name capitalization
{
    int calculus = 8;
    int programming = 12;
    int cad = 6;
    Jack.teachedClasses = calculus + programming + cad;
    return Jack.teachedClasses;
}

void University::doCollaborativeResearch(std::string organization, 
                                std::string department,
                                std::string projectName)
{
    std::cout << "This semester the University do Collaborative Research with: " << organization << " from department " << department << " in the project named: " << projectName << std::endl;
}

void University::performCulturalActivities(Student Peter,  
                                  std::string category,
                                  std::string activity)
{
    std::cout << "This semester the University performed a Cultural Activity with a student from " << Peter.career << "which likes: " << Peter.hobby << " in the category: " << category << " doing the activity " << activity << std::endl;
}

struct Computer
{
    float energyConsumption = 35.5f;
    float requiredRAM = 6.9f;
    float diskSpace = 89.5f;
    int execErrors = 48;
    int execTask = 25;
    bool programmingSoftwareInstalled = false;
    bool canSaveInfo;

    struct Hardware  
    { 
        double RAM = 16.0; 
        double disk = 1024.0; 
        double CPU = 4.5;
        double GPU = 16.0;
        double screen = 24.0;
        bool canPlayGames;
        bool canTrainAI;
        bool canUseAtOffice;
        
        bool playGames(bool specs = true); 
        bool trainAI(std::string softwareReq = "Keras"); 
        bool workAtOffice(std::string mostlyUsedTask = "Accounting"); 
    };

    void executePrograms(std::string todayTask = "Programming");  
    bool saveInfo(bool diskAvailable = true); 
    void connectToPCs(bool LANavailable = true);
};

//Computer OfficeDesktop;

bool Computer::Hardware::playGames(bool specs)
{
    if (specs == true && RAM >= 4 && disk >=256 && CPU >= 3.0 && GPU >= 2)
    {
        std::cout << "You can use this computer to play games";  
    }
    return canPlayGames = true;
}

bool Computer::Hardware::trainAI(std::string softwareReq)
{
    if (canPlayGames == true && GPU > 4)
    {
        std::cout << "You can use this computer to train AI using" << softwareReq;
    }
    return canTrainAI = true;
}

bool Computer::Hardware::workAtOffice(std::string mostlyUsedTask)
{
    if (canPlayGames == true)
    {
        std::cout << "You can use this computer to do " << mostlyUsedTask;
    }
    return canUseAtOffice = true;
} 

void Computer::executePrograms(std::string todayTask)
{
    if (programmingSoftwareInstalled == true)
    {
        std::cout << "This computer can be used  to" << todayTask;
    }
}

bool Computer::saveInfo(bool diskAvailable)
{
    if (diskAvailable == true)
    {
        std::cout << "The file will be saved";
    }
    return canSaveInfo = true;
}

void Computer::connectToPCs(bool LANavailable)
{
    if (LANavailable == true)
    {
        std::cout << "The computer is available to connect to LAN";
    }
}

struct AudioMixer
{
    int inputCh = 64; 
    int outputCh = 16; 
    int DSPRacks = 8; 
    int parallelProcessingCH = 24; 
    int DSPspeed = 800; 
    int availableInCh;
    int availableOutCh;
    int availableProcessing;

    struct ExpandableProtocols
    {
        bool MADI;
        bool waves;
        bool AVR;
        bool aviom;
        bool AES;
        float syncFrequency;

        void sends(std::string application = "Recording");
        float sync(std::string clockSource = "External",
                   float frequency = 96'000); 
    };

    int mixSignals(AudioMixer Digico, FIXME: variable name capitalization
                   std::string application = "Touring Live Sound");
    int splitSignal(AudioMixer Studer,  FIXME: variable name capitalization
                    std::string destination = "Broadcast");
    void processSignal(AudioMixer Digico, FIXME: variable name capitalization
                       int paramEQ = 64,
                       int graphEQ = 16);
};

void AudioMixer::ExpandableProtocols::sends(std::string application)
{
    if(application == "Recording")
    {
        MADI = true;
        AVR = true;
        AES = true;
    }
}

float AudioMixer::ExpandableProtocols::sync(std::string clockSource,
                                           float frequency)
{
    if (clockSource == "External")
    {
        syncFrequency = frequency;
    }
    return syncFrequency;
}

int AudioMixer::mixSignals(AudioMixer Digico, FIXME: variable name capitalization
                std::string application)
{
    if (application == "Touring")
    { FIXME: all of this stuff needs to be indented inside the curly braces
    int kick = 2;
    int snare = 2;
    int HH = 1;
    int OH = 2;
    int tom1 = 1;
    int tom2 = 1;
    int tom3 = 1;
    int drumKit = kick + snare + HH + OH + tom1 + tom2 + tom3;
    int congas = 2;
    int timbal = 3;
    int minorPerc = 2;
    int drums = congas + timbal + minorPerc;
    int sax = 2;
    int trump = 2;
    int tromb = 1;
    int winds = sax + trump + tromb;
    int bass = 1;
    int guitLead = 1;
    int guitHarm = 1;
    int strings = bass + guitLead + guitHarm;
    int chorus = 4;
    int star = 1;
    int spare = 1;
    int vocals = chorus + star + spare;
    int drumFx = 2;
    int windsFx = 2;
    int vocalsFx = 2;
    int effects = drumFx + windsFx + vocalsFx;
    int usedInCh = drumKit + drums + winds + strings + vocals + effects;
    Digico.availableInCh = Digico.inputCh - usedInCh;
    }
    return Digico.availableInCh;
}

int AudioMixer::splitSignal(AudioMixer Studer, std::string destination) FIXME: variable name capitalization
{
    if (destination == "Broadcasting")
    { FIXME: indent everything inside these curly braces
    int masterOut = 2;
    int liveOut = 2;
    int subOut = 2;
    int monitorOut = 2;
    int studioOut = 2;
    int recOut = 2;
    int usedOutCh = masterOut + liveOut + subOut + monitorOut + studioOut + recOut;
    Studer.availableOutCh = Studer.outputCh - usedOutCh;
    }
    return Studer.availableOutCh;
}   

void AudioMixer::processSignal(AudioMixer Digico, FIXME: variable name capitalization
                               int paramEQ,
                               int graphEQ)
{
    int procInCh = paramEQ * (Digico.availableInCh - Digico.inputCh);
    int procOutCh = graphEQ * (Digico.availableOutCh - Digico.outputCh);
    Digico.availableProcessing = (procInCh + procOutCh) - Digico.DSPspeed;
    std::cout << "Available Processing= " << Digico.availableProcessing;
}

struct ADSR
{
    double attackTime = 0.01;
    double holdTime = 0.01;
    double decayTime = 0.05;
    double sustainLevel = 0.5;
    double releaseTime = 0.5;

    double modifyLoudness(double x, 
                          double attackTime, 
                          double sustainLevel);
    double modOscillatorPitch(double x,
                              double oscFreq = 440.0,
                              double pitch = 0.35,
                              double pitchMod = 0.35);
    double modFilterFrequency(double x,
                              int cutoff = 2'500, 
                              double cutoffMod = 0.35);
};

double ADSR::modifyLoudness(double x, double , double)
{
    int fs = 44'100;
    double attack = attackTime * fs;
    double sustain = sustainLevel * fs;
    return x = attack + sustain;  //This is a dummy example (not true)  
}

double ADSR::modOscillatorPitch(double x,
                                double oscFreq,
                                double pitch,
                                double pitchMod)
{
    x = (oscFreq * pitch) / pitchMod; //This is a dummy example
    return x; 
}

double ADSR::modFilterFrequency(double x,
                                int cutoff, 
                                double cutoffMod)
{
    x = cutoff * cutoffMod;
    return x; //This is a dummy example
}

struct LFO
{
    float rate = 20.0f; 
    int phaseOffset  = 0.0f; 
    double amount = 48; 
    std::string shapeWaveform  = "Sine"; 
    bool bypassState = false; 

    double modulateSignal(double x, 
                          std::string routeAssign = "Oscillator");
    bool toggleONOFF(bool LFO = true);  FIXME: bad function name and argument name. This is a much better function name and function argument name: toggleEnablement(bool shouldBeOn)
    double changeSignalsInteraction(double x, 
                                    double amount, 
                                    double phaseOffset);
};

double LFO::modulateSignal(double x, std::string routeAssign)
{
    if (routeAssign == "Oscillator")
    {
        double y = 1;
        x = x + y;
    }
    return x; //This is a dummy example
}

bool LFO::toggleONOFF(bool LFO)
{
    if (LFO == false)
    {
        bypassState = true;
    }
    return bypassState; //This is a dummy example
}

double LFO::changeSignalsInteraction(double x, double , double )
{
    int fs = 44'100;
    for (int i = 0; i < fs; i++)
    {
        x = amount - phaseOffset;
    }
    return x; //This is a dummy example
}

struct Oscillator
{
    double frequency = 440; 
    float finetune = 0.01f; 
    std::string waveformShape = "Square"; 
    float pulseWidth = 0.3f; 
    int octave = 2; 
    double loadedROM;
    double storedROM;
    bool playButton;

    double generateSignal(Oscillator Square, double x); 
    double loadROMSamples(std::string selectStorageDevice = "SD",
                        bool isAudioFormat = true);
    void playbackROMSamples(double x, bool anyKeyPressed = false);
};

double Oscillator::generateSignal(Oscillator Square, double x)
{
    if (Square.waveformShape == "Square")
    {
        x = 0.5 * (frequency); //This is a dummy example
    }
    return x; 
}

double Oscillator::loadROMSamples(std::string selectStorageDevice,
                                  bool isAudioFormat)
{
    if (selectStorageDevice == "SD")
    {
        if(isAudioFormat == true)
        loadedROM = true;
    }
    return storedROM;
}

void Oscillator::playbackROMSamples(double x, bool anyKeyPressed)
{
    do 
    {
        x = storedROM + 1;
    }
    while (anyKeyPressed == true);
}

struct Filters 
{
    double gain; 
    double bandwidth = 0.7; 
    double frequency = 100.0; 
    std::string type = "Low Pass"; 
    double drive = 0.0; 
    double pianoIR;

    double boostCutFreq(Filters LowShelf, double x);
    double overDriveSignal(double drive, double x); 
    double giveSonority(double x, std::string instrument = "Piano");
};

double Filters::boostCutFreq(Filters LowShelf, double x)
{
    LowShelf.gain=-12;
    double fs = 44'100;
    double theta = (2 * 3.1416 * LowShelf.frequency) / fs;
    double miu = 10 * (LowShelf.gain/20);
    double betha = 4 / (1 + miu);
    double delta = betha * (theta / 2);
    double gamma = ((1 - delta) / (1 + delta));
    double a0 = (1 - gamma) / 2, a1 = (1 - gamma) / 2, a2 = 0;
    double b1 = -gamma, b2 = 0;
    double xn1 = 0, xn2 = 0, yn1 = 0, yn2 = 0;
    for (int n = 1; n <= fs; ++n)
    {
        x = ((a0) + (a1 * xn1) + (a2 * xn2) - (b1 * yn1) - (b2 * yn2));
    } 
    return x; //This is a dummy example
}

double Filters::overDriveSignal(double, double x)
{
    return x = (2.5 * (0.9 * drive)) + (2.5 * (1 - ((0.9 * drive))))-2.5;
}

double Filters::giveSonority(double x, std::string instrument)
{
    if (instrument == "Piano")
    {
        x = x * pianoIR;
    }
    return x;
}

struct Reverb
{
    double time = 0.1; 
    double mix = 20.0; 
    std::string type = "Plate";
    double preDelay = 0.1; 
    double size = 0.1; 
    
    double simulateSpace(Reverb Plate, double x);
    double giveBetterSound(double x, std::string instrument = "Trumpets");
    double giveDepth(double x, double pan = 75, bool stereo = true); 
};

double Reverb::simulateSpace(Reverb Plate, double x)
{
    return x = x * (Plate.time + Plate.mix);
}

double Reverb::giveBetterSound(double x, std::string instrument)
{
    if (instrument == "Trumpets")
    {
        x = x * (preDelay + size);
    }
    return x;
} 

double Reverb::giveDepth(double x, double pan, bool stereo)
{
    if (stereo == true)
    {
        double x1 = 0;
        x =  x + (x1 * pan) / 100; //This is a dummy example
    }
    return x;
}

struct Synthesizer
{
    ADSR ViolinADSR;  FIXME: variable name capitalization
    LFO VibratoLFO; FIXME: variable name capitalization
    Oscillator Amaj; FIXME: variable name capitalization
    Filters BandPass; FIXME: variable name capitalization
    Reverb Plate; FIXME: variable name capitalization

    void generateSignal(ADSR ViolinADSR); FIXME: do not declare a function argument that is identical to your member variable
    void modifySignal(ADSR ViolinADSR, LFO VibratoLFO); FIXME: do not declare a function argument that is identical to your member variable
    void processSignal(Filters BandPass, Reverb Plate); FIXME: do not declare a function argument that is identical to your member variable
};

void Synthesizer::generateSignal(ADSR Violin)
{
    ;
}

void Synthesizer::modifySignal(ADSR Violin, LFO Vibrato)
{
    ;
}

void Synthesizer::processSignal(Filters BPF, Reverb Plate)
{
    ;
}

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
