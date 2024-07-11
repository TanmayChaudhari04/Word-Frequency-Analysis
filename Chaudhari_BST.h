/*
Author: Tanmay Chaudhari
Date: 26 November, 2022 
Description: Word Frequency Analysis – Binary Search Tree
Usage: <exe>
*/
#include "Node.h"
#include "WordEntry.cpp"
#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>

class BinarySearchTree
{
    public:
        //Node Object
        Node<T>* rootOfTree;

        //Constructor
        BinarySearchTree();

        //Destructor
        ~BinarySearchTree();

        //Insert Function Declaration 
        Node<T>* Insert(Node<T>* newNode, T data);
        //Overloaded Insert Function
        void Insert(T data);

        //Remove Function Declaration
        Node<T>* Remove(Node<T>* root, T data);
        //Overloaded Remove Function
        void Remove(T data);

        //Element Exist Function Declaration
        bool ElementExists(Node<T>* root, T data);
        //Element Exist Overloaded Function
        bool ElementExists(T data);

        //Inorder Function Declaration
        void Inorder(Node<T>* root);
        //Overloaded Inorder Function Declaration
        void Inorder();

        //Find Function Declaration
        Node<T>* Find(Node<T>* node, T data);
        //Overloaded Find Function
        Node<T>* Find(T data);

        //mostFreq Function Declaration
        Node<T>* mostFreq(Node<T>* node);

        //leastFreq Function Declaration
        Node<T>* leastFreq(Node<T>* node);
        
        //ToArray Function Declaration
        string* ToArray(Node<T>* root);

        //Empty Function Declaration
        void Empty(Node<T>* node);

        //UniqueWords Function Declaration
        int UniqueWords(Node<T>* root);

        //Count Function Declaration        
        int Count(Node<T>* root);

        //isNumber Function Declaration
        bool isNumber(T& str);

        //toLower Function Declaration
        void toLower(T& str);
}; //end of class

template <typename T>
//Constructor 
BinarySearchTree<T>::BinarySearchTree()
{
    rootOfTree = nullptr;
}

template <typename T>
//Destructor 
BinarySearchTree<T>::~BinarySearchTree()
{
    rootOfTree = NULL;
}

template <typename T>
//Insert Function
//Inserts Values to nodes of the BinarySearchTree
Node<T>* BinarySearchTree<T>::Insert(Node<T>* newNode, T data)
{
    //If the newNode is Null, it sets the value to the root
    if(newNode == NULL)
    {
        newNode = new Node<T>(data);
        newNode->left = newNode->right = NULL;
    }

    //If the value is less than the value of root it goes to left 
    else if(data.compare(newNode->values->word) < 0)
    {
        newNode->left = Insert(newNode->left, data);
    }

    //If the value is greater than the value of root it goes right
    else if(data.compare(newNode->values->word) > 0)
    {
        newNode->right = Insert(newNode->right, data);
    }

    //If the value is already there it just increases the frequency
    else
    {
        newNode->values->frequency++;
    }

    return newNode;
} //end of Insert()

template <typename T>
//Overloaded Insert Function
void BinarySearchTree<T>::Insert(T data)
{
    //Passing the root and data to Insert()
    rootOfTree = Insert(rootOfTree, data);
}

template <typename T>
//Removes Function
//Removes the given data from Binary Search Tree
Node<T>* BinarySearchTree<T>::Remove(Node<T>* root, T data)
{
    Node<T>* current = root;
    Node<T>* previous = NULL; 
    
    //Checks if the word is there and if its present 
    //Then checks that the value is more or less 
    while (current != NULL && ((current->values->word.compare(data)) != 0)) 
    {
        previous = current;
        if ((data.compare(current->values->word)) < 0)
        {
            current = current->left;
        }    
        else
        {
            current = current->right;
        }    
    }
    
    //checks if the word given is present
    if (current == NULL) 
    {
        cout << "Word " << data << " not found in the" << " provided BST.\n";
        return root;
    }
 
    //Checks if the node is the last child
    if (current->left == NULL || current->right == NULL) {
 
        Node<T>* newCurr;
 
        // if the left child does not exist.
        if (current->left == NULL)
        {
            newCurr = current->right;
        }    
        else
        {
            newCurr = current->left;
        }

        //Checks if the node is the root
        if (previous == NULL)
        {
            return newCurr;
        }

        //Previous node will have newCurr value
        if (current == previous->left)
        {
            previous->left = newCurr;
        }    
        else
        {
            previous->right = newCurr;
        }

        //Makes the current NULL
        current = NULL;
    }
    
    //If the node deleted has two childrens
    else 
    {
        Node<T>* p = NULL;
        Node<T>* temp;
        
        //Storing value in temp
        temp = current->right;
        while (temp->left != NULL) 
        {
            p = temp;
            temp = temp->left;
        }

        //if p is not NULL then storing value of right to the left
        if (p != NULL)
        {
            p->left = temp->right;
        }

        //else storing value to right
        else
        {
            current->right = temp->right;
        }

        current->values = temp->values;

        //Making temp NULL
        temp = NULL;
    }
    return root;
} //end of Remove()

template <typename T>
//Overloaded Remove Function
void BinarySearchTree<T>::Remove(T data)
{
    Remove(rootOfTree, data);
}

