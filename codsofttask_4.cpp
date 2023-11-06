#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the to-do list
void addTask(vector<Task>& todoList, const string& description) {
    Task newTask = {description, false};
    todoList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view all tasks in the to-do list
void viewTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "No tasks in the to-do list." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < todoList.size(); i++) {
            cout << i + 1 << ". " << (todoList[i].completed ? "[X] " : "[ ] ") << todoList[i].description << std::endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& todoList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < todoList.size()) {
        todoList[taskIndex].completed = true;
        cout << "Task marked as completed: " << todoList[taskIndex].description << endl;
    } else {
        cout << "Invalid task index. No task marked as completed." << endl;
    }
}

// Function to remove a task from the to-do list
void removeTask(vector<Task>& todoList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < todoList.size()) {
        cout << "Task removed: " << todoList[taskIndex].description << endl;
        todoList.erase(todoList.begin() + taskIndex);
    } else {
        cout << "Invalid task index. No task removed." << endl;
    }
}

int main() {
    vector<Task> todoList;

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, description);
            addTask(todoList, description);
        } else if (choice == 2) {
            viewTasks(todoList);
        } else if (choice == 3) {
            viewTasks(todoList);
            int taskIndex;
            cout << "Enter the index of the task to mark as completed (or 0 to cancel): ";
            cin >> taskIndex;
            if (taskIndex != 0) {
                markTaskCompleted(todoList, taskIndex - 1); // Adjust for 1-based index
            }
        } else if (choice == 4) {
            viewTasks(todoList);
            int taskIndex;
            cout << "Enter the index of the task to remove (or 0 to cancel): ";
            cin >> taskIndex;
            if (taskIndex != 0) {
                removeTask(todoList, taskIndex - 1); // Adjust for 1-based index
            }
        } else if (choice == 5) {
            cout << "Thanks for using the To-Do List Manager!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
