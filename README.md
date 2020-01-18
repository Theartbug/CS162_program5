# CS162_program5

gprovost@pdx.edu
Program 5
11/29/19
CS 162

  PURPOSE: main file which contains the main function and other helper functions that do not belong to classes. These include mostly helpers for getting things from the user and validation.

  ALGORITHM:
  1. create two classes, listItem and list, and a struct, node. Node will contain the listItem class and a self-refering node pointer called next, and list will contain a linked list of nodes.
  2. listItem will have private fields date, name, description, and priority.
  3. listItem will have public functions for displaying the item, creating the item, comparing the priority, retreiving the name,
constructor, and destructor.
  4. list will hvae private fields head and count.
  5. list will have public functions for displaying the whole list, displaying by subject, adding items, removing items, clearing the list, constructor, an destructor.
  6. steps 6 onward are within a do-while loop which exits once the user selects 0
  7. The user is greeted and given a menu with getMainMenu() to pick from with integer input. The input is stored within menuChoice and then fed through menuSwitch().
  8. If the user selects 1, addItems() is called and list.add() will continuously be called until they no longer wish to add items. list.add() creates a new node and listItem within that node, taking in user input.
  9. If the user selects 2, removeItems() is called and list.remove() will continuously be called until the user no longer wishes to remove items. list.remove() takes in a name from the user and searches the list for that name. Will remove if found, will say no if unsuccessful. Will not attempt if there is no list.
  10. If the user selects 3, all items in the list are displayed. list.displayAll() is called, and each individual listItem.display() is called. If there is no list will say so.
  11. If user selects 4, items by priority are displayed. list.displayByPriority() is called, and user input is accepted for the priority. Then only items with that priority are shown. If there is no list will say so.
  12. If user selects 5, the total list count is shown. It is retreived with list.getCount();
  13. If user selects 6, the linked list is cleared with list.clearList(). list.clearList() will delete head, which will trigger the destructor on the node struct, which will trigger the destructor on the listItem, recursively. Will say if there is no list to delete
