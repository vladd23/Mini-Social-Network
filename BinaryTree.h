#pragma once
#include <iostream>

using namespace std;
template <class T>
class BinaryTree
{
private:

	T eventt;
	BinaryTree* left, * right;
	
public:
	
	//Functie care creeaza un nod nou cu informatia fiind elementul T dat ca si parametru
	BinaryTree* createNewNode(T eventParam) {
		BinaryTree* newNode = new BinaryTree();
		newNode->eventt = eventParam;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	
	//Functie care insereaza un element dat ca parametru pe pozitia corespunzatoare
	BinaryTree* insertElement(BinaryTree* rootP, T eventParam)
	{
		if (!rootP) {
			rootP = createNewNode(eventParam);
			return rootP;
		}
		else if (eventParam > rootP->eventt) {
			rootP->right = insertElement(rootP->right, eventParam);
		}
		else if (eventParam < rootP->eventt)
			rootP->left = insertElement(rootP->left, eventParam);
		
		return rootP;
	}

	//Functie care afiseaza elementele arborelui in ordine
	void inOrderShow(BinaryTree* root)
	{
		if (!root) {
			return;
		}
		inOrderShow(root->left);
		cout << root->eventt << endl;
		inOrderShow(root->right);
	}
	
	//Functie care determina minimul de pe partea dreapta a arborelui binar
	BinaryTree* findMin(BinaryTree* root) {
		while (root->left != NULL) root = root->left;
		return root;
	}

	//Functie care sterge un element dat ca parametru 
	BinaryTree* deleteElement(BinaryTree* root, T elem) {
		if (!root) return root;
		else if (elem < root->eventt) root->left = deleteElement(root->left, elem);
		else if (elem > root->eventt) root->right = deleteElement(root->right, elem);
		else { // adica l am gasit si vrem sa facem stergerea propriu zisa

			//cazul 1: nu are frunze
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
			}

			// cazul 2: are o frunza
			// a) pe dreapta
			else if (root->left == NULL) {
				BinaryTree* aux = root;
				root = root->right;
				delete aux;
			}
			// b) pe stanga
			else if (root->right == NULL) {
				BinaryTree* aux = root;
				root = root->left;
				delete aux;
			}
			// cazul 3, are 2 frunze
			else {
				BinaryTree* minim = findMin(root->right);
				root->eventt = minim->eventt;
				root->right = deleteElement(root->right, minim->eventt);
			}

		}
		return root;
	}
};


