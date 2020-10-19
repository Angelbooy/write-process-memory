#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main(){
  int thing = 500; // change to what ever
  HWND hwnd = FindWindowA(NULL,"game here");
  if(hwnd == NULL){
    cout << "HWND Not found\n\n\n";
  } else {
    DWORD procID;
    GetWindowThreadProcessId(hwnd, &procID);
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
    if(procID == NULL){
      cout << "Cannot find process ID\n\n\n";
    } else {
      string ans;
      while(true){
        cout << "Command : ";
        cin >> ans;
        if(ans == "health"){
          WriteProcessMemory(handle, (LPVOID)0x00000, &thing, sizeof(thing), 0); // lpvoid is where you put the offset
        }
      }
    }
  } 
  return 0;  
}
