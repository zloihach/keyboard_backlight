#include <windows.h>
#include <iostream>
#include <conio.h>


using namespace std;

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

//int setDelay(){
//    static int delay;
//    cout << "Enter delay: ";
//    cin >> delay;
//    return delay;
//}
//
//int delayController(){
//    static int delay = 250;
//        if (GetAsyncKeyState(VK_OEM_PLUS) && delay <=5000){
//            delay +=250;
//            return delay;
//            cout << "delay: " << delay << endl;
//
//        }
//        if (GetAsyncKeyState(VK_OEM_MINUS) && delay >=0){
//            delay -= 250;
//            return delay;
//            cout << "delay: " << delay << endl;
//
//        }
//        else{
//            cout << "Except!" << endl;
//            exit(0);
//        }
//}

DWORD handleCtl(void)
{
    const int dt = 100;
    static int delay = 1000;
    if (GetAsyncKeyState(VK_OEM_PLUS) && delay <= 5000){
        delay += dt;
        cout << "delay: " << delay << endl;
    }
    if (GetAsyncKeyState(VK_OEM_MINUS) && delay >= 0){
        delay -= dt;
        cout << "delay: " << delay << endl;
    }
    if (delay < dt) delay = dt;
    return delay;
}

int main() {
    int a = 1;
    cout << "Enter Crtl+C for close this program" << endl;
    //int delay = delayController();
    DWORD delay = 3000;
    while (a = 1 && delay > 0)  {
        SetKey(TRUE, VK_CAPITAL);
        Sleep(delay);
        delay = handleCtl();
        SetKey(FALSE, VK_CAPITAL);
        Sleep(delay);
        delay = handleCtl();
    }
}
