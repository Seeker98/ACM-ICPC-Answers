#include <iostream>
#include <set>
#include <string>

using namespace std;

const int CHARSIZE = 2;

struct Node
{
    Node *next[CHARSIZE];
    int num;

    Node() : num(0)
    {
        for (int i = 0; i < CHARSIZE; i++)
        {
            next[i] = NULL;
        }
    }
};

struct Trie
{
    Node *root;

    ~Trie()
    {
        makeEmpty(root);
        delete root;
    }

    Trie()
    {
        root = new Node;
    }

    void insert(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - '0'] == NULL)
                node->next[s[i] - '0'] = new Node;
            node = node->next[s[i] - '0'];
            node->num++;
        }
    }

    // if is prefix, should be true
    bool query(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - '0'] == NULL)
                return false;
            node = node->next[s[i] - '0'];
        }
        return node->num > 1;
    }

    void clear()
    {
        this->~Trie();
        root = new Node;
    }

  private:
    void makeEmpty(Node *s)
    {
        if (s == NULL)
            return;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (s->next[i] != NULL)
            {
                makeEmpty(s->next[i]);
                delete s->next[i];
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Trie trie;
    string t;
    set<string> s;
    set<string>::iterator it;
    bool de = false;
    int kase = 0;
    while (cin >> t)
    {
        if (t == "9")
        {
            for (it = s.begin(); it != s.end(); it++)
                de = de || trie.query(*it);
            cout << "Set " << ++kase << " is" << (de ? " not " : " ") << "immediately decodable" << endl;
            s.clear();
            trie.clear();
            de = false;
        }
        else
        {
            s.insert(t);
            trie.insert(t);
        }
    }
    return 0;
}