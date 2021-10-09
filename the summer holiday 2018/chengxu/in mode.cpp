void in(int&len,char a[maxe][maxe],char b[maxe][maxe],char c[maxe][maxe]){
	char lin[maxe];
	scanf("%s",lin);
	come(lin,a[len]);
	scanf("%s",lin);
	come(lin,b[len]);
	scanf("%s",lin);
	come(lin,c[len]);
	len++;
}
