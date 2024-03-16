//Arvin Akbari PROG72370
#include "dst.h"
#define MINCHARS 11
#define MAXCHARS 20
#define NUMOFLETTERS 26

int main(void)
{
	//seeding rand to the current time
	srand(time(NULL));

	//creating a new root and setting it to null
	Node* root = NULL;

	char charSet[] = "abcdefghijklmnopqrstuvwxyz";

	//using the rand function to pick a random number of characters between MINCHARS and MAXCHARS
	int numOfCharacter = rand() % (MAXCHARS + 1 - MINCHARS) + MINCHARS;
	
	printf("inserting %d nodes\n", numOfCharacter);
	printf("Randomly Inserted characters: ");
	
	//for loop that randomly selects a character in charset, and inserts the character into the tree
	for (int i = 0; i < numOfCharacter; i++)
	{
		char randomChar = charSet[rand() % NUMOFLETTERS];
		printf("%c ", randomChar);
		root = insert(root, randomChar);
	}
	printf("\n");

	//calling traversal function
	printf("In order traversal: ");
	inOrderTraversal(root);
	printf("\n");

	//calling count node function
	int totalNodes = countNodes(root);
	printf("Total nodes: %d\n", totalNodes);

	//calling treeHeight function
	int height = treeHeight(root);
	printf("Tree height: %d\n", height);

	//freeing the tree
	freeTree(root);
	return 0;
}