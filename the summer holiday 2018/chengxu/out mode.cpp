void out(int len,char a[maxe][maxe],char b[maxe][maxe],char c[maxe][maxe]){
	char x,y,z,ni[maxe];
	scanf("%s%c%c%c",ni,&y,&z,&x);
	if((y==' '&&z=='-')&&(x=='a'||x=='o')){
		char lin[maxe];
		come(ni,lin);
		int ji=0;
		for(;;ji++){
			if(ji>=len){
				now(1);
				printf("ceshidian1\n");
				return ;
			}
			if(strcmp(lin,a[ji])==0)break;
		}
		memset(lin,0,sizeof(lin));
		back(c[ji],lin);
		if(x=='a'){
			memset(ni,0,sizeof(ni));
			back(b[ji],ni);
			xie(ni);
			printf("ceshidian2     ");
		}
		xie(lin);
		return ;
	}
	else{
		now(1);
		printf("ceshidian3\n");
		return ;
	}
}
