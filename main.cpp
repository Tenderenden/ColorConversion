#include <iostream>
#include <math.h>
#include <stdint.h>
#include <algorithm>
using namespace std;

typedef struct RGB_Color
{
	int R;
	int G;
	int B;
}RGB_Color;

typedef struct HSL_Color
{
	int H;
	int S;
	int L;
}HSL_Color;

void RGBToHSL(int R, int G, int B);

void HSLToRGB(int H, int S, int L);

int main()
{
    int R, G, B;
    int H, S, L;
    RGBToHSL(R, G, B);
    HSLToRGB(H, S, L);
	return 0;
}

void RGBToHSL(int R, int G, int B)
{
	//Using algorithm from:
	//had2know.org/technology/hsv-rgb-conversion-formula-calculator.html
}

void HSLToRGB(int H, int S, int L)
{
	cout<<"Convert HSL to RGB"<<endl;
}
