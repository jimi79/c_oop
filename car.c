#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "car.h"

Car *Car_Create(char *name) {
	Car *res;
	res = malloc(sizeof(Car));
	res->name = malloc(sizeof(name) * sizeof(char));
	res->next = NULL;
	strcpy(res->name, name); 
	//res->name = name; // bad, but works surprisingly
	printf("Creating car %s\n", res->name);
	return res;
}

void Car_Destroy(Car *car)  {
	printf("Destroying car %s\n", car->name);
	free(car);
}

void Car_PrintName(Car *car) {
	printf("Car's name is %s\n", car->name);
}

Cars *Cars_Create(int ownObjects) {
	Cars *res;
	res = malloc(sizeof(Cars));
	res->cars = NULL;
	res->ownObjects = ownObjects;
	return res;
}

void Cars_Destroy(Cars *cars) {
	if (cars->ownObjects) {
		Car* c = cars->cars;
		Car* t;
		while (c != NULL) {
			t = c; 
			c = c->next;
			Car_Destroy(t);
		}
	}

	free(cars);
} 

void Cars_Add(Cars *cars, Car *car) {
	if (cars->cars == NULL) {
		cars->cars = car;
	} else {
		Cars_GetLast(cars)->next = car;
	}
}

void Cars_Del(Cars *cars, Car *car) {
	Car* c;
	Car* prev = NULL;
	c = cars->cars;
	while (c != NULL) {
		if (c == car) {
			if (prev == NULL) {
				cars->cars = cars->cars->next;
			} else {
				prev->next = c->next;
			}
			if (cars->ownObjects) {
				Car_Destroy(c);
			}
			break;
		} 
		prev = c;
		c = c->next;
	} 
}

void Cars_PrintNames(Cars *cars) {
	Car* c = cars->cars;
	while (c != NULL) {
		Car_PrintName(c);
		c = c->next;
	}
}

void Cars_DelByName(Cars *cars, char *name) {
	cars->cars = NULL;
	printf("%s", name);
}

Car *Cars_GetLast(Cars *cars) {
	Car* c = cars->cars;
	if (c != NULL) {
		while (c->next != NULL) {
			c = c->next;
		}
	}
	return c; 
}
