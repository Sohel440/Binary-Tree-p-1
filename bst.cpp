#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node *buildTree(node *root)
{

  cout << " Enter the data : " << endl;
  int data;
  cin >> data;
  root = new node(data);
  if (data == -1)
  {
    return NULL;
  }

  cout << "Enter data for left insert : " << data << endl;
  root->left = buildTree(root->left);

  cout << "Enter data for right insert : " << data << endl;
  root->right = buildTree(root->right);
  return root;
}

void levelorderTraversal(node *root)
{

  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {

    node *temp = q.front();
    
    q.pop();
    if (temp == NULL)
    {

      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

void inorderTraversal(node * root){
 if (root == NULL){
  return;

 }

 inorderTraversal(root->left);
 cout << root->data << " ";
 inorderTraversal(root->right);

}
void preorderTraversal(node * root){
 if (root == NULL){
  return;

 }

 cout << root->data << " ";
 preorderTraversal(root->left);
 preorderTraversal(root->right);

}

int main()
{
  node *root = NULL;

  // creating a tree
  root = buildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  cout << "Printing the Tree : " << endl;
  levelorderTraversal(root);

  cout << " Inoreder tree implementation : "<<endl; inorderTraversal(root); cout <<endl;
  cout << " preoreder tree implementation : "<< endl; preorderTraversal(root);

  return 0;
}