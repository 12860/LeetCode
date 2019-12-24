/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int ans;
    int dp_solve(TreeNode * root){
        if(root==NULL) return 0;
        int sum=root->val;
        int ls=0,rs=0;

        if(root->left!=NULL) ls=dp_solve(root->left);
        if(root->right!=NULL) rs=dp_solve(root->right);
        if(ls>0) sum+=ls;
        if(rs>0) sum+=rs;
        int next=max(ls,rs);

        ans=max(ans,sum);
        
        //return max(next,next+sum);
        return max(0,max(ls,rs))+root->val;
    }
     
    int maxPathSum(TreeNode * root) {
        // write your code here
        if(root==NULL) return 0;
        ans=-1000000;
        dp_solve(root);
        return ans;
    }
};
