#include <iostream>
#include<string.h>
#include<vector>
#include<string>
#include<stack>
using namespace std;

/*class WordDictionary1 { */
/*public: */
/*    /1** Initialize your data structure here. *1/ */
/*    WordDictionary1() { */
        
/*    } */
    
/*    /1** Adds a word into the data structure. *1/ */
/*    void addWord(string word) { */
/*        v.push_back(word); */
/*    } */
    
/*    /1** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. *1/ */
/*    bool search(string word) { */
/*        for(size_t i = 0; i < v.size(); ++i){ */
/*            if(v[i].size() < word.size()){ */
/*                continue; */
/*            } */
/*            else if(v[i].size() >= word.size()){ */
/*                string temp = ""; */
/*                size_t j = 0, k = 0; */
/*                while(j < v[i].size()){ */
/*                    if(temp.size() == word.size()){ */
/*                        return true; */
/*                    } */
/*                    if(k < word.size() && (v[i][j] == word[k] || word[k] == '.')){ */
/*                        j++; */
/*                        k++; */
/*                        temp += v[i][j]; */
/*                    } */
/*                    else if(k < word.size() && v[i][j] != word[k]){ */
/*                        k = 0; */
/*                        temp = ""; */
/*                    } */
/*                } */
/*            } */
/*        } */
/*        return false; */
/*    } */
/*private: */
/*    vector<string> v; */
/*}; */

/*class WordDictionary2 { */
/*public: */
/*    /1** Initialize your data structure here. *1/ */
/*    WordDictionary2() { */
        
/*    } */
    
/*    /1** Adds a word into the data structure. *1/ */
/*    void addWord(string word) { */
/*        v.push_back(word); */
/*    } */
    
/*    /1** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. *1/ */
/*    bool search(string word) { */
/*        stack<char> s; */
/*        for(size_t i = 0; i < v.size(); ++i){ */
/*            if(v[i].size() < word.size()){ */
/*                continue; */
/*            } */
/*            size_t index = 0; */
/*            for(size_t j = 0; j < v[i].size(); ++j){ */
/*                if(s.size() == word.size()) */
/*                    return true; */
/*                if(index < word.size() && (v[i][j] == word[index] || word[index] == '.')){ */
/*                    s.push(v[i][j]); */
/*                } */
/*                else{ */
/*                    while(s.size()) */
/*                        s.pop(); */
/*                } */
/*            } */
/*        } */
/*        if(s.size() == word.size()) */
/*            return true; */
/*        return false; */
/*    } */
/*private: */
/*    vector<string> v; */
/*}; */

/*class TrieNode{ */
/*public: */
/*    TrieNode *next[26]; */
/*    bool is_word; */
/*    TrieNode() */
/*    { */
/*        memset(next,0,sizeof(next)); */
/*        is_word=false; */
/*    } */

/*}; */

/*class WordDictionary3 { */
/*    TrieNode *root; */
/*public: */
/*    /1** Initialize your data structure here. *1/ */
/*    WordDictionary3() { */
/*        root=new TrieNode(); */
/*    } */
    
/*    /1** Adds a word into the data structure. *1/ */
/*    void addWord(string word) { */
/*    TrieNode *p=root; */
/*    for(size_t i=0;i<word.size();i++) */
/*    { */
/*        if(p->next[word[i]-'a']==NULL) */
/*            p->next[word[i]-'a']=new TrieNode(); */
/*        p=p->next[word[i]-'a']; */
/*    } */
/*        p->is_word=true; */
        
/*    } */
    
/*    /1** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. *1/ */
/*    bool search(string word) { */
/*        return query(word.c_str(),root); */
        
/*    } */
/*private: */
/*    bool query(const char* word,TrieNode *p) */
/*    { */
/*        for(int i=0;word[i]&&p;i++) */
/*        { */
/*            if(word[i]!='.') */
/*                p=p->next[word[i]-'a']; */
/*            else */ 
/*            { */
/*                TrieNode *tmp=p; */
/*                for(int j=0;j<26;j++) */
/*                { */
/*                    p=tmp->next[j]; */
/*                    if(query(word+i+1,p)) */
/*                        return true; */
/*                } */
/*            } */
/*        } */
/*        return p&&p->is_word; */
/*    } */
/*}; */

class Node{
public:
    Node *next[26];
    int num;
    Node(){
        for(int i=0; i<26; ++i)
            this->next[i] = nullptr;
        num = 0;
    }
};

class WordDictionary {
public:
    Node *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *p = root;
        for(auto i:word)
        {
            if(p->next[i-'a'] == nullptr)
            {
                p->next[i-'a'] = new Node();
            }
            p = p->next[i-'a'];
        }
        p->num++;
    }
    bool dfs(string word,  int k, Node *root);
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node *p = root;
        return dfs(word, 0, p);
    }
};



bool  WordDictionary::dfs(string word, int k, Node *root){
    
    if(k == word.size()-1)
    {
         if(word[k]!='.')
         {
             if(root->next[word[k]-'a'] && root->next[word[k]-'a']->num != 0)
                return true;
             else
                return false;
         }
         else
         {
             for(int i=0; i<26; ++i)
                 if(root->next[i] && root->next[i]->num!=0)
                     return true;
             return false;
         }
    }
    
    if(word[k]=='.') //正则匹配
    {
        for(int i=0; i<26; ++i)
        {
            if(root->next[i]!=nullptr)
            {
                if(dfs(word, k+1, root->next[i]))
                    return true;
            }
        }
    }
    else //非正则匹配
    {
        if(root->next[word[k]-'a']==nullptr)
            return false;
        else
            return dfs(word, k+1, root->next[word[k]-'a']);
    }
    return false;
}

int main(){

    WordDictionary w;
    w.addWord("dad");
    /* w.addWord("WordDictionary"); */
    /* w.addWord("addWord"); */
    /* w.addWord("addWord"); */
    /* w.addWord("addWord"); */
    /* w.addWord("search"); */
    /* w.addWord("search"); */
    /* w.addWord("search"); */
    /* w.addWord("search"); */
    /* cout << w.search("bad") << " "; */
    cout << w.search("dad") << " ";
    /* cout << w.search("mad") << " "; */
    cout << w.search("pad") << " ";
    cout << w.search("bad") << " ";
    /* cout << w.search(".ad") << " "; */
    /* cout << w.search("b..") << " "; */
}

