#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node*& root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }

    if (value < root->value)
        insert(root->left, value);
    else
        insert(root->right, value);
}

int getHeight(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

vector<int> inOrderTraversal(Node* root) {
    vector<int> result;
    if (root == NULL)
        return result;

    vector<int> left = inOrderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    result.push_back(root->value);

    vector<int> right = inOrderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

Node* balanceTree(vector<int>& sortedArray, int first, int last) {
    if (first > last)
        return NULL;

    int mid = (first + last) / 2;
    Node* root = new Node(sortedArray[mid]);

    root->left = balanceTree(sortedArray, first, mid - 1);
    root->right = balanceTree(sortedArray, mid + 1, last);

    return root;
}

bool isBalanced(Node* root){
	int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    bool isBalanced = abs(leftHeight - rightHeight) <= 1;
    
    return isBalanced;
}

bool areTreesEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->value != root2->value)
        return false;

    return areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right);
}

 

int main() {
    // Vetor de valores a serem inseridos na árvore
    int arr[] = {7, 6, 22, 14, 40, 63};
    vector<int> values(arr, arr + sizeof(arr) / sizeof(arr[0]));

    // 1) Construindo a árvore binária
    Node* root = NULL;
    for (size_t i = 0; i < values.size(); ++i)
        insert(root, values[i]);

    // 1.1) Calculando a altura da árvore
    int height = getHeight(root);
    cout << "Altura da árvore: " << height << endl;

    // 1.2) Exibindo a árvore no percurso in-order
    cout << "Árvore resultante (in-order): ";
    vector<int> inOrder = inOrderTraversal(root);
    for (size_t i = 0; i < inOrder.size(); ++i)
        cout << inOrder[i] << " ";
    cout << endl;

    // 1.3) Verificando se a árvore está balanceada
    cout << "A árvore resultante está balanceada? " << (isBalanced(root) ? "Sim" : "Não") << endl;

    // 1.4) Reordenando o vetor com sort e reconstruindo a árvore para balanceá-la
    vector<int> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end());
    Node* root_ordenada = balanceTree(sortedValues, 0, sortedValues.size() - 1);

  
    // 1.5) Reordenando o vetor com percurso e reconstruindo a árvore para balanceá-la
    cout << "Árvore balanceada (in-order): ";
    vector<int> inOrderOrdenada = inOrderTraversal(root);
    Node* root_ordenada2 = balanceTree(sortedValues, 0, sortedValues.size() - 1);
    for (size_t i = 0; i < inOrderOrdenada.size(); ++i)
        cout << inOrderOrdenada[i] << " ";
    cout << endl;

    // 1.6) Comparando as duas árvores
    int balancedHeight = getHeight(root_ordenada);
    cout << "As árvores resultantes estão balanceadas? " << endl;
    cout << "	Vetor ordenado com sort: "<< (isBalanced(root_ordenada) ? "Sim" : "Não") << endl;
    cout << "	Vetor ordenado com percurso in order: "<<(isBalanced(root_ordenada2) ? "Sim" : "Não") << endl;
    cout << "As arvores resultantes sao iguais? "<<(areTreesEqual(root_ordenada,root_ordenada2) ? "Sim" : "Não") << endl;


    return 0;
}

