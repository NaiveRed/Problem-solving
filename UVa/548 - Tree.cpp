#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>

//�̤p���|�A�p��̫�Oleaf�����|�W���`�M�A���ΧP�_�֪�level����U��
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

	�Q�� post_index ���ڸ`�I�A�]�N�O4

	�N inorder ������l��{3,2,1}�M{5,7,6}

	�k�l�𪺮ڸ`�I(rchild)�� post_index-1�Y�i(LRV)
	
	���l�𪺮ڸ`�I(lchild)�� post_index-(in_end-pos)
				
	in_begin   pos	  in_end
		  v 	v       v
	in:   3 2 1 4 5 7 6 x
	post: 3 1 2 5 6 7 4 x
              ^     ^ ^----post_index
              ^     ^
			  ^   root of right subtree    
			  ^
       root of left subtree

	�Q�� postorder �A Left-Right-Val ���S�ʡA��k�l���I�����L�C
	
	�t�@��k�i��vector���������B�z�k��A��ؾ���pop��postorder�A�ѤU���N�i������postorder�B�z���l��C

	��C�Ӥl�𶰦X ex.{3,2,1}{5,7,6} ���@�˪���(�V�U���j�Adivide and conquer)

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