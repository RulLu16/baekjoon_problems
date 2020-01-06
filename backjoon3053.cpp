#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

double taxi(int);
double uclid(int);

int main(){
	int r;
	scanf("%d",&r);
	
	printf("%lf\n%lf\n",uclid(r),taxi(r));
}

double taxi(int r){
	double result;
	result=(r*r)*2;
	
	return result;
}

double uclid(int r){
	double result;
	result=r*r*M_PI;
	
	return result;
}
