void come(char in[maxe],char out[maxe]){
	int len=strlen(in);
	for(int zl=0,i=0;zl<len;zl++){
		int lin=in[zl],shi=in[zl];
		lin*=shi*shi;
		lin+=shi*2;
		lin*=3;
		lin+=6;
		for(int z=0;z<9;z++){
			out[i]=lin%10+'0';
			lin/=10;
			i++;
		}
	}
}
