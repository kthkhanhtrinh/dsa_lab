// BINARY TREE
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int countTwoChildrenNode(Node *root)
{
    if(root == nullptr)
        return 0;
    return (root->pLeft && root->pRight) + countTwoChildrenNode(root->pLeft)
                                         + countTwoChildrenNode(root->pRight);
}

int countTwoChildrenNode()
{
    return countTwoChildrenNode(root);   
}
// STUDENT ANSWER END

//////////////////////////////////////////////////////////////

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int getHeight(Node* root)
{
    if(!root)
        return 0;
    else
    {
        int left_h = getHeight(root->pLeft);
        int right_h = getHeight(root->pRight);
        if(left_h > right_h)
            return left_h + 1;
        else
            return right_h + 1;
    }
}

int getHeight() {
    // TODO: return height of the binary tree.
    return getHeight(root);
}

 void preOrder(Node* node, ostringstream &ss) {
    if (node == nullptr) return;
    ss << node->value << " ";           
    preOrder(node->pLeft, ss);           
    preOrder(node->pRight, ss);          
}

    // Public preOrder function
string preOrder() {
    std::ostringstream ss;
    preOrder(root, ss);
    return ss.str();
}

void inOrder(Node* node, ostringstream &ss) {
    if (node == nullptr) return;
    inOrder(node->pLeft, ss);            // Traverse left subtree
    ss << node->value << " ";            // Visit the root
    inOrder(node->pRight, ss);           // Traverse right subtree
}

// Public inOrder function
string inOrder() {
    ostringstream ss;
    inOrder(root, ss);
    return ss.str();
}

// Post-order traversal helper
void postOrder(Node* node, ostringstream &ss) {
    if (node == nullptr) return;
    postOrder(node->pLeft, ss);          
    postOrder(node->pRight, ss);         
    ss << node->value << " ";            
}

string postOrder() {
    std::ostringstream ss;
    postOrder(root, ss);
    return ss.str();
}

// STUDENT ANSWER END

//////////////////////////////////////////////////////////////

//Helping functions

int sumOfLeafs(Node* root)
{
    if(root == nullptr)
        return 0;
    
    if(!root->pLeft && !root->pRight)
        return root->value;
    
    return sumOfLeafs(root->pLeft) + sumOfLeafs(root->pRight);
 
}

int sumOfLeafs(){
    //TODO
    return sumOfLeafs(root);
}

//////////////////////////////////////////////////////////////

void longestPathSum(BTNode *root, int currSum, int currPath, int& maxSum, int& maxPath)
{
    if(root == nullptr) return;
    currSum += root->val;
    currPath += 1;
    if(maxPath < currPath)
    {
        maxPath = currPath;
        maxSum = currSum;
    }
    else if(maxPath == currPath && maxSum < currSum)
        maxSum = currSum;
    
    longestPathSum(root->left, currSum, currPath, maxSum, maxPath);
    longestPathSum(root->right, currSum, currPath, maxSum, maxPath);

}

int longestPathSum(BTNode* root) {
    if(root == nullptr) return 0;
    int maxSum = root->val;
    int maxPath = 1;
    longestPathSum(root->left, root->val, 1, maxSum, maxPath);
    longestPathSum(root->right, root->val, 1, maxSum, maxPath);
    return maxSum;

}

//////////////////////////////////////////////////////////////

void BFS()
{
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        cout << current->value << " ";
        if (current->pLeft)
            q.push(current->pLeft);
        if (current->pRight)
            q.push(current->pRight);
    }
    
}
//////////////////////////////////////////////////////////////

int sumDigitPath(BTNode* root, int currSum) {
    if (!root)
        return 0;
    
    currSum = (currSum * 10 + root->val) % 27022001 ;
    if (!root->left && !root->right) {
        return currSum;
    }
    
    return (sumDigitPath(root->left, currSum) +
           sumDigitPath(root->right, currSum)) % 27022001;
}

int sumDigitPath(BTNode* root) {
    return sumDigitPath(root, 0);
}
//////////////////////////////////////////////////////////////

int lowestAncestor(BTNode* root, int a, int b) {
    if (!root)
        return -1;
        
    if (root->val == a || root->val == b)
        return root->val;
        
    int left = lowestAncestor(root->left, a, b);
    int right = lowestAncestor(root->right, a, b);
    
    if(left != -1 && right != -1)
        return root->val;
    
    if(left != -1)
        return left;
    else
        return right;
}

//////////////////////////////////////////////////////////////
