#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct TreeNode{
    string data;
    int wordPosition;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* NewTreeNode(string data, int wordPosition){
    TreeNode* newTreeNode = new TreeNode();
    newTreeNode->data=data;
    newTreeNode->wordPosition=wordPosition;
    newTreeNode->left = newTreeNode->right = NULL;
    return newTreeNode;
}
TreeNode* Insert(TreeNode* RPTR,string data, int wordPosition){
    if(RPTR == NULL){
        RPTR = NewTreeNode(data, wordPosition);
        return RPTR;
    }
    else if(data<= RPTR->data){
        RPTR->left = Insert(RPTR->left,data,wordPosition);
    } else{
        RPTR->right = Insert(RPTR->right,data,wordPosition);
    }
    return RPTR;
}
void Print (TreeNode * x, int & id)
{
    if (!x) return;
    Print(x->left,id);
    id++;
    cout<<id<< " " << x->data << " ( Word position in file are: " << x->wordPosition << " ) " <<endl;
    Print(x->right,id);
}
int main() {
    string word;
    TreeNode* RPTR = NULL;
    int wordPosition = 1;
    ifstream myFile("input.txt");
    while(myFile >> word) {
        RPTR = Insert(RPTR, word, wordPosition);
        wordPosition = wordPosition + 1;
    }
        int id = 0;
        cout<<"The current ordered words are: "<<endl;
        Print(RPTR,id);
        myFile.close();
}