#include<Windows.h>
using namespace std;
int main(){
	Sleep(5000); 
	while(true){
		keybd_event(17, 0, 0, 0);
		keybd_event('V', 0, 0, 0);
    	keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
    	keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, 0, 0);
		keybd_event('S', 0, 0, 0);
    	keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
    	keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
    	Sleep(200); 
	}
}
