/*
HUFFMAN CODING: (used for data compression)
    It is variable length prefix code to represent characters.
    Prefix code means the codes are assigned in such a way that the code assigned to one 
    character is not the prefix of code assigned to any other character.

    There are mainly two major parts in Huffman Coding:
    1) Build a Huffman Tree from input characters.
    2) Traverse the Huffman Tree and assign codes to characters.

    Time Complexity          : O(nlogn)     // n is the number of unique characters.
    Auxiliary Space          : O(n)         // maps & min-heap
*/

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


// to make priority queue act as min-heap
struct compare {
    bool operator()(pair<int, string> p1, pair<int, string> p2) {
        return p1.first >= p2.first;
    }
};

// to get the encoded message when the message and letter-to-code mapping is given
string encode(string message, unordered_map<char, string> codes) {
    string encoded_message = "";

    for(char x: message)
        encoded_message += codes[x];

    return encoded_message;
}

void HuffmanCode(string message, unordered_map<char, int> freq) {
    // priority queue (min-heap) to generate code for each letter using bottom up parsing.
    // elements in priority queue will be in the form of pairs, where first value in each pair is 
    // the frequency count and second value is a string of letters which comes as leaf nodes on or 
    // below it while parsing upward.
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
    unordered_map<char, string> codes;                // to store letter-to-code mapping

    // populate priority queue (leaf nodes)
    for(auto letter: freq)
        pq.push(make_pair(letter.second, string(1, letter.first)));

    // generate code for each letter using bottom up parsing
    while(pq.size() > 1) {
        // get two smallest nodes
        pair<int, string> letter1 = pq.top(); pq.pop();    // left node
        pair<int, string> letter2 = pq.top(); pq.pop();    // right node

        // append 0 at the beginning of code for each letter since they will be in left sub-tree
        for(auto character: letter1.second)
            codes[character] = "0" + codes[character];

        // append 1 at the beginning of code for each letter since they will be in right sub-tree
        for(auto character: letter2.second)
            codes[character] = "1" + codes[character];

        // push back result after adding count of both nodes and combining letters from both nodes
        pq.push(make_pair(letter1.first+letter2.first, letter1.second+letter2.second));
    }

    // print all details
    cout << "Given message : " << message << "\n";
    cout << "Encoded message : " << encode(message, codes) << "\n\n";
    cout << "Code for each letters : \n";
    for(auto letter: codes)
        cout << letter.first << " --> " << letter.second << "\n";
}

int main() {
    string message = "aabaaacdbaacc";                // message that we need to send
    unordered_map<char, int> frequency;              // to keep track of frequency of characters

    for(char x: message)
        frequency[x]++;

    HuffmanCode(message, frequency);

    return 0;
}