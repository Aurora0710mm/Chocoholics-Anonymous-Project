#include "provider.h"

// The purpose is to manage the provider's infromation
// Functions like adding, copying, search, display

provider::provider() // Constructor
{
  //Initialize data types
  provider_name = NULL;
  provider_number = 0;
  provider_address = NULL;
  provider_city = NULL;
  provider_state = NULL;
  provider_zipcode = 0;
}

provider::~provider() //Destructor
{
  //Deallocate the dynamic arrays
  if (provider_name) 
    delete [] provider_name;
  if (provider_address)
    delete [] provider_address;
  if (provider_city)
    delete [] provider_city;
  if (provider_state)
    delete [] provider_state;
  //Set to NULL
  provider_name = NULL;
  provider_address = NULL;
  provider_city = NULL;
  provider_state = NULL;
  provider_number = 0;
  provider_zipcode = 0;
}

//Adding the provider
int provider::add_provider (char name[], int number, char address[], char city[], char state[], int zip)
{
  this -> provider_name = new char [strlen (name) + 1];
  strcpy (this -> provider_name, name);
  this -> provider_address = new char [strlen (address) + 1];
  strcpy (this -> provider_address, address);
  this -> provider_city = new char [strlen (city) + 1];
  strcpy (this -> provider_city, city);
  this -> provider_state = new char [strlen (state) + 1];
  strcpy (this -> provider_state, state);
  this -> provider_number = number;
  this -> provider_zipcode = zip;
  return 1;
}

//Copy the provider's information
int provider::copy_provider (const provider & copy)
{
  //If the inputs are NULL
  if (!copy.provider_name || !copy.provider_address || !copy.provider_city ||!copy.provider_state)
  {
    return 0;
  }
  else
  {
    //Copy
    provider_name = new char [strlen (copy.provider_name) + 1];
    strcpy (provider_name, copy.provider_name);
    provider_address = new char [strlen (copy.provider_name) + 1];
    strcpy (provider_address, copy.provider_address);
    provider_city = new char [strlen (copy.provider_city) + 1];
    strcpy (provider_city, copy.provider_city);
    provider_state = new char [strlen (copy.provider_state) + 1];
    strcpy (provider_state, copy.provider_state);
    provider_number = copy.provider_number;
    provider_zipcode = copy.provider_zipcode;
    return 1;
  }
}

//Search Provider
int provider::search_provider (int request)
{
  if (!request || !provider_number) //If request or provider number is NULL
  {
    return -1;
  }
  if (request == provider_number) //If we find match
  {
    return 1;
  }
  else //No match
  {
    return 0;
  } 
}

int provider::display_provider()
{
  //If any the provider info is NULL
  if (!provider_name || !provider_address || !provider_city || !provider_state)
  {
    return 0;
  }
  else
  {
    //Display the provider's information
    cout << "\tProvider Name: " << provider_name << "\n\tProvider Number: " <<provider_number
         << "\n\tProvider Address: " <<provider_address << " " << provider_city << ", "
         << provider_state << " " << provider_zipcode <<endl <<endl;
    return 1;
  }
}

char * provider:: get_name () //Getting the provider's name
{
  return provider_name;
}

