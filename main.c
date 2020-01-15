// Edwin Ortiz, Dylan Sillart
// CPEG324 Lab1: 8-Bit Calculator ISA 
// main.c

#include <stdio.h>
#include <string.h>

//Variables
char bffrAmnt[16]; 
char opcode[2];
int skipAmnt = 0;

//All registers initialized to 0.
char r0 = 0;
char r1 = 0;
char r2 = 0;
char r3 = 0;

char* determineRegister(char a, char b){
    if(a == '0' && b == '0'){
        return &r0;
    }
    else if(a == '0' && b == '1'){
        return &r1;
    }
    else if(a == '1' && b == '0'){
        return &r2;
    }
	//else aka: a == '1' && b == '1'
    else{ 
	return &r3;
    }
}

void add_reg(){
    //add operation registers
    char *dest_reg = determineRegister(bffrAmnt[2],bffrAmnt[3]);
    char *src_reg = determineRegister(bffrAmnt[4],bffrAmnt[5]);
    char *trg_reg = determineRegister(bffrAmnt[6],bffrAmnt[7]);

    *dest_reg = *src_reg + *trg_reg;
}

void sub_reg(){
    //sub operation registers
    char *dest_reg = determineRegister(bffrAmnt[2],bffrAmnt[3]);
    char *src_reg = determineRegister(bffrAmnt[4],bffrAmnt[5]);
    char *trg_reg = determineRegister(bffrAmnt[6],bffrAmnt[7]);

    *dest_reg = *src_reg - *trg_reg;
}


//Loads signed immediate
void li_reg(){
    char *dest_reg = determineRegister(bffrAmnt[2], bffrAmnt[3]);
    char imm_bit_val = 0;
    char bit_val = 0;

    if(bffrAmnt[4] == '1'){
        imm_bit_val = ~imm_bit_val;
    }

    for (int i = 7; i > 3; i--){
        //Convert ASCII bit to integer bit, then sets it as first bit of imm_bit_val
        bit_val = (bffrAmnt[i] - 48);

        imm_bit_val ^= (-bit_val ^ imm_bit_val) & (1 << 7 - i); //Set the approatie bit of imm_bit_val
    }
    *dest_reg = imm_bit_val; //Load register with the immediate.
}

void display_reg(){
    char *src_reg = determineRegister(bffrAmnt[3],bffrAmnt[4]);

    if(bffrAmnt[5] == '1'){ //Prints integer
        printf("%d\n",(*src_reg));
        fflush(stdout);
    }
    if(bffrAmnt[6] == '1'){ //Prints 8 bit hexadecimal
        printf("%X\n",(*src_reg) & 0xFF);
        fflush(stdout);
    }
    if(bffrAmnt[7] == '1'){ //Prints ASCII character
        printf("%c\n",(*src_reg));
        fflush(stdout);
    }
}

void compare_reg(){
    char *src_reg = determineRegister(bffrAmnt[4],bffrAmnt[5]);
    char *trg_reg = determineRegister(bffrAmnt[6],bffrAmnt[7]);

    if(*src_reg == *trg_reg){
        skipAmnt = bffrAmnt[3] - 47 ; //Converts ASCII to bit, then adds 1
    }
}


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Simulator using: ./simulator FILENAME\n");
        fflush(stdout);
    }
    else{
        FILE *file = fopen(argv[1], "r");//Opens file from command line

        if(file == NULL){
            printf("File \"%s\" is not found.\n", argv[1]);
            printf("\nSimulation has ended.\n");
            fflush(stdout);
            return 0;
        }

        while(fgets(bffrAmnt, sizeof(bffrAmnt), file)){

            opcode[0] = bffrAmnt[0];
            opcode[1] = bffrAmnt[1];

            if(skipAmnt == 0){
                if(strcmp(opcode,"00") == 0){
                    if(bffrAmnt[2] == '0'){
                        display_reg();
                    }
                    else{ // bffrAmnt[2] == '1'
                        compare_reg();
                    }
                }
                else if((strcmp(opcode,"01") == 0)){
                    add_reg();
                }
                else if((strcmp(opcode,"10") == 0)){
                    sub_reg();
                }
                else{ //opcode is "11"
                    li_reg();
                    fflush(stdout);
                }
            }
            else{
                skipAmnt--;
            }
        }

        fclose(file);
    }
    printf("\nSimulation has ended.\n");
    fflush(stdout);

    return 0;
}
