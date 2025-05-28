/* --------------------------------------------------------------- 
   \      TRUTH TABLES FOR AND, NOT and OR  - Benjamin Archard   \
   \       - Inefficient method but used so I can learn          \
    -------------------------------------------------------------
*/



#include <cstdint>
#include <iostream>

union Tables {
    unsigned char wholeByte;

    struct bits {
        // Standard bit section
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;

        // Used for AND and NOT
        unsigned nib0 : 2;
        unsigned nib1 : 2;
        unsigned nib2 : 2;
        unsigned nib3 : 2;
    } bits;
};

// Doesn't return anything -> Feels profilific
Tables assignBits(unsigned& b0, unsigned& b1, unsigned& b2, unsigned& b3,
unsigned& b4, unsigned& b5, unsigned& b6, unsigned& b7, int mode) {
    switch (mode) {
        case 1: {
            /* ---------------------------------
               \            NOT GATE           \
               \-------------------------------\
                INPUTS                 OUTPUT
                  1                      0
                  0                      1

                FLIPS THE INPUT
                - IF THE INPUT IS A '1' THEN FLIP IT TO '0'
                - IF THE INPUT IS A '0' THEN FLIP IT TO '1'
            */


            Tables* bitTable;
            bitTable = new Tables;
            bitTable->wholeByte = 0; // Sets the byte to 0

            // Checks whether bit 0-7 is equal to zero, if not it will change it to a one.
            // E.G b0 == 0 -> Change to a 1.
            // E>G b0 == 1 -> Change to a 0.

            bitTable->bits.bit0 = (b0 == 0) ? 1 : 0; 
            bitTable->bits.bit1 = (b1 == 0) ? 1 : 0;
            bitTable->bits.bit2 = (b2 == 0) ? 1 : 0;
            bitTable->bits.bit3 = (b3 == 0) ? 1 : 0;
            bitTable->bits.bit4 = (b4 == 0) ? 1 : 0;
            bitTable->bits.bit5 = (b5 == 0) ? 1 : 0;
            bitTable->bits.bit6 = (b6 == 0) ? 1 : 0;
            bitTable->bits.bit7 = (b7 == 0) ? 1 : 0;

            std::cout << "INPUTS " << "\t" << " OUTPUTS " << std::endl; 

            std::cout << (int)b0 << "\t" << (int)bitTable->bits.bit0 << std::endl;
            std::cout << (int)b1 << "\t" << (int)bitTable->bits.bit1 << std::endl;
            std::cout << (int)b2 << "\t" << (int)bitTable->bits.bit2 << std::endl;
            std::cout << (int)b3 << "\t" << (int)bitTable->bits.bit3 << std::endl;
            std::cout << (int)b4 << "\t" << (int)bitTable->bits.bit4 << std::endl;
            std::cout << (int)b5 << "\t" << (int)bitTable->bits.bit5 << std::endl;
            std::cout << (int)b6 << "\t" << (int)bitTable->bits.bit6 << std::endl;
            std::cout << (int)b7 << "\t" << (int)bitTable->bits.bit7 << std::endl;

            break;
        }
        case 2: {
            /* ---------------------------------
               \            AND GATE           \
               \-------------------------------\
                INPUTS                 OUTPUT
                1 | 1                    1
                1 | 0                    0
                0 | 1                    0
                0 | 0                    0

                CHECKS IF BOTH INPUTS ARE '1'
                - IF BOTH INPUTS ARE 1 THEN THE OUTPUT IS 1
                - ELSE  THE OUTPUT IS 0
            */

            // This will need to be split into 2 nibbles

            // Exists on Heap rather than Stack
            Tables* bitTable;
            bitTable = new Tables;
            bitTable->wholeByte = 0; // Sets the whole byte to 0

            bitTable->bits.bit0 = b0;
            bitTable->bits.bit1 = b1;
            bitTable->bits.bit2 = b2;
            bitTable->bits.bit3 = b3;
            bitTable->bits.bit4 = b4;
            bitTable->bits.bit5 = b5;
            bitTable->bits.bit6 = b6;
            bitTable->bits.bit7 = b7;

            // Splits the byte into 2 nibbles aswell as checks them as an AND Gate

            // The check is done by adding the two bits together ~
            /* E.G if (int)b0 == 1 and (int)b1 == 1 then by adding them the result should be two,
               therefore the AND Gate will pass it as a 1. Otherwise a 0 
            */

            bitTable->bits.nib0 = (((int)b0 + (int)b1) == 2) ? 1 : 0; //nib0 is the first two bits of the byte 
            bitTable->bits.nib1 = (((int)b2 + (int)b3) == 2) ? 1 : 0; //nib1 is the third and forth bits the byte
            bitTable->bits.nib2 = (((int)b4 + (int)b5) == 2) ? 1 : 0; //nib2 is the fith and sixth bits of the byte
            bitTable->bits.nib3 = (((int)b6 + (int)b7) == 2) ? 1 : 0; //nib4 is the seventh and eighth bits of the byte 

            std::cout << "INPUTS " << "\t" << " OUTPUTS " << std::endl; 
            std::cout << (int)b0 << " " << (int)b1 << "\t" << (int)bitTable->bits.nib0 << std::endl;
            std::cout << (int)b2 << " " << (int)b3 << "\t" << (int)bitTable->bits.nib1 << std::endl;
            std::cout << (int)b4 << " " << (int)b5 << "\t" << (int)bitTable->bits.nib2 << std::endl;
            std::cout << (int)b6 << " " << (int)b7 << "\t" << (int)bitTable->bits.nib3 << std::endl;

            break;
        }
        case 3: {
            /* ---------------------------------
               \             OR GATE           \
               \-------------------------------\
                INPUTS                 OUTPUT
                1 | 1                    1
                1 | 0                    1
                0 | 1                    1
                0 | 0                    0

                CHECKS IF ATLEAST 1 INPUT IS A '1'
            */


            Tables* bitTable;
            bitTable = new Tables;
            bitTable->wholeByte = 0;

            bitTable->bits.bit0 = b0;
            bitTable->bits.bit1 = b1;
            bitTable->bits.bit2 = b2;
            bitTable->bits.bit3 = b3;
            bitTable->bits.bit4 = b4;
            bitTable->bits.bit5 = b5;
            bitTable->bits.bit6 = b6;
            bitTable->bits.bit7 = b7;

            // CHECKS IF EITHER OF THE BITS ARE '1' 
            // IF EITHER ONE OF THE BITS ARE '1' THEN INITIALISE nib'0 to 3' TO '1'
            // ELSE SET IT TO 0
            bitTable->bits.nib0 = (((int)b0 == 1) || ((int)b1 == 1)) ? 1 : 0; 
            bitTable->bits.nib1 = (((int)b2 == 1) || ((int)b3 == 1)) ? 1 : 0;
            bitTable->bits.nib2 = (((int)b4 == 1) || ((int)b5 == 1)) ? 1 : 0;
            bitTable->bits.nib0 = (((int)b6 == 1) || ((int)b7 == 1)) ? 1 : 0;   

            std::cout << "INPUTS " << "\t" << " OUTPUTS " << std::endl; 

            std::cout << (int)b0 << " " << (int)b1 << "\t" << (int)bitTable->bits.nib0 << std::endl;
            std::cout << (int)b2 << " " << (int)b3 << "\t" << (int)bitTable->bits.nib1 << std::endl;
            std::cout << (int)b4 << " " << (int)b5 << "\t" << (int)bitTable->bits.nib2 << std::endl;
            std::cout << (int)b6 << " " << (int)b7 << "\t" << (int)bitTable->bits.nib0 << std::endl;

            //break;
        }
    }
}

int main() {
    unsigned binaryString[8] = {};
    int choice;

    std::cout << "Please enter the table you wish to view:" << std::endl;
    std::cout << "1) NOT" << std::endl;
    std::cout << "2) AND" << std::endl;
    std::cout << "3) OR" << std::endl;
    std::cout << ": "; std::cin >> choice;

    // Enter bits
    for (int i = 0; i < 8; i++) {
        std::cout << "Enter value for the " << i << " bit: "; std::cin >> binaryString[i];
        while (binaryString[i] < 0 || binaryString[i] > 1) {
            std::cout << "Enter value for the " << i << " bit: "; std::cin >> binaryString[i];
        }
    }

    assignBits(binaryString[0], binaryString[1], binaryString[2], binaryString[3], binaryString[4],
    binaryString[5], binaryString[6], binaryString[7], choice);
}