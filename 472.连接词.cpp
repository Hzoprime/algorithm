/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */
#include "windows_header.hpp"
// @lc code=start

class Trie
{
public:
    bool is_word;
    vector<Trie *> children;
    Trie() : children(vector<Trie *>(26, nullptr)), is_word(false)
    {
    }
};

class Solution
{
public:
    Trie *root;

    Solution() : root(new Trie())
    {
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans;
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        for (auto &&s : words)
        {
            if (s.empty())
            {
                continue;
            }
            if (dfs(s, 0))
            {
                ans.push_back(s);
            }
            else
            {
                insert(s);
            }
        }
        return ans;
    }
    int dfs(const string &s, const int &start)
    {
        if (s.size() == start)
        {
            return true;
        }
        Trie *node = root;
        for (int i = start; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            node = node->children[index];
            if (node == nullptr)
            {
                return false;
            }
            if (node->is_word)
            {
                if (dfs(s, i + 1))
                {
                    return true;
                }
            }
        }
        return false;
    }
    void insert(const string &s)
    {
        Trie *node = root;
        for (auto &&c : s)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->is_word = true;
    }
};
static const int x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// @lc code=end
