#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct node {
    int value;
    unique_ptr<node> next;
};

struct list {
    int size = 0;
    unique_ptr<node> head = nullptr;
};

// Crea un nodo como unique_ptr
unique_ptr<node> createNode(int value) {
    return make_unique<node>(node{value, nullptr});
}

// Inserta al frente
void pushFront(list& lista, int value) {
    auto newNode = createNode(value);
    newNode->next = move(lista.head);
    lista.head = move(newNode);
    lista.size++;
}

// Inserta al final
void pushBack(list& lista, int value) {
    auto newNode = createNode(value);
    if (!lista.head) {
        lista.head = move(newNode);
    } else {
        node* current = lista.head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = move(newNode);
    }
    lista.size++;
}

// Inserta en posición específica
void insert(list& lista, int pos, int value) {

    if (pos < 0) return;

    if(pos >= lista.size) {
        pushBack(lista, value);
        lista.size++;
        std::cout << "Posicion fuera de rango, se insertara al final" << std::endl;
        return;
    }

    if (pos == 0) {
        pushFront(lista, value);
        lista.size++;
        return;
    }

    auto newNode = createNode(value);
    node* current = lista.head.get();

    for (int i = 0; i < pos - 1; ++i) {

        current = current->next.get();

    }

    newNode->next = move(current->next);
    current->next = move(newNode);

    lista.size++;
}

void erase(list& lista, int pos) {
    if (pos < 0) return;

    if (pos >= lista.size) {
        erase(lista, lista.size - 1);
        lista.size--;
        std::cout << "Posicion fuera de rango, se elimino el ultimo" << std::endl;
        return;
    }

    if (pos == 0) {
        lista.head = move(lista.head->next);
    } else {
        node* current = lista.head.get();
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next.get();
        }
        current->next = move(current->next->next);
    }

    lista.size--;
}

string print_list(const list& lista) {
    string result = "";
    node* current = lista.head.get();
    while (current) {
        result += to_string(current->value) + " ";
        current = current->next.get();
    }
    return result;
}

int main() {
    
    list lista;

    pushBack(lista, 10);
    pushBack(lista, 20);
    pushFront(lista, 5);      
    insert(lista, 1, 7);       
    insert(lista, 0, 2);       
    insert(lista, 5, 30);     
    erase(lista, 2);           
    erase(lista, 0);         
    erase(lista, 3);           

    cout << "Lista final: " << print_list(lista) << endl; 

    return 0;
}
