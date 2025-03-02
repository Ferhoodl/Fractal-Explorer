#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100 
#define HEIGHT 100 
#define MAXITERS 200;
#define BLACK "256 255 255"
#define WHITE "0 0 0"
typedef struct {
	double real;
	double imag;
} point;

char[] fileName = "image.ppm";
int main(){
	FILE *fp = fopen(fileName, "wb");

	fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
	int iters = 0;
	int val = 0;
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			while (iters < MAXITERS){
				iters++;

			}
			iters = 0;
			val = 0;
		}
	}
}

iterate(point *pt, point c){
	int r = pt->real;
	int i = pt->imag;
	pt->real = r*r - i*i + c.real;
	pt->imag = i*r + i*r + c.imag;
}
