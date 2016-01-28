// binaere Suchbaeume
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode {
	char name[20];
	struct treenode* left;
	struct treenode* right;
} Node;

typedef Node* PNode;

void insertNode(PNode* root, char* name);
void printTree(PNode root);
int containsName(PNode root, char* name);
void freeTree(PNode root);

int main(void) {
	char buffer[20];
	PNode root = NULL;
	while (1) {
		printf("Name (leer fuer Ende):");
		fgets(buffer, 20, stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		if (buffer[0] == '\0')
			break;
		insertNode(&root, buffer);
	};
	printTree(root);
	return 0;
}

// erzeugt neuen Knoten und fuegt in binaeren Suchbaum ein
// erhaelt den Zeiger auf die Wurzel als Referenz (Zeiger auf Zeiger)
// damit die Funktion einen neuen Wurzelknoten erstellen kann

void insertNode(PNode* root, char* name) {
	if (*root == NULL) { // Baum ist leer
		*root = (PNode) malloc(sizeof(Node));
		if (*root != NULL) {
			strcpy((*root)->name, name);
			(*root)->left = NULL;
			(*root)->right = NULL;
		}
	} else {
		if (strcmp(name, (*root)->name) < 0)
			insertNode(&((*root)->left), name); // links einfuegen
		if (strcmp(name, (*root)->name) > 0)
			insertNode(&((*root)->right), name); // rechts einfuegen
	}
}

void printTree(PNode root) {
	if (root == NULL)
		return;
	printTree(root->left);
	printf(" %s ", root->name);
	printTree(root->right);
}

int containsName(PNode root, char* name) {
	if (root == NULL)
		return 0;
	if (strcmp(name, root->name) == 0)
		return 1;
	if (strcmp(name, root->name) < 0)
		return containsName(root->left, name);
	if (strcmp(name, root->name) > 0)
		return containsName(root->right, name);
	return 0;
}

void freeTree(PNode root) {
	// TODO implement freeTree
}
