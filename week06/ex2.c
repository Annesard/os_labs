#include <stdio.h>
#include <zconf.h>

int main() {
    char first[] = "I am a string";
    char second[100];
    int pipe_data[2];

    pipe(pipe_data);

    int process_id = fork();
    if (process_id > 0) {
        close(pipe_data[0]); 

        write(pipe_data[1], first, (sizeof(first) + 1));
        close(pipe_data[1]);
    } else if (!process_id) {
        close(pipe_data[1]); 

        read(pipe_data[0], second, sizeof(second));
        printf("%s\n", second);
        close(pipe_data[0]);
    }
    return 0;

}
