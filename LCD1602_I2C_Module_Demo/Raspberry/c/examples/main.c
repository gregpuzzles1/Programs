#include "LCD_Test.h" // Examples
#include <math.h>

int main(int argc, char *argv[])
{
    // Check if exactly one argument is passed
    if (argc != 2)
    {
        printf("Please input 1~5.\r\n");
        printf("Example: sudo ./main 1\r\n");
        exit(1);
    }

    double size;
    // Convert the input argument to a double value
    sscanf(argv[1], "%lf", &size);
    size = (fabs(size)); // Get the absolute value of the size

    // Based on the input size, call the corresponding function
    if (size == 1)
        Character_display(); // Function for 1-inch LCD display
    else if (size == 2)
        Custom_char(); // Function for custom character display
    else if (size == 3)
        Direction_control(); // Function for controlling display direction
    else if (size == 4)
        Display_time(); // Function to display time
    else if (size == 5)
        Scroll_display(); // Function to scroll display
    else
        printf("Error: Cannot find the demo\r\n"); // Invalid input
    return 0;
}
