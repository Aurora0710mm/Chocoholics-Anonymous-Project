#ifndef PROVIDER_H
#define PROVIDER_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
//New Add
#include <stdio.h>
#include <termios.h>
#include <time.h>
#include <curses.h>

using namespace std;

//temp add
static struct termios old, current;

class provider
{
  public:
    provider (void); //Constructor
    ~provider (void); //Destructor
    //Add provider
    int add_provider (char name[], int number, char address[], char city[], char state[], int zip); //Adding provider
    int copy_provider (const provider & copy); //Copying song
    int search_provider (int number); //Search through provider number
    int display_provider (); //Display the provider
    char * get_name(); //Getting the provider's name
    

  private:
    char * provider_name; //Dynamically allocated array for provider name
    int provider_number; //Provider Number 
    char * provider_address; //Dynamically allocated array for provider's address
    char * provider_city; //Dynamically allocated array for provider's city
    char * provider_state; //Dynamically allocated array for provider's state
    int provider_zipcode; //Provider's zipcode
};

#endif