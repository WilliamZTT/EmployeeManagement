#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define FILE "WorkerInfo.txt"
using namespace std;
class Worker
{
    friend class WorkerManager;
public:
    Worker() {}
    virtual ~Worker() {}
    virtual void Show_Info() = 0;
protected:
    int id;
    string name;
    int deptId;
};
class WorkerManager
{
public:
    WorkerManager();
    ~WorkerManager();
    void Show_Menu();
    void ExitSystem();
    void Add_Worker();
    void SaveInfo();
    bool IsFileEmpty();
    void Display_Workers();
protected:
    vector<Worker*> WorkerArray;
};

class Employee : public Worker
{
public:
    Employee(int id, string name, int deptId);
    ~Employee();
    void Show_Info();
};
class Manager : public Worker
{
public:
    Manager(int id, string name, int deptId);
    ~Manager();
    void Show_Info();
};
class Boss : public Worker
{
public:
    Boss(int id, string name, int deptId);
    ~Boss();
    void Show_Info();
};
#endif // WORKERMANAGER_H