#include <stdio.h>
#include <stdint.h>

uint8_t n = 89;

// convert to bin
void int_to_bin(uint8_t num) {
	char str[9] = {0};
	for(int i = 7; i >=0; i--) {
		str[i] = (num & 1) ? '1':'0';
		num = num >> 1;
	}

	printf("%d in binary: 0b%s\n",num,  str);
}


int main() {
	//printf("Before shifting: %d\n", n);
	//n = (n >> 1);
	//printf("After shifting: %d\n", n);
	
	int_to_bin(89);

	return 0;
}
