# Trie
```cpp
class Node{
  public:
     bool isWord;
     Node* next[26];
     Node(){
         for(int i=0;i<26;i++){
             this->next[i]=NULL;
         }
         this->isWord=false;
     }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string s) {
        Node* curr=root;
        for(int i=0;i<s.size();i++){
            if(curr->next[s[i]-'a']==NULL){
                curr->next[s[i]-'a']=new Node;
            }
            curr=curr->next[s[i]-'a'];
        }
        curr->isWord=true;
    }
    
    bool search(string s) {
        Node* curr=root;
        for(int i=0;i<s.size();i++){
            if(curr->next[s[i]-'a']==NULL)return false;
            curr=curr->next[s[i]-'a'];
        }
        if(curr->isWord)return true;
        return false;
    }
    
    bool startsWith(string s) {
        Node* curr=root;
        for(int i=0;i<s.size();i++){
            if(curr->next[s[i]-'a']==NULL)return false;
            curr=curr->next[s[i]-'a'];
        }
        return true;
    }
};
```
---
# max xor
![](https://assets.leetcode.com/users/images/5bbde8f6-016e-4987-9ea8-2b51021b8e03_1643256352.788602.gif)
```cpp
class Solution {
public:
class TrieNode{
public:
    TrieNode* next[2];
	TrieNode(){ //two options 1 or 2
	      next[0]=NULL;
          next[1]=NULL;
	  }
};
int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode;
        for(int num : nums){
            TrieNode* curr = root;
            for(int i=30;i>=0;i--){
                int bit = num>>i & 1 ;
                if(curr->next[bit]==NULL){
                    curr->next[bit] = new TrieNode;
                }
                curr=curr->next[bit];
            }
        }
        int ans=0;
        for(int num : nums){
            int res=0;
            TrieNode* curr = root;
            for(int i=30;i>=0;i--){
                int bit = num>>i & 1 ;
                int oppbit = !bit;
                if(curr->next[oppbit]!=NULL){
                    curr=curr->next[oppbit];
                    res+= 1<<i;
                }else{
                    curr=curr->next[bit];
                }
            }
            ans=max(res,ans);
        }
    return ans;
	}
```
# 720. Longest Word in Dictionary
```
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word. 
```
```cpp
class Node{
   public:
    string word; //to check if at a node we are at the end of a word
    Node* next[26]; //all children it ccan have
    Node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
        word=""; 
    }
};
class Solution {
public:
    int maxlen = 0;
    string ans="";
    void dfs(Node* curr){
        if(curr == NULL)return; // when there is no such node
        if(curr->word.size()<1)return; // when there is no such word in dictionary
        if(curr->word.size()>0){
            cout<<curr->word<<endl;
            if(maxlen<curr->word.size()){
                maxlen = curr->word.size();
                ans=curr->word;
            }
        }
        for(int i=0;i<26;i++)dfs(curr->next[i]);
        
    }
    string longestWord(vector<string>& words) {
        Node* root = new Node;
        for(string word : words){
            Node* curr = root;
            for(char c : word){
                c-='a';
                if(curr->next[c]==NULL){
                    curr->next[c]=new Node;
                }
                curr = curr->next[c];
            }
            curr->word = word;
        }
        for(int i=0;i<26;i++){
            dfs(root->next[i]);
        }
        return ans;
    }
};
```
# 745. Prefix and Suffix Search
```
apple|apple
pple|apple
ple|apple
le|apple
e|apple
```
```cpp
class Node{
    public:
  unordered_map<char, Node*> next;
    int index;
    Node(){
        index=-1;
    }
};
class WordFilter {
public:
    Node* root;
    WordFilter(vector<string>& words) {
        root = new Node;
        int i=0;
        for(string word : words){ 
            string search_word = word + '|' + word;
            int ind=0;
            while(search_word[ind]!='|'){
                string curr_search_word = search_word.substr(ind++);
                Node* curr = root;
                for(char ch : curr_search_word){
                    if(curr->next.find(ch)==curr->next.end()){
                        curr->next[ch] = new Node;
                    }
                    curr = curr->next[ch]; 
                    curr->index=i;
                }
                curr->index = i;
            }
            i++;
        }
    }
    
    int f(string prefix, string suffix) {
        string word=suffix+'|'+prefix; //// 
        Node* curr = root;
        for(auto ch : word){
            if(curr->next.find(ch)==curr->next.end())return -1;
            curr=curr->next[ch];
        }
        return curr->index;
        
    }
};

```