template <typename T>
//ElementExist Function 
bool BinarySearchTree<T>::ElementExists(Node<T>* root, T data)
{
    //creating boolean variable     
    bool flag = false;

    //If root is NULL return false
    if (root == NULL)
    {
        flag = false;
    }    

    //If the key is found return true
    else if((root->values->word.compare(data)) == 0)
    {
        flag = true;
    }    

    //If the data to be found is greater than go to right
    else if(root->values->word.compare(data) < 0)
    {
        flag = ElementExists(root->right, data);
    }    

    //Else go to left
    else
    {
        flag = ElementExists(root->left, data);
    }

    return flag;    
} //end of ElementExist()

template <typename T>
//Overloaded ElementExist Function
bool BinarySearchTree<T>::ElementExists(T data)
{
    return ElementExists(rootOfTree, data);
}

template <typename T>
//Inorder Function
void BinarySearchTree<T>::Inorder(Node<T>* root)
{
    //If the root is null then return
    if (root == NULL) 
    {
        return;
    }
    //Else traverse left 
    Inorder(root->left);

    //Then traverse right
    Inorder(root->right);
} //end of Inorder Function

template <typename T>
//Overloaded Inorder Function
void BinarySearchTree<T>::Inorder()
{
    Inorder(rootOfTree);
}

template <typename T>
//Find Function
Node<T>* BinarySearchTree<T>::Find(Node<T>* node, T data)
{
    //If node is NULL return false
    if (node == NULL)
    {
        return NULL;
    }    

    //If the data is found return node
    else if((node->values->word.compare(data)) == 0)
    {
        return node;
    }    

    //If the data to be found is greater than go to right
    else if(node->values->word.compare(data) < 0)
    {
        return Find(node->right, data);
    }    

    //Else go left
    else
    {
        return Find(node->left, data);
    }    
} //end of Find Function

template <typename T>
//Overloaded Find Function
Node<T>* BinarySearchTree<T>::Find(T data)
{
    return Find(rootOfTree, data);
}

template <typename T>
//Count Function
int BinarySearchTree<T>::Count(Node<T>* root)
{
    //If the root is NULL then return 0
    if(root == NULL)
    {
        return 0;
    }

    //Else count all the frequency
    else 
    {
        int count = root->values->frequency + Count(root->left) + Count(root->right);
        return count;
    }
} //end of Count Function

template <typename T>
//UniqueWords Function
int BinarySearchTree<T>::UniqueWords(Node<T>* root)
{
    //If the root is null return 0
    if(root == NULL)
    {
        return 0;
    }

    //Else count all the nodes
    else 
    {
        int uniqueCount = 1 + UniqueWords(root->left) + UniqueWords(root->right);
        return uniqueCount;
    }
} //end of UniqueWords Function

template <typename T>
//mostFreq Function
Node<T>* BinarySearchTree<T>::mostFreq(Node<T>* node)
{
    //If the node is null return node
    if(node == NULL)
    {
        return node;
    }

    //First creates the max variable, 
    //storing the frequency of root to max;
    int max = node->values->frequency;
    Node<T>* n = node;

    //Traversing till we reach last element
    while(node != NULL)
    {
        //Comparing all the values to max 
        //If greater than max then changing max by that value
        if(node->values->frequency > max)
        {
            max = node->values->frequency;
            n = node;
        }
        //Traversing to left
        node = node->left;
    }

    //For right
    while(node != NULL)
    {
        //Comparing all the values to max 
        //If greater than max then changing max by that value
        if(node->values->frequency > max)
        {
            max = node->values->frequency;
            n = node;
        }
        node = node->right;
    }

    return n; 
} //end of mostFreq

template <typename T>
//leastFreq Function
Node<T>* BinarySearchTree<T>::leastFreq(Node<T>* node)
{
    //If the node is null return node
    if(node == NULL)
    {
        return node;
    }
    //First creates the least variable, 
    //storing the frequency of root to least
    int least = node->values->frequency;
    Node<T>* n = node;

    //Traversing till we reach last element
    while(node != NULL)
    {
        //Comparing all the values to least
        //If less than least then changing least by that value
        if(node->values->frequency < least)
        {
            least = node->values->frequency;
            n = node;
        }
        //Traversing to left
        node = node->left;
    }

    while(node != NULL)
    {
        //Comparing all the values to least
        //If less than least then changing least by that value
        if(node->values->frequency < least)
        {
            least = node->values->frequency;
            n = node;
        }
        //Traversing to right
        node = node->right;
    }

    return n; 
} //end of leastFreq Function

template <typename T>
//ToArray Function
string* BinarySearchTree<T>::ToArray(Node<T>* root)
{ 
    int i = 0;
    string strArr [UniqueWords(root)];
    //If the root is null then return
    if (root == NULL) 
    {
        return strArr;
    }
    //Traversing to left 
    ToArray(root->left);
    cout << root->values->word << endl;
    strArr[i++] = root->values->word;
    //Traversing to right
    ToArray(root->right);

    return strArr;
}// end of ToArray

template <typename T>
//Empty Function
void BinarySearchTree<T>::Empty(Node<T>* node)
{
    //If the node is null then return 
    if(node == NULL)
    {
        return;
    }
    
    //Emptying out left and right
    Empty(node->left);
    Empty(node->right);   

    //deleting node
    delete node;
} //end of Empty()

template <typename T>
//isNumber Function
bool BinarySearchTree<T>::isNumber(T& str)
{
    //Checks if the element is Number or not 
    //If it's number then returns true
    for(int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == 0)
        {
            return false;   
        }    
    }
    return true;
}// end of isNumber()

template <typename T>
//toLower Function
void BinarySearchTree<T>::toLower(T& str)
{
    //Traverses to the string and converts to lowercase characters
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
} //end of toLower()