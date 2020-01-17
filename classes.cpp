/*  Grace Provost
    *  gprovost@pdx.edu
   *  Program 5
   *  11/29/19
   *  CS 162
   *
   *  PURPOSE: contains the implementation of the class functions for listItem and list
*/

 #include "header.h"

 using namespace std;

 // a destructor for the node
 node::~node()
{
    // will recursively call a destructor on the next node
    // can delete NULL
    delete next;
}

// constructor that sets initial values
 listItem::listItem(void)
{
    name = NULL;
    description = NULL;
    date = NULL;
    priority = 0;
}



// destructor for dynamically allocated pointers
listItem::~listItem(void)
{
    if (name) delete [] name;
    if (description) delete [] description;
    if (date) delete [] date;
}



// displays the list item
void listItem::display(void)
{
    cout << "Name: " << name << endl;
    cout << "Priority: " << priority << endl;
    cout << "Due Date: " << date << endl;
    cout << "Description: " << description << endl;
    cout << "_________________________" << endl;
    cout << endl;
    return;
}



// get the name for future comparison
char *listItem::getName(void)
{
    return name;
}



// compares a given priority to the one stored in the list item, returns true if equal
bool listItem::comparePriority(int priority)
{
    return this->priority == priority;
}



// to compare two names for list placement
int listItem::compareName(const char* name)
{
    return strcmp(name, this->name);
}



// takes user input to create a list item
void listItem::getListItem(void)
{
    cout << "Give a name to this item: ";
    getString(name, MAX_NAME_SIZE);
    cout << "Enter a description of this item: ";
    // obtain description
    getString(description, MAX_DESCRIPTION_SIZE);
    cout << "Enter the date you'd like to accomplish this item (xx/xx/xxxx): ";
    // obtain the date from the user     
    getDate(date, MAX_DATE_SIZE);
    cout << "Enter a priority between 0 and 10 for this item (10 is top): ";
    priority = getIntegerRangeResponse(10, 0);
    cout << endl;
    return;
}



// constructor that sets initial values
list::list(void)
{
    head = NULL;
    count = 0;
}



// destructor for dynamically allocated pointers
list::~list(void)
{
    // can delete NULL
    delete head;
}



// display all items in the list
void list::displayAll(void)
{
    node *curr = head;
    if(head) {
        cout << "~~~~ Displaying all items in list ~~~~" << endl;
        while(curr) {
            curr->item.display();
            curr = curr->next;
        }
    }
    else cout << "There is no list to display. Add items to the list first." << endl;
    return;
}



// display by priority
void list::displayByPriority(void)
{
    int priority = 0;
    bool displayedItem = false;
    node *curr = head;
    if (head)
    {
        cout << "Enter a priority you would like to display (0-10): ";
        priority = getIntegerRangeResponse(10, 0);
        cout << "~~~~ Displaying items in list with " << priority << " priority ~~~~" << endl << endl;
        while(curr)
        {
            // if the item priority matches the desired
            // display it
            if(curr->item.comparePriority(priority)) 
            {
                curr->item.display();
                displayedItem = true; 
            } 
            // move to next item
            curr = curr->next;
        }
        if (!displayedItem) cout << "We didn't find anything in the list with that priority!" << endl;
    }
    else cout << "There is no list to display. Add items to the list first." << endl;
  return; 
}



// display number in list
int list::getCount(void)
{
    return count;
}



// add a list item in name alphabetical order
void list::add(void)
{
    // create a new node
    node *newNode = new node;
    // keep track of previous value in case we need to change its next
    node *prev = head;
    // keep track of current for looping
    node *curr = head;
    // additional early exit condition
    bool found = false;
    // variable for easier reading within code
    int comparison = 0;

    // get the contents of the item in the node
    newNode->item.getListItem();
    // if we have a head to our list
    if (head)
    {
        // find the location of where the node should be placed alphabetically
        while(curr && !found) 
        {
            // compare the name of the newNode to the current node in the list
            comparison = curr->item.compareName(newNode->item.getName());
            // if they are the same or 
           // if the new node has a less character value than the current node
           // place the new node prior to the current
           if (comparison == 0 || comparison < 0) 
           {
               // if we are at the very first position
               if (curr == head) 
               {
                   newNode->next = head;
                   // overwrite head
                   head = newNode;
               }
               else 
               {
                   // cut in front of current
                   prev->next = newNode;
                   newNode->next = curr;
               }
               found = true;
           }
           // update prev
           prev = curr;
           // move to the next node
           curr = curr->next;
        }
        // if we didn't locate a place in the list
        if(!found) 
        {
           // we are at the very end
           // and curr == null
           // but we have the last node via prev
            prev->next = newNode;
            newNode->next = NULL;
        }
    }
    // if there is no head yet, create the list
    else 
    {
        // create head
        head = newNode;
        head->next = NULL;
    }
    // increase the count of the list
    count++;
    return;
}



// remove an item by name
void list::remove(void)
{
    // create a place to hold the name
    char *name = NULL;
    // keep track if we found something to delete
    bool deleted = false;
    // for looping through the list
    node *curr = head;
    // for re-linking the list after removal
    node *prev = head;
    int comparison = 0;

    if (head)
    {
        // obtain the name from user
        cout << "Enter the name you would like to remove: ";
        getString(name, MAX_NAME_SIZE);
        // while there are nodes in our list and we have not found the item to delete
        while(curr && !deleted)
        {
            // compare the given name with the item name
            comparison = curr->item.compareName(name);
            // if we found the name
            if (comparison == 0)
            {
                // if we found it at position head
                // move head to the next node
                if (curr == head) head = head->next;
                // link up the previous with the next
                else prev->next = curr->next;
                // so we do not trigger deallocation with destructor
                // recursively when we delete curr
                curr->next = NULL;
                deleted = true;
                // deallocate the current
                delete curr;
                // decrease the count
                count--;
            }
            // move forward
            else
            {
                // bring prev up
                prev = curr;
                // move forward with curr
                curr = curr->next;
            }
        }
        // if we did not find anything to delete
        if(!deleted) cout << "We did not find a list item with that name. Please try again." << endl;
        // if we did
        else cout << "Deletion successful!" << endl;
    }
    else cout << "There is no list to delete from! You must add items to your list first." << endl;
    return;
}

// clears out the list. This happens recursively since
// once head is deleted, then the node destructor deletes the next
// and so on
void list::clearList() {
    if(head) {
        delete head;
        // so we don't access it again
        head = NULL;
        count = 0;
        cout << "Your to-do list was cleared!" << endl;
    }
    else cout << "There is no list to delete!" << endl;
    return;
}
