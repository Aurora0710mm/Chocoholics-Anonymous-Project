#include "provider_table.h"
#include "tests.h"
#include "mainfunctions.h"


int main() {
  //Unit tests
  //testExistingProviderFuncs();
  //testNonExistingProviderFuncs();
  //validServiceCodeTest();
  //invalidServiceCodeTest();
  //validInputCheckDigitsTest();
  //invalidInputCheckDigitsTest();
  //cout << endl << endl;
  
  //Object Calls
  provider prov; //Provider Class Object Call
  provider_table pt; //Provider Table Object Call
  member customer; //Member Class Object Call
  service server; //Service Class Object Call

	// Variables
	int prov_num; // Provider number
  int mem_num; //Member Number
	string input; // String input
	int flag = 0; // To determine if the user has to re-enter the info
  int temp = 0; // Manipulate the wait character

	char name[26]; //Name
	char address[26]; // Street Address
	char city[15]; //City
	char state[3]; //State
	int zip; //Zipcode
  char response; //The user's response
  int quit = 0;

  //Service Variables
  char service_date [11]; //Service Date
  char current_date_time [20]; //Time that we receive the data
  char service_name [21]; //Service Name
  int service_fee; //Service Fee

  char comments [101]; //Comments about the service
  int service_code = 0; //Service Code
  
  // List of services
  char services[10][30] = {"Dietician", "Aerobics Exercise", "Dermotologist","Neurologist", "ENT", "Pulmonologist", "Dentist", "Cardiologist", "Addiction Specialist", "Physical Therapist"};

  // List of services fee
  int service_charge[11]= {20,30,10,60,150,170,130,120,100,90};


  // list of service codes
  int service_codes[11]= {598470,883948, 634298,444187,397464,548512,812349,178634,649778,357745};

  do
  {
    cout << "**********";
	  cout << "  Welcome to the provider terminal!  ";
    cout << "**********"<<endl;

	  // Entering the provider number
	  cout << "\nPlease enter in your provider number (9 digits)" << endl;
    prov_num = enter_number (0);
	  cout << "Provider Number: " << prov_num << endl;

    if (!pt.retrieve (prov_num)) //If the provider is not in the system
    {
      //Prompt and read in user's input
      cout << "Your provider number is not in the system. Please enter in your information below" <<endl;

      cout << "Please press any key (except enter) to keep going! "<<endl;
      temp = getchar();
      system("clear");
      cin.ignore(100,'\n');

	    cout << "\nPlease enter in your name (25 characters)" << endl;
	    cin.get(name, 26);
	    cin.ignore(100, '\n');

	    cout << "\nPlease enter in street address (25 characters)" << endl;
	    cin.get(address, 26);
	    cin.ignore(100, '\n');

	    cout << "\nPlease Enter in the city (14 characters)" << endl;
	    cin.get(city, 15);
	    cin.ignore(100, '\n');

	    cout << "\nPlease enter in the state (2 letters) ex. OR, CA, WA" << endl;
	    cin.get(state, 3);
	    cin.ignore(100, '\n');

      cout << "\nPlease enter in the zipcode (5 digits)" <<endl;
	    zip = enter_number (1); // Turning string to int

      //Adding the information
      prov.add_provider (name, prov_num, address, city, state, zip);
      if (pt.insert (prov_num, prov))
      {
        cout << "Your information is in the system!" <<endl;
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');
      }
      else
      {
        cerr << "Sorry we could not save your information (most likely the inputs were blank" <<endl;
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');
      }
      prov.~provider();
    }
    else
    {
      cout << "You are in the system" <<endl;
    }
    do
    {
      time_t current_time; //Calling in object call
      tm * current; //Current pointer
      setenv("TZ", "PST8PDT", 1); //Set to Pacific Time
      tzset(); //Set
      current_time = time(NULL); 
      current = localtime (&current_time); //Local time
      //Set current_date_time to current time right now
      strftime (current_date_time, 20, "%D %T", current);

      cout << "\n>>>>>>>>>>>>>>>>>>>"
           << "  Content  "
           << "<<<<<<<<<<<<<<<<<<<\n";
      cout << "       ※       ";
      cout<< current_date_time; 
      cout << "       ※           ";
      cout << "\n\nHere's the menu:\nEnter P if you want to search the provider\n"
           << "Enter D if you want to display all the providers"
           << "\nEnter W to switch providers" 
           << "\nEnter M to add a member"
           << "\nEnter S to add service to a member"
           << "\nEnter C to display services and the service codes"
           << "\nEnter A to display all services that the member requested"
           << "\nEnter E if you want to end the week with emails and billing"
           << "\nClick Q to quit the program" <<endl;
           
      cin >> response; 
      cin.ignore (100, '\n');
      response = toupper (response);
      
      //If the user wants to see all the services requested by the member
      if(response == 'A') 
      {
        cout << "Please enter in the member's number" <<endl;
        mem_num = enter_number (0);
        if (pt.retrieve_member (prov_num, mem_num))
        {
          cout<<"display_all_services_show here \n";
          pt.display_all_services(prov_num, mem_num);
          //repeat the member_display_menu 
          cout<<"\n\t\tTotal Fees: $";
          pt.display_each_fee(prov_num,mem_num);
          cout << "\n";
          cout << "Please press any key (except enter) to keep going! "<<endl;
          temp = getchar();
          system("clear");
          cin.ignore(100,'\n');
        } 
        else
        {
          cerr << "Invalid Member Number" <<endl;
          cout << "Please press any key (except enter) to keep going! "<<endl;
          temp = getchar();
          system("clear");
          cin.ignore(100,'\n');
        }
      }
      
      if(response == 'C') //If the user wants to see the services provided and code
      {
        display_services(services,service_codes,service_charge); //Display
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');
      }
      
      
      if (response == 'P') //Searching Provider
      {
        cout << "Enter in the provider number to search" <<endl;
        int search = enter_number (0); //Entering valid search
        if (!pt.retrieve (search)) //If we can't find it
        {
          cerr << "The search result invalid" <<endl; //Error
        }
        else
        {
          cout << "Search Success!" <<endl; //Successful
        } 
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');
      }
      //Testing the display all
      if (response == 'D')
      {
        pt.display_all();  
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');
      }

      //Adding members
      if (response == 'M')
      {
        cout << "Did you request services from this provider this week? (Ans. Y or N)" <<endl;
        cin >> response;
        response = toupper (response);
        if (response == 'Y')
        {
          cout << "Please enter in the member's number" <<endl;
          mem_num = enter_number (0);
          if (pt.retrieve_member (prov_num, mem_num)) //Validated
          {
            cout << "VALIDATED" <<endl;
          }
          else //Invalid
          {
            cout << "INVALID NUMBER / MEMBER SUSPENDED" <<endl;
          }
          cout << "Please press any key (except enter) to keep going! "<<endl;
          temp = getchar();
          system("clear");
          cin.ignore(100,'\n');
          
        }
        else if (response == 'N') //If they answer N
        {
          //Enter in the member's information
          cout << "Please enter in the member's number" <<endl;
          mem_num = enter_number (0);
          if (!pt.retrieve_member (prov_num, mem_num)) //If the member is not in list
          {
            //Prompt and read in the user's input
            cout << "Please enter the information" <<endl;
            cout << "\nPlease enter in your name (25 characters)" << endl;
	          cin.get(name, 26);
	          cin.ignore(100, '\n');

	          cout << "\nPlease enter in street address (25 characters)" << endl;
	          cin.get(address, 26);
	          cin.ignore(100, '\n');

	          cout << "\nPlease Enter in the city (14 characters)" << endl;
	          cin.get(city, 15);
	          cin.ignore(100, '\n');

	          cout << "\nPlease enter in the state (2 letters) ex. OR, CA, WA" << endl;
	          cin.get(state, 3);
	          cin.ignore(100, '\n');

            cout << "\nPlease enter in the zipcode (5 digits)" <<endl;
	        zip = enter_number (1); // Turning string to int
            customer.add_member (name, mem_num, address, city, state, zip);
            pt.add_member (prov_num, customer);
          }
          else
          {
            cout << "The member is already in the system" <<endl;
          }
          cout << "Please press any key (except enter) to keep going! "<<endl;
          temp = getchar();
          system("clear");
          cin.ignore(100,'\n');
        }
      }

      if (response == 'S') //If the user wants to add a service   
      {
        cout << "Please enter in the member's number" <<endl;
        mem_num = enter_number (0);
        if (pt.retrieve_member (prov_num, mem_num))
        {
          //Enter in the service code 
          do
          {
            cout << "Please enter in the service code" <<endl;
            service_code = enter_number (2);
            //Determine what the user request
            flag = check_services (service_code);
            if (flag == 99) 
            {
              cout << "There's no service for that" <<endl;
            }
          }while (flag == 99);

          //Setting the service name
          strcpy (service_name, services[flag]); //Get service name
          //service_fee  
          //service_charge
          service_fee = service_charge[flag]; //Get the service fee
        

          //Enter in the service information
          cout << "Enter in date of service provided (Ex. MM-DD-YYYY)" <<endl;
          cin.get (service_date, 11);
          cin.ignore (100, '\n');

          cout << "Getting current date and time (Ex. MM-DD-YYYY HH:MM:SS)" <<endl; 
          time_t current_time; //Calling in object call
          tm * current; //Current pointer
          setenv("TZ", "PST8PDT", 1); //Set to Pacific Time
          tzset(); //Set
          current_time = time(NULL); 
          current = localtime (&current_time); //Local time
          //Set current_date_time to current time right now
          strftime (current_date_time, 20, "%D %T", current); 

          cout << "Any comments about the service (if yes click y)" <<endl
               << "If not enter n" <<endl;
          cin >> response;
          cin.ignore (100, '\n');
          response = toupper (response);
          if (response == 'Y')
          {
            cout << "Enter in comment" <<endl;
            cin.get (comments, 100);
            cin.ignore (100, '\n');
          }
          else
          {
            strcpy (comments, "None"); //Set comment to none
          }

          int fee = 123;
          fee = service_fee; 
          pt.add_service(prov_num, mem_num, service_name, service_date, current_date_time, comments, service_code, fee); //Add the service into our linked list
          
          //Recording Disk
          cout << "\nRecording to Disk: " <<endl << "Current date and time: "
               << current_date_time << "\nDate Service Provided: " <<service_date
               << "\nProvider Number: " <<prov_num << "\nMember Number: " <<mem_num
               << "\nService Code: " <<service_code << "\nComments: " <<comments <<endl;
        }
        else
        {
          cout << "That's a invalid member number" <<endl;
        }
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');
      }

      if (response == 'E') //Wants to end the week
      {
        if(LoginAdmin() == 0) // Restricting user login
        {
          cout<<"Verification failed"<<endl;

        }
        else
        {

          //Email Attachment
          pt.display_email (prov_num);

          //Generating Weekly Report
          cout << "\nGenerating Weekly Report: " <<endl <<endl;
          pt.display_report (prov_num); 
        }
        cout << "Please press any key (except enter) to keep going! "<<endl;
        temp = getchar();
        system("clear");
        cin.ignore(100,'\n');

      }

      if (response == 'Q') //If the user wants to quit
      {
        quit = 1;
      }
    }while (response != 'Q' && response != 'W');
  }while (quit != 1);
  cout << "Thank you for using the program!" <<endl;
	return 0;
}

