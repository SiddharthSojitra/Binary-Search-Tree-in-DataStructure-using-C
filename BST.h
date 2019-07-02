typedef struct Node
{
	int data;
	struct Node *left, *right;
}NODE;

NODE *createNode()
{
	NODE *n =(NODE *)malloc(sizeof(NODE));
	n->data = NULL;
	n->left = NULL;
	n->right = NULL;
}

NODE *insertBST(NODE * root, int val)
{
	if(root == NULL)
	{
		NODE *n = createNode();
		n->data = val;
		root = n;
	}
	else
	{
		if(root->data < val)
			root->right = insertBST(root->right, val);
		else if(root->data > val)
			root->left = insertBST(root->left, val);
	}
	return root;
}

NODE *deleteBST(NODE * root, int val)
{
	NODE *tmp = NULL;
	int	sucval;

	if(root == NULL)
		printf("\n VALUE NOT FOUND \n");
	else if(val > root->data)
			root->right = deleteBST(root->right, val);
	else if(val < root->data)
			root->left = deleteBST(root->left, val);
	else
	{
		if(root->left != NULL && root->right != NULL)
		{
			sucval = inordersucc(root);
			root->data = sucval;
			root->right = deleteBST(root->right, sucval);
		}
		else if(root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left != NULL && root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return tmp;
		}
		else if(root->left == NULL && root->right != NULL)
		{
			tmp = root->right;
			free(root);
			return tmp;
		}
	}
	return root;
}

void preorder(NODE *root)
{
	if(root != NULL)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(NODE *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

void postorder(NODE *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}

int inordersucc(NODE *root)
{
	NODE *tr = root;
	tr = tr->right;
	while(tr->left != NULL)
		tr = tr->left;
	return (tr->data);
}
