#include <stdio.h>

int main() {
	// bit hack number 1 -> check if integer is odd or off
	int x = 45; // 0b 00101101  
		   
	if((x & 1) == 0){
		// integer is even
		printf("EVEN");
	} else {
		// integer is odd
		printf("ODD");
	}


	// bit hack number 2 -> test if n-th bit is set 
	int n = 5;
	if(x & (1<<n)){
		printf("Bit %d is set\n", n);

	} else {
		printf("bit %d is not set\n", n);
	}


	// bit hack number 3 -> set the n-th bit 
	int a = 3;
	int b = 129; // 0b 1000 0001
	printf("Old set value: %d\n", b);
	b = b | (1<<a);
	printf("New set value: %d\n", b); // expected value 137 -> 0b1000 1001
	

	// bit hack number 4 -> clear the n-th bit 
	int y = 89;
	int j = 4;
	
	printf("Before clearing bit %d: %d\n", j, y);
	y &= ~(1<<j);

	printf("After clearing bit %d: %d\n", j, y);
	
	// bit hack number 5 -> toggle the n-th bit 
	int i = 34;
	int h = 2; 
	i ^= (1<<h);

	// bit hack number 6 -> turn off the righttmost 1-bit 
	y = 78; //0b 0100 1110
	y &= (y-1);

	// bit hack number 7 -> 
	

	
	

	return 0;

}
