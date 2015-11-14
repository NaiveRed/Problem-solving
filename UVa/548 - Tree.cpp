#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>

//最小路徑，計算最後是leaf的路徑上的總和，不用判斷誰的level比較下面
struct node
{
	int val;
	int path_sum;
	node* left;
	node* right;
};

int inorder[10000]{}, post[10000]{};

node* getPathMin(node* root, int sum);
node* buildTree(int* in_begin, int* in_end, int post_index);
int main()
{
	std::stringstream ss;
	std::string str;

	while (std::getline(std::cin, str))
	{
		ss.clear();
		ss << str;

		int i(0);

		while (ss >> inorder[i])i++;

		std::getline(std::cin, str);
		ss.clear();
		ss << str;

		i = 0;
		while (ss >> post[i])i++;

		node* root = buildTree(inorder, inorder+i, i-1);

		printf("%d\n", getPathMin(root, 0)->val);

		std::fill(inorder, inorder + 9999, 0);
		std::fill(post, post + 9999, 0);
	}


	return 0;
}
/*build tree by inorder and postorder*/
node* buildTree(int* in_begin, int* in_end, int post_index)
{
	if (post_index<0|| in_begin >= in_end)
		return NULL;

	/*
	ex.
	
	in:   3 2 1 4 5 7 6
	post: 3 1 2 5 6 7 4

	利用 post_index 找到根節點，也就是4

	將 inorder 分成兩子樹{3,2,1}和{5,7,6}

	右子樹的根節點(rchild)為 post_index-1即可(LRV)
	
	左子樹的根節點(lchild)為 post_index-(in_end-pos)
				
	in_begin   pos	  in_end
		  v 	v       v
	in:   3 2 1 4 5 7 6 x
	post: 3 1 2 5 6 7 4 x
              ^     ^ ^----post_index
              ^     ^
			  ^   root of right subtree    
			  ^
       root of left subtree

	利用 postorder ， Left-Right-Val 的特性，把右子樹的點給跳過。
	
	另一方法可用vector之類的先處理右邊，邊建樹邊pop掉postorder，剩下的就可直接用postorder處理左子樹。

	對每個子樹集合 ex.{3,2,1}{5,7,6} 做一樣的事(向下遞迴，divide and conquer)

	*/
	int* pos = std::find( in_begin, in_end, post[post_index ]);

	node* n = new node;
	n->val = post[post_index];

	n->left = buildTree(in_begin, pos, post_index-(in_end-pos));
	n->right = buildTree(pos + 1, in_end, post_index-1);

	return n;
}
node* getPathMin(node* root, int sum)
{
	if (!root)
		return NULL;

	sum += root->val;
	root->path_sum = sum;

	node* lc = getPathMin(root->left, sum);
	node* rc = getPathMin(root->right, sum);

	if (!lc&&!rc)
		return root;
	else if (!lc)
		return rc;
	else if (!rc)
		return lc;

	return lc->path_sum < rc->path_sum ? lc : rc;
}