#include "workermanager.h"
int main()
{
    WorkerManager wm;
    int choice = 0;
    while(1)
    {
        wm.Show_Menu();
        cout << "Please enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                wm.ExitSystem();
                break;
            case 2:
                wm.Add_Worker();
                break;
            case 3:
                wm.Display_Workers();
                break;
            case 4:
                wm.Delete_Worker();
                break;
            case 5:
                wm.Modify_Worker();
                break;
            case 6:
                wm.Find_Worker();
                break;
            case 7:
                wm.Sort_Worker();
                break;
            case 8:
                wm.Clear_Worker();
                break;
        }
    }
    return 0;
}
