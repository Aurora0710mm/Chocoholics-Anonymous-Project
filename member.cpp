#include "member.h"

//The purpose of this file is to manage the member's information
//and manage the linked of list of members

member::member() //Constructor
{
  //Initialize the data types
  member_name = NULL; 
  member_number = 0;
  member_address = NULL;
  member_city = NULL;
  member_state = NULL;
  member_zipcode = 0;
}

member::~member()
{
 //Deallocate the dynamic arrays
  if (member_name) 
    delete [] member_name;
  if (member_address)
    delete [] member_address;
  if (member_city)
    delete [] member_city;
  if (member_state)
    delete [] member_state;
  //Set to NULL
  member_name = NULL;
  member_address = NULL;
  member_city = NULL;
  member_state = NULL;
  member_number = 0;
  member_zipcode = 0; 
}

//This is where we add the member information through this pointer
int member::add_member (char name[], int number, char address[], char city[], char state[], int zip)
{
  this -> member_name = new char [strlen (name) + 1];
  strcpy (this -> member_name, name);
  this -> member_address = new char [strlen (address) + 1];
  strcpy (this -> member_address, address);
  this -> member_city = new char [strlen (city) + 1];
  strcpy (this -> member_city, city);
  this -> member_state = new char [strlen (state) + 1];
  strcpy (this -> member_state, state);
  this -> member_number = number;
  this -> member_zipcode = zip;
  return 1;
}

//Copy the member's information
int member::copy_member (const member & copy)
{
  //If the inputs are NULL
  if (!copy.member_name || !copy.member_address || !copy.member_city ||!copy.member_state)
  {
    return 0;
  }
  else
  {
    //Copy
    member_name = new char [strlen (copy.member_name) + 1];
    strcpy (member_name, copy.member_name);
    member_address = new char [strlen (copy.member_address) + 1];
    strcpy (member_address, copy.member_address);
    member_city = new char [strlen (copy.member_city) + 1];
    strcpy (member_city, copy.member_city);
    member_state = new char [strlen (copy.member_state) + 1];
    strcpy (member_state, copy.member_state);
    member_number = copy.member_number;
    member_zipcode = copy.member_zipcode;
    return 1;
  }
}

//Search member
bool member::search_member (int request)
{
  if (!request || !member_number) //If request or member number is NULL
  {
    return false;
  }
  if (request == member_number) //If we find match
  {
    return true;
  }
  else //No match
  {
    return false;
  } 
}

int member::display_member()
{
  //If any the member info is NULL
  if (!member_name || !member_address || !member_city || !member_state)
  {
    return 0;
  }
  else
  {
    //Display the member's information
    cout << "\t\tMember Name: " << member_name << "\n\t\tMember Number: " <<member_number
         << "\n\t\tMember Address: " <<member_address << " " << member_city << ", "
         << member_state << " " << member_zipcode <<endl <<endl;
    return 1;
  }
}

char * member:: get_name () //Getting the member's name
{
  return member_name;
}

int member::get_number () //Getting the member's number
{
  return member_number;
}

//Managing the linear linked list of members 
member_list::member_list () //Constructor
{
  head = NULL;
}

member_list::~member_list() //Destructor (prototype)
{
  member_node * temp = NULL;
  while (head)
  {
    temp = head -> next;
    delete head;
    head = temp;
  }
}

int member_list::insert(const member & to_add) //Wrapper
{
  if (!head) //If there is no list
  {
    head = new member_node; //New node
    head -> mem.copy_member (to_add); //Add the information
    head -> mem.display_member();
    head -> next = NULL; //Next is NULL
    return 1;
  }
  return insert (head -> next, to_add); //Call in function
}

//Insert
int member_list::insert (member_node *& head, const member & to_add)
{
  if (!head) 
  {
    head = new member_node; //New node
    head -> mem.copy_member (to_add); //Add the information
    head -> mem.display_member(); //Display the information
    head -> next = NULL; //Set next to null
    return 1;
  }
  return insert (head -> next, to_add); //Recursive call
}

int member_list::display_all() //Display all wrapper
{
  if (!head) //If head is NULL
  {
    return 0;
  }
  return display_all (head);
}

int member_list::display_all (member_node * head) //Display all
{
  if (!head)
  {
    return 0;
  }
  head -> mem.display_member(); //Display member info
  head -> serv_list.display_all(); //Display all service for each member
  return display_all (head -> next) + 1; //Recursive Call
}

int member_list::search (int number) //Search Function Wrapper
{
  if (!head) //If head is NULL
  {
    return 0;
  }
  return search (number, head);
}

int member_list::search(int number, member_node * head) //Search Function
{
  if (!head) //If head is NULL
    return 0;
  if (head -> mem.search_member (number) == true) //If we find it
  {
    //head -> mem.display_member(); //Display the information
    return 1;
  }
  return search (number, head -> next); //Recursive Call
}


int member_list::add_service_wrapper(int number,char name[], char date[], char time[],char comments[],int code, int fee) //Search Function Wrapper
{
  if (!head) //If head is NULL
  {
    return 0;
  }
  return add_service (number,name,date,time,comments,code,fee,head);
}

int member_list::add_service(int number,char name[], char date[], char time[],char comments[],int code, int fee,member_node *& head)
{
  if (!head) //If head is NULL
    return 0;
  if (head -> mem.search_member (number) == true) //If we find it
  {
    head -> mem.display_member(); //Display the information
    head->serv_list.insert_service(number,name,date,time,comments,code,fee);
    return 1;
  }
  return add_service (number, name, date, time, comments, code, fee, head -> next); //Recursive Call   
}

//Wrapper (display all services)
int member_list::display_all_services (int number)
{
  if (!head) return 0;
  return display_all_services (number, head);
}

int member_list::display_all_services(int number, member_node * head)
{
  if (!head) //If head is NULL
    return 0;
  if (head -> mem.search_member (number) == true) //If we find it
  {
    head -> mem.display_member(); //Display the member's info
    head -> serv_list.display_all(); //Display all the services
    return 1;
  }
  return display_all_services(number, head -> next); //Recursive Call
}

int member_list::display_each_fee (int number)
{
  if (!head) return 0;
  return display_each_fee (number, head);
}

int member_list::display_each_fee(int number, member_node * head)
{
  if(!head)
    return 0;
  if(head -> mem.search_member(number) == true)
  {
    head->serv_list.display_fee();
    return 1;
  }
  return display_each_fee(number,head->next); //Recursive Call
}

int member_list::display_email (char * name) //Display email wrapper
{
  if (!head) //If the list is empty
    return 0;
  return display_email (name, head);
}

//Display Email (Recursive)
int member_list::display_email (char * name, member_node * head)
{
  if (!head)
    return 0;
  cout << "\nSending Email To: " <<endl;
  head -> mem.display_member(); //Display the member information
  cout << "Service Provided: " <<endl;
  head -> serv_list.display_email(name); //Display the service part
  return display_email (name, head -> next) + 1; //Recursive Call
}

int member_list::display_report (int & cost) //Displaying the weekly report
{
  if (!head) //If the LLL of members is empty
    return 0;
  return display_report (head, cost);
}

int member_list::display_report (member_node * head, int & cost) //Displaying the weekly report
{
  if (!head) 
    return 0;
  char * name = head -> mem.get_name(); //Get the member's name
  int number = head -> mem.get_number(); //Get the member's number
  if (head -> serv_list.display_report(name, number, cost)) //If there is a LLL of services
  {
    return display_report (head -> next, cost) + 1; //Recursive Call
  }
  return display_report (head -> next, cost); //Recursive Call
}