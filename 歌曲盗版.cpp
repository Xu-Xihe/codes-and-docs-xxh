#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<WinUser.h>
#define yici 1000//�˴�Ϊ���һ��¼�������밴���ڴ��С�����趨��
#define qian 2999//�˴�Ϊ¼��ǰ�ȴ�ʱ�䣨��λ�����룩��ע��1000����=1�롣
#define mccd 1200//�˴�Ϊ�������ļ�������󳤶ȡ���ע���ַ�����β\0��
using namespace std;
int	shou, sj[yici],fh[yici],shu;
unsigned short ff;
char name[yici][mccd],lujing[mccd];
const char stx = 'T', xx = 'X';//stx=���š���ͣ��xx=��һ�ס�ע��Ϊ��д�� 
bool zj;
void shuru(char in[1000])
{
	for (int i = 0;;i++)
	{
		scanf("%c", &in[i]);
		if (in[i] == '\n') {
			in[i] = 0;
			i--;
			if(i>0)return ;
		}
	}
}
void mc(char in[mccd])
{
	int len = strlen(in);
	for (int i = 0; i < len; i++)
	{
		if (in[i] == '.')break;
		if (in[i] >= 'A'&&in[i] <= 'Z')
		{
			keybd_event(16, 0, 0, 0);
			keybd_event(in[i], 0, 0, 0);
			keybd_event(in[i], 0, KEYEVENTF_KEYUP, 0);
			keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		}
		if (in[i] >= 'a'&&in[i] <= 'z')
		{
			in[i] -= 32;
			keybd_event(in[i], 0, 0, 0);
			keybd_event(in[i], 0, KEYEVENTF_KEYUP, 0);
		}
		if (in[i]==' ')
		{
			keybd_event(' ', 0, 0, 0);
			keybd_event(' ', 0, KEYEVENTF_KEYUP, 0);
		}
		if (in[i] == '-')
		{
			keybd_event(189, 0, 0, 0);
			keybd_event(189, 0, KEYEVENTF_KEYUP, 0);
		}
		if (in[i] == '_')
		{
			keybd_event(16, 0, 0, 0);
			keybd_event(189, 0, 0, 0);
			keybd_event(189, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		}
		if(in[i] == '��')
	}
	keybd_event(110, 0, 0, 0);
	keybd_event(110, 0, KEYEVENTF_KEYUP, 0);
	keybd_event('M', 0, 0, 0);
	keybd_event('M', 0, KEYEVENTF_KEYUP, 0);
	keybd_event('P', 0, 0, 0);
	keybd_event('P', 0, KEYEVENTF_KEYUP, 0);
	keybd_event('3', 0, 0, 0);
	keybd_event('3', 0, KEYEVENTF_KEYUP, 0);
}
int main()
{
	printf("��ǰ¼������ʼ��ݼ�ΪCtrl+F1\n");
	printf("��ǰ¼����������ݼ�ΪCtrl+F2\n");
	printf("��ǰ��������ʼ����ͣ��ݼ�ΪCtrl+Shift+%c\n", stx);
	printf("��ǰ�������л���һ�׿�ݼ�ΪCtrl+Shift+%c\n", xx);
	printf("\n�Ѳ���˳�����Ϊ˳�򲥷š�\n");
	printf("\n��Ѹ������ȵ���Ϊ0:00�����������糩ͨ��\n\n");
	printf("�Ƿ���ļ���ȡ����0�������ļ���ȡ[���ñ�׼��]��1�����ļ���ȡ[ʹ��freopen�ض���]������");
	scanf("%d", &zj);
	if (zj)
	{
		printf("�����ļ�·����");
		scanf("%s", lujing);
		freopen(lujing, "r", stdin);
	}
	if(zj == 0)printf("Ҫ¼�����׸裿\n");
	scanf("%d", &shou);
	if (zj == 0)printf("���ٷ��ӣ����밴˳�����룬��������֡��룬�м��ѿո������������3 36����\n");
	for (int i = 0; i < shou; i++)
	{
		int j = 0;
		if(zj==0)printf("\n��%d�ף�",i+1);
		scanf("%d", &sj[i]);
		scanf("%d", &j);
		sj[i] *= 60;
		sj[i] += j;
	}
	if (zj == 0)printf("�����������뷽ʽ����0�������롣1��ȫ�����롣2������Ҫ����������Ƶ���š�3�����벻Ҫ����������Ƶ���ţ���");
	scanf("%d", &ff);
	if (ff == 2 || ff == 3)
	{
		if (zj == 0)printf("\n��Ҫ���������������");
		scanf("%d", &shu);
		if (zj == 0)printf("\n��ʼ�����ţ�");
		for (int i = 0; i < shu; i++)
		{
			scanf("%d", &fh[i]);
		}
	}
	if (ff != 0)
	{
		if (zj == 0)printf("����������ע��ֻ֧�ִ�Сд��ĸ���ո�_ ��-)����˳�����룬�Իس���β�����ɰ����ģ�\n");
		if (ff == 3)
		{
			for (int i = 0; i < shou; i++)
			{
				int z = 0;
				for (int j = 0; j < shu; j++)
				{
					if (i == fh[j] - 1)z = 88;
				}
				if (z == 0)
				{
					if (zj == 0)printf("��%d�ף�", i + 1);
					shuru(name[i]);
				}

			}
		}
		if (ff == 2)
		{
			for (int i = 0; i < shu; i++)
			{
				if (zj == 0)printf("\n��%d�ף�", fh[i]);
				shuru(name[fh[i] - 1]);
			}
		}
		if (ff == 1)
		{
			for (int i = 0; i < shou; i++)
			{
				if (zj == 0)printf("\n��%d�ף�",i + 1);
				shuru(name[i]);
			}
		}
	}
	for (int i = 0; i<shou; i++)
	{
		keybd_event(17, 0, 0, 0); //��ʼ��
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
		Sleep(qian);
		keybd_event(16, 0, 0, 0);//��ʽ¼�ơ�
		keybd_event(18, 0, 0, 0);
		keybd_event(stx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(stx, 0, KEYEVENTF_KEYUP, 0);
		printf("��%d��¼���С�������\n", i + 1);
		for (int j = 0; j < sj[i]-1; j++)
		{
			Sleep(1000);
		}
		keybd_event(16, 0, 0, 0);//���ֽ�����
		keybd_event(18, 0, 0, 0);
		keybd_event(stx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(stx, 0, KEYEVENTF_KEYUP, 0);//<
		keybd_event(17, 0, 0, 0); //������
		keybd_event(113, 0, 0, 0);
		keybd_event(113, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);//<
		Sleep(1000);
		if (name[i][0] != 0)mc(name[i]);
		keybd_event(13, 0, 0, 0);//��������ɡ�
		keybd_event(13, 0, KEYEVENTF_KEYUP, 0);//<
		Sleep(1000);
		keybd_event(16, 0, 0, 0);//�л���һ�ס�
		keybd_event(18, 0, 0, 0);
		keybd_event(xx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(xx, 0, KEYEVENTF_KEYUP, 0);//<
		Sleep(100);
		keybd_event(16, 0, 0, 0);//��ͣ��
		keybd_event(18, 0, 0, 0);
		keybd_event(stx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(stx, 0, KEYEVENTF_KEYUP, 0);//<
	}
	printf("��¼����ɣ��ļ���¼����Ĭ��·���¡�");
	system("pause");
	printf("�˳�");
	Sleep(1000);
	return 0;
}
