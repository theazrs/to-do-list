#include <iostream>
#include <string> // to use getline
#include <vector> // must include to use vectors 
using namespace std; 

// global
class Tasks {
    public:
        string name;
        bool isCompleted = false;
};

vector<Tasks> taskV = {};

// function to clear screen
void clearScreen() {
    cout << "\033[2J\033[1;1H" << endl;
}

// function to re-order tasks
void reOrder() {
    vector<Tasks> tempV = {};
    Tasks tempT;
    for (int i = 0; i < taskV.size(); i++) {
        if (taskV.at(i).isCompleted) {
            tempT = taskV.at(i);
            taskV.erase(taskV.begin() + i);
            taskV.push_back(tempT);
        }
    }
}

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
    string temp;
    for (Tasks task : taskV) {
        if (!task.isCompleted) {
            temp = "";
        }
        else {
            temp = " ✓";
        }
        cout << i << ". " << task.name << temp << endl;
        i++;
    }
}

// function to add task to vector
void addTask() {
    string temp;
    Tasks task;
    cout << "Enter the name of the task" << endl;
    cout << "If you do not wish to add a task right now, simply press enter" << endl;
    getline(cin, temp);
    // if blank input
    if (temp == "") {
        clearScreen();
        cout << "No task was added" << endl;
    }

    else {
        task.name = temp;
        taskV.push_back(task);
        reOrder();
        clearScreen();
        cout << "Task added successfully" << endl;
    }

}

// function to mark task as done (temp)
void deleteTask(int index) {
    if (index <= taskV.size() && index > 0) {
        if (taskV.at(index - 1).isCompleted) {
            cout << "Task was already marked as done. No changes made..." << endl;
        }
        else {
            taskV.at(index - 1).isCompleted = true;
            cout << "Task marked as done" << endl;
            reOrder();
        }
    } 
    else {
        cout << "Error!! " << endl;
    }
}

// function to check if vector is empty
int isEmpty() {
    if (taskV.empty() == true) {
        return 1;
    }
    return 0;
}

// main
int main() {
    clearScreen();
    int response;

    // initial screen
    cout << "Welcome to my to-do list!!!" << endl << endl;
    while (true) {
        index();

        // input checking
        while (true) {
            cin >> response;
            if (!cin.fail()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),   '\n');
            cout << "Please enter an integer. " << endl;
        }
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
                cout << "Enter 0 to return." << endl;
                // integer check
                while (true) {
                    cin >> response1;
                    if (!cin.fail()) {
                        break;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),   '\n');
                    cout << "Please enter an integer. " << endl;
                }
                cin.ignore();

                if (response1 == 0) {
                    clearScreen();
                    cout << "No task was marked as done." << endl;
                    waitOnInput();
                    clearScreen();
                    break;
                }
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