#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int gcd(int a, int b){
	int c;
	
	while(b){
		c = a%b;
		a = b;
		b = c;
	}
	
	return a;
}

int main(){
	int gox, goy;
	int stopx, stopy;
	int x, y;
	int rx, ry;
	
	scanf("%d %d", &stopx, &stopy);
	scanf("%d %d %d %d", &x, &y, &gox, &goy);
	
	if(gox == 0 && goy == 0) {
		printf("%d %d\n", x, y);
		return 0;
	}
	
	int g = gcd(gox, goy);
	if(g < 0) g = -g;
	gox /= g; goy /= g;
	
	double distance = sqrt((x-stopx)*(x-stopx) + (y - stopy)*(y - stopy));
	rx = x; ry = y;
	
	while(1){
		x += gox;
		y += goy;
		
		double tmp = sqrt((x-stopx)*(x-stopx) + (y - stopy)*(y - stopy));
		
		if(distance < tmp){
			printf("%d %d\n", rx, ry);
			break;
		}
		
		distance = tmp;
		rx = x; ry = y;
	}
}
