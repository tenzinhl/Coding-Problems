#include <string>
#include <unordered_set>
#include <iostream>
#include <cstring>

using namespace std;

enum ErrorTypes
{
    NO_ERROR,
    ERROR1,
    ERROR2,
    ERROR3,
    ERROR4,
    ERROR5,
    NUM_ERRORS
};

class Node
{
public:
    Node() = default;
    explicit Node(char name) { this->name = name; }
    char name = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    bool isChild = false;
};

/**
 * @param[in] nodeString: a tree node in the string format described by
 *      the problem.
 * 
 * @return `true` if string is formatted correctly, `false` otherwise
 */
bool isNodeStringValid(string nodeString)
{
    if (nodeString.length() == 5 &&
        nodeString[0] == '(' &&
        nodeString[4] == ')' &&
        nodeString[2] == ',' &&
        nodeString[1] >= 'A' && nodeString[1] <= 'Z' &&
        nodeString[3] >= 'A' && nodeString[1] <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Populates an array of nodes using the next line of input in stdin
 * 
 * @param[out] rootDestination: the root of the tree will be stored in this out parameter.
 *      If more than one root then its value is undefined
 * 
 * @return a code representing any detected error, with highest priority error
 *      returned if multiple errors detected.
 */
ErrorTypes parseInput(Node*& rootDestination)
{
    Node* nodes[26];
    bool isTreeRoot[26];
    unordered_set<string> seenPairs;
    // Store whether error number has been detected.
    bool errors[NUM_ERRORS];

    // Initialization
    memset(errors, false, sizeof(errors));
    for (int i = 0; i < 26; i++)
    {
        nodes[i] = nullptr;
    }

    string input;
    getline(cin, input);

    // Input format is strict. Make sure valid number of characters
    if ((input.length() - 5) % 6 != 0)
    {
        return ERROR1;
    }

    size_t start = 0;
    while (start + 4 < input.length())
    {
        string nodeString = input.substr(start, 5);
        start += 6;
        if (!isNodeStringValid(nodeString))
        {
            return ERROR1;
        }

        // Check to see if this is a duplicate pair
        if (seenPairs.count(nodeString))
        {
            errors[ERROR2] = true;
        }
        seenPairs.insert(nodeString);

        // If we've already seen an ERROR2 the only error
        // that can surpass it is error1, so we can just continue
        // to check for invalid input format
        if (errors[ERROR2])
        {
            continue;
        }

        char parent = nodeString[1] - 'A';
        char child = nodeString[3] - 'A';

        // Check if nodes are new
        if (nodes[parent] == nullptr)
        {
            nodes[parent] = new Node(parent + 'A');
            isTreeRoot[parent] = true;
        }
        if (nodes[child] == nullptr)
        {
            nodes[child] = new Node(child + 'A');
        }

        // A node can only have one parent, otherwise it must mean either
        // ERROR5 or ERROR4 has occurred. Because either one or more of its
        // upstream parents converge forming a closed loop (ERROR5) or they never
        // converge and leave more than one dangling root (ERROR4). Consider `(A,C) (B,C)` 
        // or `(A,B) (B,C) (C,B)`. We indicate lower priority as it will be overridden
        // by higher priority error if it's an ERROR4
        if (nodes[child]->isChild == true)
        {
            errors[ERROR5] = true;
        }

        nodes[child]->isChild = true;
        isTreeRoot[child] = false;

        if (nodes[parent]->left != nullptr && nodes[parent]->right != nullptr)
        {
            // Node has more than two children
            errors[ERROR3] = true;
            // Don't need to worry about updating graph to have this pair
            // as the only errors with higher priority than this do not need
            // this information.
        }
        else if (nodes[parent]->left != nullptr)
        {
            nodes[parent]->right = nodes[child];
        }
        else
        {
            nodes[parent]->left = nodes[child];
        }
    }

    int rootCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (isTreeRoot[i])
        {
            rootCount++;
            rootDestination = nodes[i];
        }
    }
    if (rootCount > 1)
    {
        errors[ERROR4] = true;
    }
    else if (rootCount == 0)
    {
        // Graph with no roots is a cyclic graph.
        errors[ERROR5] = true;
    }

    for (int i = 0; i < NUM_ERRORS; i++)
    {
        if (errors[i])
        {
            return static_cast<ErrorTypes>(i);
        }
    }
    return NO_ERROR;
}

void printTree(Node* root)
{
    if (root != nullptr)
    {
        cout << '(' << root->name;
        
        if (root->left != nullptr && root->right != nullptr &&
            root->left->name < root->right->name)
        {
            printTree(root->left);
            printTree(root->right);
        }
        else
        {
            printTree(root->right);
            printTree(root->left);
        }

        cout << ')';
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    Node* root = nullptr;
    ErrorTypes error = NO_ERROR;
    if ((error = parseInput(root)) != NO_ERROR)
    {
        cout << 'E' << static_cast<int>(error) << endl;
    }
    else
    {
        // Input formed a valid tree. Traverse tree and print it.
        printTree(root);
        cout << endl;
    }
    return 0;
}