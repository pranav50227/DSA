#include<bits/stdc++.h>
using namespace std ;

class TrieNode{
    public :

    char data ;
    TrieNode* children[26] ;
    bool isTerminal ;

    TrieNode(char c){
        this->data = c ;
        for(int i = 0 ; i<26 ; i++)this->children[i] = NULL ;
        isTerminal = false ;
    }
};

class Trie{
    public :
    TrieNode* root ;

    Trie(){
        root = new TrieNode('\0') ;
    }

    void insertUtil(TrieNode* root , string word){
        if(word.length() == 0){
            root->isTerminal = true ;
            return ;
        }

        //assumpiton all the words will be in caps 
        int index = word[0] - 'A' ;
        TrieNode* child ;

        //present 
        if(root->children[index] != NULL){
            child = root->children[index] ;
        }else{
            //absent 
            child = new TrieNode(word[0]) ;
            root->children[index] = child ;
        }

        // Recursion
        insertUtil(child , word.substr(1)) ;
    }

    void insertWord(string word){
        insertUtil(root , word) ;
    }

    bool searchUtil(TrieNode* root , string word){
        if(word.length() == 0) return true ;

        TrieNode* child ;

        int index = word[0] - 'A' ;

        if(root->children[index] != NULL){
            child = root->children[index] ;
        }else {
            return false ;
        }

        return searchUtil(child , word.substr(1)) ;
    }

    bool searchWord(string word){
        return searchUtil(root , word) ;
    }

};

int main(){

    Trie *t = new Trie() ;

    t->insertWord("abcd") ;

    cout << "Hello World" ;

    return 0 ;
}

