using namespace std;

#include "string"
#include "unordered_map"
#include "iostream"

static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{

}


void registerMover(std::string instruction, int* registes){
    char registerName = instruction[4];
    cout <<  "Register Name : " << registerName << endl;
    auto hashed = (int) registerName;

    char valueToBeStored = instruction[6];
    int valueInteger = valueToBeStored - 48;
    cout << "Register new Value : " << valueInteger << endl;

    registes[hashed] = valueInteger;
}

void registerAlgorithm(std::string instruction, int* registers, int operation){
    char registerName = instruction[4];
    auto hashed = (int) registerName;

    if(operation == 0){
        registers[hashed] --;
        cout << "Decreased register : " << registerName << endl;
    }
    else if(operation == 1){
        registers[hashed]++;
        cout << "Increased register : " << registerName << endl;
    }
    else{
        cout << "error no register found" << endl;
    }
}

int registerJumper(const std::string &instruction, int* registers, int line){
    char registerName = instruction[4];
    auto hashed = (int) registerName;

    char toJump = instruction[6];
    //can be a '-', a register(char) or a number(const)
    int jump = toJump;
    //-
    if(jump == 45){
        jump = instruction[7] - 48;
        jump = -1 - jump;
    }
    //number
    else if(jump >= 48 && jump <= 57){
        jump = jump - 48;
    }
    //register
    else{
        jump = registers[jump];
    }

    if(registers[hashed] != 0){
        line += jump;
    }
    cout << "Jumped to line : " << line << endl;

    return line;
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
    unordered_map<std::string, int> result = {};
    //hash for the registers
    int registers[10000];
    for(int i =0;i<10000;i++){
        registers[i] = -1000;
    }

    //loop through the instructions
    for(int i =0;i<program.size();i++){
        char instruction = program[i][0];
        //m - copies value y into register x --> mov x y
        //i - increase value in register x by one --> inc x
        //d - decrease --> dec x
        //j - jump to instruction y steps awaf if x==0 --> jnz x y

        switch(instruction){
            case 'm' : registerMover(program[i], registers);
                break;
            case 'i' :  registerAlgorithm(program[i], registers, 1);
                break;
            case 'd' :  registerAlgorithm(program[i], registers, 0);
                break;
            case 'j' :  i = registerJumper(program[i], registers, i);
                break;
            default:
                cout << "instruction error" << endl;
        }
    }


    for(int i = 0;i<10000;i++){
        if(registers[i] != -1000){
            auto registerName = (char) i;
            int value = registers[i];
            string s(1, registerName);

            // Inserting elements through an initializer_list
            result.insert({ {s, value} } );
        }
    }
    return result;
}