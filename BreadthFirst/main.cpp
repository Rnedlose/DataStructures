/* Author: Rodney Nedlose
 * Date: 10.25.19
 * File:   BreadthFirst
 * Purpose: Create a Binary Tree, and then populate it as a Binary Search
 * Tree with 15 random numbers.  Then use Breadth First Traversal to show
 * each level of the tree in left to right order, top to bottom.
 * Input: None.
 * Output: Shows created random numbers list as well as breadth first
 * traversal on the tree afterwords.
 * Exceptions: None.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct node
{
    // The data value of the node
    int data;
    // Left and right node pointers
    node* left;
    node* right;
};

// Create a new node
struct node *newNode(int val)
{
    struct node *temp = new node();
    // Set the node's data value
    temp -> data = val;
    // initialize left and right pointers to null
    temp -> left = NULL;
    temp -> right = NULL;
}

// Insert new nodes into tree
struct node* insertNode(struct node* node, int val)
{
    // Base case for recursive calls
    if (node == NULL)
        return newNode(val);
    // Insert on the left subtree
    else if (val < node -> data)
        node -> left = insertNode(node -> left, val);
    // Insert on the right subtree
    else
        node -> right = insertNode(node -> right, val);

    return node;
}

// Get the height of the tree
int heightOfTree(node* node)
{
    // Base case
    if (node == NULL)
        return 0;
    // Compute height of each subtree recursively
    else
    {
        int lftHeight = heightOfTree(node -> left);
        int rgtHeight = heightOfTree(node -> right);

        // Determine which height is greater and return that value
        if (lftHeight > rgtHeight)
            return (lftHeight + 1);
        else
            return (rgtHeight + 1);
    }
}

// Print nodes on each level
void printLevel (node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root -> data << " ";
    else if (level > 1)
    {
        printLevel(root -> left, level - 1);
        printLevel(root -> right, level - 1);
    }
}
// Function to print level order traversal of a tree
// (Breadth First Traversal)
void BreadthFirstTraversal(node* root)
{
    int hgt = heightOfTree(root);
    for (int i = 1; i <= hgt; i++)
        printLevel(root, i);
}

int main()
{
    // Seed a random time in order to use rand() function
    srand(time(0));

    // Message to programs function
    cout << "This program shows Breadth First Tree Traversal." << endl;
    // Variables needed
    int count = 1;
    vector <int> nums;

    // Get a list of 15 Random numbers between 1 and 100
    while (count <= 15)
    {
        nums.push_back(1 + rand() % 100);
        count++;
    }

    cout << "Here is the generated list of random numbers." << endl;
    // See the list of numbers
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    // Create the tree
    struct node *root = NULL;

    // Add each number from list to tree
    for (int i = 0; i < nums.size(); i++)
        if(root == NULL) root = newNode(nums[i]); // If root is NULL, create the node using the value passed
        else insertNode(root, nums[i]); // If root already exists, insert new node in appropriate place

    cout << "\n";
    cout << "Breadth First Traversal: ";
    BreadthFirstTraversal(root);

    return 0;
}