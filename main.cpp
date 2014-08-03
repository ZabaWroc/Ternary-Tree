#include <iostream>

using namespace std;

struct TreeNode {                                   //tworzymy strukture wezla drzewa
    int value;
    TreeNode *left, *mid, *right;
};

const int LEFT = 1;                                 //kierunki, w ktorych powstana wezly
const int MID = 2;
const int RIGHT = 3;

void add(TreeNode *tree, int direction, int i)         //dodawanie kolejnych wezlow
{
    TreeNode *nowy = new TreeNode;
    nowy->value = i;
    nowy->left = nowy->mid = nowy->right = NULL;    //zerowanie poczatkowych wartosci nowych wezlow
    if(direction == LEFT)                           //kierunki, w ktorych powstana wezly
        tree->left = nowy;
    else
        if(direction == RIGHT)
            tree->right = nowy;
    else
        tree->mid = nowy;
}

TreeNode *root;                                      //stworzenie glownego wezla - korzenia

void initialize(int i)                                //inicjowanie wartosci glownego wezla
{
    root = new TreeNode;
    root->value = i;
    root->left = root->mid = root->right = NULL;
}

void display_node(TreeNode *tree, int level)                  //wyswietlanie wezlow
{
    if(tree == NULL) { cout << ""; return;}
    for(int i = 0; i < level - 1; i++) cout << " | ";
    if(level>0) cout << "\\---";
    cout << tree->value << endl;
    display_node(tree->left, level +1);
    display_node(tree->mid, level +1);
    display_node(tree->right, level +1);
}

int main()
{
    initialize(1);                                      //wartosc korzenia = 1

    add(root, LEFT, 2);                                //wezly na 1 poziomie
    add(root, MID, 3);
    add(root, RIGHT, 4);

    add(root->left, LEFT, 5);                          //wezly na 2 poziomie
    add(root->left, MID, 6);
    add(root->left, RIGHT, 7);

    add(root->mid, LEFT, 8);
    add(root->mid, MID, 9);
    add(root->mid, RIGHT, 10);

    add(root->right, LEFT, 11);
    add(root->right, MID, 12);
    add(root->right, RIGHT, 13);

    cout << "TERNARY TREE:" << endl << endl;
    display_node(root, 1);

    return 0;
}
