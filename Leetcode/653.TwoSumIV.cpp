// Two Sum IV - Input is a BST
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> mp;
    bool calc(TreeNode* root, int k){
        if(root==NULL)
            return false;
        if(mp[k-root->val]) return true;
        mp[root->val]++;
        return (calc(root->left, k)|| calc(root->right, k));
        
    }
    bool findTarget(TreeNode* root, int k) {
        return calc(root, k);
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(6);
    root->right->right=new TreeNode(6);

    Solution s;
    cout<<s.findTarget(root, 9);
    return 0;
}
