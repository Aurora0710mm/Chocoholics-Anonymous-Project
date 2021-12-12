#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include "provider_table.h"

int display_services(char services[][30],int codes[11],int services_fee[11]);
int enter_number (int check); //Checking the provider/member number are valid
bool is_digit(string input); //Checking if the input is all numbers
int check_services (int code); //Check which service they requested

int LoginAdmin(); // admin login 

bool is_digit(string s) // Checking number is all digits
{
	for (int i = 0; i < s.length(); ++i) {
		if (isdigit(s[i]) == false) {
			return false;
		}
	}
	return true;
}

int enter_number (int check) //Checking number is valid
{
  int flag = 0; //Flag Variable
  int result; //Result
  string input; //where the user will enter in the input
  if (check == 0) //Check the provider/member number
  {
    do
    {
      cin >> input; //Read in
		  cin.ignore(100, '\n');
		  cout << "Input: " << input << endl;
		  if (!is_digit(input) || input.length() != 9) // If the number is invalid (not 9 digits or it has)
		  {
			  cerr << "Error: The number is invalid (ex. not entering 9 " 
             << "digits or it contained letters/symbols" 
             <<endl << "Please enter in the number again" <<endl;
		  } 
      else 
      {
			  flag = 1;
		  }
	  } while (flag != 1);
  }
  else if (check == 1) //Check zipcode
  {
    do 
    {
		  cin >> input;
		  cin.ignore(100, '\n');
		  if (!is_digit(input) || input.length() != 5) 
      {
			  cerr << "Error: Zipcode is invalid\n Please enter it again" << endl;
		  } 
      else 
      {
			  flag = 1;
		  }
	  } while (flag != 1);
  }
  else //Check service code (int check = 2)
  {
    do
    {
      cin >> input; //Read in the input
      cin.ignore (100, '\n');
      if (!is_digit(input) || input.length() != 6) //Check the conditions
      {
        cerr << "Error: Service Code is invalid\n Please enter it again" <<endl;
      }
      else
      {
        flag = 1;
      }
    }while (flag != 1); //Keep going until the user enters valid input
  }
  result = stoi (input); //Turn string to int
  return result; 
}

int check_services (int code) //Check if the service code is valid
{
  if (code == 598470)
  {
    return 0;
  }
  else if (code == 883948)
  {
    return 1;
  }
  
  else if (code == 634298)
  {
    return 2;
  }
  
  else if (code == 444187)
  {
    return 3;
  }

  else if (code == 397464)
  {
    return 4;
  }

  else if (code == 548512)
  {
    return 5;
  }
  
  else if (code == 812349)
  {
    return 6;
  }

  else if (code == 178634)
  {
    return 7;
  }

  else if (code == 649778)
  {
    return 8;
  }

  else if (code == 357745)
  {
    return 9;
  }


  else
  {
    return 99;
  }
}

//Displaying the service
int display_services(char services[][30],int codes[11], int services_fee[11])
{
 
   for(int i=0;i<10;++i)
   {
      cout << "\n Service: " << services[i] << " / " << "Code: " << codes[i]<<" / "<<" Fee: $"<< services_fee[i];
   }

   cout << endl << endl;

   if(services == NULL)
     return 0;

   return 1;

}

int LoginAdmin()
{
  char adminid[16];
  char adminpw[16];
  cout<<"Admin_Login:";
  cin.get(adminid, 17);
  cin.ignore (100, '\n');
  cout<<"Admin_Password:";
  cin.get(adminpw, 17); 
  cin.ignore (100, '\n');
  if(!(strcmp("admin", adminid) == 0 && strcmp("1234",adminpw) == 0))
    return 0;
  return 1;
}

#endif