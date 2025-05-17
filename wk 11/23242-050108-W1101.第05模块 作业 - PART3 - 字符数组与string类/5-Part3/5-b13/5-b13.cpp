/* 2351050 ÑîÈð³¿ ÐÅ05 */
#include <iostream>
#include <time.h>
using namespace std;

const int MAX_X = 26;
const int MAX_Y = 10;

int countBomb(char bomb[MAX_Y][MAX_X], int y, int x) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newY = y + i;
            int newX = x + j;
            if (newY >= 0 && newY < MAX_Y && newX >= 0 && newX < MAX_X && bomb[newY][newX] == '*') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char bomb[MAX_Y][MAX_X] = { 0 };

    srand((unsigned int)(time(0)));
    for (int k = 0; k < 50; k++) {
        int y = rand() % MAX_Y;
        int x = rand() % MAX_X;

        if (bomb[y][x] == '*') {
            k--;
        }
        else {
            bomb[y][x] = '*';
        }
    }

    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (bomb[i][j] != '*') {
                int count = countBomb(bomb, i, j);
                bomb[i][j] = count + '0';
            }
        }
    }

    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            cout << bomb[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}