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

bool odnoznach(int num) {

    int i = 0;

    while (num > 0) {

        i++;
        num /= 10;

    }

    return i == 1;

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
    Node* prev;
    Node* next;

};

Node* append(int data, Node*& last, Node*& head) {
    
    Node* current = new Node{ data, last, head };

    head->prev = current;

    last->next = current;

    return current;

}

void print(Node*& head) {

    Node* current = head->next;

    while (current->data != -1) {

        std::cout << current->data << ' ';
        current = current->next;

    }

    std::cout << std::endl;

}

void main() {

    Node* head = new Node{ -1, nullptr, nullptr };
    Node* last;
    int lastFDigit, lastLDigit;
    
    bool flagf = true, flagl = true, whileperekl = true;

    std::cout << "Enter a sequence of natural numbers(enter - 1 to stop) : " << std::endl;

    while (true) {

        if (whileperekl) {

            int input;
            std::cin >> input;

            lastFDigit = FirstDigit(input);
            lastLDigit = input % 10;
            
            last = append(input, head, head);

            whileperekl = false;

        }
        else {
            
            int input;
            std::cin >> input;

            if (input == -1) {

                break;

            }

            last = append(input, last, head);

            if (lastFDigit < FirstDigit(input)) {

                flagf = false;
                
            }
            if (lastLDigit < input % 10) {

                flagl = false;
                
            }

            lastFDigit = FirstDigit(input);
            lastLDigit = input % 10;

        }
        
    }
    
    if (flagf or flagl) {
        
        Node* current = head->next;

        while (current->data != -1) {
            
            if (odnoznach(current->data)) {

                current->prev->next = current->next;
                current->next->prev = current->prev;

                current = current->next;

            }
            else if (ProverkaNaPalindrom(current->data)) {

                Node* newCurrent = new Node{ current->data,current,current->next };

                current->next->prev = newCurrent;
                current->next = newCurrent;

                current = newCurrent->next;

            }
            else {

                current = current->next;

            }

        }

    }
    else {
        
        Node* current = head->next;

        while (current->next->next->data != -1) {
            
            Node* current1 = current->next;

            while (current1->next->data != -1) {
                
                if (FirstDigit(current->data) > FirstDigit(current1->data)) {
                    
                    int tmp = current1->data;

                    current1->data = current->data;
                    current->data = tmp;

                }

                current1 = current1->next;

            }

            current = current->next;

        }

    }

    print(head);

}