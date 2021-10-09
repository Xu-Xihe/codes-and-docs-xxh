void back(char in[maxe],char out[maxe]) {
	int len=strlen(in)/9;
	for(int i=0,zl=0;zl<len;zl++){
		int lin=0;
		for(int zll=0;zll<9;zll++){
			int a=in[i]-'0';
			for(int zlll=0;zlll<zll;zlll++){
				a*=10;
			}
			lin+=a;
			i++;
		}
		lin-=6;
		lin/=3;
		for(int linshi=0;linshi<200;linshi++){
			int shi=linshi;
			shi*=shi;
			shi*=linshi;
			shi+=linshi*2;
			if(shi==lin){
				out[zl]=linshi;
				break;
			}
		}
	}
}
