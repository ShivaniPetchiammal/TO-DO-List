#include <iostream>
#include <string>
using namespace std;
struct Task
{
    string name;
    bool completed;
};
Task tasks[100];
int totalTasks = 0;
void addTask()
{
    cin.ignore();
    cout << "\nEnter Task: ";
    getline(cin, tasks[totalTasks].name);
    tasks[totalTasks].completed = false;
    totalTasks++;
    cout << "Task Added Successfully!\n";
}
void viewTasks()
{
    if(totalTasks == 0)
    {
        cout << "\nNo Tasks Available!\n";
        return;
    }
    cout << "\n------ TO-DO LIST ------\n";
    for(int i = 0; i < totalTasks; i++)
    {
        cout << i + 1 << ". " << tasks[i].name;

        if(tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}
void completeTask()
{
    int n;
    if(totalTasks == 0)
    {
        cout << "\nNo Tasks Available!\n";
        return;
    }
    viewTasks();
    cout << "\nEnter Task Number to Complete: ";
    cin >> n;
    if(n >= 1 && n <= totalTasks)
    {
        tasks[n - 1].completed = true;
        cout << "Task Marked as Completed!\n";
    }
    else
    {
        cout << "Invalid Task Number!\n";
    }
}
void removeTask()
{
    int n;
    if(totalTasks == 0)
    {
        cout << "\nNo Tasks Available!\n";
        return;
    }
    viewTasks();
    cout << "\nEnter Task Number to Remove: ";
    cin >> n;
    if(n >= 1 && n <= totalTasks)
    {
        for(int i = n - 1; i < totalTasks - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }
        totalTasks--;

        cout << "Task Removed Successfully!\n";
    }
    else
    {
        cout << "Invalid Task Number!\n";
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n========== TO-DO LIST ==========\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "\nThank You!\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }
    } while(choice != 5);
    return 0;
}
