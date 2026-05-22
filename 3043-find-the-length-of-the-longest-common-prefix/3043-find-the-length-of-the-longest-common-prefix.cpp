class Solution {
public:
struct TrieNode{
    TrieNode*child[10];
    bool isend;
    TrieNode(){
    for(int i=0;i<10;i++){
        child[i]=NULL;
    }
    isend=false;
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(char ch:word){
            int idx=ch-'0';
            if(node->child[idx]==NULL){
                node->child[idx]=new TrieNode();
            }
            node=node->child[idx];
        }
        node->isend=true;
    }
};
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(to_string(arr1[i]));
        }
        int ans=0;
        for(int i=0;i<m;i++){
          TrieNode*node=trie.root;
          int count=0;
          for(char ch:to_string(arr2[i])){
            int idx=ch-'0';
            if(node->child[idx]==NULL)break;
            count++;
            node=node->child[idx];
          }
          ans=max(ans,count);
        }
        return ans;
    }
};