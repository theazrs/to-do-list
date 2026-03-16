#include <iostream>
#include <string> // to use getline
#include <vector> // must include to use vectors 
using namespace std; 

// global
vector<string> tasks = {};

// function to idle until something is imput
void waitOnInput() {
    cout << "Press ENTER to continue... ";
    cin.get();

}

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
    int i = 1;
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
    tasks.push_back(task);
    // clear 
    cout << "Task added successfully" << endl;
}

// function to mark task as done (temp)
void deleteTask(int index) {
    if (tasks.size() <= index && index > 0) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task marked as done / deleted" << endl;
    } 
    else {
        cout << "Error!! " << endl;
    }
}

// function to check if vector is em
int isEmpty() {
    if (tasks.empty() == true) {
        return 1;
    }
    return 0;
}

// function to clear screen
void clearScreen() {
    cout << "\033[2J\033[1;1H" << endl;
}

// main
int main() {
    clearScreen();
    int response;

    // initial screen
    cout << "Welcome to my to-do list!!!" << endl << endl;
    while (true) {
        index();
        cin >> response;
        cin.ignore();
        clearScreen();
        switch(response) {
            case 1:
                // if user has no tasks it won't have to print your tasks
                if (isEmpty()) {
                    cout << "To-do list is empty, add tasks to be able to view them.." << endl;
                    waitOnInput();
                    clearScreen();
                    break;
                }
            
                // else
                cout << "Your tasks: " << endl << endl;
                printTasks();
                waitOnInput();
                clearScreen();
                break;

            case 2:
                addTask();
                waitOnInput();
                clearScreen();
                break;

            case 3:
                // check to ensure users without any task cannot view
                if (isEmpty()) {
                    cout << "To-do list is empty, add tasks to be able to mark them as done" << endl;
                    waitOnInput();
                    clearScreen();
                    break;
                }

                // else
                int response1;
                clearScreen();
                printTasks();
                cout << "Choose which task to mark as done." << endl;
                cin >> response1;
                cin.ignore();
                deleteTask(response1);
                waitOnInput();
                clearScreen();
                break;

            case 4:
                cout << "Exiting..." << endl;

                // write to file 
                return 0;

            default:
                cout << "Invalid option" << endl;
                waitOnInput();
                clearScreen();
                break;
        }
    }
    
    
    return 0;
}