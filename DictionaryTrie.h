// CSE 100 PA3 C++ Autocomplete
// Authors: Jor-el Briones, Christine Alvarado, Benjamin Llanes, A13138925

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define NO_VAL UINT_MAX

// Used for finding completions.
typedef std::pair<std::string, unsigned int> word_and_freq;

// Structure for a node in this ternary search tree
struct DictionaryTrieNode {
  DictionaryTrieNode * left;
  DictionaryTrieNode * right;
  DictionaryTrieNode * center;
  char key;
  unsigned int freq;
  DictionaryTrieNode(char k, unsigned int f = NO_VAL) : left(0), right(0),
    center(0), key(k), freq(f) {}
};

// The class for a dictionary ADT, implemented as a trie
// You may implement this class as either a mulit-way trie
// or a ternary search trie, but you must use one or the other.
class DictionaryTrie
{
public:

  // Create a new Dictionary that uses a Trie back end
  DictionaryTrie();

  // Insert a word with its frequency into the dictionary.
  // Return true if the word was inserted, and false if it
  // was not (i.e. it was already in the dictionary or it was
  // invalid (empty string)
  bool insert(std::string word, unsigned int freq);

  // Return true if word is in the dictionary, and false otherwise
  bool find(std::string word) const;

  // Return up to num_completions of the most frequent completions
  // of the prefix, such that the completions are words in the dictionary.
  // These completions should be listed from most frequent to least.
  // If there are fewer than num_completions legal completions, this
  // function returns a vector with as many completions as possible.
  // If no completions exist, then the function returns a vector of size 0.
  // The prefix itself might be included in the returned words if the prefix
  // is a word (and is among the num_completions most frequent completions
  // of the prefix)
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  // Destructor
  ~DictionaryTrie();

private:
  // Add your own data members and methods here

  // The root node of the ternary search tree.
  DictionaryTrieNode * root;

  // Insert a word with its frequency into the dictionary, starting at
  // the specified node.
  // Return true if the word was inserted, and false if it
  // was not (i.e. it was already in the dictionary or it was
  // invalid (empty string)
  bool insert(DictionaryTrieNode *& curr, std::string word, unsigned int freq);

  // Return true if word is in the dictionary, and false otherwise
  bool find(DictionaryTrieNode * curr, std::string word) const;

  // Returns a pointer to the node holding the specified string.
  DictionaryTrieNode * getNode(DictionaryTrieNode * curr, std::string word)
    const;

  // Deletes the specified node and all its children.
  void delete_all(DictionaryTrieNode * root);
};

#endif // DICTIONARY_TRIE_H
