// Driver Code
void main()
{
    int m, n;
  
    // Generate boundary
    setup();
  
    // Until the game is over
    while (!gameover) {
  
        // Function Call
        draw();
        input();
        logic();
    }
}
