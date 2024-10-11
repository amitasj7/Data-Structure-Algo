#include <bits/stdc++.h>
using namespace std;

class Node
{

    Node *links[26];
    int countWord = 0;
    int countPrefix = 0;

public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void increasePrefix()
    {
        countPrefix++;
    }
    void reducePrefix()
    {
        countPrefix--;
    }
    void increaseEnd()
    {
        countWord++;
    }
    void deleteEnd()
    {
        countWord--;
    }
    int totalWord()
    {
        return countWord;
    }
    int totalPrefix()
    {
        return countPrefix;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // update node
            node = node->get(word[i]);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            else
            {
                node = node->get(word[i]);
            }
        }

        return node->totalWord();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {

            if (!node->containsKey(word[i]))
                return 0;

            else
            {
                node = node->get(word[i]);
            }
        }

        return node->totalPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return;
            }
            else
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
        }

        node->deleteEnd();
    }
};
