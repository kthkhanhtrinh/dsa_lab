//BINARY SEARCH TREE
void add(T value) {
    root = addRec(root, value); // Use a recursive helper function
}

Node* addRec(Node* root, T value) {
    if (root == nullptr) {
        return new Node(value); // Create a new node if the tree is empty or we reach a null child
    }

    // If the value is smaller, recurse to the left subtree
    if (value < root->value) {
        root->pLeft = addRec(root->pLeft, value);
    }
    // If the value is greater, recurse to the right subtree
    else if (value > root->value) {
        root->pRight = addRec(root->pRight, value);
    }
    // If the value is equal, add to the left subtree as per problem statement
    else {
        root->pLeft = addRec(root->pLeft, value);
    }

    return root;
}

void deleteNode(T value) {
    root = deleteRec(root, value); // Use a recursive helper function
}

Node* deleteRec(Node* root, T value) {
    if (root == nullptr) {
        return nullptr; // If the tree is empty or the value is not found
    }

    // Traverse the tree to find the node to delete
    if (value < root->value) {
        root->pLeft = deleteRec(root->pLeft, value);
    } else if (value > root->value) {
        root->pRight = deleteRec(root->pRight, value);
    } else {
        // Node to be deleted found

        // Case 1: No children
        if (root->pLeft == nullptr && root->pRight == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->pLeft == nullptr) {
            Node* temp = root->pRight;
            delete root;
            return temp;
        }
        if (root->pRight == nullptr) {
            Node* temp = root->pLeft;
            delete root;
            return temp;
        }

        // Case 3: Two children
        // Find the inorder successor (smallest in the right subtree)
        Node* successor = findMin(root->pRight);

        // Replace the value of the current node with the successor's value
        root->value = successor->value;

        // Delete the inorder successor
        root->pRight = deleteRec(root->pRight, successor->value);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->pLeft != nullptr) {
        root = root->pLeft;
    }
    return root;
}

//////////////////////////////////////////////////////////////
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
T getMin(Node *root)
{
    if(root == nullptr)
        return 0;
    
    if(root->pLeft == nullptr)
        return root->value;
    
    return getMin(root->pLeft);
}
T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    return getMin(root);

}
T getMax(Node *root)
{
    if(root == nullptr)
        return 0;
    
    if(root->pRight == nullptr)
        return root->value;
    
    return getMax(root->pRight);
}

T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    return getMax(root);
}

// STUDENT ANSWER END
//////////////////////////////////////////////////////////////
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

bool find(Node* root, T i)
{
    if (root == nullptr)
        return false;
    // cout << root->value << " ";
    if(root->value == i)
        return true;
    
    if(i < root->value)
        return find(root->pLeft, i);
    else
        return find(root->pRight, i);
    // return true;
}

bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    return find(root, i);
}

T sum(Node* root, T l, T r)
{
    if(root == nullptr)
        return 0;
    if(root->value < l)
        return sum(root->pRight, l, r);
    else if(root->value > r)
        return sum(root->pLeft, l, r);

    return root->value + sum(root->pLeft, l, r)
                       + sum(root->pRight, l, r);
}

T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    return sum(root, l, r);
}

// STUDENT ANSWER END
//////////////////////////////////////////////////////////////
vector<int> levelAlterTraverse(BSTNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    queue<BSTNode*> q;
    q.push(root);

    bool leftToRight = true; 

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; ++i) {
            BSTNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }

        result.insert(result.end(), level.begin(), level.end());

        leftToRight = !leftToRight;
    }

    return result;
}
//////////////////////////////////////////////////////////////
int rangeCount(BTNode* root, int lo, int hi) {
    if (!root) {
        return 0;
    }

    int count = (root->val >= lo && root->val <= hi) ? 1 : 0;

    count += rangeCount(root->left, lo, hi);
    count += rangeCount(root->right, lo, hi);

    return count;
}
//////////////////////////////////////////////////////////////
int singleChild(BSTNode* root) {
    if (!root) return 0;

    int count = 0;
    if ((root->left && !root->right) || (!root->left && root->right)) {
        count = 1;
    }

    count += singleChild(root->left);
    count += singleChild(root->right);

    return count;
    
}
//////////////////////////////////////////////////////////////
int kthSmallestHelper(BSTNode* root, int& k) {
    if (!root) return -1; 

    // Search in the left subtree
    int left = kthSmallestHelper(root->left, k);
    if (k == 0) return left;

    --k;
    if (k == 0) return root->val; 


    return kthSmallestHelper(root->right, k);
}

int kthSmallest(BSTNode* root, int k) {
    return kthSmallestHelper(root, k);
}

//////////////////////////////////////////////////////////////
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (!root) return nullptr;

    if (root->val < lo) {
        return subtreeWithRange(root->right, lo, hi);
    }
    if (root->val > hi) {
        return subtreeWithRange(root->left, lo, hi);
    }

    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);

    return root;
}