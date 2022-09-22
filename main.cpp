#include <windows.h>
#include <iostream>
#include <conio.h>


using namespace std;

const int size = 10;
//DWORD arr[size];
void SetKey(BOOL bState, DWORD key) {
    BYTE keyState[256];

    GetKeyboardState((LPBYTE) &keyState);
    if ((bState && !(keyState[key] & 1)) ||
        (!bState && (keyState[key] & 1))) {
        keybd_event(key,
                    0x45,
                    KEYEVENTF_EXTENDEDKEY | 0,
                    0);

        keybd_event(key,
                    0x45,
                    KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                    0);
    }
}

int main() {
    int a = 1;
    while (a = 1) {
        SetKey(TRUE, VK_CAPITAL);
        Sleep(500);
        SetKey(FALSE, VK_CAPITAL);
        Sleep(500);
    }
}
