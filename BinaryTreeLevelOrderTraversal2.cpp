#include <vector>;
#include <queue>;
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class BinaryTreeLevelOrderTraversal2
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> levels;
		if (!root) return levels;

		queue<TreeNode*> Q;
		Q.push(root);

		while (!Q.empty()) {
			int n = Q.size();
			vector<int> level(n);

			for (int i = 0; i < n; i++) {
				TreeNode* f = Q.front();
				Q.pop();
				level[i] = f->val;

				if (f->left) Q.push(f->left);
				if (f->right) Q.push(f->right);
			}
			levels.push_back(level);
		}

		reverse(levels.begin(), levels.end());
		return levels;
	}
};

