/*Trie*/
class Node{
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        isTerminal = false;
    }
};

class Trie{
    Node* root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node* temp = root;
        for(char ch : word)
        {
            if(temp->m.count(ch) == 0)
            {
                Node* node = new Node(ch);
                temp->m[ch] = node;
            }
            temp = temp -> m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node* temp = root;
        for(char ch:word)
        {
            if(temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

};

class Solution {
public:
    
    bool helper(string s, Trie &t)
    {
        int size = s.size();
        if(size == 0) return true;
        
        for(int i=1; i<=size; i++)
        {
            if(t.search(s.substr(0,i)) && helper(s.substr(i), t)) return true;
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wd)
    {
        Trie t;
        for(int i=0; i<wd.size(); i++)
        {
            t.insert(wd[i]);
        }
        return helper(s, t);
    }
};