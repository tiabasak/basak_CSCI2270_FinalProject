#ifndef DATEBOOK_H
#define DATEBOOK_H
#include <string>
#include <vector>

struct DateElem
{
    std::string month;
    int date;
    std::string event;
    DateElem *next;
    DateElem *prev;
    DateElem(){};
    DateElem(std::string in_month,int in_date,std::string in_event)
    {
        month = in_month;
        date = in_date;
        next = NULL;
        prev = NULL;
        event = in_event;
    }
};

class DateBook
{
    public:
        DateBook();
        ~DateBook();
        void insertdate(std::string month,int date,std::string event);
        void deletedate(std::string month,int date);
        void deleteall();
        int size();
        void SearchByDate(std::string month, int date);
        void SearchByKey(std::string key);
        void printTableContents();
        void print(DateElem *x);
        void MainMenu();
        void Edit(std::string month, int date);
        void upcoming(std::string month,int date);
        bool checkTable();
    protected:
    private:
        int hashAssign(std::string x);
        int tableSize = 12;
        DateElem* hashTable[12];
};

#endif // DATEBOOK_H
