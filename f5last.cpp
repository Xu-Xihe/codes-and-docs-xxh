#include <cstdio>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
using namespace std;
int main()
{
    while (1)
    {
        keybd_event(116, 0, 0, 0);
        keybd_event(116, 0, KEYEVENTF_KEYUP, 0);
        Sleep(2000);
    }
}