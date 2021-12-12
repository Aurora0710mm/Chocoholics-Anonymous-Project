#include "member.h"


service::service() // Constructor
{
  //Initialize data types
  service_name = NULL;
  service_date = NULL;
  current_date_time = NULL;
  comments = NULL;
  service_code = 0;
  service_fee = 0; 
}

service::~service() //Destructor
{
  //Deallocate the dynamic arrays
  if (service_name) 
    delete [] service_name;
  if (service_date)
    delete [] service_date;
  if(current_date_time)
    delete [] current_date_time;
  if(comments)
    delete [] comments;
 
  //Set to NULL
  service_name = NULL;
  service_date = NULL;
  current_date_time = NULL;
  comments = NULL;
 
}

//Adding the service
int service::add_service (char new_name[],char new_date[], char new_time[], char new_comments[], int new_code,int new_fee)
{
    //cout << "\t\tService name: " << new_name  <<endl;
  this -> service_name = new char [strlen (new_name) + 1];
  strcpy (this -> service_name, new_name);
  this -> service_date = new char [strlen (new_date) + 1];
  strcpy (this -> service_date, new_date);
  this -> current_date_time = new char [strlen (new_time) + 1];
  strcpy (this -> current_date_time, new_time);

  this -> comments = new char [strlen (new_comments) + 1];
  strcpy (this -> comments, new_comments);

  this -> service_code = new_code;
  this -> service_fee = new_fee; 
  return 1;
}


int service::copy (int number,char name[], char date[], char time[],char new_comments[],int code, int fee)
{
  
  //If the inputs are NULL
  if (!name || !date || !time ||!new_comments)
  {
    return 0;
  }
  else
  {
    //Copy
    service_name = new char [strlen (name) + 1];
    strcpy (service_name, name);
    service_date = new char [strlen(date) + 1];
    strcpy (service_date, date);
    current_date_time = new char [strlen (time) + 1];
    strcpy (current_date_time, time);
    comments = new char [strlen (new_comments) + 1];
    strcpy (comments, new_comments);
    service_code = code;
    service_fee = fee; 
    return 1; 
  }
}
//

int service::display_service()
{
  //If any the service info is NULL
  if (!service_name || !service_date)
  {
    return 0;
  }
  //Display the service's information
  cout << "\t\t\tService name: " << service_name << "\n\t\t\tService date: " 
       <<service_date  << "\n\t\t\tCurrent Time and Date: " 
       << current_date_time << "\n\t\t\tService code:"  << service_code 
       << "\n\t\t\tFees: $" << service_fee << "\n\t\t\tAdditional Comments: " 
       << comments << endl << endl; 
    return 1;
}

int service::display_fee() //Getting the service fee
{
  if (!service_name || !service_date)
  {
    return 0;
  }
  return service_fee;
}

int service::display_email(char * name) //Displaying the service info (email)
{
  cout << "\t\t\t Date of Service: " <<service_date <<endl
       << "\t\t\t Provider Name: " <<name <<endl
       << "\t\t\t Service Name: " <<service_name <<endl <<endl;
  return 1;
}

//Displaying the report of service provided
int service::display_report (char * name, int number) 
{
  cout << "\n\t\tDate of Service: " <<service_date <<endl
       << "\t\tDate and time data were received by the computer: "
       <<current_date_time <<"\n\t\tMember Name: " <<name
       <<"\n\t\tMember Number: " <<number << "\n\t\tService Code: "
       << service_code << "\n\t\tFee to be paid: " <<service_fee <<endl;
  return 1;
}

//Updating the total cost
int service::total_cost (int & cost)
{
  return cost += service_fee;
}