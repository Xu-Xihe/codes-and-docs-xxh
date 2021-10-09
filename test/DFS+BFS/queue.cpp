#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 10;
class MyQueue{
	int num[maxn];
	int startPos,endPos,len;
public:
	void MyPop(){
		if (len>0){
			startPos++;
			startPos %= maxn;
			len--;
		}
		else {
			printf("Queue is empty!!!\n");
		}
		
	}
	bool MyEmpty(){
		return (len==0);
	}
	void MyPush(int value){
		if (len == maxn){
			printf("Error!!!\n");
			return ;
		}
		num[endPos] = value;
		endPos++;
		endPos %= maxn;
		len ++;
	}
	void init(){
		memset(num,0,sizeof num);
		startPos = endPos = 0;
		len = 0;
	}
	int front(){
		return num[startPos];
	}
};
/*
struct MyQueue{
	int num[maxn];
	int startPos,endPos,len;
};
void MyPop(MyQueue &que){
	//if (que.startPos>=que.endPos)
	//	que.startPos++;
	if (que.len>0){
		que.startPos++;
		que.startPos %= maxn;
		que.len--;
	}
	else {
		printf("Queue is empty!!!\n");
	}
	
}
bool MyEmpty(const MyQueue &que){
	return (que.len==0);
}
void MyPush(MyQueue &que, int value){
	if (que.len == maxn){
		printf("Error!!!\n");
		return ;
	}
	que.num[que.endPos] = value;
	que.endPos++;
	que.endPos %= maxn;
	que.len ++;
}
void init(MyQueue &que){
	memset(que.num,0,sizeof que.num);
	que.startPos = que.endPos = 0;
	que.len = 0;
}
*/
int main(){
	int op;
	MyQueue myQueue;
	queue <int> que;
	while (~scanf("%d",&op)){
		if (op == 1){
			int value;
			scanf("%d",&value);
			//MyPush(myQueue,value);
			myQueue.MyPush(value);
			que.push(value);
		}
		else{
			//printf("%d %d\n",myQueue.num[myQueue.startPos],que.front());
			//MyPop(myQueue);
			printf("%d %d\n",myQueue.front(),que.front());
			myQueue.MyPop();
			que.pop();
		}
	}
	return 0;
}