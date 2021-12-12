#ifndef TESTS_H
#define TESTS_H

#include "mainfunctions.h"
#include "provider_table.h"

//Service code check success
//Tests the check_services(int) function with valid input
void validServiceCodeTest() {
  cout << "Valid service codes test" << endl;
  try {
    int codes[11] = {598470, 883948, 634298, 444187, 397464, 548512, 812349, 178634, 649778, 357745};
    bool results = true;
    for (int i = 0; i < 10; i++) {
      int res = check_services(codes[i]);
      if (res >= 0 && res < 10)
        cout << "Valid service code " << codes[i] << ": test passed" << endl;
      else {
        results = false;
        throw codes[i];
      }
    }
  }
  catch (int thrown) {
    cout << "Service code " << thrown << " is invalid" << endl;
  }
}

//Test for invalid service code
//Tests the check_services(int) function with invalid input
void invalidServiceCodeTest() {
  cout << "Invalid service codes test" << endl;
  try {
    int codes[4] = {1, 12333, 43232131};
    bool results = true;
    for (int i = 0; i < 3; i++) {
      int res = check_services(codes[i]);
      if (res == 99)
        cout << "Invalid service code " << codes[i] << ": test passed" << endl;
      else
        throw codes[i];
    }
  }
  catch (int thrown) {
    cout << "Service code " << thrown << " is a valid service number" << endl;
  }
}


//Tests the is_digits(string) function with valid input
void validInputCheckDigitsTest() {
  try {
      string s[4] = {"213", "543644", "321321421321"};
      for (int i = 0; i < 3; i++) {
      bool res = is_digit(s[i]);
      if (res == true)
        cout << "Digits (" << s[i] << ") test: passed" << endl;
      else
        throw res;
    }
  }
  catch (bool e) {
    cout << "Digits test: failed" << endl;
  }
}

//Tests the is_digits(string) function with invalid input
void invalidInputCheckDigitsTest() {
  try {
      string s[4] = {"a", "5aa", "321aa23"};
      for (int i = 0; i < 3; i++) {
      bool res = is_digit(s[i]);
      if (res == false)
        cout << "Digits (" << s[i] << ") test: passed" << endl;
      else
        throw res;
    }
  }
  catch (bool e) {
    cout << "Digits test: failed" << endl;
  }
}

//Tests the provider functions display() and search_provider(int)
//when a provider does exist
void testExistingProviderFuncs() {
  provider p;
  char name[] = {'n', 'a', 'm', 'e'};
  int number = 123123123;
  char address[] = {'a', 'd', 'd', 'e'};
  char city[] = {'c', 'i', 't', 'y'};
  char state[] = {'o', 'r'};
  int zip = 21321;
  p.add_provider(name, number, address, city, state, zip);
  try {
    int res = p.display_provider();
    system("clear");
    if (res == 1) 
      cout << "Existing provider display test: passed" << endl;
    else
      throw res;
  }
  catch (int t) {
    cout << "Existing provider display test: failed" << endl;
  }
  try {
    int res = p.search_provider(number);
    if (res == 1) 
      cout << "Matching search test: passed" << endl;
    else
      throw res;
  }
  catch (int t) {
    cout << "Matching search test: failed" << endl;
  }
  try {
    int res = p.search_provider(32132);
    if (res == 0) 
      cout << "Non-matching existing provider search test: passed" << endl;
    else
      throw res;
  }
  catch (int t) {
    cout << "Non-matching existing provider search test: passed" << endl;
  }
}

//Tests the provider functions display() and search_provider(int)
//when a provider does not exist
void testNonExistingProviderFuncs() {
  provider p;
  try {
    int res = p.display_provider();
    if (res == 0) 
      cout << "Non-existent provider display test: passed" << endl;
    else
      throw res;
  }
  catch (int t) {
    cout << "Non-existent provider display test: failed" << endl;
  }

  try {
    int res = p.search_provider(2132121);
    if (res == -1) 
      cout << "Non-existent search test: passed" << endl;
    else
      throw res;
  }
  catch (int t) {
    cout << "Non-existent search test: failed" << endl;
  }
}



#endif