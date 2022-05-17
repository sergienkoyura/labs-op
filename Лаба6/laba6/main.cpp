#include "func.h"
int main() {
    cout<<"Input the size of a tree:\n";
    int n;
    cin>>n;
    vector<int> m = genArr(n); //генеруємо послідовність чисел
    printArr(m);
    Node* tree = makeTree(m, 0, n, 0); //формуємо дерево
    outputTree(tree); //обходимо дерево
    printNodes(tree); //виводимо внутрішні вузли
}
