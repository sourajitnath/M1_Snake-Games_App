// Function to draw the boundaries
#include <stdio.h>   // Required for printf()
#include <stdlib.h>  // Required for system()

// Define global variables
int height = 20, width = 40;
int x, y, fruitx, fruity;

void draw()
{
    system("cls"); // Clears the console (use "clear" for Linux/Mac)

    int i, j; // Declare loop variables

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");  // Boundary
            }
            else {
                if (i == x && j == y)
                    printf("0");  // Player
                else if (i == fruitx && j == fruity)
                    printf("*");  // Fruit
                else
                    printf(" ");  // Empty space
            }
        }
        printf("\n");
    }
}

int main() {
    x = height / 2;  // Initialize player position
    y = width / 2;
    fruitx = rand() % (height - 2) + 1;  // Avoid placing on the border
    fruity = rand() % (width - 2) + 1;

    draw(); // Call the draw function

    return 0;
}

       
