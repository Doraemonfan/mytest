#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("usage: %s <address>\n", argv[0]);
		exit(0);
	}
	uint32_t dec;
	if (strlen(argv[1]) != 10 ||
			sscanf(argv[1], "%x", &dec) != 1) {
		printf("address error!\n");
		exit(0);
	}

	uint32_t d[4];
	int ct = 4;
	while (dec != 0) {
		d[--ct] = dec % 256;
		dec /= 256;
	}
	printf("%u.%u.%u.%u\n", d[0], d[1], d[2], d[3]);

	return 0;
}


