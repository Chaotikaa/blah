#include "util.h"
#include "DictionaryTrie.h"

bool word_cmp(word_and_freq w1, word_and_freq w2) {
  return w1.second < w2.second;
}

// Create a new Dictionary that uses a Trie back end
DictionaryTrie::DictionaryTrie() : root(0) {}


// Insert a word with its frequency into the dictionary.
// Return true if the word was inserted, and false if it
// was not (i.e. it was already in the dictionary or it was
// invalid (empty string)
// Defers to private recursive insert method, passing in
// the root node as the starting point.
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  return insert(root, word, freq);
}

// Insert a word with its frequency into the dictionary,
// starting at the specified node.
// Return true if the word was inserted, and false if it
// was not (i.e. it was already in the dictionary or it was
// invalid (empty string)
bool DictionaryTrie::insert(DictionaryTrieNode *& curr,
	std::string word, unsigned int freq) {
    return true;
}

// Return true if word is in the dictionary, and false otherwise
//
// Defers to private find method, passing in the root node
// as the starting point.
bool DictionaryTrie::find(std::string word) const
{
  return true;
}

// Return true if word is in the dictionary, and false otherwise
bool DictionaryTrie::find(DictionaryTrieNode * curr, std::string word) const {
  return true;
}

// Returns a pointer to the node holding the specified string.
DictionaryTrieNode * DictionaryTrie::getNode(DictionaryTrieNode * curr,
  return 0;
}

// Deletes all nodes of the tree; called in destructor
void DictionaryTrie::delete_all(DictionaryTrieNode * curr) {
}

// Return up to num_completions of the most frequent completions
// of the prefix, such that the completions are words in the dictionary.
// These completions should be listed from most frequent to least.
// If there are fewer than num_completions legal completions, this
// function returns a vector with as many completions as possible.
// If no completions exist, then the function returns a vector of size 0.
// The prefix itself might be included in the returned words if the prefix
// is a word (and is among the num_completions most frequent completions
// of the prefix)
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  return std::vector<std::string>();
}

// Destructor
DictionaryTrie::~DictionaryTrie(){
	delete_all(root);
}
