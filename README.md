# basak_CSCI2270_FinalProject
Tia Basak
Data Structures
Final Project
27 April 2016

Final Project Data Structures: Date Book

	For the Data Structures final project I created a Date Book. It is basically a program that the user can insert dates and events and can organize themselves. It uses a perfect hash table of 12 one for each month and then uses a doubly linked list for each of the dates. The features include inserting a date, by first inputting the month then the date, deleting a specific input date, deleting all of the inputs, printing the contents, searching an event by date, or searching an event by keyword. The insert function uses a doubly linked list inserting each date at every index which is representative of a month. Instead of using a hash function, each index is assigned a month. The search by date function allows the user to input any date and see if they have any events that day. The search by keyword function on the other asks the user for a keyword and searches through the database for an event with the matching keyword. The delete an event feature allows the user to delete any event, and the delete all allows them to clear the entire calendar. They also have the option to print the contents of the calendar this is done by traversing through the hash Table. 
To run this program, first open the main cpp file titled Final Project along with the class file and the header file titled Datebook. If you are running this in Code blocks then you must include the “Datebook.cpp”. Then in the Final Project when you run it a Main menu should open where all the options are listed. Depending on the choice number you can input a month, date, and event. The only known bugs in this program is the Search by keyword doesn’t work properly. Right now a limitation that this program has is that you can only add one event per date. So that is an enhancement option. 

