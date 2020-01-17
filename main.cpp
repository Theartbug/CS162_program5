    /*  Grace Provost
       *  gprovost@pdx.edu
       *  Program 5
       *  11/29/19
       *  CS 162
       *
       *  PURPOSE: main file which contains the main function and other helper functions that do not belong to classes. These include mostly helpers for getting things from the user and validation.
       *
       *  ALGORITHM:
       *  1. create two classes, listItem and list, and a struct, node. Node will contain the listItem class and a self-refering node pointer called next, and list will contain a linked list of nodes. 
       *  2. listItem will have private fields date, name, description, and priority.
       *  3. listItem will have public functions for displaying the item, creating the item, comparing the priority, retreiving the name, 
constructor, and destructor.
       *  4. list will hvae private fields head and count.
       *  5. list will have public functions for displaying the whole list, displaying by subject, adding items, removing items, clearing the list, constructor, an destructor.
       *  6. steps 6 onward are within a do-while loop which exits once the user selects 0
       *  7. The user is greeted and given a menu with getMainMenu() to pick from with integer input. The input is stored within menuChoice and then fed through menuSwitch().
       *  8. If the user selects 1, addItems() is called and list.add() will continuously be called until they no longer wish to add items. list.add() creates a new node and listItem within that node, taking in user input.
       *  9. If the user selects 2, removeItems() is called and list.remove() will continuously be called until the user no longer wishes to remove items. list.remove() takes in a name from the user and searches the list for that name. Will remove if found, will say no if unsuccessful. Will not attempt if there is no list.
       *  10. If the user selects 3, all items in the list are displayed. list.displayAll() is called, and each individual listItem.display() is called. If there is no list will say so.
       *  11. If user selects 4, items by priority are displayed. list.displayByPriority() is called, and user input is accepted for the priority. Then only items with that priority are shown. If there is no list will say so.
       *  12. If user selects 5, the total list count is shown. It is retreived with list.getCount();
       *  13. If user selects 6, the linked list is cleared with list.clearList(). list.clearList() will delete head, which will trigger the destructor on the node struct, which will trigger the destructor on the listItem, recursively. Will say if there is no list to delete.
    */

 #include "header.h"

 using namespace std;

 int main()
{
    // create the list
    list myList;
    // store the menu choice
    int menuChoice;
    // welcome the user and show main menu to begin
    cout << "Welcome. This program allows you to enter items into a to-do list and displays them back to you. Please select what you would like to do:" << endl;
    do
    {
        menuChoice = getMainMenu();
        cout << "________________________________" << endl;
        // switch case to interpret users selection
         menuSwitch(menuChoice, myList);

    }
    while(menuChoice != 0);

    cout << "Goodbye!" << endl;
    return 0;
}



 // FUNCTION IMPLEMENTATIONS
 
// repeatedly asks the user if they would like to add items to their list
// then adds them until the user says no more
void addItems(list& myList)
{
    // While the user would like to add more items
    do 
    {
        myList.add();
        cout << "would you like to add another item to your to-do list? (y/n) ";
    }
    while(getResponse());
    return;
}



