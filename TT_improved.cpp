#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> bits; // Basic input 
    std::bitset<8> compareBits; // Used for AND, OR, XOR and XAND
    std::bitset<8> result;
    int input, choice;

    for (int i = 0; i < 8; i++) {
        do {
            std::cout << "Enter value for bit " << i << ": "; std::cin >> input;
        } while (input != 0 && input != 1);
        bits[i] = input;
    }

    std::cout << "Enter gate to view" << std::endl;
    std::cout << "1) AND" << std::endl;
    std::cout << "2) NOT" << std::endl;
    std::cout << "3) OR" << std::endl;
    std::cout << "4) NOR" << std::endl;
    std::cout << "5) XOR" << std::endl;
    std::cout << "6) XAND" << std::endl;
    std::cout << ": "; std::cin >> choice;

    switch (choice) {
        case 1: {
            // AND
            for (int i = 0; i < 8; i++) {
                do {
                    std::cout << "Enter value for bit " << i << ": "; std::cin >> input;
                } while (input != 0 && input != 1);
                compareBits[i] = input;
            }

            result = bits & compareBits;
            break;
        }
        case 2: {
            // NOT
            result = ~bits;

            break;
        }
        case 3: {
            // OR
            for (int i = 0; i < 8; i++) {
                do {
                    std::cout << "Enter value for bit " << i << ": "; std::cin >> input;
                } while (input != 0 && input != 1);
                compareBits[i] = input;
            }

            result = bits | compareBits;
            
            break;
        }
        case 4: {
            // NOR
            for (int i = 0; i < 8; i++) {
                do {
                    std::cout << "Enter value for bit " << i << ": "; std::cin >> input;
                } while (input != 0 && input != 1);
                compareBits[i] = input;
            }

            result = ~(bits | compareBits);
            
            break;
        }
        case 5: {
            // XOR
            for (int i = 0; i < 8; i++) {
                do {
                    std::cout << "Enter value for bit " << i << ": "; std::cin >> input;
                } while (input != 0 && input != 1);
                compareBits[i] = input;
            }

            result = bits ^ compareBits;

            break;
        }
        case 6: {
            // XAND
            for (int i = 0; i < 8; i++) {
                do {
                    std::cout << "Enter value for bit " << i << ": "; std::cin >> input;
                } while (input != 0 && input != 1);
                compareBits[i] = input;
            }

            result = ~(bits ^ compareBits);

            break;
        }
    }

    std::cout << "RESULT: " << result << std::endl;
}