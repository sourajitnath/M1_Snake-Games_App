// C program to build the outline
// boundary using draw()
#include <stdio.h>
#include <stdlib.h>

int i, j, height = 30;
int width = 30, gameover, score;

// Function to draw a boundary
void draw()
{
    system("cls"); 

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    draw();
    return 0;
}
