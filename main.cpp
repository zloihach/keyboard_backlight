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

int setDelay(){
    int delay;
    cout << "Enter delay: ";
    cin >> delay;
    return delay;
}


int main() {
    int a = 1;
    int delay = setDelay();
    while (a = 1 && delay > 0)  {
        SetKey(TRUE, VK_CAPITAL);
        Sleep(delay);
        SetKey(FALSE, VK_CAPITAL);
        Sleep(delay);
    }
}
