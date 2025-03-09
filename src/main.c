#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAXITERS 100

const char WHITE[] = "255 255 255";
const char BLACK[] = "0 0 0";

typedef struct {
	double real;
	double imag;
} point;

point iterate(point pt, point c);

char fileName[] = "image.ppm";
int main(){
	FILE *fp = fopen(fileName, "wb");

	fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
	int iters;
	point initPoint = {0.0, 0.0};
	for(int i = -WIDTH/2; i < WIDTH/2; i++){
		for(int j = -HEIGHT/2; j < HEIGHT/2; j++){
			iters = 0;
			point thisPixel = {(double)i/(WIDTH/4), (double)j/(HEIGHT/4)};
			point currPoint = initPoint;
			while (iters < MAXITERS && (sqrt(currPoint.real*currPoint.real + currPoint.imag*currPoint.imag) < 2)){
				currPoint = iterate(currPoint, thisPixel);
				iters++;
			}
			if(sqrt(pow(currPoint.real, 2) + pow(currPoint.imag, 2)) > 2){
				fprintf(fp, "%s\n", WHITE);
			}else{
				fprintf(fp, "%s\n", BLACK);
			}
		}
	}
}

point iterate(point pt, point c){
	point currPoint;
	double r = pt.real;
	double i = pt.imag;
	currPoint.real = r*r - i*i + c.real;
	currPoint.imag = i*r + i*r + c.imag;
	return currPoint;
}
