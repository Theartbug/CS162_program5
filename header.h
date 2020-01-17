   /*  Grace Provost
      *  gprovost@pdx.edu
      *  Program 5
      *  11/29/19
      *  CS 162
      *
      *  PURPOSE: header file containing function prototypes, constants, structs, and classes. all in one place for convenience to bring into the .cpp files.
   */

#include <iostream>
#include <cctype>
#include <cstring>

// CONSTANTS AND GLOBALS

// the max character size for an listItem name
const int MAX_NAME_SIZE = 40;
// max date size xx/xx/xxxx and includes space for '\n'
const int MAX_DATE_SIZE = 11;
// number of characters for the question text
const int MAX_DESCRIPTION_SIZE = 130;


// CLASS DEFINITIONS

class listItem
{
    public:
        // constructor that sets initial values
        listItem(void);
        // destructor for dynamically allocated pointers
        ~listItem(void);
        // displays the list item
        void display(void);
        // compares a given priority to the one stored in the list item, returns true if equal
        bool comparePriority(int priority);
        // takes user input to create a list item
        void getListItem(void);
        // get the name for future comparison
        char *getName(void);
        // to compare two names for list placement
        int compareName(const char* name);

    private:
        // to store the name of the wish list item
        char *name;
        // to store the description of the wish list item
        char *description;
        // to store the desired completion date
        char *date;
        // to store the priority
        int priority;
};

// struct for a node
struct node
{
    ~node();
    listItem item;
    node *next;
};

// linked list
class list
{
    public:
        // constructor that sets initial values
       list(void);
       // destructor for dynamically allocated pointers
       ~list(void);
       // display all items in the list
       void displayAll(void);
       // display by priority
       void displayByPriority(void);
       // display number in list
       int getCount(void);
       // add a list item in name alphabetical order
       void add(void);
       // remove an item by name
       void remove(void);
       // clear the list
       void clearList(void);

    private:
        // keep track of the first item in the list
        node *head;
        // keep track of the number of items in the list
        int count;
};


// FUNCTION PROTOTYPES


// switch case to interpret users selection
void menuSwitch(int menuChoice, list& myList);

// obtains an integer response
// between a certain inclusive range
int getIntegerRangeResponse(int max, int min);

// this helper obtains a single character
// checks if it is a valid y / n response
// and returns a boolean based on if the response
// is yes = true, no = false
bool getResponse(void);

// this helper takes in a char pointer
// and creates a temp array to obtain user input up to the arraySize
// then creates a new char array the exact size of the temp array
// and places into the pointer
// while providing validation specific to a date
void getDate(char* &pointer, int arraySize);

// this helper takes in a char pointer
// and creates a temp array to obtain user input up to the arraySize
// then creates a new char array the exact size of the temp array
// and places into the pointer
void getString(char* &pointer, int arraySize);

// a helper function for cleaning out the buffer
// since we will be doing it multiple times
void clearBufferStream(void);

// displays the main menu and obtains the users
// response to what they want to do
int getMainMenu();

