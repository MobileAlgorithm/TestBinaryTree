//
//  main.cpp
//  TestStack
//
//  Created by Lin, Forrest on 1/30/15.
//  Copyright (c) 2015 Lin, Forrest. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

void inOrder_traverse(Node* root){
    if (root->left != NULL ) {
        inOrder_traverse(root->left);
    }
    
    std::cout << "node " << root->value << std::endl;
    
    if (root->right) {
        inOrder_traverse(root->right);
    }
}

void postOrder_traverse(Node* root){
   
    if (root->left != NULL ) {
        postOrder_traverse(root->left);
    }

    if (root->right != NULL) {
        postOrder_traverse(root->right);
    }
    
    std::cout << "node " << root->value << std::endl;

}

void preOrder_traverse(Node* root){
    
    cout << "node " << root->value << endl;

    
    if (root->left != NULL ) {
        preOrder_traverse (root->left);
    }
    
    if (root->right != NULL ) {
        preOrder_traverse (root->right);
    }

}


//

Node* generateBTfromSortedArray(int array[],int size){

    Node *root = new Node;
    
    int center = size/2;
    root->value = array[center];
    cout << "value: "<< root->value <<endl;
    
    if (center == 0 ) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    if (center>0) {
        root->left = generateBTfromSortedArray(array, center);
    }
    
    if (size-center-1 > 0) {
        root->right = generateBTfromSortedArray(&(array[center+1]), size-center-1);
    }
    return root;
}

void testCase1OrderAlgorithm(){
    /**
     10
     
     6       20
     
     1       8
     
     
     
     
     */

     
     Node node6;
     Node node20;
     
     Node root;
     root.value = 10;
     root.left = &node6;
     root.right = &node20;
     root.parent = NULL;
     
     
     Node node1;
     node1.left = NULL;
     node1.right = NULL;
     node1.value = 1;
     node1.parent = &node6;
     
     Node node8;
     node8.value = 8;
     node8.left = NULL;
     node8.right = NULL;
     node8.parent = &node6;
     
     node6.parent = &root;
     node6.value = 6;
     node6.left = &node1;
     node6.right = &node8;
     
     
     node20.parent = &root;
     node20.value = 20;
     node20.left = NULL;
     node20.right = NULL;
     
     
     // pre- in- post- order travel algorithm
     //
     //
     
     preOrder_traverse(&root);
     
     
     inOrder_traverse(&root);
     
     
     postOrder_traverse(&root);
     

}

void testCase2GenerateBT(){
    
    //Given a sorted array, generate binary tree
    //
    //
    
    int sortedArray1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    
    cout<< "array size "<< sizeof(sortedArray1)/sizeof(int)<<endl;
    cout << "int " <<sizeof(int)<<endl;
    
    Node *root = generateBTfromSortedArray(sortedArray1,7);
    
//    preOrder_traverse(root);
    
//    inOrder_traverse(root);
    
    postOrder_traverse(root);

}

int main(int argc, const char * argv[]) {
    
    
    testCase2GenerateBT();

    
    
    return 0;
}
