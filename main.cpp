/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Market
{
    Market();
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

Market::Market()
{
    std::cout << "Market being constructed!" << std::endl;
}

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
    productsPrice = (breakfastProds * bfProdsPrice) + (morningBreakProds * mbProdsPrice) + (lunchProds * lProdsPrice) + (coffeeBreakProds * cbProdsPrice) + (dinnerProds * dProdsPrice);

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

    --numLogisticVehicles;
    --numPeopleWorkingAtStore;
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
    University();
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

        float computeWeekStudyTime(int research = 28, int teaching = 16);
        float computeMonthlyExpenses(float food, 
                                     float fun = 220, 
                                     float other = 350);
    }; 

    Student peter;

    float teachStudents();  
    void doCollaborativeResearch(std::string organization = "UCLA",
                                 std::string department = "Chemistry",
                                 std::string projectName = "influence of fertilizer on plant cultivation"); 
    void performCulturalActivities(Student name,
                                   std::string category = "Arts",
                                   std::string activity = "Music Museum Visit"); 
};

University::University()
{
    std::cout << "University being constructed!" << std::endl;
}

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

float University::Student::computeWeekStudyTime(int research, int teaching)
{
    return research + teaching;
}

float University::Student::computeMonthlyExpenses(float food = 350,
                                                  float fun, 
                                                  float other)
{
    return food + fun + other;
}

float University::teachStudents() 
{
    int calculus = 8;
    int programming = 12;
    int cad = 6;
    return calculus + programming + cad;
}

void University::doCollaborativeResearch(std::string organization, 
                                         std::string department,
                                         std::string projectName)
{
    std::cout << "This semester the University do Collaborative Research with: " << organization << " from department " << department << " in the project named: " << projectName << std::endl;
}

void University::performCulturalActivities(Student,
                                           std::string category,
                                           std::string activity)
{
    std::cout << "This semester the University performed a Cultural Activity with a student from " << peter.career << "which likes: " << peter.hobby << " in the category: " << category << " doing the activity " << activity << std::endl;
}

struct Computer
{
    Computer();
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
        
        void playGames(bool specs = true); 
        void trainAI(std::string softwareReq = "Keras"); 
        void workAtOffice(std::string mostlyUsedTask = "Accounting"); 
    };

    void executePrograms(std::string todayTask = "Programming");  
    void saveInfo(bool diskAvailable = true); 
    void connectToPCs(bool LANavailable = true);
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

void Computer::Hardware::playGames(bool specs)
{
    if (specs == true && RAM >= 4 && disk >=256 && CPU >= 3.0 && GPU >= 2)
    {
        std::cout << "You can use this computer to play games";  
    
        canPlayGames = true;
    }
}

void Computer::Hardware::trainAI(std::string softwareReq)
{
    if (canPlayGames == true && GPU > 4)
    {
        std::cout << "You can use this computer to train AI using" << softwareReq;

        canTrainAI = true;
    }
    
}

void Computer::Hardware::workAtOffice(std::string mostlyUsedTask)
{
    if (canPlayGames == true)
    {
        std::cout << "You can use this computer to do " << mostlyUsedTask;

        canUseAtOffice = true;
    }
    
} 

void Computer::executePrograms(std::string todayTask)
{
    if (programmingSoftwareInstalled == true)
    {
        std::cout << "This computer can be used  to" << todayTask;
    }
}

void Computer::saveInfo(bool diskAvailable)
{
    if (diskAvailable == true)
    {
        std::cout << "The file will be saved";

        canSaveInfo = true;
    }
    
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
    AudioMixer();
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

    int mixSignals(std::string application = "Touring Live Sound");
    int splitSignal(std::string destination = "Broadcast");
    void processSignal(int paramEQ = 64,
                       int graphEQ = 16);
};

AudioMixer::AudioMixer()
{
    std::cout << "AudioMixer being constructed!" << std::endl;
}
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

int AudioMixer::mixSignals(std::string application)
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
        availableInCh = inputCh - usedInCh;
    }
    return availableInCh;
}

int AudioMixer::splitSignal(std::string destination) 
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
        availableOutCh = outputCh - usedOutCh;
    }
    return availableOutCh;
}   

void AudioMixer::processSignal(int paramEQ,
                               int graphEQ)
{
    int procInCh = paramEQ * (availableInCh - inputCh);
    int procOutCh = graphEQ * (availableOutCh - outputCh);
    availableProcessing = (procInCh + procOutCh) - DSPspeed;
    std::cout << "Available Processing= " << availableProcessing;
}

struct ADSR
{
    ADSR();
    double attackTime = 0.01;
    double holdTime = 0.01;
    double decayTime = 0.05;
    double sustainLevel = 0.5;
    double releaseTime = 0.5;
    double signal;

    void modifyLoudness();
    void modOscillatorPitch(double oscFreq = 440.0,
                              double pitch = 0.35,
                              double pitchMod = 0.35);
    void modFilterFrequency(int cutoff = 2'500, 
                              double cutoffMod = 0.35);
};

ADSR::ADSR()
{
    std::cout << "ADSR being constructed!" << std::endl;
}

void ADSR::modifyLoudness()
{
    int fs = 44'100;
    double attack = attackTime * fs;
    double sustain = sustainLevel * fs;
    signal = attack + sustain;  //This is a dummy example (not true)  
}

void ADSR::modOscillatorPitch(double oscFreq,
                              double pitch,
                              double pitchMod)
{
    signal = (oscFreq * pitch) / pitchMod; //This is a dummy example 
}

void ADSR::modFilterFrequency(int cutoff, 
                              double cutoffMod)
{
    signal = cutoff * cutoffMod; //This is a dummy example
}

