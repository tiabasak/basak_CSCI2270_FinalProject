#include <iostream>
#include <string>
#include "DateBook.h"
#include <stdlib.h>
//#include "DateBook.cpp"

using namespace std;

int main()
{
    DateBook Obj;
    string schoice;
    int choice;
    bool truth;
    while(choice != 7)
    {
        Obj.MainMenu();
        getline (cin,schoice);
        choice = atoi(schoice.c_str());

        if(choice == 1)
        {
            int date;
            string month;
            string event;

            cout<<"Enter Month"<<endl;
            getline(cin,month);
            if (Obj.hashAssign(month)==-1)
            {
                truth = true;
                while (truth)
                {
                    cout<<"Please enter an acceptable month"<<endl;
                    getline(cin,month);
                    if (Obj.hashAssign(month)!=-1)
                        truth = false;
                }
            }

            cout<<"Enter Date"<<endl;
            cin>>date;

            cout<<"Enter Event"<<endl;
            cin.ignore(1,'\n');
            getline(cin,event);


            Obj.insertdate(month,date,event);
        }
        if(choice == 2)
        {
            int date;
            string month;


            cout<<"Enter Month"<<endl;
            getline(cin,month);
            if (Obj.hashAssign(month)==-1)
            {
                truth = true;
                while (truth)
                {
                    cout<<"Please enter an acceptable month"<<endl;
                    getline(cin,month);
                    if (Obj.hashAssign(month)!=-1)
                        truth = false;
                }
            }

            cout<<"Enter Date"<<endl;
            cin>>date;

            Obj.deletedate(month,date);
        }

        if(choice == 3)
        {
            int date;
            string month;

            cout<<"Enter Month"<<endl;
            cin.ignore(1,'\n');
            getline(cin,month);

            cout<<"Enter Date"<<endl;
            cin>>date;
            Obj.SearchByDate(month,date);
        }
        if(choice == 4)
        {
            Obj.printTableContents();
        }
        if(choice == 5)
        {
            string Keyword;


            cout<<"Enter Keyword"<<endl;
            cin.ignore(1,'\n');
            getline(cin,Keyword);

            Obj.SearchByKey(Keyword);
        }
        if(choice == 6)
        {
            Obj.deleteall();
        }
        if(choice == 7)
        {
            cout<<"Goodbye!"<<endl;
        }
    }

}
