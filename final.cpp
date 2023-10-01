// Personal To-Do List Manager Programming Exercise
#include <iostream>
#include <vector>
#include <string>

class TodoItems {
public:
    TodoItems(const std::string& data) : data(data), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    const std::string& getdata() const {
        return data;
    }

private:
    std::string data;
    bool completed;
};

class ToDoList {
public:
    void addTodoItems(const std::string& data) {
        todoItems.push_back(TodoItems(data));
    }

    void markTodoItemsCompleted(int index) {
        if (isValidIndex(index)) {
            todoItems[index].markCompleted();
        }
    }

    void deleteTodoItems(int index) {
        if (isValidIndex(index)) {
            todoItems.erase(todoItems.begin() + index);
        }
    }

    void viewAllTodoItems() const {
        std::cout<<std::endl << "All Tasks:" << std::endl << std::endl;
        for (size_t i = 0; i < todoItems.size(); ++i) {
            const TodoItems& todo = todoItems[i];
            std::cout << i + 1 << ". ";
            std::cout << todo.getdata() << " ";
            if (todo.isCompleted()) {
                std::cout << "[Completed] "<<std::endl;
            }
            else {
                std::cout << "[Pending] "<<std::endl;
            }
        }
        if (todoItems.empty()) {
            std::cout << "No Items in TodoList." << std::endl;
        }
    }

    std::vector<TodoItems> viewCompletedList() const {
        std::vector<TodoItems> completedList;
        for (const TodoItems& todo : todoItems) {
            if (todo.isCompleted()) {
                completedList.push_back(todo);
            }
        }
        return completedList;
    }

    std::vector<TodoItems> viewPendingList() const {
        std::vector<TodoItems> pendingList;
        for (const TodoItems& todo : todoItems) {
            if (!todo.isCompleted()) {
                pendingList.push_back(todo);
            }
        }
        return pendingList;
    }


private:
    std::vector<TodoItems> todoItems;

    bool isValidIndex(int index) const {
        return index >= 0 && index <static_cast<int>(todoItems.size());
    }
};

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        std::cout<<std::endl<<"-----------------" << "To-Do List Manager" <<"-----------------"<< std::endl;
        std::cout << "1. Add TodoItems" << std::endl;
        std::cout << "2. Delete TodoItems" << std::endl;
        std::cout << "3. View All TodoItems" << std::endl;
        std::cout << "4. Mark Completed TodoItems" << std::endl;
        std::cout << "5. View Completed TodoItems" << std::endl;
        std::cout << "6. View Pending TodoItems" << std::endl;
        std::cout << "7. Quit" << std::endl<<std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout<<std::endl;

        if (choice == 7) {
            std::cout<<"Thank you"<<std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                std::string data;
                std::cout << "Add your Todo here -->  ";
                std::cin.ignore();
                std::getline(std::cin, data);
                todoList.addTodoItems(data);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter the index of the TodoItems to delete: ";
                std::cin >> index;
                todoList.deleteTodoItems(index - 1); 
                break;
            }
            case 3:{
                std::cout<<std::endl;
                todoList.viewAllTodoItems();
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter the index of the TodoItems to mark them as completed: ";
                std::cin >> index;
                todoList.markTodoItemsCompleted(index - 1); 
                break;
            }
            case 5: {
                std::cout<<"List of completed tasks: "<<std::endl;
                std::vector<TodoItems> arr=todoList.viewCompletedList();
                std::cout<<std::endl;
                int j=1;
                for(int i=0;i<arr.size();i++){
                    const TodoItems& todo=arr[i];
                    std::cout<<j<<". ";
                    std::cout<<todo.getdata()<<std::endl;
                    j++;
                }
                if (arr.empty()) {
                    std::cout << "No task is completed yet." << std::endl;
                }
                break;
            }
            case 6: {
                std::cout<<"List of pending tasks: "<<std::endl;
                std::vector<TodoItems> arr=todoList.viewPendingList();
                int j=1;
                for(int i=0;i<arr.size();i++){
                    const TodoItems& todo=arr[i];
                    std::cout<<j<<". ";
                    std::cout<<todo.getdata()<<std::endl;
                    j++;
                }
                if (arr.empty()) {
                    std::cout << "No task is pending." << std::endl;
                }
                break;
            }
            default:
                std::cout << "InValid request!! Please enter a valid choice." << std::endl;
        }
    }

    return 0;
}
