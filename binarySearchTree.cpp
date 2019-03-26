#include<iostream>
#include<queue>
using namespace std;
struct bstNode
{
	int info;
	bstNode* left;
	bstNode* right;
};
bstNode* getNode(int info)
{
	bstNode* newNode = new bstNode();
	newNode->info = info;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
bstNode* insertNode(bstNode* root,int info)
{
	if(root == NULL)
		root = getNode(info);
	else if(info <= root->info)
		root->left = insertNode(root->left,info);
	else if(info > root->info)
		root->right = insertNode(root->right,info);
	return root;
}
void searchNode(bstNode* root,int info)
{
	if(root == NULL)
		cout<<info<<" Not Found"<<endl;
	else if(root->info == info)
		cout<<info<<" Found"<<endl;
	else if(info < root->info)
		searchNode(root->left,info);
	else if(info > root->info)
		searchNode(root->right,info);
}
void levelOrder(bstNode* root)
{
	if(root == NULL)
		return;
	queue<bstNode*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		bstNode* current = Q.front();
		cout<<current->info<<"\t";
		if(current->left != NULL)
			Q.push(current->left);
		if(current->right != NULL)
			Q.push(current->right);
		Q.pop();
	}
	cout<<endl;
}
void preOrder(bstNode* root)
{
	if(root == NULL)
		return;
	cout<<root->info<<"\t";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(bstNode* root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->info<<"\t";
	inOrder(root->right);
}
void postOrder(bstNode* root)
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->info<<"\t";
}
bstNode* findMin(bstNode* root)
{
	while(root->left != NULL)
		root = root->left;
	return root;
}
bstNode* deleteNode(bstNode* root,int info)
{
	if(root == NULL)
	{
		cout<<"Element Does No Exist"<<endl;
		return root;
	}
	else if(info < root->info)
		root->left = deleteNode(root->left,info);
	else if(info > root->info)
		root->right = deleteNode(root->right,info);
	else 
	{
		if(root->left == NULL & root->right == NULL)
		{
				delete root;
				root = NULL;	
		}
		else if(root->left == NULL)
		{
			bstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			bstNode* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			bstNode* min = findMin(root->right);
			root->info = min->info;
			root->right = deleteNode(root->right,min->info);
		}
	}
	return root;
}
int main()
{
	bstNode* root = NULL;
	int ch,n;
	while(1)
	{
		cout<<"1. Insert Node\n2. Search Node\n3. Level Order Traversal\n4. Pre Order Traversal\n5. In Order Traversal\n6. Post Order Traversal\n7. Delete Node\n8. Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter Number to be Inserted : ";
					cin>>n;
					root = insertNode(root,n);
					cout<<n<<" Inserted\n";
					break;
			case 2: cout<<"Enter Number to be Searched : ";
					cin>>n;
					searchNode(root,n);
					break;
			case 3: cout<<"Level Order Traversal :\n";
					levelOrder(root);
					cout<<endl;
					break;
			case 4: cout<<"Pre Order Traversal :\n";
					preOrder(root);
					cout<<endl<<endl;
					break;
			case 5: cout<<"In Order Traversal :\n";
					inOrder(root);
					cout<<endl<<endl;
					break;
			case 6: cout<<"Post Order Traversal :\n";
					postOrder(root);
					cout<<endl<<endl;
					break;
			case 7: cout<<"Enter Number to be Deleted : ";
					cin>>n;
					root = deleteNode(root,n);
					cout<<n<<" Deleted\n";
					break;
			case 8: return 0;
		}	
	}
	return 0;
}