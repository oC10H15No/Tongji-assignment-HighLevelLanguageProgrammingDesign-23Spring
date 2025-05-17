/* 2351050 ÑîÈð³¿ ÐÅ05 */
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

const int MAX_X = 80;
const int MAX_Y = 100;


int main() {
   int bomb[MAX_Y][MAX_X] = { 0 };

    srand((unsigned int)(time(0)));
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            bomb[i][j] = fabs(rand() % 2);
        }
        
    }

    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            cout << bomb[i][j];
        }

    }

    return 0;
}
