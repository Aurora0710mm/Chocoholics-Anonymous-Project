#ifndef MEMBER_H
#define MEMBER_H
#include "services.h"

//Managing the member's information
class member
{
  public: 
    member(); //Constructor
    ~member(); //Destructor
    int add_member (char name[], int number, char address[], char city[], char state[], int zip); //Adding provider
    int copy_member (const member & copy); //Copying song
    bool search_member (int number); //Search through provider number
    int display_member(); //Display the provides
    void insert_service(int number,char name[], char date[], char time[],char comments[],int code, int fee);

    int display_member_services(); 
    char * get_name(); //Getting the member's name
    int get_number(); //Getting the member's number
    
  private:
    //Dyanmically allocated arrays
    char * member_name; //Member's name
    int member_number; //Member's number
    //Member's address information
    char * member_address; 
    char * member_city; 
    char * member_state;
    int member_zipcode; //Member's zipcode
    
};

struct member_node //Our member node
{
  member mem; //Object call
  member_node * next; //Next pointer
  service_LLL serv_list;
};

class member_list  //Linked list of members
{
  public:
    member_list();  //Constructor
    ~member_list(); //Destructor
    //Wrappers
    int insert(const member &); //Insert
    int display_all(); //Display
    int search(int number); //Search
    //int remove_all(); //Removing the whole list
    int add_service_wrapper(int number,char name[], char date[], char time[],char comments[],int code, int fee);

    int add_service(int number,char name[], char date[], char time[],char comments[],int code, int fee, member_node *&head);
    
    int display_all_services (int number);

    int display_each_fee (int number); //Wrapper

    int display_email (char * name); //Wrapper

    int display_report (int & cost); //Wrapper

  protected:
    member_node * head; //Head pointer
    //Implementation
    int insert (member_node *& head, const member &); //Insert member function with head
    int display_all (member_node * head); //Display all with head pointer 
    int search (int number, member_node * head); //Search member with head 
    int display_all_services(int number, member_node * head); //Display all the services from a member
    int display_each_fee(int number, member_node * head); //Display the fees
    int display_email (char * name, member_node * head); //Display email function
    int display_report(member_node * head, int & cost); //Display report function
};




#endif