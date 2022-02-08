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
    totalSteps++;
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
    double numProdLocalInv = 215;
    int numLogisticVehicles = 5; 
    int numPeopleWorkingAtStore =32; 
    double dailyBasicUtilitiesFee = 320.53;  
    double dailyIncome = 0; 
    double dailyProfit = 0;

    struct Customer
    {
        int age = 38;
        bool member = true;
        int visitsPerWeek = 7;
        std::string gender = "Male";
        int breakfastProds = 4;
        int morningBreakProds = 2;
        int lunchProds = 5;
        int coffeeBreakProds = 2;
        int dinnerProds = 3;
        int productsToOrder;
        double productsPrice;
        double totalToPay;

        void selectDailyFood(); 
        void calculateOrderPrice(); 
        void orderProducts(bool deliveryRequired = true);
    };

    Customer nick;
    Customer jack;

    void sellProducts();
    void adjustInventary();
    void computeDailyProfit();
};

void Market::Customer::selectDailyFood()
{
    productsToOrder = breakfastProds + morningBreakProds + lunchProds +coffeeBreakProds + dinnerProds;
}

void Market::Customer::calculateOrderPrice()
{
    double bfProdsPrice = 0.75;
    double mbProdsPrice = 1.25;
    double lProdsPrice = 0.85;
    double cbProdsPrice = 1.25;
    double dProdsPrice = 0.9;
    double memberDiscount = 0.9;
    productsPrice = (breakfastProds * bfProdsPrice) +\
                    (morningBreakProds * mbProdsPrice) +\
                    (lunchProds * lProdsPrice) +\
                    (coffeeBreakProds * cbProdsPrice) +\
                    (dinnerProds * dProdsPrice);
    if(member == true)
    {
        productsPrice = productsPrice * memberDiscount;
    }
}

void Market::Customer::orderProducts(bool requiredDelivery)
{
    double deliveryCharge = 0;
    double tax = 1.19;
    if (requiredDelivery == true)
    {
        if (productsPrice > 20)
        {
            deliveryCharge = 0;
        }
        else
        {
            deliveryCharge = 5;
        }
    }
    totalToPay = (productsPrice * tax) + deliveryCharge;
}

void Market::sellProducts() //Nick example
{ 
    std::cout << "Dear Customer, you ordered " <<  nick.productsToOrder << "products, with a total cost of $" << nick.totalToPay << "which will be Delivered by Tom. Thanks for buying with us!";

    numLogisticVehicles--;
    numPeopleWorkingAtStore--;
    dailyIncome += nick.totalToPay;
}

void Market::adjustInventary()
{
    numProdLocalInv -= nick.productsToOrder;
}

void Market::computeDailyProfit()
{
    dailyProfit = dailyIncome - dailyBasicUtilitiesFee;
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

    float teachStudents(Professor jack);  
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

float University::teachStudents(Professor) 
{
    int calculus = 8;
    int programming = 12;
    int cad = 6;
    float teachedClasses = calculus + programming + cad;
    return teachedClasses;
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

    int mixSignals(AudioMixer digico, 
                   std::string application = "Touring Live Sound");
    int splitSignal(AudioMixer studer,  
                    std::string destination = "Broadcast");
    void processSignal(AudioMixer digico, 
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

int AudioMixer::mixSignals(AudioMixer digico,
                std::string application)
{
    if (application == "Touring")
    { 
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
        digico.availableInCh = digico.inputCh - usedInCh;
    }
    return digico.availableInCh;
}

int AudioMixer::splitSignal(AudioMixer studer, std::string destination) 
{
    if (destination == "Broadcasting")
    { 
        int masterOut = 2;
        int liveOut = 2;
        int subOut = 2;
        int monitorOut = 2;
        int studioOut = 2;
        int recOut = 2;
        int usedOutCh = masterOut + liveOut + subOut + monitorOut + studioOut + recOut;
        studer.availableOutCh = studer.outputCh - usedOutCh;
    }
    return studer.availableOutCh;
}   

void AudioMixer::processSignal(AudioMixer digico, 
                               int paramEQ,
                               int graphEQ)
{
    int procInCh = paramEQ * (digico.availableInCh - digico.inputCh);
    int procOutCh = graphEQ * (digico.availableOutCh - digico.outputCh);
    digico.availableProcessing = (procInCh + procOutCh) - digico.DSPspeed;
    std::cout << "Available Processing= " << digico.availableProcessing;
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
    bool toggleEnablement(bool shouldBeOn = true);  
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

bool LFO::toggleEnablement(bool shouldBeOn)
{
    if (shouldBeOn == false)
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
    ADSR violinADSR;  
    LFO vibratoLFO; 
    Oscillator aMaj; 
    Filters bandPass; 
    Reverb plate; 

    void generateSignal(ADSR violin);
    void modifySignal(ADSR violin, LFO vibrato); 
    void processSignal(Filters bpf, Reverb fixedPlate);
};

/*void Synthesizer::generateSignal(ADSR Violin)
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
}*/

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
