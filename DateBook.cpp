#include "DateBook.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
DateBook::DateBook()
{
    //ctor
    for(int j = 0; j<tableSize; j++)
    {
        hashTable[j] = NULL;
    }
}

int DateBook::hashAssign(string x)
{
    int index;
    if(x == "January")
    {
        index = 0;
    }
    else if(x == "February")
    {
        index = 1;
    }
     else if(x == "March")
    {
        index = 2;
    }
     else if(x == "April")
    {
        index = 3;
    }
     else if(x == "May")
    {
        index = 4;
    }
     else if(x == "June")
    {
        index = 5;
    }
     else if(x == "July")
    {
        index = 6;
    }
     else if(x == "August")
    {
        index = 7;
    }
     else if(x == "September")
    {
        index = 8;
    }
     else if(x == "October")
    {
        index = 9;
    }
     else if(x == "November")
    {
        index = 10;
    }
     else if(x == "December")
    {
        index = 11;
    }
     else
    {
        cout<<x<<" Not Found"<<endl;
    }
    return index;
};

void DateBook::insertdate(string month, int date,string event)
{
    int index = hashAssign(month);

    DateElem *node = new DateElem(month,date,event);

    if(hashTable[index] == NULL) // if there nothing in that index
    {
        node->prev = NULL;
        hashTable[index] = node;
    }
    else if(hashTable[index]->next == NULL) //if the next one is empty after the first spot
    {
        DateElem *temp = hashTable[index];

        if(temp->date < node->date)
        {
            node->prev = hashTable[index];
            node->next = NULL;
            hashTable[index]->next = node;
        }
        else if(temp->date > node->date)
        {
            temp->prev = node;
            node->next  = temp;
            temp->next = NULL;
        }
        else
        {
            cout<<"An Event Already Exists Edit to modify "<<endl;
        }

    }
    else
    {
        DateElem *temp = hashTable[index]; //traverse through until find an empty spot
        while(temp != NULL)
        {
            temp = temp->next;
        }
        if(temp->date < node->date)
        {
            node->next = NULL;
            node->prev = temp;
            temp->next = node;
        }
        else if(temp->date > node->date)
        {
            node->next = temp->next;
            temp->next = node;
            node->prev = temp;
            node->next->prev = node;
        }
        else
        {
            cout<<"An Event Already Exists Edit to modify "<<endl;
        }

    }
};

void DateBook::SearchByDate(string month,int date)
{
    int index = hashAssign(month);
    bool found = false;
    if(hashTable[index] != NULL)
    {
        DateElem *temp = hashTable[index];

        while(temp != NULL)
        {
            if(temp->date == date)
            {
                print(temp);
                found = true;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if(!found)
        {
            cout<<"No Events"<<endl;
        }

    }
    else
    {
        cout<<"No Events"<<endl;
    }
}

void DateBook::SearchByKey(string keyword)
{
    bool found = false;
    if(!checkTable())
    {
        cout<<"Empty Datebook"<<endl;
    }
    else
    {
        for(int i = 0; i < tableSize; i++)
        {
            DateElem *temp = hashTable[i];
            if(temp != NULL)
            {
                while(temp != NULL)
                {
                    //find the keyword in the events string
                    string str1 = temp->event;
                    string str2 = keyword;
                    if(str1.find(str2))
                    {
                        found = true;
                        return;
                    }
                    else
                    {
                        cout<<"Keyword Not found"<<endl;
                    }
                    if(found)
                    {
                        print(temp);
                    }
                    temp = temp->next;

                }
            }
        }
    }
}

void DateBook::deletedate(string month,int date)
{
    int index = hashAssign(month);
    if(hashTable[index] != NULL)
    {
        DateElem *temp = hashTable[index];
        while(temp != NULL)
        {
            if(temp->date == date)
            {
                if(temp->prev == NULL)
                {
                    if(temp->next != NULL)
                    {
                        temp->next->prev = NULL;
                        hashTable[index] = temp->next;
                    }
                    else
                    {
                        hashTable[index] = NULL;
                    }
                    delete temp;
                    break;
                }
                else
                {
                    if(temp->next != NULL)
                    {
                        temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;
                    }
                    else
                    {
                        temp->prev->next = NULL;
                    }
                    delete temp;
                    break;
                }
            }
            temp = temp->next;
        }
    }
}

void DateBook::deleteall()
{

    if(!checkTable())
    {
        cout<<"Datebook is empty"<<endl;
    }
    else
    {
        for(int i = 0; i < tableSize; i++)
        {
            DateElem *temp = hashTable[i];
            if(temp != NULL)
            {
                while(temp != NULL)
                {
                    deletedate(temp->month,temp->date);
                    temp = temp->next;
                }
            }
        }
    }
}

void DateBook::MainMenu()
{
    cout<<"Main Menu"<<endl;
    cout<<"1. Insert Event"<<endl;
    cout<<"2. Edit Event"<<endl;
    cout<<"3. Delete Event"<<endl;
    cout<<"4. Search By Date"<<endl;
    cout<<"5. Print Contents"<<endl;
    cout<<"6. Search By Keyword"<<endl;
    cout<<"7. Delete All"<<endl;
    cout<<"8. Quit"<<endl;

}

void DateBook::printTableContents()
{
    if(!checkTable())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        for(int i = 0; i < tableSize; i++)
        {
            DateElem *temp = hashTable[i];
            if(temp != NULL)
            {
                while(temp != NULL)
                {
                    print(temp);
                    temp = temp->next;
                }
            }
        }
    }
}

void DateBook::print(DateElem* x)
{
    cout<<x->month<<" "<<x->date<<": \n"<<x->event<<endl;
}

bool DateBook::checkTable()
{
    bool built = false;
    for (int i = 0; i<tableSize; i++)
    {
        if (hashTable[i] != NULL)
        {
            built = true;
        }

    }
    return built;
}
DateBook::~DateBook()
{
    //dtor
}
