#include<stdio.h>
#include<Windows.h>
using namespace std;
int in;
bool pan;
int main(){
	printf("ָ��ˢ������������0������ָ��ˢ�����ʱ�䣨����1����");
	scanf ("%d",&pan);
	printf("������ʱ��(�룬Ϊ����)��");
	scanf("%d",&in);
	for(int i=0;i<5;i++){
		printf("%d���ʼ\n",5-i);
		Sleep(1000);
	}
	if(pan){
		while(true){
			keybd_event(17,0,0,0);
			keybd_event('V',0,0,0);
			keybd_event('V',0,KEYEVENTF_KEYUP,0);
			keybd_event(17,0,KEYEVENTF_KEYUP,0);
			keybd_event(18,0,0,0);
			keybd_event('S',0,0,0);
			keybd_event('S',0,KEYEVENTF_KEYUP,0);
			keybd_event(18,0,KEYEVENTF_KEYUP,0);
			for(int i=0;i<in;i++)
				Sleep(1000);
		}
	}
	else{
		for(int i=0;i<in;i++){
			keybd_event(17,0,0,0);
			keybd_event('V',0,0,0);
			keybd_event('V',0,KEYEVENTF_KEYUP,0);
			keybd_event(17,0,KEYEVENTF_KEYUP,0);
			keybd_event(18,0,0,0);
			keybd_event('S',0,0,0);
			keybd_event('S',0,KEYEVENTF_KEYUP,0);
			keybd_event(18,0,KEYEVENTF_KEYUP,0);
		}
	}
	return 0;
} 
