#include "workermanager.h"
WorkerManager::WorkerManager()
{
    
}
WorkerManager::~WorkerManager()
{
    for (Worker* p : WorkerArray)
        delete p;
    WorkerArray.clear();
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
void Employee::Show_Info()
{
    cout << "ID: " << this->id << "\tName: " << this->name << "\tDepartment: " << "Employee" << endl;
}
Employee::Employee(int id, string name, int deptId)
{
    this->id = id;
    this->name = name;
    this->deptId = deptId;
}
Employee::~Employee() {}
void Manager::Show_Info()
{
    cout << "ID: " << this->id << "\tName: " << this->name << "\tDepartment: " << "Manager" << endl;
}
Manager::Manager(int id, string name, int deptId)
{
    this->id = id;
    this->name = name;
    this->deptId = deptId;
}
Manager::~Manager() {}
void Boss::Show_Info()
{
    cout << "ID: " << this->id << "\tName: " << this->name << "\tDepartment: " << "Boss" << endl;
}
Boss::Boss(int id, string name, int deptId)
{
    this->id = id;
    this->name = name;
    this->deptId = deptId;
}
Boss::~Boss() {}
void WorkerManager::Add_Worker()
{
    cout << "Adding worker's information" << endl;
    cout<<"Please enter the number of workers you want to add: " << endl;
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int id;
        string name;
        int deptId;
        cout << "Please enter worker's ID: " << endl;
        cin >> id;
        cout << "Please enter worker's name: " << endl;
        cin >> name;
        cout << "Please enter worker's department ID: " << endl;
        cin >> deptId;
        Worker* worker = nullptr;
        switch (deptId)
        {
            case 1:
                worker = new Employee(id, name, deptId);
                break;
            case 2:
                worker = new Manager(id, name, deptId);
                break;
            case 3:
                worker = new Boss(id, name, deptId);
                break;
            default:
                cout << "Invalid department ID!" << endl;
                return;
        }
        WorkerArray.push_back(worker);
    }
}
        