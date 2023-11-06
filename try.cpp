#include <Windows.h>
#include <stdio.h>

int main ()
{
    DWORD PId;
    // get the game name of the game i want to hack into
    HWND game = ::FindWindow(NULL, "PlantsVsZombies");
    GetWindowThreadProcessId(game, &PId);
    printf("this will show if the code get the ip sucessfully");
    printf("%d",&PId);
    //used the id i have got
    HANDLE hpro = ::OpenProcess(PROCESS_ALL_ACCESS, false, PId);

    if (hpro == NULL){
        printf("nononono, that is bad this shoudln't be hereeeee");
    }
//game base address
    LPVOID staic_address = (LPVOID)7692072;
    int sun = 0;

    LPVOID sunva = (LPVOID)&sun;
// the function need a 10 based digit
    SIZE_T byred;
    ReadProcessMemory(hpro, (LPVOID)7692072, sunva, 4, &byred);

    staic_address = (LPVOID)(sun + 2152);//16 based to 10
    ReadProcessMemory(hpro, staic_address, sunva, 4, &byred);

    staic_address = (LPVOID)(sun + 21880);//16 based to 10
    ReadProcessMemory(hpro, staic_address, sunva, 4, &byred);

    ReadProcessMemory(hpro, (LPVOID)(sun + 2152), sunva, 4, &byred);
    ReadProcessMemory(hpro, (LPVOID)(sun + 21880), sunva, 4, &byred);
    printf("sun value now：%d \n", sun);
    int value = 0;
    printf("input the sun value wants to change\n");
    scanf("%d", &value);
    LPVOID input = (LPVOID)&value;
    SIZE_T byt;
    WriteProcessMemory(hpro,staic_address,input,4,&byt);
    printf("done\n");
    }