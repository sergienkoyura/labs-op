#include "func.h"
Node* makeTree(vector<int> m, int from, int n, int pos){ //формуємо дерево
    if(n==0)return NULL;
    Node* temp = new Node(m[from], pos); //створюємо вузл, передаємо перший елемент масиву(вектору)
    vector<int> up, down; //створюємо вектори для елементів більших та менших за батька
    for(int i = 1;i<n;i++){
        if(m[i]>temp->data) //порівнюємо елементи масиву з батьком
            up.push_back(m[i]);
        else
            down.push_back(m[i]);
    }
    temp->left = makeTree(down, from, down.size(),pos+1); //рекурсивно передаємо вектор (менший) в ліву гілку
    temp->right = makeTree(up, from, up.size(), pos+1); //.. рекурсивно передаємо вектор (більший) в праву гілку
    return temp;
}

void outputTree(Node* tree){ //обхід дерева (прямий обхід)
    SetConsoleOutputCP(CP_UTF8); //підключаємо для виведення дерева
    Node*current = tree; //поточний вузол
    vector<Node*> temp; //стек
    int root = current->data; //визначаємо корінь
    while (current != nullptr || !temp.empty()){
        while (current != nullptr){
            temp.push_back(current); //заповнюємо стек
            if(temp.back()->data < root){ //форматоване виведення
                for(int i =0;i<temp.back()->level;i++){
                    cout<<"   ";
                }
                cout <<"└──"<<temp.back()->data<<endl;
            }

            else if(temp.back()->data == root)
                cout <<"└──"<<temp.back()->data <<"\n";
            else{
                for(int i =0;i<temp.back()->level;i++){
                   cout<<"   ";
                }
                cout <<"└──"<<temp.back()->data <<"\n";
            }

            current = current->left; //переміщаємо вузол на лівого нащадка
        }
        current = temp.back()->right; //переміщаємо вузол на правого нащадка
        temp.pop_back(); //видаляємо останній елемент стека
    }
}

vector<int> genArr(int n){ //генеруємо унікальний масив чисел від 1 до n
    srand(time(nullptr));
    vector<int> m;
    for(int i =0;i<n;i++){
        m.push_back(rand()%n+1);
        bool checker = false;
        for(int j =0;j<m.size()-1;j++){ //перевірка на унікальність
            for(int k = 1;k<m.size();k++){
                if(m[j]==m[k+j])
                    checker = true;
            }
        }
        if(checker){ //якщо елемент повторився - знищуємо його і повертаємось на ітерацію назад
            m.pop_back();
            i--;
        }
    }
    return m;
}

void printArr(vector<int> m){ //виведення згенерованих чисел для заповнення дерева
    cout<<"Numbers for the tree:\n";
    for(int n : m)
        cout<<n<<" ";
    cout<<endl;
}

void printNodes(Node*tree){ //виведення внутрішніх вузлів дерева
    Node*current = tree; //поточний вузол
    vector<Node*> temp; //стек
    cout<<"\nNodes:\n";
    while (current != nullptr || !temp.empty()){
        while (current != nullptr){
            temp.push_back(current);
            if(temp.back()->left!=nullptr || temp.back()->right!=nullptr) //перевіряємо чи вузол має нащадків
                cout<<temp.back()->data<<", "<<temp.back()->level<<" level"<<endl;
            current = current->left;
        }
        current = temp.back()->right;
        temp.pop_back();
    }
}