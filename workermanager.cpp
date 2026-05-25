#include "workermanager.h"
WorkerManager::WorkerManager()
{
    if (IsFileEmpty())
        return;
    ifstream ifs(FILE, ios::in);
    int id, deptId;
    string name;
    while (ifs >> id >> name >> deptId)
    {
        Worker* worker = nullptr;
        switch (deptId)
        {
            case 1: worker = new Employee(id, name, deptId); break;
            case 2: worker = new Manager(id, name, deptId); break;
            case 3: worker = new Boss(id, name, deptId); break;
        }
        if (worker)
            WorkerArray.push_back(worker);
    }
    ifs.close();
}
WorkerManager::~WorkerManager()
{
    SaveInfo();
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
    SaveInfo();
    cout << "Thank you for using Employee Management System!" << endl;
    system("pause");
    exit(0);
}

bool WorkerManager::IsFileEmpty()
{
    ifstream ifs(FILE, ios::in);
    if (!ifs.is_open())
        return true;
    ifs >> ws;
    bool empty = ifs.eof();
    ifs.close();
    return empty;
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
void WorkerManager::SaveInfo()
{
    ofstream ofs(FILE, ios::out);
    for (Worker* worker : WorkerArray)
    {
        ofs << worker->id << " " << worker->name << " " << worker->deptId << endl;
    }
    ofs.close();
}
void WorkerManager::Display_Workers()
{
    if (WorkerArray.empty())
    {
        cout << "No worker information available!" << endl;
        return;
    }
    for (Worker* worker : WorkerArray)
    {
        worker->Show_Info();
    }
}
void WorkerManager::Delete_Worker()
{
    if (WorkerArray.empty())
    {
        cout << "No worker information available!" << endl;
        return;
    }
    cout << "Deleting worker's information" << endl;
    cout << "Please enter the ID of the worker you want to delete: " << endl;
    int id;
    cin >> id;
    auto it = find_if(WorkerArray.begin(), WorkerArray.end(), [id](Worker* worker) 
    {
        return worker->id == id;
    });
    if (it != WorkerArray.end())
    {
        delete *it;
        WorkerArray.erase(it);
        cout << "Worker with ID " << id << " has been deleted." << endl;
    }
    else
    {
        cout << "Worker with ID " << id << " not found!" << endl;
    }
    this->SaveInfo();
}
void WorkerManager::Modify_Worker()
{
    cout << "Modifying worker's information" << endl;
    cout << "Please enter the ID of the worker you want to modify: " << endl;
    int id;
    cin >> id;
    auto it = find_if(WorkerArray.begin(), WorkerArray.end(), [id](Worker* worker) {
        return worker->id == id;
    });
    if (it != WorkerArray.end())
    {
        delete *it;
        int newId;
        string newName;
        int newDeptId;
        cout << "Please enter new ID: " << endl;
        cin >> newId;
        cout << "Please enter new name: " << endl;
        cin >> newName;
        cout << "Please enter new department ID: " << endl;
        cin >> newDeptId;
        Worker* newWorker = nullptr;
        switch (newDeptId)
        {
            case 1:
                newWorker = new Employee(newId, newName, newDeptId);
                break;
            case 2:
                newWorker = new Manager(newId, newName, newDeptId);
                break;
            case 3:
                newWorker = new Boss(newId, newName, newDeptId);
                break;
            default:
                cout << "Invalid department ID!" << endl;
                return;
        }
        *it = newWorker;
        cout << "Worker with ID " << id << " has been modified." << endl;
        this->SaveInfo();
    }
    else
    {
        cout << "Worker with ID " << id << " not found!" << endl;
    }
}
void WorkerManager::Find_Worker()
{
    cout << "Finding worker's information" << endl;
    cout << "Please enter the ID of the worker you want to find: " << endl;
    int id;
    cin >> id;
    auto it = find_if(WorkerArray.begin(), WorkerArray.end(), [id](Worker* worker) {
        return worker->id == id;
    });
    if (it != WorkerArray.end())
    {
        (*it)->Show_Info();
    }
    else
    {
        cout << "Worker with ID " << id << " not found!" << endl;
    }
}
void WorkerManager::Sort_Worker()
{
    cout << "Sorting worker's information by ID" << endl;
    sort(WorkerArray.begin(), WorkerArray.end(), [](Worker* a, Worker* b) {
        return a->id < b->id;
    });
    cout << "Workers have been sorted by ID." << endl;
    this->SaveInfo();
}
void WorkerManager::Clear_Worker()
{
    cout << "Clearing all worker information" << endl;
    for (Worker* worker : WorkerArray)
    {
        delete worker;
    }
    WorkerArray.clear();
    ofstream ofs(FILE, ios::out);
    ofs.close();
    cout << "All worker information has been cleared." << endl;
}