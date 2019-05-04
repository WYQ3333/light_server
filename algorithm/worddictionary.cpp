#include <iostream>
#include<vector>
#include<string>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
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

int main(){
    WordDictionary w;
    w.addWord("bad");
    w.addWord("b..");
    w.addWord(".ad");
    cout << w.search(".a.") << endl;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
