#ifndef SERVICES_H
#define SERVICES_H
#include "provider.h"

//Managing the services's information
class service
{
  public:
    service (void); //Constructor
    ~service (void); //Destructor
    int add_service (char new_name[],char new_date[], char new_time[], char new_comments[], int new_code,int new_fee); //Adding service
    bool search_service(int number); //Search through servicenumber
    int display_service (); //Display the services
    int copy(int number,char name[], char date[], char time[],char comments[],int code, int fee); //Copy the service information 
    
    int display_fee();  //Getting the service fee
    //int display_all();

    int display_email (char * name); //Display the email information
    int display_report (char * name, int number); //Display the report (service)
    int total_cost (int & cost); //Updating the total cost

  private:
    //Dynamically allocated arrays
    char * service_name; //Service Name
    char * service_date;  //Service Date (MM:DD:YYYY)
    char * current_date_time; //Current date and time (MM:DD:YYYY HH:MM:SS)
    char * comments; //Comments about the service
    int service_code; //Service code
    float service_fee; //Fees for the service
};

struct service_node //Our member node
{
  service serv; //Object call
  service_node * next; //Next pointer
};

class service_LLL //Linear Linked List of services
{
  public:
    service_LLL (); //Constructor
    ~service_LLL(void); //Destructor
    int display_all (void); //Displaying all the services

    //Adding member through the service table (Wrapper)
    int insert_service (int number,char name[], char date[], char time[],char comments[],int code, int fee); 
    int display_fee(void); //Displaying all the fees
    //
    int display_email (char * name); //Wrapper
    int display_report (char * name, int number, int & cost); //Wrapper
    
  protected:
    service_node * head; //Head pointer
    //Insert service doing the work through head pointer
    int insert_service(service_node *& head, int number,char name[], char date[], char time[],char comments[],int code, int fee);
    //Displaying the service info for email
    int display_email (char * name, service_node * head); //Display email 
    int display_report (char * name, int number, service_node * head, int & cost); //Display weekly report (service)
    
};

#endif