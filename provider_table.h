#ifndef PROVIDER_TABLE_H
#define PROVIDER_TABLE_H
#include "member.h"

//#include "services.h"

//This purpose is to manage the providers information
struct node
{
  provider pvd;
  node * next; //Next pointer
  member_list list;
  
};

class provider_table //Hash table of providers
{
  public:
    provider_table (int size = 15); //Constructor
    ~provider_table(void); //Destructor
    int insert (int key_value, const provider & to_add); //Inserting a song
    int hash_function (int key_value); //Hash Function
    int display_all (void); //Displaying all the information

    //Wrapper Functions
    int retrieve (int key_value); //Wrapper
    int add_member (int key_value, const member & to_add); //Adding member through the provider table 
    int retrieve_member (int key, int number); //See if member is in the whole system
    int add_service(int key, int number,char name[], char date[], char time[],char comments[],int code, int fee); //Adding the service information
    int display_all_services(int key,int number); //Displaying all the services
    int display_each_fee(int key,int number); //Display the fees
    int display_email (int key); //Displaying the email attachment
    int display_report (int key); //Display weekly report (wrapper)
    
  private:
    node ** provider_hash_table; //A dynamically allocated array of head pointers
    int provider_hash_size; //Size of the provider hash table

    //Functions that will be doing recursion (doing the work)
    int retrieve (int key_value, node * head); //Retrieve Function
    int add_member (int key, const member & to_add, node * head); //Function to add a member into the provider's linear linked list of members
    int retrieve_member (int key, int number, node * head); //Function to retrieve the member in the linked list
    int add_service (int key, int number, node * head,char name[], char date[], char time[],char comments[],int code, int fee); //Adding service in LLL of services
    int display_all_services(int key,int number, node * head); //Display all function
    int display_each_fee(int key, int number, node * head); //Display the fees function
    int display_email (int key, node * head); //Displaying the email attachement function
    int display_report (int key,node * head, int & cost);
};

#endif