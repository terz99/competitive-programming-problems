#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include "Date.h"


// hardcoded positions of digits in date format
const int POS[] = {0, 1, 3, 4, 6, 7, 8, 9};
const int POS_SIZE = 8;

// helper function for checkValidDate()
bool checkPos(const int &idx){
    for(int i = 0; i < POS_SIZE; i++){
        if(idx == POS[i]) {
            return true;
        }
    }
    return false;
}

// checks if the date format is valid (DD.MM.YYYY)
bool checkValidDate(const std::string &date) {

    for(int i = 0; i < (int)date.length(); i++){
        if(checkPos(i)) {
            if (!isdigit(date[i])) {
                return false;
            }
        } else {
            if(date[i] != '.'){
                return false;
            }
        }
    }
    return true;
}

// it shows all the todos in 'todoList'
void showAll(const std::set<Date> &todoList){

    for (std::set<Date>::iterator it = todoList.begin(); it != todoList.end(); it++) {

        Date i = *it;
        std::cout << i.getDay() << "." << i.getMonth()
                  << "." << i.getYear() << " --> "
                  << i.getData() <<std::endl;
    }
}

// shows all the dates before or after some 'date'
// if 'lower' is true then it shows before
// otherwise it shows after
void showAll(const std::set<Date> &todoList, const std::string &date,
             const bool &lower){

    Date d(date, "");
    for(std::set<Date>::iterator it = todoList.begin(); it != todoList.end(); it++){

        Date i = *it;
        if(lower && i < d){
            std::cout << i.getDay() << "." << i.getMonth()
                      << "." << i.getYear() << " --> "
                      << i.getData() <<std::endl;
        } else if(!lower && i > d){
            std::cout << i.getDay() << "." << i.getMonth()
                      << "." << i.getYear() << " --> "
                      << i.getData() <<std::endl;
        }
    }
}


// This functions search for a 'statement' in a set of todoList
// If the statement(s) is(are) found in some of the todos it asks you if you are sure
// that you want to delete it. If yes it deletes it.
void del(std::set<Date> &todoList, const std::string& statement){

    for(std::set<Date>::iterator it = todoList.begin(); it != todoList.end(); it++){

        Date date = *it;
        if(date.getData().find(statement) != std::string::npos){

            std::cout << date.getDay() << "." << date.getMonth()
                      << "." << date.getYear() << " --> "
                      << date.getData() <<std::endl;
            std:: cout << "Are you sure you want to delete this? (y/n/na(no all))\n";
            std::string op;
            std::cin >> op;
            if(op == "y"){
                todoList.erase(it);
            } else if(op == "na"){
                break;
            }
        }
    }
}

int main() {

    std::ifstream in;
    in.open("/home/dushan/Workspace/C++/todo_sort/todo_data.txt");

    if(!in.is_open()){
        std::cout << "There has been some problem opening the file\n";
        exit(1);
    }

    std::set<Date> todoList;
    std::pair< std::string, std::string > input_data;
    while(std::getline(in, input_data.first)){

        if(input_data.first == "" || input_data.first == "\n")
            break;

        // reads all the todos from a file

        std::getline(in, input_data.second);

        if(checkValidDate(input_data.first)){
            todoList.insert( Date(input_data.first, input_data.second) );
        }
    }

    in.close();


    std::string op;
    while(true){

        std::cout << "type 'legend' to see commands\n";
        std::cin >> op;
        if(op == "legend"){

            // shows all available commands
            std::cout << "q --> quit" << std::endl;
            std::cout << "show --> show all the todos" << std::endl;
            std::cout << "showb --> show all before the 'date'" << std::endl;
            std::cout << "showa --> show all after the 'date'" << std::endl;
            std::cout << "add --> add a new item in the todo list" << std::endl;
            std::cout << "delete --> delete a new item in the todo list" << std::endl;
        } else if(op == "q"){ // quits the application
            break;
        } else if(op == "show"){
            showAll(todoList);
        } else if(op =="showb"){

            // first asks for a date
            // then it shows you all the todos before that date
            std::cout << "Enter the date (DD.MM.YYYY): ";
            std::cin >> op;
            if(checkValidDate(op)) {
                showAll(todoList, op, true);
            } else {
                std::cout << "The date format you entered is not valid\n";
            }
        } else if(op == "showa"){

            // first asks for a date
            // then it shows you all the todos before that date
            std::cout << "Enter the date (DD.MM.YYYY): ";
            std::cin >> op;
            if(checkValidDate(op)) {
                showAll(todoList, op, false);
            } else {
                std::cout << "The date format you entered is not valid\n";
            }
        } else if(op == "add"){

            // asks for a date and a statement
            // then it adds the date and the statement as a todos
            std::string date;
            std::string statement;
            std::cout << "Enter deadline (DD.MM.YYYY): \n";
            std::cin >> date;
            getchar();
            if(checkValidDate(date)){

                std::cout << "Enter statement:\n";
                std::getline(std::cin, statement);
                todoList.insert( Date(date, statement) );
                std::cout << "Todo added successfully\n";
            } else {
                std::cout << "The date format you entered is invalid\n";
            }
        } else if(op == "delete"){

            // deletes a todos if exists
            std::cout << "Type any substring of the statement you wish to delete"
                      << " (please make sure that the substring does not occur in other todos)\n";
            std::string statement;
            getchar();
            std::getline(std::cin, statement);
            del(todoList, statement);
        } else {
            std::cout << "Sorry the command you entered is invalid. Try again\n";
        }
    }

    std::ofstream out;
    out.open("/home/dushan/Workspace/C++/todo_sort/todo_data.txt");

    if(!out.is_open()){
        std::cout << "There has been some problem with opening file\n";
        exit(1);
    }

    for(auto it = todoList.begin(); it != todoList.end(); it++){

        Date date = *it;
        out << date.getDate() << std::endl;
        out << date.getData() << std::endl;
    }

    out.close();
    std::cout << "Good luck!\n";

    return 0;
}