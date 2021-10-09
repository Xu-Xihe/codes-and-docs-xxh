void close(int len,char a[maxe][maxe],char b[maxe][maxe],char c[maxe][maxe]){
	freopen("key.xxh","w",stdout);
	int chang=0;
	char ji[maxe],shi[maxe];
	for(;;chang++){
		int lin=1;
		for(int i=0;i<chang;i++){
			lin*=10;
		}
		if(len/lin==0)break;
	}
	for(int i=0;i<chang;i++){
		shi[i]=len%10;
		len/10;
	}
	come(shi,ji);
	printf("%s\n",ji);
	for(int i=0;i<len;i++){
		printf("%s\n%s\n%s\n",a[i],b[i],c[i]);
	}
}
