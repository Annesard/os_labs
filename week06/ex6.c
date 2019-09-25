#include <zconf.h>
#include <stdio.h>
#include <signal.h>


int main() {
    pid_t first_child_id, second_child_id;

    int pipe_data[2];

    pipe(pipe_data);

    first_child_id = fork();

    if (first_child_id > 0) {
       
        second_child_id = fork();

        if (second_child_id > 0) {
            
            close(pipe_data[0]);

            printf("First child:  %d\n", first_child_id);
            printf("Second child: %d\n", second_child_id);

            write(pipe_data[1], &second_child_id, sizeof(second_child_id));
            close(pipe_data[1]);

            waitpid(second_child_id, NULL, NULL);

            printf("Child 2 is killed. Data in the pipe.\n");

        } else if (!second_child_id) {
            // second child
            printf("Second child is alive\n");
            while (1);
        }

    } else {
        
        printf("First child is alive\n");
        close(pipe_data[1]);

        int second_pid = 0;

        printf("first child is waiting for data in the pipe...\n");
        read(pipe_data[0], &second_pid, sizeof(second_pid));


        kill(second_pid, SIGSTOP);
        printf("Second children PID was: %d\n", second_pid);

    }

    return 0;


}
