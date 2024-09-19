#include <iostream>

bool ProverkaNaPalindrom(int number) {

    int originalNumber = number;
    int reversedNumber = 0;

    while (number > 0) {

        int lastDigit = number % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        number = number / 10;

    }

    return originalNumber == reversedNumber;

}

int FirstDigit(int number) {

    int fdigit;

    while (number > 0) {

        fdigit = number % 10;
        number /= 10;

    }

    return fdigit;

}

struct Node {

    int data;
    Node* next;

};

void append(Node*& root, int data) {

    if (root == nullptr) {

        root = new Node{ data, nullptr };

    }
    else {

        Node* current = root;

        while (current->next != nullptr) {

            current = current->next;

        }

        current->next = new Node{ data,nullptr };

    }

}

void print(Node*& root) {

    Node* current = root;

    while (current != nullptr) {

        std::cout << current->data << ' ';
        current = current->next;

    }

    std::cout << std::endl;

}

void main() {

    Node* root = nullptr;
    bool Flag = false;
    int N;

    std::cout << "Enter number of digit" << std::endl;
    std::cin >> N;

    std::cout << "Enter digits:" << std::endl;

    for (int i = 0; i < N; i++) {

        int input;
        std::cin >> input;

        if (ProverkaNaPalindrom(input)) {
            
            Flag = true;

        }

        append(root, input);

    }

    if (Flag) {

        Node* current = root;

        for (int i = 0; i < N - 1; i++) {
            
            Node* current1 = current->next;

            for (int j = i + 1; j < N; j++) {
                
                if (current->data < current1->data) {

                    int number = current1->data;

                    current1->data = current->data;
                    current->data = number;

                }

                current1 = current1->next;

            }
            
            current = current->next;

        }
    }
    else {
        
        Node* current = root;

        while (current != nullptr) {

            if (FirstDigit(current->data) == 3) {
                
                current->data = current->next->data;
                current->next = current->next->next;

            }
            if (FirstDigit(current->data) == 2 or FirstDigit(current->data) == 7) {
                
                Node* newNode = new Node{ current->data,current->next };

                current->next = newNode;

                current = current->next;

            }
            
            current = current->next;

        }

    }
    
    print(root);

}