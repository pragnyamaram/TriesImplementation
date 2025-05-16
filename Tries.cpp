#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
        char val;
        unordered_map<char,TrieNode*> children;
        bool isTerminal;

    TrieNode(char data){
        val=data;
        isTerminal=false;
    }
};

void insertIntoTrie(TrieNode* root,const string &word){
    //base case
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }
    //1case solve karna
    //ek char ko trie node meh insert kardho
    char ch = word[0];
    TrieNode* child;

    if(root->children.count(ch)==1){
        child = root->children[ch];
    }
    else{
        child = new TrieNode(ch);
        root->children[ch] = child; 
    }
    //baaki recursion
    insertIntoTrie(child,word.substr(1));
}
bool searchTrie(TrieNode* root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch)!=root->children.end()){
        child = root->children[ch];
    }
    else{
        return false;
    }
    bool recursionAns = searchTrie(child, word.substr(1));
    return recursionAns;
}
void deleteNode(TrieNode* root, string word){

    if(word.length()==0){
        root->isTerminal=false;
        return;
    }
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch)!=root->children.end()){
        child = root->children[ch];
    }
    else{
        return;
    }
    deleteNode(child,word.substr(1));
}
int main(){
    TrieNode* root = new TrieNode('-');
    insertIntoTrie(root,"cover");
    insertIntoTrie(root,"car");
    insertIntoTrie(root,"toy");
    insertIntoTrie(root,"snake");
    insertIntoTrie(root,"care");
    insertIntoTrie(root,"self");
    insertIntoTrie(root,"tag");
    insertIntoTrie(root,"obsessed");
    insertIntoTrie(root,"take");
    insertIntoTrie(root,"taken");

    bool ans = searchTrie(root,"take");
    if(ans)
        cout<<"Found"<<endl;
    else    
        cout<<"Not Found"<<endl;
    deleteNode(root,"take");
    bool ans1 = searchTrie(root,"take");
    if(ans1)
        cout<<"Found"<<endl;
    else    
        cout<<"Not Found"<<endl;
}