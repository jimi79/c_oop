#ifndef __CAR_H__
#define __CAR_H__

typedef struct Car {
	char *name; 
	struct Car *next;
} Car; 
Car *Car_Create(char *name);
void Car_Destroy(Car *car);
void Car_PrintName(Car *car);

typedef struct Cars {
	Car *cars; // chained list
	int ownObjects;
} Cars; 
Cars *Cars_Create(int ownObjects);
void Cars_Destroy(Cars *cars);
void Cars_Add(Cars *cars, Car *car);
Car *Cars_GetLast(Cars* cars);
void Cars_Del(Cars *cars, Car *car);
void Cars_DelByName(Cars *cars, char *name);
void Cars_PrintNames(Cars *cars);

#endif

