#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string taskName;
    // using boolean operator to known the task in boolean from
    bool completed;

public:
    Task(const std::string& name) : taskName(name), completed(false) {}

    void completeTask() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    std::string getName() const {
        return taskName;
    }
};

class ToDoList {
private:
    // manage the Task list given by input so using vector header.
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskName) {
        tasks.push_back(Task(taskName));
    }

    void completeTask(int index) {
        //When both conditions are true, it means that index is valid due to AND operation
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completeTask();
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            // i from 0 to i and which runs till i is less than task size
            //++i for first increase then use instead i++
            for (size_t i = 0; i < tasks.size(); ++i) {
                const Task& task = tasks[i];
                std::cout << i + 1 << ": " << task.getName() << " - "
                          << (task.isCompleted() ? "Completed" : "Pending") << std::endl;
            }
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        std::cout << "Welcome to the Simple To-Do List App!" << std::endl;
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add a new Task" << std::endl;
        std::cout << "2. Complete Task" << std::endl;
        std::cout << "3. Display a List of Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Please enter your choice: (1 - 4) " <<std::endl;

        int choice;
        std::cin >> choice;
       // cases for each condition Occurance
        switch (choice) {
            case 1: {
                std::string taskName;
                std::cout << "Enter task name: ";

                std::cin.ignore();  // Clear the newline character
                std::getline(std::cin, taskName);
                todoList.addTask(taskName);
                std::cout << "Task \"" << taskName << "\" added!" << std::endl;
                // break this line  here and move next case
                break;
            }
            case 2: {
                todoList.displayTasks();
                int taskIndex;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskIndex;
                // completed task will marked and minus in the task list
                todoList.completeTask(taskIndex - 1);
                break;
            }
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                return 0;
                // in case invalid operation
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
                break;
        }
    }

    return 0;
}
