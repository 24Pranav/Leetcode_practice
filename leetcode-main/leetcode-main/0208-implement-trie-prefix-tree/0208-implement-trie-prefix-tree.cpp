class Trie {
public:
    struct TNode
    {
        char val;
        int count;
        int endhere;
        TNode* child[26];
    };
    TNode * root;
    TNode* getNode(int idx)
    {
        TNode * newnode= new TNode;
        newnode->val='a'+idx;
        newnode->count=newnode->endhere=0;
        for(int i=0;i<26;i++)
            newnode->child[i]=NULL;
        return newnode;
    }
    
    Trie() {
        root=getNode('/'-'a');
    }
    
    void insert(string word) {
        TNode* curr=root;
        int idx;
        for(int i=0;i<word.size();i++)
        {
            idx=word[i]-'a';
            if(curr->child[idx]==NULL)
                curr->child[idx]=getNode(idx);
            curr->child[idx]->count+=1;
            curr=curr->child[idx];
        }
        curr->endhere+=1;
    }
    
    bool search(string word) {
        TNode* curr=root;
        int idx;
        for(int i=0;i<word.size();i++)
        {
            idx=word[i]-'a';
            if(curr->child[idx]==NULL)
                return false;
            curr=curr->child[idx];
        }
        return (curr->endhere > 0);
    }
    
    bool startsWith(string word) {
        TNode* curr=root;
        int idx;
        for(int i=0;i<word.size();i++)
        {
            idx=word[i]-'a';
            if(curr->child[idx]==NULL)
                return false;
            curr=curr->child[idx];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */