#define R(k,l)(a[k][l]-!!P*a[P-1][l]-!!p*a[k][p-1]+(P&&p)*a[P-1][p-1])
a[12][1234],i,j,k,C,p,P,g,f,A,h,w,K,r;
main(){
	scanf("%d%d%d",&h,&w,&K);
	for(;i<h;++i)
	for(j=0;j<w;scanf(" %c",&A),a[i][j]=A-48+!!i*a[i-1][j]+!!j*a[i][j-1]-(i&&j)*a[i-1][j-1],++j);
	for(A=h+w-2,i=0;i<1<<(h-1);A=!g&&C<A?C:A,++i)
		for(C=__popcountdi2(i),p=g=j=0;j<w;++j){
			for(f=P=k=0;k<h-1;++k)
				if(i&(1<<k))g|=(f|=R(k,j)>K)&&R(k,j-1)>K,P=k+1;
			if(R(h-1,j)>K||f)g|=R(h-1,j-1)>K,p=j,++C;
		}
	printf("%d",A);
}