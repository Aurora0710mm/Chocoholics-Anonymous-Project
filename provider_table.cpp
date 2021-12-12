#include "provider_table.h"

//The purpose of this file is to create and manage the provider's information for certain indexes

provider_table::provider_table(int size) //Constructor
{
  provider_hash_table = new node * [size]; //New node
  provider_hash_size = size; //Establish the size of the hash table
  for (int i = 0; i < size; i++) 
  {
    provider_hash_table [i] = NULL;
  }
}

provider_table::~provider_table(void) //Destructor
{
  node * current;
  node * temp;
  for (int i = 0; i < provider_hash_size; ++i)
  {
    if (provider_hash_table [i] != NULL) //If the hash table is not NULL
    {
      current = provider_hash_table [i]; //Set current
      while (current) //While current is not NULL
      {
        temp = current; //Set temp
        current = temp  -> next; //Set current to the next one
        delete temp; //Delete
      }
    }
  }
  delete [] provider_hash_table;
}

int provider_table::hash_function (int key) //This will help us determine the index
{
  return key % provider_hash_size;
}

//Insert the information into a node
int provider_table::insert (int key, const provider & to_add)
{
  int i = hash_function (key); //Will be our index
  node * temp = new node;
  if (!temp -> pvd.copy_provider(to_add)) //If we can't copy the information
  {
    delete temp; //Delete
    return 0;
  }
  temp -> next = provider_hash_table[i]; //Set temp -> next
  provider_hash_table[i] = temp; //Set hash_table[i] to temp
  return 1;
}

int provider_table::retrieve (int key) //Wrapper
{
  int index = hash_function (key); //Getting the index
  return retrieve (key, provider_hash_table[index]); //Call in the function
}

//Retrieve the provider's information based on user's request (provider number)
int provider_table::retrieve (int key, node * head)
{
  if (!head) //If the list is empty
    return 0;
  int counter = retrieve (key, head -> next); //Recursive Call
  if (head -> pvd.search_provider(key) == 1) //If we found it
  { 
    head -> pvd.display_provider(); //Display
    ++counter; //Update counter
  }
  return counter; //Return counter
}

//Display all the information
int provider_table::display_all()
{
  node * temp; //Temp pointer
  int count = 0; //Count Variable
  for (int i = 0; i < provider_hash_size; i++)
  {
    temp = provider_hash_table [i]; //Set temp
    cout << "\nIndex: " << i <<endl;
    if (temp != NULL)
    {
      while (temp) //Repeat until temp is NULL
      {
        if (temp -> pvd.display_provider()) //Display the informatio
        {
          temp -> list.display_all();
          count += 1; //Update count
        }
        temp = temp -> next; //Set to next
      }
    }
  }
  return count; //Return the count
}

//Working with member features
int provider_table::add_member (int key, const member & to_add) //Wrapper
{
  int index = hash_function (key); //Getting the index
  return add_member (key, to_add, provider_hash_table[index]); //Call in the function
}

int provider_table::add_member (int key, const member & to_add, node * head) //Adding
{
  if (!head)
  {
    return 0;
  }
  if (head -> pvd.search_provider(key)) //Once we found the provider
  {
    head -> list.insert(to_add); //Adding the member to a linked list
    return 1;
  }
  return retrieve (key, head -> next); //Recursive Call
}

int provider_table::retrieve_member (int key, int number) //Wrapper
{
  int index = hash_function (key); //Getting the index
  return retrieve_member (key, number, provider_hash_table[index]); //Call in the function
}

//Retrieving the member
int provider_table::retrieve_member (int key, int number, node * head)
{
  if (!head) //If the list is empty
    return 0;
  int counter = retrieve (key, head -> next); //Recursive Call
  if (head -> pvd.search_provider(key)) //If we found it
  { 
    if (head -> list.search(number))
    {
      ++counter; //Update Counter
    }
  }
  return counter; //Return counter
}


//Retrieving the member to insert service.
int provider_table::add_service (int key, int number,char name[], char date[], char time[],char comments[],int code, int fee) //Wrapper
{
  int index = hash_function (key); //Getting the index
  return add_service (key, number, provider_hash_table[index], name,date,time,comments,code,fee); //Call in the function
}

//Retrieving the member to insert service.
int provider_table::add_service (int key, int number, node * head,char name[], char date[], char time[],char comments[],int code, int fee)
{
  if (!head) //If the list is empty
    return 0;
  int counter = retrieve (key, head -> next); //Recursive Call
  if (head -> pvd.search_provider(key)) //If we found it
  { 
    head -> list.add_service_wrapper(number,name, date, time, comments, code, fee);
    return ++counter;
  }
  return counter; //Return counter
}

int provider_table::display_all_services(int key,int number)
{
  int index = hash_function (key); //Getting the index
  return display_all_services(key, number, provider_hash_table[index]); //Call in the function
}

int provider_table::display_all_services(int key,int number, node * head)
{
  if (!head) //If the list is empty
    return 0;
  int counter = retrieve (key, head -> next); //Recursive Call
  if (head -> pvd.search_provider(key)) //If we found it
  { 
    if (head -> list.search(number) == 1) //Once we find the member number
    {
      head -> list.display_all_services(number); //Display the services
    }  
  }
  return counter; //Return counter
}

 //Display each fees (Wrapper)
int provider_table::display_each_fee(int key, int number)
{
  int index = hash_function(key); //Getting the index
  return display_each_fee(key,number,provider_hash_table[index]);
}

//Display each fee function
int provider_table::display_each_fee(int key, int number, node * head)
{
  if(!head)
    return 0;
  //int counter = retrieve(key, head->next);
  if (head -> pvd.search_provider(key)) //If we foudn it
  { 
    if (head -> list.search(number)) //Once we reach the member
    {
      head -> list.display_each_fee(number); //Display the fees
    }  
  }
  return 0;
}

int provider_table::display_email (int key) //Display Email (Wrapper)
{
  int index = hash_function (key); //Get the index
  return display_email (key, provider_hash_table[index]);
}

int provider_table::display_email (int key, node * head) //Display Email (recursion)
{
  if (!head) //If the list is empty
    return 0;
  int counter = display_email (key, head -> next); //Recursive Call
  if (head -> pvd.search_provider(key)) //Once we get to the provider
  {
    char * name = head -> pvd.get_name(); //Setting name
    counter = head -> list.display_email (name); //Set counter
  }
  return counter;
}

int provider_table::display_report (int key) //Wrapper
{
  int index = hash_function (key); //Getting the index
  int cost = 0; //Total cost of fees
  return display_report (key, provider_hash_table[index], cost);
}

//Displaying our weekly report
int provider_table::display_report (int key, node * head, int &cost)
{
  if (!head) //If the list is empty
    return 0;
  int counter = display_report (key, head -> next, cost); //Recursive Call
  if (head -> pvd.search_provider (key)) //Once we find the provider
  {
    head -> pvd.display_provider(); //Display the provider's info
    cout << "For each services provided:" <<endl;
    counter = head -> list.display_report (cost); //Display the rest of the info
    cout << "Total number of consultations with members: " << counter <<endl;
    cout << "Total Fees for the week: $" <<cost <<endl; 
  }
  return counter;
}
