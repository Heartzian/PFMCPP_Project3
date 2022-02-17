/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) {} 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()

//***************************************************************
/*namespace StudentWork1
{
struct Filter
{ 
    int gain = 0; 
    Filter(int n) : gain(n) {} 
};
struct EQ
{
    Filter varyGain( int maxGain, int startingVal )  
    {
        Filter lowFreq(startingVal);                
        while( lowFreq.gain < maxGain )          
        { 
            lowFreq.gain += 1;                    
            std::cout << "  increasing lowFreq.gain: " << lowFreq.gain << std::endl; //4)
            if( lowFreq.gain >= maxGain )       
                return lowFreq;
        }
        
        return Filter {-1}; 
    }
};

int main()
{
    EQ lowParamEQ;
    auto lowFreq = lowParamEQ.varyGain(6, 0);
    
    std::cout << "lowFreq.gain: " << lowFreq.gain << std::endl;     //4) 
    return 0;
}
}



namespace StudentWork2
{
struct Filter
{ 
    int gain = 0; 
    Filter(); 

    void addOneToGain();
};

Filter::Filter() {}

void Filter::addOneToGain()
{
    gain += 1;
}

struct EQ
{
    Filter lowFreq;
    Filter midFreq;
    Filter highFreq;
    EQ();

    int increaseGain(Filter filterName, int maxGain = 6, int startingVal = 0);
    void increaseFrequency(Filter filterName);
    void increaseBandwidth(Filter filterName);    
};

EQ::EQ() {}

int EQ::increaseGain(Filter filterName, int maxGain, int startingVal)
{
    filterName.gain = startingVal;
    while( filterName.gain < maxGain )
    {
        filterName.addOneToGain();                    
        std::cout << "  increasing lowFreq.gain: " << filterName.gain << std::endl; 
    }
    return filterName.gain;
}


int main()
{
    Filter lowFreq;
    EQ lowParamEQ;
    auto lowGain = lowParamEQ.increaseGain(lowFreq, 6, 0);     
    std::cout << "lowFreq.gain: " << lowGain << std::endl;
    return 0;
}
}*/


struct Market
{
    double numProdLocalInv = 215;
    int numLogisticVehicles = 5; 
    int numPeopleWorkingAtStore =32; 
    double dailyBasicUtilitiesFee = 320.53;  
    double dailyIncome = 0; 
    double dailyProfit = 0;
    int peopleAtStore = 0;
    std::string marketCompleteName {"Asia SuperMarket"};
    Market();

    struct Customer
    {
        int age = 38;
        bool member = true;
        int visitsThisWeek = 0;
        std::string gender = "Male";
        int breakfastProds = 4;
        int morningBreakProds = 2;
        int lunchProds = 5;
        int coffeeBreakProds = 2;
        int dinnerProds = 3;
        std::string name = "";
        std::string customerName {"Frederick Carl Steinhaus"};
        int productsToOrder = 0;
        double productsPrice = 0;
        double totalToPay = 0;
        Customer();

        void selectDailyFood(); 
        void calculateOrderPrice(); 
        void orderProducts(bool deliveryRequired = true);
        void printMarketCustomerInitVar();            
    };

    void sellProducts(Customer customerName);
    void adjustInventary(Customer customerName);
    void printMarketInitVar();
    int calculateVisitors(Market marketName, int maxPeople, int startValue);  
};

Market::Market()
{
    std::cout << "\nMarket being constructed!" << std::endl;
}

