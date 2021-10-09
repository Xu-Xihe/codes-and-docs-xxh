#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<WinUser.h>
#define yici 1000//此处为最大一次录制量，请按照内存大小合理设定。
#define qian 2999//此处为录制前等待时间（单位：毫秒）。注：1000毫秒=1秒。
#define mccd 1200//此处为歌曲、文件名称最大长度。（注意字符串结尾\0）
using namespace std;
int	shou, sj[yici],fh[yici],shu;
unsigned short ff;
char name[yici][mccd],lujing[mccd];
const char stx = 'T', xx = 'X';//stx=播放、暂停；xx=下一首。注意为大写！ 
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
		if(in[i] == '、')
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
	printf("当前录制器开始快捷键为Ctrl+F1\n");
	printf("当前录制器结束快捷键为Ctrl+F2\n");
	printf("当前播放器开始、暂停快捷键为Ctrl+Shift+%c\n", stx);
	printf("当前播放器切换下一首快捷键为Ctrl+Shift+%c\n", xx);
	printf("\n把播放顺序调整为顺序播放。\n");
	printf("\n请把歌曲进度调整为0:00，并保持网络畅通。\n\n");
	printf("是否从文件读取？（0：不从文件读取[采用标准流]。1：从文件读取[使用freopen重定向]。）：");
	scanf("%d", &zj);
	if (zj)
	{
		printf("输入文件路径：");
		scanf("%s", lujing);
		freopen(lujing, "r", stdin);
	}
	if(zj == 0)printf("要录多少首歌？\n");
	scanf("%d", &shou);
	if (zj == 0)printf("多少分钟？（请按顺序输入，依次输入分、秒，中间已空格隔开。样例：3 36。）\n");
	for (int i = 0; i < shou; i++)
	{
		int j = 0;
		if(zj==0)printf("\n第%d首：",i+1);
		scanf("%d", &sj[i]);
		scanf("%d", &j);
		sj[i] *= 60;
		sj[i] += j;
	}
	if (zj == 0)printf("歌曲名称输入方式？（0：不输入。1：全部输入。2：输入要输入歌曲名称的序号。3：输入不要输入歌曲名称的序号）：");
	scanf("%d", &ff);
	if (ff == 2 || ff == 3)
	{
		if (zj == 0)printf("\n需要特殊输入的数量：");
		scanf("%d", &shu);
		if (zj == 0)printf("\n开始输入编号：");
		for (int i = 0; i < shu; i++)
		{
			scanf("%d", &fh[i]);
		}
	}
	if (ff != 0)
	{
		if (zj == 0)printf("歌曲名？（注：只支持大小写字母，空格，_ ，-)（按顺序输入，以回车结尾，不可包中文）\n");
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
					if (zj == 0)printf("第%d首：", i + 1);
					shuru(name[i]);
				}

			}
		}
		if (ff == 2)
		{
			for (int i = 0; i < shu; i++)
			{
				if (zj == 0)printf("\n第%d首：", fh[i]);
				shuru(name[fh[i] - 1]);
			}
		}
		if (ff == 1)
		{
			for (int i = 0; i < shou; i++)
			{
				if (zj == 0)printf("\n第%d首：",i + 1);
				shuru(name[i]);
			}
		}
	}
	for (int i = 0; i<shou; i++)
	{
		keybd_event(17, 0, 0, 0); //开始。
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
		Sleep(qian);
		keybd_event(16, 0, 0, 0);//正式录制。
		keybd_event(18, 0, 0, 0);
		keybd_event(stx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(stx, 0, KEYEVENTF_KEYUP, 0);
		printf("第%d首录制中…………\n", i + 1);
		for (int j = 0; j < sj[i]-1; j++)
		{
			Sleep(1000);
		}
		keybd_event(16, 0, 0, 0);//音乐结束。
		keybd_event(18, 0, 0, 0);
		keybd_event(stx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(stx, 0, KEYEVENTF_KEYUP, 0);//<
		keybd_event(17, 0, 0, 0); //结束。
		keybd_event(113, 0, 0, 0);
		keybd_event(113, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);//<
		Sleep(1000);
		if (name[i][0] != 0)mc(name[i]);
		keybd_event(13, 0, 0, 0);//重命名完成。
		keybd_event(13, 0, KEYEVENTF_KEYUP, 0);//<
		Sleep(1000);
		keybd_event(16, 0, 0, 0);//切换下一首。
		keybd_event(18, 0, 0, 0);
		keybd_event(xx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(xx, 0, KEYEVENTF_KEYUP, 0);//<
		Sleep(100);
		keybd_event(16, 0, 0, 0);//暂停。
		keybd_event(18, 0, 0, 0);
		keybd_event(stx, 0, 0, 0);
		keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(stx, 0, KEYEVENTF_KEYUP, 0);//<
	}
	printf("已录制完成，文件在录制器默认路径下。");
	system("pause");
	printf("退出");
	Sleep(1000);
	return 0;
}
