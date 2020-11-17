#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "random_num.h"

int main(){
	// array with random numbers using random_number()
	int arr[10];
	int i;
	printf("Generating random numbers:\n");
	for(i = 0; i < 10; i++){
		arr[i] = random_number();
	}

	//prints the array with random numbers
	print_array(arr);

	printf("\nWriting numbers to file...\n\n");
	int write_file = open("text.txt", O_CREAT | O_WRONLY, 0664);
	if (write_file == -1){
        	printf("Open failed. Error: %d -> %s\n", errno, strerror(errno));
        	return -1;
    	}

	int write_check = write(write_file, arr, sizeof(arr));
	//checking return value
	if (write_check == -1){
        	printf("Write failed. Error: %d -> %s\n", errno, strerror(errno));
        	return -1;
	}

	close(write_file);

	int new_arr[10];
	printf("Reading numbers from file...\n\n");
 	int read_file = open("text.txt", O_RDONLY);
	if (read_file == -1){
                printf("Open failed. Error: %d -> %s\n", errno, strerror(errno));
                return -1;
        }
	int read_check = read(read_file, new_arr, sizeof(new_arr));
	//checking return value
	if (read_check == -1){
		printf("Read Failed. Error: %d -> %s\n", errno, strerror(errno));
        	return -1;
	}

	printf("Verification that written values were the same:\n");
	print_array(new_arr);

	close(read_file);

	return 0;
}
