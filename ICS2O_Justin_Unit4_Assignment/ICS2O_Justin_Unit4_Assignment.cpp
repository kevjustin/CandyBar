/*Kevin Justin
ICS2O
RST
Creates an array of a structure
and displays the information
06/12/2020*/

#include <iostream>                                                             //A preprocessor directive
#include <string>                                                               //Includes the string library
#include <sstream>                                                              //Inclues sstream library
#include <limits>																//Includes limits library
using namespace std;                                                            //Makes definitions visible

/*Constant Declaration and Assignment*/
const int arraySize = 100;

/*Function Prototypes*/
void printWelcomeMessage();
void askBarInfo(int barNum);
void printBarInfo(int barNum);
void printDivider();
void printResults();
void printClosingMessage();

/*Enumeration for type Bar*/
enum Bar
{
    bar1,
    bar2,
    bar3
};

/*CandyBar Structure*/
struct CandyBar
{
    string brandName;                                                           //First member

    union {                                                                     //Second member
        int integer;
        double fractional;
    } weight;

    int calories;                                                               //Third Member
};

CandyBar * bars = new CandyBar[3];                                              //Array of CandyBar (makes array global)

/*Main*/
int main()
{
    Bar bar;                                                                    //Initializes Enum Bar

	//Prints Message
    printWelcomeMessage();
    printDivider();

    /*Gets Candy Bar Info From User*/

    //First Bar
    askBarInfo(bar1);
    printDivider();

    //Second Bar
    cin.get();
    askBarInfo(bar2);
    printDivider();

    //Third Bar
    cin.get();
    askBarInfo(bar3);
    printDivider();

    /*Prints Candy Bar Info*/

    //Displays results
    printResults();
    printDivider();

    //First Bar
    printBarInfo(bar1);
    printDivider();

    //Second Bar
    printBarInfo(bar2);
    printDivider();

    //Third Bar
    printBarInfo(bar3);
    printDivider();
	
	//Prints Message
	printClosingMessage();
	printDivider();

    /*Ends Program*/
    system("PAUSE");
    return 0;
}




/*Function Definitions*/

//Function definition for printWelcomeMessage
void printWelcomeMessage()
{
    cout << "\12Welcome to Kevin's Candy Bar Survey!" << endl;
    cout << "We would like to get your input on 3 different candy bars!" << endl;
    system("PAUSE");
}

//Function definition for askBarInfo
void askBarInfo(int barNum)
{
    //Function variable definitons
    bool name_status = 1;
    bool weight_status = 1;
    bool calories_status = 1;

    cout << "\12Enter the information for Candy Bar #" << barNum+1 << ":" << endl;

    cout << "\12\11Candy Bar Name: ___\b\b\b";
    
    /*Repeats until input is correct*/
    while(name_status == 1)
    {
        int hasNumber = 0;
        string input;
        getline(cin, input);                                                    //Reads the line

        /* Checks if string input is number*/
        for(int x=0;x<input.length();x++)
        {
            if(isdigit(input[x]) == false)
            {
                hasNumber++;
            }
            else{
                hasNumber = 0;
            }
        }

        if(hasNumber == 0)
        {
            name_status == 1;
            cout << "\11INVALID! Please enter a name again: ";
        }
        else{
            name_status == 0;
            bars[barNum].brandName = input;
            break;
        }
    }

    cout << "\11Weight (in grams): __\b\b";
    
	/*Repeats until input is correct*/
    while(weight_status == 1)
    {
        double weight;
        cin >> weight;

        if(!cin)                                                                //If the input failed
        {
            cin.clear();                                                        //Sets a fail bait
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                //Ignores
            weight_status = 1;
            cout << "\11INVALID! Please input the weight again: ";
        }
        else
        {
            bars[barNum].weight.fractional = weight;
            weight_status = 0;
            break;
        }
    }
    cin.get();                                                                  //Clears input queue

    cout << "\11Calories of the bar: __\b\b";\

    /*Repeats until input is correct*/
    while(calories_status == 1)
    {
        int calories;
        cin >> calories;
        if(!cin)                                                                //If the input failed
        {
            cin.clear();                                                        //Sets a fail bait
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            calories_status = 1;
            cout << "\11INVALID! Please input the calories again: ";
        }
        else
        {
            bars[barNum].calories = calories;
            calories_status = 0;
            break;
        }
    }
}

//Function definition for printDivider
void printDivider()
{
    //This function prints 2 empty lines and these characters in order to divide the information
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

//Function definition for printResults
void printResults()
{
	system("CLS");																//Clears the board for upcoming text
    cout << "\12What were your results?" << endl;
    system("PAUSE");
}

//Function definition for printBarInfo
void printBarInfo(int barNum)
{
    cout << "\12\11" << bars[barNum].brandName << "'s Candy Bar: \n";
    cout << "\12\11Weight: " << bars[barNum].weight.fractional << " grams" << endl;
    cout << "\12\11Calories: " << bars[barNum].calories << endl;
}

//Function definition for printClosingMessage
void printClosingMessage()
{
	system("PAUSE");
    system("CLS");																//Clears the board
    cout << "\12Thank you for participating in Kevin's Candy Bar Survey!" << endl;
}
