#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("usage: %s <address>\n", argv[0]);
		exit(0);
	}
	uint32_t d[4];
	if (sscanf(argv[1], "%u.%u.%u.%u", 
			&d[0], &d[1], &d[2], &d[3]) != 4) {
		printf("address error!\n");
		exit(0);
	}
	uint32_t hex = 0;
	for (int i = 0; i < 4; ++i) 
		hex = hex * 256 + d[i];
	printf("%#x\n", hex);

	return 0;
}
