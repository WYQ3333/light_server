#include <iostream>
#include<string.h>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class WordDictionary1 {
public:
    /** Initialize your data structure here. */
    WordDictionary1() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        v.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(size_t i = 0; i < v.size(); ++i){
            if(v[i].size() < word.size()){
                continue;
            }
            else if(v[i].size() >= word.size()){
                string temp = "";
                size_t j = 0, k = 0;
                while(j < v[i].size()){
                    if(temp.size() == word.size()){
                        return true;
                    }
                    if(k < word.size() && (v[i][j] == word[k] || word[k] == '.')){
                        j++;
                        k++;
                        temp += v[i][j];
                    }
                    else if(k < word.size() && v[i][j] != word[k]){
                        k = 0;
                        temp = "";
                    }
                }
            }
        }
        return false;
    }
private:
    vector<string> v;
};

class WordDictionary2 {
public:
    /** Initialize your data structure here. */
    WordDictionary2() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        v.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        stack<char> s;
        for(size_t i = 0; i < v.size(); ++i){
            if(v[i].size() < word.size()){
                continue;
            }
            size_t index = 0;
            for(size_t j = 0; j < v[i].size(); ++j){
                if(s.size() == word.size())
                    return true;
                if(index < word.size() && (v[i][j] == word[index] || word[index] == '.')){
                    s.push(v[i][j]);
                }
                else{
                    while(s.size())
                        s.pop();
                }
            }
        }
        if(s.size() == word.size())
            return true;
        return false;
    }
private:
    vector<string> v;
};

class TrieNode{
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode()
    {
        memset(next,0,sizeof(next));
        is_word=false;
    }

};

class WordDictionary {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
    TrieNode *p=root;
    for(size_t i=0;i<word.size();i++)
    {
        if(p->next[word[i]-'a']==NULL)
            p->next[word[i]-'a']=new TrieNode();
        p=p->next[word[i]-'a'];
    }
        p->is_word=true;
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word.c_str(),root);
        
    }
private:
    bool query(const char* word,TrieNode *p)
    {
        for(int i=0;word[i]&&p;i++)
        {
            if(word[i]!='.')
                p=p->next[word[i]-'a'];
            else 
            {
                TrieNode *tmp=p;
                for(int j=0;j<26;j++)
                {
                    p=tmp->next[j];
                    if(query(word+i+1,p))
                        return true;
                }
            }
        }
        return p&&p->is_word;
    }
};

int main(){

    WordDictionary w;
    w.addWord("WordDictionary");
    w.addWord("addWord");
    w.addWord("addWord");
    w.addWord("addWord");
    w.addWord("search");
    w.addWord("search");
    w.addWord("search");
    w.addWord("search");
    cout << w.search("bad") << " ";
    cout << w.search("dad") << " ";
    cout << w.search("mad") << " ";
    cout << w.search("pad") << " ";
    cout << w.search("bad") << " ";
    cout << w.search(".ad") << " ";
    cout << w.search("b..") << " ";
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
