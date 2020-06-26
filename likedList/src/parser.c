#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int ret = -1;
	char buffer[4][100];
	int r;
	Employee *auxEmp;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		do {
			r = fscanf(pFile, "%[^,] , %[^,] , %[^,] , %[^\n]\n", buffer[0],
					buffer[1], buffer[2], buffer[3]);
			if (r != 4) {
				printf("\nError while trying to read the file");
			} else {
				auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2],
						buffer[3]);
				if (auxEmp != NULL) {
					ll_add(pArrayListEmployee, auxEmp);
				}
			}
		} while (!feof(pFile));
		ret = 0;
	} else {
		printf("Error\n");
	}
	return ret;
}
/*
 int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
 int ret = -1;
 Employee *auxEmp;
 int r;

 if (pFile != NULL && pArrayListEmployee != NULL) {
 do {
 auxEmp = employee_new();
 r = fread(auxEmp, sizeof(auxEmp), 1, pFile);
 if (r != 1) {
 printf("\nError while trying to read the file");
 } else {
 ll_add(pArrayListEmployee, auxEmp);
 ret = 0;
 }
 } while (!feof(pFile));
 } else {
 printf("\nError");
 }

 return ret;
 }
 */