// repeatedly asks the user if they would like to remove a list item by name
// then attempts to remove it
// if the item was / was not removed, will say so
void removeItems(list& myList)
{
    // boolean for conditional
    bool removeAgain = false;
    do
    {
        myList.remove();
        if (myList.getCount() != 0)
        {
            cout << "Would you like to attempt remove another item from your to-do list? (y/n) ";
            removeAgain = getResponse();
        }
    }
    while(removeAgain);
    return;
}



 // switch case to interpret users selection
  void menuSwitch(int menuChoice, list& myList)
  {
      switch(menuChoice)
      {
            case 1:
              cout << "Let's add some items to our list!" << endl << endl;
              addItems(myList);
              break;
            case 2:
              removeItems(myList);
              break;
            case 3:
              myList.displayAll();
              break;
            case 4:
              myList.displayByPriority();
              break;
            case 5:
              cout << "The total items in the list is: " << myList.getCount() << endl;
              break;
            case 6:
              myList.clearList();
              break;
            default:
              break;
      }
  }



 // displays the main menu and obtains the users
  // response to what they want to do
  int getMainMenu()
  {
      // an integer for the highest possible response
      int maxResponse = 6;
      // an integer for the lowest possible response
      int minResponse = 0;
      cout << "~~~~~~~~~~ Main Menu ~~~~~~~~~~" << endl;
      cout << "0. Quit program" << endl;
      cout << "1. Add a to-do list items" << endl;
      cout << "2. Remove a to-do list item" << endl;
      cout << "3. Display all to-do items" << endl;
      cout << "4. Display all to-do items of a given priority" << endl;
      cout << "5. Display the number of items within your to-do list" << endl;
      cout << "6. Clear your to-do list" << endl;
      cout << "Enter a corresponding number to preform a task: ";

      return getIntegerRangeResponse(maxResponse, minResponse);
  }



   // this helper obtains a single character
  // checks if it is a valid y / n response
  // and returns a boolean based on if the response
  // is yes = true, no = false
  bool getResponse(void)
  {
    char response = '\0';
    // if the buffer stream is in error state
    while(!cin.get(response)
            // if response is not equal to y
            || (tolower(response) != 'y'
                // if the response is not equal to n
                && tolower(response) != 'n')
            // or the next character in the buffer is not a carriage return
            || cin.peek() != '\n')
    {
            if(cin.peek() != '\n') cout << "You entered too many characters, please try again: ";
            else cout << "Invalid input, please try again: ";
            // clear out that dirty stream
            clearBufferStream();
    }
            // clear out that dirty stream
            clearBufferStream();
    // return a boolean
    return tolower(response) == 'y';
  }

  // this helper takes in a char pointer
  // and creates a temp array to obtain user input up to the arraySize
  // then creates a new char array the exact size of the temp array
  // and places into the pointer
  void getString(char* &pointer, int arraySize)
  {
      // make a temp pointer so we can utilize this as a helper with possible    different array sizes
     char *tempArray = new char[arraySize];
    // if the buffer stream is in error state
    while(!cin.get(tempArray, arraySize, '\n')
            // or the next character in the buffer is not a carriage return
            || cin.peek() != '\n')
    {
            cout << endl;
            if(cin.peek() != '\n' && strlen(tempArray) > 1) cout << "You entered too many characters, please try again: ";
            else cout << "Invalid input, please try again: ";
            // clear out that dirty stream
            clearBufferStream();
    }
    // clear out that dirty stream
    clearBufferStream();
    // create a new place in data for the char array
    pointer = new char[strlen(tempArray) + 1];

    // copy the temp array into the pointer;
    strcpy(pointer, tempArray);

    // clean up local memory
    delete [] tempArray;

    return;
  }

  // obtains an integer response
  // between a certain inclusive range
  int getIntegerRangeResponse(int max, int min)
  {
      int response;
      while(!(cin >> response)
              // if not greater than or equal to min
              || !(response >= min
              // or less than or equal to max
              && response <= max))
      {
          cout << "Invalid input, try again: ";
          clearBufferStream();
      }
      clearBufferStream();
      return response;
  }



  // a helper function for cleaning out the buffer
  // since we will be doing it multiple times
  void clearBufferStream(void)
  {
     // clear out the errorstate
     // just in case it exists
     cin.clear();
     // ignore the rest of what is in the stream
     // up to 200 characters or
     // until carriage return is hit '\n'
     // and we can flush out the carriage return
     cin.ignore(200,'\n');
     return;
  }



  // this helper takes in a char pointer
  // and creates a temp array to obtain user input up to the arraySize
  // then creates a new char array the exact size of the temp array
  // and places into the pointer
  // while providing validation specific to a date
  void getDate(char* &pointer, int arraySize)
  {
      // make a temp pointer so we can utilize this as a helper with possible    different array sizes
     char *tempArray = new char[arraySize];
    // if the buffer stream is in error state
    while(!cin.get(tempArray, arraySize, '\n')
            // or the next character in the buffer is not a carriage return
            || cin.peek() != '\n'
            // if the date is less in size than it should be
            // not including the null terminator
            || strlen(tempArray) < arraySize - 1
            // if the dashes in the date dont exist
            || (tempArray[2] != '/' || tempArray[5] != '/')
            // if the date values are not numerical
            || !(isdigit(tempArray[0]) && isdigit(tempArray[1]) && isdigit(tempArray[3]) && isdigit(tempArray[4]) && isdigit(tempArray[6]) && isdigit(tempArray[7]) && isdigit(tempArray[8]) && isdigit(tempArray[9]))
            )
    {
            // insert a break so we are not on the same line as "enter phrase    number...:"
            cout << endl;
            if(cin.peek() != '\n') cout << "You entered too many characters,     please try again: ";
            else if(strlen(tempArray) < arraySize - 1) cout << "You entered too  few characters, enter in xx/xx/xxxx format: ";
            else if(tempArray[2] != '/' || tempArray[5] != '/') cout << "You     did not provide '/' at the expected positions, enter in xx/xx/xxxx format: ";
            else if(!(isdigit(tempArray[0]) && isdigit(tempArray[1]) && isdigit(tempArray[3]) && isdigit(tempArray[4]) && isdigit(tempArray[6]) && isdigit(tempArray[7]) && isdigit(tempArray[8]) && isdigit(tempArray[9]))) cout  << "You did not enter digits for the day, month, or year. Enter in xx/xx/xxxx   format: ";
            else cout << "Invalid input, please try again: ";
            // clear out that dirty stream
            clearBufferStream();
    }
    // clear out that dirty stream
    clearBufferStream();
    // create a new place in data for the char array
    pointer = new char[strlen(tempArray) + 1];

    // copy the temp array into the pointer;
    strcpy(pointer, tempArray);

    // clean up local memory
    delete [] tempArray;

    return;
  }
