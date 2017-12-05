#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
  struct student
  {
    char name[50];
    char lname[50];
    int id;
    float GPA;
  };
void toAdd(vector<student*> *plist);
void toDelete(vector<student*>* plist);
void toPrint(vector<student*>* plist);
int main(){
  //vector of pointers to structs, pointer to that vector, variables
  vector<student*> list;
  vector<student*>* plist = &list;
  char input[80];
  bool running = true;
  while (running == true){
    //Take a user input and run the corresponding function
    cout << "What would you like to do?" << endl;
    cin.getline (input,80);
    if(strcmp (input, "ADD") == 0){
      toAdd(plist);
    }
    else if(strcmp (input, "DELETE") == 0){
      toDelete(plist);
    }
    else if(strcmp (input, "PRINT") == 0){
      toPrint(plist);
    }
    else if(strcmp (input, "END") == 0){
      running = false;
    }
    else{
      cout << "That is not a valid response!" << endl;
    }
  }
  return 0;
}

void toAdd(vector<student*> *plist){
  //input each part of new student, push back
  student* stu = new student;
  cout << "First Name: ";
  cin.getline(stu->name,20);
  cout << "Last Name: ";
  cin.getline(stu->lname,20);
  cout << "ID: ";
  cin >> stu->id;
  cin.ignore();
  cout << "GPA: ";
  cin >> stu->GPA;
  cin.ignore();
  plist->push_back(stu);
}

void toDelete(vector<student*> *plist){
  //ask user for id
  int inid = 0;
  cout << "What is the ID number of the student you wish to delete?" << endl;
  cin >> inid;
  cin.ignore();
  //For each item in the vector, if entered id matches id
  for(std::vector<student*>::const_iterator i = plist->begin(); i != plist->end(); ++i){
    if (inid == (*i)->id){
      //delete struct and pointer, return to stop iterator  looping over deleted thing
      delete *i;
      plist->erase(i);
      return;
    }
  }
}

void toPrint(vector<student*> *plist){
  //for each item in vector, print out each part of the struct
  for (std::vector<student*>::const_iterator i = plist->begin(); i != plist->end(); ++i){
    cout << "Name:" << (*i)->name << ' ' << (*i)->lname << endl;
    cout << "ID:" << (*i)->id << endl;
    cout << "GPA:" << (*i)->GPA << endl;
  }
}

