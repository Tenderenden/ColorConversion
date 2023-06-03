#include <iostream>
//#include <math.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main()
{
    int R = 213, G = 100, B = 32;
    cout << "RGB -> HSL" << endl;
    RGB2HSL(R, G, B);
    cout << "HSL -> RGB" << endl;
    float H = 360.0, S = 0.8, L = 0.12;
    HSL2RGB(H, S, L);
	
    return 0;
}