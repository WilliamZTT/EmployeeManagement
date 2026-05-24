#include "workermanager.h"
WorkerManager::WorkerManager()
{
    
}
WorkerManager::~WorkerManager()
{
    
}
void WorkerManager::Show_Menu()
{
    cout<<"Welcome to Employee Management System!" << endl;
    cout << "1. Exit Management System" << endl;
    cout << "2. Add Employee Information" << endl;
    cout << "3. Display Employee Information" << endl;
    cout << "4. Delete Employee Information" << endl;
    cout << "5. Modify Employee Information" << endl;
    cout << "6. Find Employee Information" << endl;
    cout << "7. Sort Employee Information" << endl;
    cout << "8. Clear All Employee Information" << endl;
}
void WorkerManager::ExitSystem()
{
    cout << "Thank you for using Employee Management System!" << endl;
    system("pause");
    exit(0);
}