#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


struct inode {
    int id;
    int counter;
    int file_count;
    char files[100][100];
};

struct inode my_inodes[10000];
int count = 0;

void add(int inode_number, char *filename) {
    for (int i = 0; i < count; ++i) {
        if (my_inodes[i].id == inode_number) {
            my_inodes[i].counter++;
            my_inodes[i].file_count++;
            strcpy(my_inodes[i].files[my_inodes[i].file_count - 1], filename);
            return;
        }
    }

    struct inode new_inode;
    new_inode.id = inode_number;
    new_inode.counter = 1;
    new_inode.file_count = 1;
    strcpy(new_inode.files[new_inode.file_count - 1], filename);
    my_inodes[count] = new_inode;
    count++;
}

int main() {

    struct dirent *current_file;
    DIR *scnning_directory;

    struct stat *buf;

    scnning_directory = opendir("tmp");

    while ((current_file = readdir(scnning_directory)) != NULL) {
        buf = malloc(sizeof(struct stat));
        char file_name[100] = "tmp";
        strcat(file_name, "/");
        strcat(file_name, current_file->d_name);
        stat(file_name, buf);
        
        add(buf->st_ino, current_file->d_name);
        struct stat s = {};
      
        free(buf);
    }
    
    for (int i = 0; i < count; ++i) {
        if (my_inodes[i].file_count < 2)
            continue;

        printf("inode %d appar %d times:\n", my_inodes[i].id, my_inodes[i].file_count);
        for (int j = 0; j < my_inodes[i].file_count; ++j) {
            printf("   %s\n", my_inodes[i].files[j]);
        }
    }
    return 0;

}  
