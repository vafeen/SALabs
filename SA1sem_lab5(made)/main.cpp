#include"tree.hpp"

int main()
{
    Trie trie;
    vector<string> words = {"apple",
                            "application",
                            "bananas",
                            "boook",
                            "booox",
                            "booooooof"};
    for (size_t i = 0; i < words.size(); i++)
    {
        trie.addWord(words[i]);
    }
    trie.printTrie();

    cout << "boo: " << trie.countWordsStartingWith("boo") << '\n';
    cout << "b: " << trie.countWordsStartingWith("b") << '\n';
    system("pause");
}
