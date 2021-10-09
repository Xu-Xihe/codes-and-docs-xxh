#include<Windows.h>
#include<stdio.h>
using namespace std;
int a;
int main(){
	printf("µÈ´ý¼¸Ãë±£´æ£¿"); 
	scanf("%d",&a);
	a*=1000;
	while(true){
		Sleep(a);
		keybd_event(17,0,0,0); 
		keybd_event('S',0,0,0); 
		keybd_event('S',0,KEYEVENTF_KEYUP,0);
		keybd_event(17,0,KEYEVENTF_KEYUP,0);
	} 
} 
