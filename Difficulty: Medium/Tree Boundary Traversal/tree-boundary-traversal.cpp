class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> v;
        if (root == NULL) return v;

        // Root (only if not leaf)
        if (!(root->left == NULL && root->right == NULL))
            v.push_back(root->data);

        // Left boundary (excluding leaves)
        solve(root->left, v);

        // All leaves
        solve2(root, v);

        // Right boundary (excluding leaves, bottom-up)
        vector<int> temp;
        solve3(root->right, temp);
        v.insert(v.end(), temp.begin(), temp.end());

        return v;
    }

    // Left boundary
    void solve(Node* root, vector<int>& v) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return; // skip leaves
        v.push_back(root->data);
        if (root->left) solve(root->left, v);
        else solve(root->right, v);
    }

    // Leaves
    void solve2(Node* root, vector<int>& v) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->data);
            return;
        }
        solve2(root->left, v);
        solve2(root->right, v);
    }

    // Right boundary (bottom-up)
    void solve3(Node* root, vector<int>& v) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return; // skip leaves
        if (root->right) solve3(root->right, v);
        else solve3(root->left, v);
        v.push_back(root->data); // add after recursion → bottom-up
    }
};
