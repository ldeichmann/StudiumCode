/*
 * tasks.c
 *
 *  Created on: 22.04.2015
 *      Author: ansch
 */

#include <time.h>
#include <stdio.h>
#include "tasks.h"

void printID(int taskid){
	printf("id: %d\n", taskid);
}

void printHello(int taskid){
	printf("Hello\n");
}

void printDate(int taskid){
	time_t t = time(NULL);
	printf("%s", ctime(&t));
}
