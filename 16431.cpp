#include <stdio.h>
#include <stdlib.h>

int maxVal(int a, int b){
	if(a<b) return b;
	else return a;
}

int main(){
	int bessiX, bessiY;
	int daisyX, daisyY;
	int johnX, johnY;
	int bessiMove, daisyMove;
	
	scanf("%d %d",&bessiX, &bessiY);
	scanf("%d %d",&daisyX, &daisyY);
	scanf("%d %d",&johnX, &johnY);
	
	bessiMove=maxVal(abs(johnX-bessiX),abs(johnY-bessiY));
	daisyMove=abs(johnX-daisyX)+abs(johnY-daisyY);
	
	if(bessiMove<daisyMove) printf("bessie\n");
	else if(bessiMove>daisyMove) printf("daisy\n");
	else printf("tie\n");
}