Market::Customer::Customer()
{
    std::cout << "Customer Market being constructed!\n" << std::endl;
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

void Market::Customer::printMarketCustomerInitVar()
{
    std::cout << "\tMarket::Customer::printMarketCustomerInitVar()\n\t\t" << customerName << std::endl;
}

void Market::sellProducts(Customer customerName) //Nick example
{ 
    ++customerName.visitsThisWeek;
    customerName.name = "Carl Sag";
    --numLogisticVehicles;
    --numPeopleWorkingAtStore;
    dailyIncome += customerName.totalToPay;

    std::cout << "Dear " << customerName.name << ", you ordered " <<  customerName.productsToOrder << " products, with a total cost of $" << customerName.totalToPay << ", which will be Delivered by Tom." << " this week, you have come to our store " << customerName.visitsThisWeek << " times, Thanks for buying with us!\n" << std::endl;
}

void Market::adjustInventary(Customer customerName)
{
    numProdLocalInv -= customerName.productsToOrder;
}

void Market::printMarketInitVar()
{
    std::cout << "Market::printMarketInitVar()\n\t\t" << marketCompleteName << std::endl;
}

int Market::calculateVisitors(Market marketName, int maxPeople, int startValue)
{
    marketName.peopleAtStore = startValue;
    while(marketName.peopleAtStore < maxPeople)
    {
        marketName.peopleAtStore += 1;
        std::cout << "People at Store: " << marketName.peopleAtStore << std::endl;
        if( marketName.peopleAtStore >= maxPeople )
        {
            std::cout << "Because of COVID19 regulations, no more people is allowed to get in." << std::endl;
        }
    }
    return marketName.peopleAtStore;
}

struct University
{
    int numClassrooms = 80;
    int numLabs = 36;
    int numProfessors = 95;
    float semIncome = 0;
    int classesPerSemester = 0;
    std::string universityName {"Programming Technology University"};
    University();

    struct Professor
    {
        int age = 30;
        std::string name = "";
        std::string profession = "Engineer";
        std::string postgraduateStudies = "MsC";
        std::string teachingRank = "Band 4";
        std::string professorName {"Joseph Abraham Stern"};
        int yearsExperience = 15;
        int teachedClasses;
        Professor();

        void checkSubscribedStudents();
        float computeMonthlyExpenses(float rent = 1800,
                                     float food = 550,
                                     float fun = 120, 
                                     float other = 150);
        void printUniversityProfessorInitVar();
    };

    struct Student
    {
        int age = 18; 
        std::string name = "";
        std::string department = "Engineer"; 
        std::string career = "AgroIndustrial Engineer";
        std::string courseName = "Managing a Field of Corn";
        std::string studentCompleteName {"Frank Kaf"};
        float courseID = 001;
        std::string hobby = "Play Bass";
        int semestralCredits = 9;
        int weeklyPresentialStudyHours = 0;
        int weeklyResearchStudyHours = 0;
        double semestralStudyTime = 0;
        double semestralAllowedAbsences = 0;
        Student();

        void computeWeekStudyTime();
        void computeSemestralAbsences();
        void displayStudentInfo(Student studentName);
        void subscribeCourse(Student studentName, Professor professorName);
        void printUniversityStudentInitVar();
    }; 

    float teachStudents();  
    void doCollaborativeResearch(std::string organization = "UCLA",
                                 std::string department = "Chemistry",
                                 std::string projectName = "influence of fertilizer on plant cultivation"); 
    void performCulturalActivities(Student name,
                                   std::string category = "Arts",
                                   std::string activity = "Music Museum Visit"); 
    void printUniversityInitVar();
};

University::University()
{
    std::cout << "University being constructed!" << std::endl;
}

University::Professor::Professor()
{
    std::cout << "University Professor being constructed!" << std::endl;
}

void University::Professor::printUniversityProfessorInitVar()
{
    std::cout << "\tUniversity::Professor::printUniversityProfessorInitVar()\n\t\t" << professorName << std::endl;
}

University::Student::Student()
{
    std::cout << "University Student being constructed!\n" << std::endl;
}

void University::Professor::checkSubscribedStudents()
{
    return ;
}

float University::Professor::computeMonthlyExpenses(float rent,
                                                    float food,
                                                    float fun, 
                                                    float other)
{
    return rent + food + fun + other;
}

void University::Student::computeWeekStudyTime()
{
    weeklyPresentialStudyHours = semestralCredits * 3;
    weeklyResearchStudyHours = weeklyPresentialStudyHours * 2;
    semestralStudyTime = (weeklyPresentialStudyHours + weeklyResearchStudyHours) * 16;
    name = "Frank Kaf";
}

void University::Student::computeSemestralAbsences()
{
    semestralAllowedAbsences = ((weeklyPresentialStudyHours * 16) * 0.1) / 3;
}

void University::Student::displayStudentInfo(Student studentName)
{
    std::cout << "Dear " << studentName.name << ". Welcome to study " << studentName.career << ". This semester you chose " << studentName.semestralCredits << " credits. You'll have " << studentName.weeklyPresentialStudyHours << " weekly presential study hours. Please remember you can only have 10% of class absence, which in your case means " << studentName.semestralAllowedAbsences << " hours per class. Enjoy your time!\n" << std::endl;
}

void University::Student::subscribeCourse(Student studentName, Professor professorName)
{
    std::cout << "Dear " << studentName.name << " you've successfully subscribed the assignature " << courseName << ". Which will have Professor " << professorName.name << " as Main Professor for this class.\n" << std::endl;
}

void University::Student::printUniversityStudentInitVar()
{
    std::cout << "\tUniversity::Student::printUniversityStudentInitVar()\n\t\t" << studentCompleteName << std::endl;
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

void University::performCulturalActivities(Student studentName,
                                           std::string category,
                                           std::string activity)
{
    std::cout << "This semester the University performed a Cultural Activity with " << studentName.name << " from " << studentName.career << " which likes to " << studentName.hobby << " in the category: " << category << " doing the activity " << activity << ".\n" << std::endl;
}

void University::printUniversityInitVar()
{
    std::cout << "University::printUniversityInitVar()\n\t\t" << universityName << std::endl;
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
    std::string computerName {"Republic of Gamers Strix Scar"};
    Computer();

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
        Hardware();
        
        void playGames(); 
        void trainAI(); 
        void workAtOffice(); 
    };

    void executePrograms(Hardware specs, std::string installedSoft);  
    void saveInfo(bool diskAvailable = true); 
    void connectToPCs(bool LANavailable = true);
    void printComputerInitVar();
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

Computer::Hardware::Hardware()
{
    std::cout << "Computer Hardware being constructed!\n" << std::endl;
}

void Computer::Hardware::playGames()
{
    if (RAM >= 4 && disk >=256 && CPU >= 3.0 && GPU >= 2)
    {
        //std::cout << "You can use this computer to play games";  
    
        canPlayGames = true;
    }
}

void Computer::Hardware::trainAI()
{
    if (canPlayGames == true && GPU > 4)
    {
        //std::cout << "You can use this computer to train AI using" << softwareReq;

        canTrainAI = true;
    }
    
}

void Computer::Hardware::workAtOffice()
{
    if (canPlayGames == true)
    {
        //std::cout << "You can use this computer to do " << mostlyUsedTask;

        canUseAtOffice = true;
    }
    
} 

void Computer::executePrograms(Hardware specs, std::string installedSoft)
{
    if (installedSoft == "GTA")
    {
        if (specs.canPlayGames == true)
        {
            std::cout << "According to the given specs, this computer can be used to play Grand Theft Auto\n" << std::endl;
        }
        else
        {
            std::cout << "Sorry!! This computer can NOT be used to play Grand Theft Auto becasuse of the specs" << std::endl;
        }
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

void Computer::printComputerInitVar()
{
    std::cout << "Computer::printComputerInitVar()\n\t" << computerName << std::endl;
}

struct AudioMixer
{
    int inputCh = 128; 
    int outputCh = 64; 
    int DSPRacks = 16; 
    int parallelProcessingCH = 24; 
    int DSPspeed = 800; 
    int availableInCh = 0;
    int availableOutCh = 0;
    int availableProcessing = 0;
    std::string mixerName {"Allen & Heath S7000"};
    AudioMixer();

    struct ExpandableProtocol
    {
        bool MADI;
        bool waves;
        bool AVR;
        bool aviom;
        bool DANTE;
        std::string protocol;
        float syncFrequency;
        ExpandableProtocol();

        void sends(std::string application = "Recording");
        float sync(std::string clockSource = "External",
                   float frequency = 96'000); 
    };

    void mixSignals(std::string application = "Touring Live Sound");
    void splitSignal(std::string destination = "Broadcast");
    void processSignal(int paramEQ = 64,
                       int graphEQ = 16);
    void info(ExpandableProtocol connectionName);
    void printAudioMixerInitVar();
};

AudioMixer::AudioMixer()
{
    std::cout << "AudioMixer being constructed!" << std::endl;
}

AudioMixer::ExpandableProtocol::ExpandableProtocol()
{
    std::cout << "AudioMixer ExpandableProtocol being constructed!\n" << std::endl;
}

void AudioMixer::ExpandableProtocol::sends(std::string application)
{
    if(application == "Monitors")
    {
        DANTE = true;
        if (DANTE == true)
        {
            protocol = "Dante";
        }
    }
}

float AudioMixer::ExpandableProtocol::sync(std::string clockSource,
                                            float frequency)
{
    if (clockSource == "External")
    {
        syncFrequency = frequency;
    }
    return syncFrequency;
}

void AudioMixer::mixSignals(std::string application)
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
}

void AudioMixer::splitSignal(std::string destination) 
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
    else if (destination == "Monitors")
    {
        int frontMix = 3;
        int sideMix = 2;
        int subOut = 2;
        int trumpMix = 1;
        int saxMix = 1;
        int drumMix = 2;
        int usedOutCh = frontMix + sideMix + subOut + trumpMix + saxMix + drumMix;
        availableOutCh = outputCh - usedOutCh;
    }
}   

void AudioMixer::processSignal(int paramEQ,
                               int graphEQ)
{
    int procInCh = paramEQ * (availableInCh - inputCh);
    int procOutCh = graphEQ * (availableOutCh - outputCh);
    availableProcessing = (procInCh + procOutCh) - DSPspeed;
    //std::cout << "Available Processing= " << availableProcessing;
}

void AudioMixer::info(ExpandableProtocol connectionName)
{
    std::cout << "The selected mixer have " << inputCh << " inputs channels and " << outputCh << " output channels, which right now still have " << availableInCh << " input channels and " << availableOutCh << " output channels. The Main signal will be splitted with Monitors using " << connectionName.protocol << ".\n" <<std::endl;
}

void AudioMixer::printAudioMixerInitVar()
{
    std::cout << "AudioMixer::printAudioMixerInitVar()\n\t" << mixerName << std::endl;
}

struct ADSR
{
    double attackTime = 0.01;
    double holdTime = 0.01;
    double decayTime = 0.05;
    double sustainLevel = 0.5;
    double releaseTime = 0.5;
    double signal;
    std::string adsrName {"Impulsive Transient Signal"};
    ADSR();

    void modifyLoudness();
    void modOscillatorPitch(double oscFreq = 440.0,
                              double pitch = 0.35,
                              double pitchMod = 0.35);
    void modFilterFrequency(int cutoff = 2'500, 
                              double cutoffMod = 0.35);
    void printADSRInitVar();
};

ADSR::ADSR()
{
    std::cout << "ADSR being constructed!\n" << std::endl;
}

void ADSR::modifyLoudness()
{
    int fs = 44'100;
    double attack = attackTime * fs;
    double sustain = sustainLevel * fs;
    signal = attack + sustain + releaseTime;  //This is a dummy example (not true)  
    std::cout << "Loudness Parameters:\n" << "\tAttack Time: " << attackTime << "ms\n" << "\tSustain:" << sustainLevel << std::endl;
}

void ADSR::modOscillatorPitch(double oscFreq,
                              double pitch,
                              double pitchMod)
{
    signal = (oscFreq * pitch) / pitchMod; //This is a dummy example 
    std::cout << "Oscillator Pitch Modulation Parameters:\n" << "\tOscillation Frequency: " << oscFreq << "Hz.\n" << "\tPitch: " << pitch << "\n\tPitch Modulation: " << pitchMod << "\n" << std::endl;
}

void ADSR::modFilterFrequency(int cutoff, 
                              double cutoffMod)
{
    signal = cutoff * cutoffMod; //This is a dummy example
}

void ADSR::printADSRInitVar()
{
    std::cout << "ADSR::printADSRInitVar()\n\t" << adsrName << std::endl;
}

struct LFO
{
    float rate = 20.0f; 
    int phaseOffset  = 0.0f; 
    double amount = 48; 
    std::string shapeWaveform  = "Sine"; 
    bool bypassState = false; 
    double signal;
    std::string lfoName {"Low Frequency Oscillator"};
    LFO();

    void modulateSignal(std::string routeAssign = "Oscillator");
    void toggleEnablement(bool shouldBeOn = true);  
    void changeSignalsInteraction();
    void printLFOInitVar();
};

LFO::LFO()
{
    std::cout << "LFO being constructed!\n" << std::endl;
}

void LFO::modulateSignal(std::string routeAssign)
{
    if (routeAssign == "Oscillator")
    {
        double y = 1;
        signal = signal + y; //This is a dummy example
        std::cout << "LFO Assigned to " << routeAssign << std::endl;
    } 
}

void LFO::toggleEnablement(bool shouldBeOn)
{
    if (shouldBeOn == false)
    {
        bypassState = true;
    }
    std::cout << "LFO in Bypass Mode: " << bypassState << std::endl;
}

void LFO::changeSignalsInteraction()
{
    int fs = 44'100;
    for (int i = 0; i < fs; i++)
    {
        signal = amount - phaseOffset; //This is a dummy example
    }
    std::cout << "LFO Signals Interaction:\n\tAmount: " << amount << "\n\tPhase Offset: " << phaseOffset << "\n" << std::endl;
}

void LFO::printLFOInitVar()
{
    std::cout << "LFO::printLFOInitVar()\n\t" << lfoName << std::endl;
}

struct Oscillator
{
    float finetune = 0.01f; 
    std::string waveformShape = "Sine"; 
    float pulseWidth = 0.3f; 
    int octave = 2; 
    double loadedROM;
    double storedROM;
    bool playingTone;
    bool playButton;
    double signal;
    std::string oscillatorName {"Signal Wave Generator"};
    Oscillator();

    void generateTone(std::string waveformShape, double frequency); 
    void loadROMSamples(std::string selectStorageDevice = "SD",
                        bool isAudioFormat = true);
    void playbackROMSamples();
    void printOscInitVar();
};

Oscillator::Oscillator()
{
    std::cout << "Oscillator being constructed!\n" << std::endl;
}

void Oscillator::generateTone(std::string waveformShapeName, double freq = 1000)
{
    if (waveformShapeName == "Sine")
    {
        signal = 0.5 * (freq); //This is a dummy example
        playingTone = true;
        std::cout << "A " << waveformShapeName << " tone on " << freq << " Hz was generated." << std::endl;
    }
    else if (waveformShapeName == "None")
    {
        std::cout << "No waveform selected!" << std::endl;
        playingTone = false;
    }

}

void Oscillator::loadROMSamples(std::string selectStorageDevice,
                                  bool isAudioFormat)
{
    if (selectStorageDevice == "SD")
    {
        if(isAudioFormat == true)
        loadedROM = true;
    }
    std::cout << "The Audio File is loaded successfully: " << loadedROM << std::endl;
}

void Oscillator::playbackROMSamples()
{
    if (playingTone == true)
    {
        std::cout << "The tone is still playing, please press ESC to stop it, then push PLAY button. \n" << std::endl;
    }
    else 
    {
        std::cout << "The loaded Audio File is now being reproduced.\n" << std::endl;
    }
}

void Oscillator::printOscInitVar()
{
    std::cout << "Oscillator::printOscInitVar()\n\t" << oscillatorName << std::endl;
}

struct Filter 
{
    double gain = -12; 
    double bandwidth = 0.7; 
    double frequency = 440.0; 
    double drive = 0.0; 
    double pianoIR;
    double signal;
    std::string filterType = "Low Pass";
    std::string filterName {"Low Pass Filter"};
    Filter();

    void selectFilter(std::string filterCall = "LP");
    void boostCutFreq();
    void overDriveSignal(); 
    void giveSonority(std::string instrument = "Piano");
    void printFilterInitVar();
};

Filter::Filter()
{
    std::cout << "Filter being constructed!\n" << std::endl;
}

void Filter::selectFilter(std::string filterCall)
{
    if (filterCall == "LP")
    {
        filterType = "Low Pass";
    }
}

void Filter::boostCutFreq()
{
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
    std::cout << "Filter Parameters:\n\tFilter Type : " << filterType << "\n\tGain: " << gain << " dB\n\tCut Frequency: " << frequency << "Hz" <<std::endl;
}

void Filter::overDriveSignal()
{
    signal = (2.5 * (0.9 * drive)) + (2.5 * (1 - ((0.9 * drive))))-2.5;
    std::cout << "\tFilter OverDrive: " << drive << "dB" << std::endl;
}

void Filter::giveSonority(std::string instrument)
{
    if (instrument == "Piano")
    {
        signal = signal * pianoIR;
    }
    std::cout << "\tPreset Loaded: " << instrument << " \n" << std::endl;
}

void Filter::printFilterInitVar()
{
    std::cout << "Filter::useTheSameFrequency()\n\t" << filterName << std::endl;
}

struct Reverb
{
    double time = 0.1; 
    double mix = 20.0; 
    std::string type = "Plate";
    double preDelay = 0.1; 
    double spaceSize = 200; 
    double signal;
    std::string reverbName {"Plate Reverb for Trumpets"};
    Reverb();
    
    void simulateSpace();
    void giveBetterSound(std::string instrument = "Trumpets");
    void giveDepthOnSpace(double pan = 75, bool stereo = true); 
    void printReverbInitVar();
};

Reverb::Reverb()
{
    std::cout << "Reverb being constructed!\n" << std::endl;
}

void Reverb::simulateSpace()
{
    signal = signal * (time + preDelay);
    std::cout << "Reverb Parameters:\n\tReverb Time: "<< time <<  " ms\n"<< "\tPre-Delay Time:" << preDelay << std::endl;
}

void Reverb::giveBetterSound(std::string instrumentName)
{
    if (instrumentName == "Trumpets")
    {
        type = "Plate";
        signal = signal * (preDelay + spaceSize);
    }
    std::cout << "\tReverb for used for this instrument (Preset Name): " << type <<std::endl;
} 

void Reverb::giveDepthOnSpace(double pan, bool stereo)
{
    if (stereo == true)
    {
        double x1 = 1;
        signal =  signal + (x1 * pan) / 100;
    }
    std::cout << "\tReverb Spaceness Quantity: " << spaceSize << " \n" << std::endl;
}

void Reverb::printReverbInitVar()
{
    std::cout << "Reverb::printReverbInitVar()\n\t" << reverbName << std::endl;
}

struct Synthesizer
{
    ADSR violinADSR;  
    LFO vibratoLFO; 
    Oscillator aMaj; 
    Filter lowShelf; 
    Reverb plate; 
    Synthesizer();

    void startSignal(std::string toneDef = "Tone");
    void modifySignal(); 
    void processSignal();
    void checkAllIsOK();
};

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer being constructed!" << std::endl;
}

void Synthesizer::startSignal(std::string toneOrSample)
{
    if (toneOrSample == "Tone")
    {
        aMaj.generateTone("Sine", 1000); 
    }
    else if (toneOrSample == "Sample")
    {
        aMaj.loadROMSamples("SD", true);
        aMaj.playbackROMSamples();
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
    plate.giveDepthOnSpace(75, true); 
}

void Synthesizer::checkAllIsOK()
{
    std::cout << "Synthesizer::checkAllIsOK() " << "I don't know what should I write here!! :(" << std::endl;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.*/
 

#include <iostream>
int main()
{
    Example::main();
    //StudentWork1::main();
    //StudentWork2::main();
    
    Market superStarMarket;
    Market::Customer carl;
    carl.selectDailyFood(); 
    carl.calculateOrderPrice(); 
    carl.orderProducts(true);
    superStarMarket.sellProducts(carl);
    superStarMarket.adjustInventary(carl);
    auto superStarMarketCustomers = superStarMarket.calculateVisitors(superStarMarket, 10, 2);

    std::cout << "market.peopleAtStore: " <<             superStarMarketCustomers << " \n" << std::endl;     
    
    //std::cout << "Is superStarMarket member var 'dailyProfit' equal to 0? " << (superStarMarket.dailyProfit == 0 ? "Yes" : "No") << "\n";

    University programmingSchoolUniversity;
    University::Professor joseph;
    University::Student frank;
    joseph.name = "Joseph Stewart";
    frank.computeWeekStudyTime();
    frank.computeSemestralAbsences();
    frank.displayStudentInfo(frank);
    frank.subscribeCourse(frank, joseph);
    programmingSchoolUniversity.performCulturalActivities(frank);

    Computer gamingPC;
    Computer::Hardware highSpecs;
    highSpecs.playGames();
    gamingPC.executePrograms(highSpecs, "GTA");

    AudioMixer fohMixer;
    AudioMixer::ExpandableProtocol fohToMonitorConnection;
    fohToMonitorConnection.sends("Monitors");
    fohToMonitorConnection.sync("External");
    fohMixer.mixSignals("Touring");
    fohMixer.splitSignal("Monitors");
    fohMixer.processSignal();
    fohMixer.info(fohToMonitorConnection);

    ADSR impulsive;
    impulsive.modifyLoudness();
    impulsive.modOscillatorPitch(400, 35, 10);

    LFO assignedToOsc;
    assignedToOsc.modulateSignal("Oscillator");
    assignedToOsc.toggleEnablement(true);  
    assignedToOsc.changeSignalsInteraction();

    Oscillator pureTone;
    Oscillator sampleOnSD;
    pureTone.generateTone("Sine"); 
    sampleOnSD.loadROMSamples("SD");
    sampleOnSD.playbackROMSamples(); 

    Filter lowPass;
    lowPass.selectFilter("LP");
    lowPass.boostCutFreq();
    lowPass.overDriveSignal(); 
    lowPass.giveSonority("Piano");

    Reverb trumpetPlate;
    trumpetPlate.simulateSpace();
    trumpetPlate.giveBetterSound("Trumpets");
    trumpetPlate.giveDepthOnSpace(75, true); 

    Synthesizer allTogether;
    allTogether.startSignal("Sample");
    allTogether.modifySignal(); 
    allTogether.processSignal();
    //allTogether.checkAllIsOK();  

    //Here starts the Part4 work!
    superStarMarket.printMarketInitVar();
    carl.printMarketCustomerInitVar();
    programmingSchoolUniversity.printUniversityInitVar();
    joseph.printUniversityProfessorInitVar();
    frank.printUniversityStudentInitVar();
    gamingPC.printComputerInitVar();
    fohMixer.printAudioMixerInitVar();
    impulsive.printADSRInitVar();
    assignedToOsc.printLFOInitVar();
    pureTone.printOscInitVar();
    lowPass.printFilterInitVar();
    trumpetPlate.printReverbInitVar();
    
    std::cout << "good to go!" << std::endl;
}
