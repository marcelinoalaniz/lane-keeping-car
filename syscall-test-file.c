#include <syscall.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #define SYS_COUNTER 452  // My syscall is 452 in syscall_64.tbl
 int main(int argc, char *argv[]) {
    int reset_flag = 0;    // By default, do not reset
    int increment = 1;     // By default, increment by 1
    int initial_value = -1; // "no explicit initial value"
    printf("Counter syscall called\n"); // Prints every time the syscall is called
    // Processing the reset flag
    if (argc >= 2) {
        reset_flag = atoi(argv[1]); // Convert the string to an integer
        if (reset_flag != 0 && reset_flag != 1) { // If the input is not 0 or 1, it
 is invalid
            printf("Input was invalid\n");
            return 1;
        }
    }
    // Processing the increment value
    if (argc >= 3) { // If increment value is provided, convert it to an integer
        increment = atoi(argv[2]);
    }
    // Process third argument: initial value if provided
    if (argc >= 4) { 
        initial_value = atoi(argv[3]); // Convert the string to an integer
    }
    // If reset flag is set, ignore other arguments and reset counter.
    if (reset_flag == 1) {
        syscall(SYS_COUNTER, 1, 0, 0);
    } else {
        // When initial_value is not provided (i.e. remains -1),
        // the system call should simply increment the current persistent counter.
        syscall(SYS_COUNTER, 0, increment, initial_value); // doing the actual 
incrememnting
    }
    return 0;
 }
