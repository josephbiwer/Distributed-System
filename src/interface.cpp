#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {


	std::cout << "C++ application running\n";

	char buffer[256];
	strcpy(buffer, "c++ application pipe write");

	std::cout << "write fd: " << atoi(argv[1]) << std::endl;

	write(atoi(argv[1]), buffer, 256);
	
	return 0;
}
