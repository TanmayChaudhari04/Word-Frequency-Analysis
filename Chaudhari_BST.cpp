/*
Author: Tanmay Chaudhari
Description: Word Frequency Analysis – Binary Search Tree
Usage: <exe>
*/
#include "Chaudhari_BST.h"
#include "Node.h"
#include "WordEntry.cpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

//Main Function
int main(int argc, char** argv)
{
    //Declaring all the Objects and Variables 
    BinarySearchTree<string>* bst = new BinarySearchTree<string>();
    Node<string>* node = NULL;
    string getFrequency;
    string inputFile;
    string outputFile;
    
    ifstream inFile;

    cout << "Enter the Input File, to get the Analysis: ";
    cin >> inputFile;

    inFile.open(inputFile);

    cout << "Enter the Output File, to get the Analysis: ";
    cin >> outputFile;

    ofstream outFile;
    outFile.open(outputFile);

    string line;

    //Taking the input in file    
    while (getline(inFile, line)) 
    {
        //Replacing all the extra characters with spaces
        replace(line.begin(), line.end(), ',', ' ');
        replace(line.begin(), line.end(), '-', ' ');
        replace(line.begin(), line.end(), '.', ' ');
        replace(line.begin(), line.end(), '"', ' ');
        replace(line.begin(), line.end(), '(', ' ');
        replace(line.begin(), line.end(), ')', ' ');
        replace(line.begin(), line.end(), '{', ' ');
        replace(line.begin(), line.end(), '}', ' ');
        replace(line.begin(), line.end(), '[', ' ');
        replace(line.begin(), line.end(), ']', ' ');
        replace(line.begin(), line.end(), '#', ' ');
        replace(line.begin(), line.end(), ':', ' ');
        replace(line.begin(), line.end(), '?', ' ');
        replace(line.begin(), line.end(), ';', ' ');
        replace(line.begin(), line.end(), '!', ' ');
        replace(line.begin(), line.end(), '/', ' ');
        replace(line.begin(), line.end(), '@', ' ');
        replace(line.begin(), line.end(), '*', ' ');
        replace(line.begin(), line.end(), '&', ' ');
        replace(line.begin(), line.end(), '$', ' ');
        replace(line.begin(), line.end(), '%', ' ');

        string word;
        stringstream s(line);
        while(s >> word)
        {            
            if (bst->isNumber(word))
            { 
                continue;
            }

            else    
            {    
                bst->toLower(word);
                bst->Insert(word); 
            }       
        }
    } //end of while loop
    
    //Converting tree to Inorder
    bst->Inorder();

    //Finding Total Words 
    int size = bst->Count(bst->rootOfTree);

    //Finding Unique words
    int uniqueWords = bst->UniqueWords(bst->rootOfTree);

    //Summary Analysis 
    cout << "Summary of the Analysis: " << endl;
    outFile << "Summary of the Analysis: " << endl;

    cout << "\n";
    outFile << "\n";

    cout << "Total Words: " << size << endl; 
    outFile << "Total Words: " << size << endl;

    cout << "Total Unique Words: " << uniqueWords << endl;
    outFile << "Total Unique Words: " << uniqueWords << endl;

    cout << "Most frequently used words: " << endl;
    outFile << "Most frequently used words: " << endl;

    //Finding Five Most Used Words

    string firstMostFreqWord;
    Node<string>* firstFreq = bst->mostFreq(bst->rootOfTree);
    firstMostFreqWord = firstFreq->values->word;
    int first = firstFreq->values->frequency;

    cout << "First Most Frequently Used Word: " << firstMostFreqWord << endl;
    outFile << "First Most Frequently Used Word: " << firstMostFreqWord << endl;

    bst->Remove(firstMostFreqWord);

    string secondMostFreqWord;
    Node<string>* secondFreq = bst->mostFreq(bst->rootOfTree);
    secondMostFreqWord = secondFreq->values->word;
    int second = secondFreq->values->frequency;

    cout << "Second Most Frequently Used Word: " << secondMostFreqWord << endl;
    outFile << "Second Most Frequently Used Word: " << secondMostFreqWord << endl;

    bst->Remove(secondMostFreqWord);

    string thirdMostFreqWord;
    Node<string>* thirdFreq = bst->mostFreq(bst->rootOfTree);
    thirdMostFreqWord = thirdFreq->values->word;
    int third = thirdFreq->values->frequency;

    cout << "Third Most Frequently Used Word: " << thirdMostFreqWord << endl;
    outFile << "Third Most Frequently Used Word: " << thirdMostFreqWord << endl;

    bst->Remove(thirdMostFreqWord);

    string fourthMostFreqWord;
    Node<string>* fourthFreq = bst->mostFreq(bst->rootOfTree);
    fourthMostFreqWord = fourthFreq->values->word;
    int fourth = fourthFreq->values->frequency;

    cout << "Fourth Most Frequently Used Word: " << fourthMostFreqWord << endl;
    outFile << "Fourth Most Frequently Used Word: " << fourthMostFreqWord << endl;

    bst->Remove(fourthMostFreqWord);

    string fifthMostFreqWord;
    Node<string>* fifthFreq = bst->mostFreq(bst->rootOfTree);
    fifthMostFreqWord = fifthFreq->values->word;
    int fifth = fifthFreq->values->frequency;

    cout << "Fifth Most Frequently Used Word: " << fifthMostFreqWord << endl;
    outFile << "Fifth Most Frequently Used Word: " << fifthMostFreqWord << endl;

    bst->Remove(fifthMostFreqWord);

    for(int i = 0; i < first; i++)
    {
        bst->Insert(firstMostFreqWord);   
    }

    for(int i = 0; i < second; i++)
    {
        bst->Insert(secondMostFreqWord);   
    }

    for(int i = 0; i < third; i++)
    {
        bst->Insert(thirdMostFreqWord);   
    }

    for(int i = 0; i < fourth; i++)
    {
        bst->Insert(fourthMostFreqWord);   
    }

    for(int i = 0; i < fifth; i++)
    {
        bst->Insert(fifthMostFreqWord);   
    }

    //Finding Five Least Used Words

    cout << "\n";
    outFile << "\n";

    cout << "Least frequently used words: " << endl;
    outFile << "Least frequently used words: " << endl;

    string firstLeastFreqWord;
    Node<string>* firstLeastFreq = bst->leastFreq(bst->rootOfTree);
    firstLeastFreqWord = firstLeastFreq->values->word;
    int fLeast = firstLeastFreq->values->frequency;

    cout << "First Least Frequently Used Word: " << firstLeastFreqWord << endl;
    outFile << "First Least Frequently Used Word: " << firstLeastFreqWord << endl;

    bst->Remove(firstLeastFreqWord);

    string secondLeastFreqWord;
    Node<string>* secondLeastFreq = bst->leastFreq(bst->rootOfTree);
    secondLeastFreqWord = secondLeastFreq->values->word;
    int sLeast = secondLeastFreq->values->frequency;

    cout << "Second Least Frequently Used Word: " << secondLeastFreqWord << endl;
    outFile << "Second Least Frequently Used Word: " << secondLeastFreqWord << endl;

    bst->Remove(secondLeastFreqWord);

    string thirdLeastFreqWord;
    Node<string>* thirdLeastFreq = bst->leastFreq(bst->rootOfTree);
    thirdLeastFreqWord = thirdLeastFreq->values->word;
    int tLeast = thirdLeastFreq->values->frequency;

    cout << "Third Least Frequently Used Word: " << thirdLeastFreqWord << endl;
    outFile << "Third Least Frequently Used Word: " << thirdLeastFreqWord << endl;

    bst->Remove(thirdLeastFreqWord);

    string fourthLeastFreqWord;
    Node<string>* fourthLeastFreq = bst->leastFreq(bst->rootOfTree);
    fourthLeastFreqWord = fourthLeastFreq->values->word;
    int fourthLeast = fourthLeastFreq->values->frequency;

    cout << "Fourth Least Frequently Used Word: " << fourthLeastFreqWord << endl;
    outFile << "Fourth Least Frequently Used Word: " << fourthLeastFreqWord << endl;

    bst->Remove(fourthLeastFreqWord);

    string fifthLeastFreqWord;
    Node<string>* fifthLeastFreq = bst->leastFreq(bst->rootOfTree);
    fifthLeastFreqWord = fifthLeastFreq->values->word;
    int fifthLeast = fifthLeastFreq->values->frequency;

    cout << "Fifth Least Frequently Used Word: " << fifthLeastFreqWord << endl;
    outFile << "Fifth Least Frequently Used Word: " << fifthLeastFreqWord << endl;

    bst->Remove(fifthLeastFreqWord);

    for(int i = 0; i < fLeast; i++)
    {
        bst->Insert(firstLeastFreqWord);   
    }

    for(int i = 0; i < sLeast; i++)
    {
        bst->Insert(secondLeastFreqWord);   
    }

    for(int i = 0; i < tLeast; i++)
    {
        bst->Insert(thirdLeastFreqWord);   
    }

    for(int i = 0; i < fourthLeast; i++)
    {
        bst->Insert(fourthLeastFreqWord);   
    }

    for(int i = 0; i < fifthLeast; i++)
    {
        bst->Insert(fifthLeastFreqWord);   
    }

    cout << "\n";
    outFile << "\n";

    //Asking User to input the Word to get Frequency of that word

    cout << "Input Word to get the Frequency of that Word: ";
    cin >> getFrequency;
    int inpFreq;
    Node<string>* getFreq = bst->Find(getFrequency);

    while(getFreq == NULL)
    {
        cout << "This word is not available! Try Again!!" << endl;
        cout << "Input Word to get the Frequency of that Word: ";
        cin >> getFrequency;
        getFreq = bst->Find(getFrequency);
    }

    inpFreq = getFreq->values->frequency;   
    cout << "The frequency of the word " << "\"" << getFrequency << "\"" << " is: " << inpFreq << endl;
    outFile << "The frequency of the word " << "\"" << getFrequency << "\"" << " is: " << inpFreq << endl;

    return 0;
} //end of main