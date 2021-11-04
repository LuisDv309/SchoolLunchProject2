// SchoolLunch02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>


using namespace std;

struct Parents {     //Structure to hold Parents registration data//
    string FullName;
    string DOB;      //Date of Birth//
    double ContactNumber;
    string ChildFullName;
    int ChildRoomNum;
    long int VisaCardNum;
    string VisaCardExpireDate;
    string UserName;
    string Password;

};
vector<Parents>InputParentsRegis(vector<Parents>& inparents);

void Exit() {
    exit(0); 
}
void Line(int n);
vector<Parents>ReadFromFile();

int main() {
    
    vector<Parents>inparents;
    Line(66);
    InputParentsRegis(inparents);
    ReadFromFile();
}
vector<Parents>InputParentsRegis(vector<Parents>& inparents) {

    Parents p;
    char answer = 'y';
    fstream  MyFile("ParentsFile.csv", ios::app);// Adding to existing file
    while (tolower(answer) == 'y') {
     
        cin.ignore();
        cout << " Register For The School Lunch Order System" << endl;
        cout << "Please Enter your Full Name :" << endl;
        getline(cin, p.FullName);

        cout << "Date Of Birth :" << endl;
        getline(cin, p.DOB);

        cout << "Phone Number :" << endl;
        cin >> p.ContactNumber;
        cin.ignore();
        cout << "Please Enter Your Child Full Name :" << endl;
        getline(cin, p.ChildFullName);
        cout << "Your Child ClassRoom Number :" << endl;
        cin >> p.ChildRoomNum;
        cout << "Enter Your Credit Card Number :" << endl;
        cin >> p.VisaCardNum;
        cin.ignore();
        cout << "Expire Date: " << endl;
        getline(cin, p.VisaCardExpireDate);
        MyFile << p.FullName << "," << p.DOB << "," << p.ContactNumber << p.ChildFullName << "," << p.ChildRoomNum << "," << p.VisaCardNum << "," << p.VisaCardExpireDate << "," << p.UserName << endl;
        cout << "Do You Wish to Submmit Your Registration Y / N" << endl;
        cin >> answer;

    }
   
    MyFile.close();
    return (inparents);
}


void Line(int n) {
   
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << "*";
    }

    cout << endl;
}

vector<Parents>ReadFromFile() {

    cout << "FromReadFrom File Function" << endl;
     Line(66);
     fstream MyFile("ParentsFile.csv", ios::in);
     vector <Parents>TempParents;
     Parents p;
     string line;
     while (getline(MyFile, line)) {
         cout << line << endl;
         istringstream linestream(line);
         string RegisteredParent;
         getline(linestream, RegisteredParent, ',');
         p.FullName = RegisteredParent;

         getline(linestream, RegisteredParent, ',');
         p.DOB = RegisteredParent;

         getline(linestream, RegisteredParent, ',');

         stringstream ss(RegisteredParent);
         ss >> p.ContactNumber;
         TempParents.push_back(p);
     }
     MyFile.close();
     return(TempParents);

}
