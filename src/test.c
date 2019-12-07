#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	printf("this is a test from the test program\n");	

	int i;
	for(i = 0; i < argc; i++) {
		printf(" - %s\n", argv[i]);
	}

	// Sending data across pipe
	char buffer[256];
	strcpy(buffer, "this is a test");
	printf("buffer: %s\n", buffer);
	printf("sizeof(buffer): %lu\n", sizeof(buffer)/sizeof(char));

	write(atoi(argv[1]), buffer, sizeof(buffer)/sizeof(char));

	return 0;
}
