//Written by: Daniel Adewetan
//Date: 12/1/2022
//Project 5
#include<iostream>
using namespace std;
template<typename T>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	class BinTree
	{
		Node<int>* root;

	public:
		BinTree()
		{
			root == NULL;
		}

		~BinTree()
		{
			delete root;
		}

	private:
		struct Node* Delete(struct Node* root, int data)
		{
			if (root == NULL)
				return root;
			else if (data < root->data) root->left = Delete(root->left, data);
			else if (data > root->data) root->right = Delete(root->right, data);

			else
			{
				if (root->left == NULL && root->right == NULL)
				{
					delete root;
					root = NULL;
				}

				else if (root->left == NULL)
				{
					struct Node* temp = root;
					root = root->right;
					delete temp;
				}

				else if (root->right == NULL)
				{
					struct Node* temp = root;
					root = root->left;
					delete temp;
				}
			}
			return root;
		}

		Node* Insert(Node* root, char data)
		{
			if (root == NULL)
			{
				root = new Node();
				root->data = data;
				root->left = root->right = NULL;
			}

			else if (data <= root->data)
			{
				root->left = Insert(root->left, data);
			}

			else
				root->right = Insert(root->right, data);

			return root;
		}

		void displayTree(Node<int>* root)
		{
			if (root == NULL)
				return root;
			cout << root->data << ":";
		}

	public:
		void deleteTree(int data)
		{
			root = Delete(data, root);
		}

		void displayTree()
		{
			displayTree(root);
		}

	private:
		Node<int>* Insert(int data, Node<int>* temp)
		{
			if (temp == NULL)
			{
				Node<int>* newNode = new Node<int>(data);
				return newNode;
			}

			if (data < temp->data)
			{
				temp->left = Insert(data, temp->left);
			}

			else
			{
				temp->right = Insert(data, temp->right);
			}

			return temp;
		}

	public:
		void Insert(int data)
		{
			this->root = Insert(data, this->root);
		}

	private:
		bool DataInputSearch(int data, Node<int>* temp)
		{
			if (temp == NULL)
			{
				return false;
			}
		}

		if(temp->data == data)
		{
		return true;
		}

		else if (data < temp->data)
		{
			return DataInputSearch(data, temp->left);
		}

		else {

			return DataInputSearch(data, temp->right);
		}

		public:
			bool findingTree(int data)
			{
				return DataInputSearch(data, root);
			}

	};
};

int main()
{
	int input;

	int i = 0;

	cout << "Please enter numbers for the binary search tree: " << endl;

	cin >> input;

	int search;

	for (i = 0; i < input; i++)
	{
		cin >> search;
	}

	if (input < 16)
	{
		cout << "You MUST enter at the very least 16 integers: " << endl;
	}

	system("PAUSE");
}