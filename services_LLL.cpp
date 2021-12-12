#include "member.h" 
 
//Constructor
service_LLL::service_LLL () //Constructor
{
  head = NULL; //Set to NULL
}
 
service_LLL::~service_LLL () //Destructor
{
  service_node * temp = NULL;
  while (head)
  {
    temp = head -> next; //Set temp
    delete head; //Delete
    head = temp; //Set head
  }
}


// Insert service node
int service_LLL::insert_service(int number,char name[], char date[], char time[],char comments[],int code, int fee) //Wrapper
{
  if (!head) //If there is no list
  {
    head = new service_node; //New node
    //head -> serv.copy(number,name,date,time,comments,code,fee); //Add the information
    head -> serv.add_service (name, date, time, comments, code, fee); //Adding the service information
    head -> serv.display_service(); //Display the information
    head -> next = NULL; //Next is NULL
    return 1;
  }
  return insert_service (head -> next, number,name,date,time,comments,code,fee); //Call in function
}

// Insert service node
int service_LLL::insert_service(service_node *& head, int number,char name[], char date[], char time[],char comments[],int code, int fee)
{
  if (!head) //Once head is NULL
  {
    head = new service_node; //New node
    head -> serv.add_service (name, date, time, comments, code, fee); //Add the service information
    head -> serv.display_service(); //Display the information
    head -> next = NULL; //Next is NULL
    return 1;
  }
  return insert_service (head -> next, number,name,date,time,comments,code,fee); //Recursive call
}

//Displaying all the services
int service_LLL::display_all (void)
{
  service_node * current = head; //Set current
  while(current != NULL)
  {
    current -> serv.display_service(); //Display
    current = current -> next; //Set current to next
  }
  return 0;
}

//This function is to get the total fee
int service_LLL::display_fee(void) 
{
  service_node * current = head; //Set current
  int total_fee = 0;
  while(current != NULL) //Keep going until current is NULL
  {
    total_fee += current-> serv.display_fee(); //Update total_fee
    current = current->next; //Update current
  }
  cout<<total_fee; 
  return total_fee;
}

int service_LLL::display_email (char * name) //Display email (Wrapper)
{
  if (!head) //If the list is empty
  {
    return 0;
  }
  return display_email (name, head);
}

//Display Email (Recursive)
int service_LLL::display_email (char * name, service_node * head)
{
  if (!head)
  {
    return 0;
  }  
  head -> serv.display_email (name); //Display the service info 
  return display_email (name, head -> next); //Recursvie Call
}

int service_LLL::display_report (char * name, int number, int & cost)
{
  if (!head) return 0; //If there's no list
  return display_report (name, number, head, cost);
}

int service_LLL::display_report (char * name, int number, service_node * head, int & cost)
{
  if (!head)
  {
    return 0;
  }
  head -> serv.display_report(name, number); //Display the service info
  cost = head -> serv.total_cost (cost);
  return display_report (name, number, head -> next, cost) + 1; //Recursive Call
}
    