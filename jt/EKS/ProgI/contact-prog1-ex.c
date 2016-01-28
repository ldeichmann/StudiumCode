/*
* contact.c
*
*  Created on: 10.01.2016
*      Author: ansch
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Contact_ {
	char firstName[20];
	char lastName[20];
	int age;
	struct Contact_* next;
} Contact;

typedef Contact* PContact;

PContact addContact(PContact root);
void printContactList(PContact pcontact);
void freeList(PContact root);
void getContactInfo(PContact newContact);

int main(void) {
	PContact root = NULL;
	int stop = 0;
	while (stop == 0) {
		root = addContact(root);
		printf("Stop? J");
		stop = (getchar() == 'J');
		while (getchar() != '\n')
			;
	}
	printContactList(root);
	freeList(root);
}

void getContactInfo(PContact newContact) {
	printf("Vorname: ");
	fgets(newContact->firstName, 20, stdin);
	newContact->firstName[strcspn(newContact->firstName,
		"\n")] = 0;
}

PContact addContact(PContact root) {
	PContact newContact = malloc(sizeof(Contact));
	if (newContact == NULL)
		exit(1);
	getContactInfo(newContact);
	newContact->next = root; // vorne einhaengen
	return newContact;
}

void printContactList(PContact root) {
	PContact pcontact = root;
	while (pcontact != NULL) {
		printf("Name: %s\n", pcontact->firstName);
		pcontact = pcontact->next;
	}
}