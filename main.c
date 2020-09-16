#include <stdlib.h>
#include <stdio.h>
#include "car.h" 

int main() {
	int ownObjects = 1; // try with 0 if you wnat

	Car* cars[20];
	Cars* cars2 = Cars_Create(ownObjects);

	char s[20];
	for (int i = 0; i < 10; i++) {
		sprintf(s, "test %d", i);
		cars[i] = Car_Create(s);
		Cars_Add(cars2, cars[i]);
	}

	printf("Printing individual names\n");
	Car_PrintName(cars[1]);
	Car_PrintName(cars[2]);
	Car_PrintName(cars[5]);


	printf("Printing list\n");
	Cars_PrintNames(cars2);

	printf("Removing a car\n");
	Cars_Del(cars2, cars[2]); // also do a free if ownobject = true
	Cars_PrintNames(cars2);

	if (!ownObjects) {
		for (int i = 0; i < 10; i++) {
			Car_Destroy(cars[i]);
		}
	} 
	Cars_Destroy(cars2);
}
