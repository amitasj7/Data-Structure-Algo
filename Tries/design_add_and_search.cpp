#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node *links[26];

    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary
{
private:
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;

        // travers word
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                // insert key
                node->put(word[i], new Node());
            }
            // move to references
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        return searchHelper(word, root);
    }
    bool searchHelper(string word, Node *node)
    {
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (ch == '.')
            {
                for (auto c : node->links)
                {
                    if (c && searchHelper(word.substr(i + 1), c))
                        return true;
                }
                return false;
            }
            if (!node->containsKey(ch))
                return false;
            // update node
            node = node->get(ch);
        }

        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */