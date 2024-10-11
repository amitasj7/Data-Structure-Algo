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

class Trie
{
private:
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
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

        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;

            node = node->get(prefix[i]);
        }

        return true;
    }
};
class Solution
{
    vector<string> ans;
    Trie data;

public:
    void solve(vector<vector<char>> &board, int i, int j, int totalRow, int totalCol, vector<vector<bool>> &visited, Node *node, string word)
    {
        char ch = board[i][j];
        // BASE CASE
        if (i < 0 || i >= totalRow || j < 0 || j >= totalCol || node->isEnd() || node->links[ch - 'a'] == NULL)
        {
            return;
        }

        // LOGIC
        visited[i][j] = 1;
        // update node

        node = node->links[ch - 'a'];

        // check for last character of word
        if (node->isEnd())
        {
            ans.push_back(word + ch);
        }

        // call all four direction
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int k = 0; i < 4; i++)
        {
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            solve(board, newRow, newCol, totalRow, totalCol, visited, node, word + ch);
        }

        visited[i][j] = 0;

        // RETURN
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        // create Trie data structure

        for (string str : words)
        {
            data.insert(str);
        }

        int totalRow = board.size();
        int totalCol = board[0].size();

        // take visited
        vector<vector<bool>> visited(totalRow, vector<bool>(totalCol, false));

        // traverse board and find all words
        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                string ch = board[i][j] + "";

                // check that character starting a word or not
                if (data.startsWith(ch))
                {
                    solve(board, i, j, totalRow, totalCol, visited, data.root, "");
                }
            }
        }

        return ans;
    }
};
