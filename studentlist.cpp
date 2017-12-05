#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
  struct student
  {
    char name[];
    char lname[];
    int id;
    float GPA;
  };
void toAdd(vector<student*>* list);
void toDelete(vector<student*>* list);
void toPrint(vector<student*>* list);
int main(){
  vector<student*>* list;
  char input[80];
  bool running = true;
  while (running == true){
    cout << "What would you like to do?" << endl;
    cin.getline (input,80);
    if(strcmp (input, "ADD") == 0){
      toAdd(vector<student*>* list);
    }
    else if(strcmp (input, "DELETE") == 0){
    }
    else if(strcmp (input, "PRINT") == 0){
    }
    else{
      cout << "That is not a valid response!" << endl;
	}
  }
}
  
void toAdd(vector<student*>* list){
                  
  student* stu = new student;
  int n,i;
  cout << "What a test!" << endl;
  cout << "How many students would you like to enter?" << endl;
    cout << "First Name: ";
    cin.getline(stu -> name,20);
    cout << "Last Name: ";
    cin.getline(stu -> lname,20);
    cout << "ID: ";
    cin.getline(stu -> id);
    cout << "GPA: ";
    cin.getline(stu -> GPA);
    list -> push_back(stu);
  }
}
void toDelete(){
  
}
void toPrint(){
}