struct LFO
{
    LFO();
    float rate = 20.0f; 
    int phaseOffset  = 0.0f; 
    double amount = 48; 
    std::string shapeWaveform  = "Sine"; 
    bool bypassState = false; 
    double signal;

    void modulateSignal(std::string routeAssign = "Oscillator");
    bool toggleEnablement(bool shouldBeOn = true);  
    void changeSignalsInteraction();
};

LFO::LFO()
{
    std::cout << "LFO being constructed!" << std::endl;
}

void LFO::modulateSignal(std::string routeAssign)
{
    if (routeAssign == "Oscillator")
    {
        double y = 1;
        signal = signal + y; //This is a dummy example
    } 
}

bool LFO::toggleEnablement(bool shouldBeOn)
{
    if (shouldBeOn == false)
    {
        bypassState = true;
    }
    return bypassState; //This is a dummy example
}

void LFO::changeSignalsInteraction()
{
    int fs = 44'100;
    for (int i = 0; i < fs; i++)
    {
        signal = amount - phaseOffset; //This is a dummy example
    }

}

struct Oscillator
{
    Oscillator();
    double frequency = 440; 
    float finetune = 0.01f; 
    std::string waveformShape = "Square"; 
    float pulseWidth = 0.3f; 
    int octave = 2; 
    double loadedROM;
    double storedROM;
    bool playingTone;
    bool playButton;
    double signal;

    void generateTone(); 
    double loadROMSamples(std::string selectStorageDevice = "SD",
                        bool isAudioFormat = true);
    void playbackROMSamples(bool anyKeyPressed = false);
};

Oscillator::Oscillator()
{
    std::cout << "Oscillator being constructed!" << std::endl;
}

void Oscillator::generateTone()
{
    if (waveformShape == "Square")
    {
        signal = 0.5 * (frequency); //This is a dummy example
        playingTone = true;
    }
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

void Oscillator::playbackROMSamples(bool anyKeyPressed)
{
    if (anyKeyPressed == true)
    {
        signal = storedROM + 1;
    }
    
}

struct Filter 
{
    Filter();
    double gain; 
    double bandwidth = 0.7; 
    double frequency = 100.0; 
    std::string type = "Low Shelf"; 
    double drive = 0.0; 
    double pianoIR;
    double signal;

    void boostCutFreq();
    void overDriveSignal(); 
    void giveSonority(std::string instrument = "Piano");
};

Filter::Filter()
{
    std::cout << "Filter being constructed!" << std::endl;
}

void Filter::boostCutFreq()
{
    gain = -12;
    double fs = 44'100;
    double theta = (2 * 3.1416 * frequency) / fs;
    double miu = 10 * (gain/20);
    double betha = 4 / (1 + miu);
    double delta = betha * (theta / 2);
    double gamma = ((1 - delta) / (1 + delta));
    double a0 = (1 - gamma) / 2, a1 = (1 - gamma) / 2, a2 = 0;
    double b1 = -gamma, b2 = 0;
    double xn1 = 0, xn2 = 0, yn1 = 0, yn2 = 0;
    for (int n = 1; n <= fs; ++n)
    {
        signal = ((a0) + (a1 * xn1) + (a2 * xn2) - (b1 * yn1) - (b2 * yn2));
    } 
}

void Filter::overDriveSignal()
{
    signal = (2.5 * (0.9 * drive)) + (2.5 * (1 - ((0.9 * drive))))-2.5;
}

void Filter::giveSonority(std::string instrument)
{
    if (instrument == "Piano")
    {
        signal = signal * pianoIR;
    }
}

struct Reverb
{
    Reverb();
    double time = 0.1; 
    double mix = 20.0; 
    std::string type = "Plate";
    double preDelay = 0.1; 
    double size = 0.1; 
    double signal;
    
    void simulateSpace();
    void giveBetterSound(std::string instrument = "Trumpets");
    void giveDepth(double pan = 75, bool stereo = true); 
};

Reverb::Reverb()
{
    std::cout << "Reverb being constructed!" << std::endl;
}

void Reverb::simulateSpace()
{
    signal = signal * (time + mix);
}

void Reverb::giveBetterSound(std::string instrument)
{
    if (instrument == "Trumpets")
    {
        signal = signal * (preDelay + size);
    }
} 

void Reverb::giveDepth(double pan, bool stereo)
{
    if (stereo == true)
    {
        double x1 = 1;
        signal =  signal + (x1 * pan) / 100;
    }
}

struct Synthesizer
{
    Synthesizer();
    ADSR violinADSR;  
    LFO vibratoLFO; 
    Oscillator aMaj; 
    Filter lowShelf; 
    Reverb plate; 

    void startSignal();
    void modifySignal(); 
    void processSignal();
};

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer being constructed!" << std::endl;
}

void Synthesizer::startSignal()
{
    if (aMaj.playingTone == true)
    {
        aMaj.generateTone(); 
    }
    else
    {
        aMaj.loadROMSamples("SD", true);
        aMaj.playbackROMSamples(false);
    }
    
    violinADSR.modifyLoudness();
    violinADSR.modOscillatorPitch(320, 0.35, 0.35);
    violinADSR.modFilterFrequency(500, 0.5);
}

void Synthesizer::modifySignal()
{
    vibratoLFO.modulateSignal("Oscillator");
    vibratoLFO.toggleEnablement(true);  
    vibratoLFO.changeSignalsInteraction();;
}

void Synthesizer::processSignal()
{
    lowShelf.boostCutFreq();
    lowShelf.overDriveSignal(); 
    lowShelf.giveSonority("Piano");

    plate.simulateSpace();
    plate.giveBetterSound("Trumpets");
    plate.giveDepth(75, true); 
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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
