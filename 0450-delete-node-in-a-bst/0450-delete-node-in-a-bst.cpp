/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* findlargestleft(TreeNode* root){
        if(root->right == NULL) return root;
        return findlargestleft(root->right);
    }

    TreeNode* func(TreeNode* root,int val){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;

        TreeNode* rightchild = root->right;
        TreeNode*  temp = findlargestleft(root->left);
        temp->right = rightchild;

        return root->left;  
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val == key) return func(root,key);

        TreeNode* temp = root;

        while(root!=NULL){
            if(root->val > key){
                if(root->left!=NULL && root->left->val == key){
                    root->left=func(root->left,key);
                    break;

                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val == key){
                    root->right=func(root->right,key);
                    break;

                }
                else{
                    root=root->right;
                }
            }
        }

        return temp;
    }
};