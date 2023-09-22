class Node{
    private:
    Node* links[26];
    bool flag;

    public:
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }

    bool searchHelper(string word, int index, Node* node){

        //base cases
        if(index == word.size() && node->isEnd()) return true;
        
        if(index == word.size()) return false;
        
        if(word[index] != '.'){
            if(!node->containsKey(word[index])) return false;
            else{
                return searchHelper(word,index+1,node->get(word[index]));
            }
        }
        else{
            for(int i=0;i<26;i++){
                if(node->containsKey(i+'a')){
                    Node* nextNode = node->get(i+'a');
                    if(searchHelper(word,index+1,nextNode)){
                        return true;
                    }
                }
            }

            return false;
        }
    }
    
    void addWord(string word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};
