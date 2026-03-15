#include <iostream>
#include <string>
#include <vector> // must include to use vectors 
using namespace std; 

// global
vector<string> tasks = {};

// main screen
void index() {
    cout << "Select option below" << endl << endl;
    cout << "1. View tasks" << endl;
    cout << "2. Add a task" << endl;
    cout << "3. Mark task as done" << endl;
    cout << "4. Save and exit" << endl;
}

// function to output to screen
void printTasks() {
    int i = 0;
    for (string task : tasks) {
        cout << i << ". " << task << endl;
        i++;
    }
}

// function to add task to vector
void addTask() {
    string task;
    cout << "Enter the name of the task" << endl;
    getline(cin, task);
    cin.ignore();
    tasks.push_back(task);
    // clear 
    cout << "Task added successfully" << endl;
}

void deleteTask(int index) {
    if (tasks.size() < index) {
        tasks.erase(tasks.begin() + index);
        cout << "Task marked as done / deleted" << endl;
    } 
    else {
        cout << "Error!! " << endl;
    }
}
// main
int main() {
    int response;

    // initial screen
    cout << "Welcome to my to-do list!!!" << endl << endl;
    index();
    cin >> response;
    switch(response) {
        case 1:
            cout << "Your tasks: " << endl << endl;
            printTasks();
            break;

        case 2:
            addTask();
            break;

        case 3:
            // add check to ensure users without any task cannot input anything
            int response1;
            printTasks();
            cin >> response1;
            // function to delete 
            break;

        case 4:
            cout << "Exiting..." << endl;
            // write to file 
            return 0;
    }
    
    return 0;
}