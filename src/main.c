#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10000
#define HEIGHT 10000
#define MAXITERS 200

const char WHITE[] = "255 255 255";
const char BLACK[] = "0 0 0";

typedef struct {
	double real;
	double imag;
} point;

point initPoint = {0.0, 0.0};

point iterate(point pt, point c);

char fileName[] = "image.ppm";
int main(){
	FILE *fp = fopen(fileName, "wb");
	fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
	int iters;
	for(double i = 0; i < HEIGHT; i++){
		for(double j = 0; j < WIDTH; j++){
			iters = 0;
			point thisPixel = {
			-2.0 + j / WIDTH * 3.0,
			-1.5 + i / HEIGHT * 3.0};
			point currPoint = initPoint;

			while (iters < MAXITERS && (currPoint.real*currPoint.real + currPoint.imag*currPoint.imag) < 4){
				currPoint = iterate(currPoint, thisPixel);
				iters++;
			}

			if(iters == MAXITERS) {
				fprintf(fp, "%s\n", BLACK);
			}else{
				fprintf(fp, "%s\n", WHITE);
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
