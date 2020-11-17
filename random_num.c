#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int random_number(){
	int num[1];

	int random_file = open("/dev/random",O_RDONLY);

	if (random_file == -1){
		printf("Open Error %d: Message: %s\n", errno, strerror(errno));
		return -1;
	}

	int error = read(random_file, num, sizeof(num[1]));

	if (error == -1){
		printf("Read Error %d: Message: %s\n", errno, strerror(errno));
		return -1;
	}

	close(random_file);
	return *num;
}

void print_array(int *array){
	int i;

	for (i = 0; i < 10; i++){
		printf("\trandom %d: %d\n", i, array[i]);
	}
}
