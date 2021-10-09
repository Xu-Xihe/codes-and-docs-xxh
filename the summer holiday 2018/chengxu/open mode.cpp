bool open(int&len,char a[maxe][maxe],char b[maxe][maxe],char c[maxe][maxe]){
	if(freopen("key.xxh","r",stdin)==NULL){
		freopen("key.xxh","w",stdout);
		for(int i=0;i<9;i++){
			printf("0");
		}
		len=0;
		return false;
	}
	freopen("key.xxh","r",stdin);
	char lin[maxe],shi[maxe];
	scanf("%s",lin);
	back(lin,shi);
	int linshi=strlen(shi);
	for(int i=0;i<linshi;i++){
		int z=shi[i]-'0';
		for(int zl=0;zl<i;zl++){
			z*=10;
		}
		len+=z;
	}
	if(len<=0)return false;
	for(int i=0;i<len;i++){
		scanf("%s%s%s",a[i],b[i],c[i]);
	}
	return true;
}
