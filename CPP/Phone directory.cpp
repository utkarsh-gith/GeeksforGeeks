class TrieNode
{
public:
    bool isTerminal;
    vector<TrieNode *> children;

    TrieNode()
    {
        isTerminal = false;
        children.resize(26, NULL);
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insertNode(string word)
    {
        TrieNode *node = root;
        for (char x : word)
        {
            int index = x - 'a';
            if (node->children[index] == NULL)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    void startsWithUtil(string word, vector<string> &output, TrieNode *node)
    {
        if (node->isTerminal)
        {
            output.push_back(word);
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                char temp = 'a' + i;
                startsWithUtil(word + temp, output, node->children[i]);
            }
        }
    }
    vector<string> startsWith(string prefix)
    {
        TrieNode *node = root;
        vector<string> output;
        for (char x : prefix)
        {
            int index = x - 'a';
            if (node->children[index] == NULL)
            {
                output.push_back("0");
                return output;
            }
            node = node->children[index];
        }
        startsWithUtil(prefix, output, node);
        return output;
    }
};
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {

        Trie *t = new Trie();
        for (int i = 0; i < n; i++)
        {
            t->insertNode(contact[i]);
        }
        vector<vector<string>> result;
        string word = "";
        for (char c : s)
        {
            word += c;
            vector<string> output = t->startsWith(word);
            result.push_back(output);
        }
        return result;
    }
};