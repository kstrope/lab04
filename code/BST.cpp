#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
	root->left == NULL;
	root->right == NULL;
	root->parent == NULL;
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  delete root;
}

void BST::Insert(int toInsert) {
  Node *x = new Node;
  Node *y = new Node;
  Node *z = new Node;
  y = NULL;
  x = root;
  z->val = toInsert;
  z->left = NULL;
  z->right = NULL;
  while (x != null){
	  y = x;
	  if (toInsert < x->val)
		  x = x->left;
	  else x = x->right;
  }
  z->parent = y;
  if (y == NULL)
	  root = z;
  else if (z->val < y->val)
	  y->left = z;
  else y->right = z;
}



void BST::Delete(int toDelete) {
  Node *x = new Node;
  Node *y = new Node;
  x = Search(toDelete);
  if (x->left == NULL)
	  Transplant(x, x->right);
  else if (x->right == NULL)
	  Transplant(x, x->left);
  else{
	  y = Minimum(x->right);
	  if (y->parent != x){
		  Transplant(y, y->right);
		  y->right = x->right;
		  y->right->parent = y;
	  }
	  Transplant(x, y);
	  y->left = x->left;
	  y->left->parent = y;
  }
}

void BST::Transplant(Node *u, Node *v) {
  if (u->parent == NULL){
	  root = v;
  }
  else if (u == u->parent->left){
	  u->parent->left = v;
  }
  else u->parent->right = v;
  if (v != NULL)
	  v->parent = u->parent;
}

Node *BST::Successor(Node *x) {
  if (x->right != NULL)
	  return Minimum(x->right);
  Node *y = new Node;
  y = x->parent;
  while (y != NULL && x == y->right){
	  x = y;
	  y = y->parent;
  }
  return y;
}

Node *BST::Minimum(Node *x) {
  while (x->left != NULL){
	  x = x->left;
  }
  return x;
}

Node *BST::Maximum(Node *x) {
  while (x->right != NULL){
	  x = x->right;
  }
  return x;
}

Node *BST::Search(int toFind) {
	Node* x = new Node;
	x = root;
	while (x != NULL && toFind != x->val){
		if (toFind < x->val)
			x = x->left;
		else x = x->right;
	}
	return x;
}

void BST::Print(TraversalOrder Order) {
  if(Order==InOrderTrav)
    InOrder(root);
  else if(Order==PreOrderTrav)
    PreOrder(root);
  else if(Order==PostOrderTrav)
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
  if (x != NULL){
	  cout << x->val << endl;
	  PreOrder(x->left);
	  PreOrder(x->right);
  }
}

void BST::InOrder(Node *x) {
  if (x != NULL){
	  InOrder(x->left);
	  cout << x->val << endl;
	  InOrder(x->right);
  }
}

void BST::PostOrder(Node *x) {
  if (x != NULL){
	  PostOrder(x->left);
	  PostOrder(x->right);
	  cout << x->val << endl;
  }
}

