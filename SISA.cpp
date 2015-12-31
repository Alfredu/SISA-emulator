#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<bitset>
#include<stdlib.h>
#include<iomanip>
//#include"stringManipulation.hpp"
//#include<stdint.h>

using namespace std;

int16_t translateToMachineCode(string *linia){
	string opcode;
	string instruccio;
    instruccio.append(*linia);

	string buf; // Have a buffer string
    stringstream ss(*linia); // Insert the string into a stream

    vector<string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);

    if(tokens.empty()){
    	return -1;
    }


    if(tokens[0]=="AND"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("000");

    }

    else if(tokens[0]=="OR"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[8]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[4]-'0').to_string());

    	opcode.append("001");

    }

    else if(tokens[0]=="XOR"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("010");


    }

    else if(tokens[0]=="NOT"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("011");

    }

    else if(tokens[0]=="ADD"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("100");

    }

    else if(tokens[0]=="SUB"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("101");

    }

    else if(tokens[0]=="SHA"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("110");


    }

    else if(tokens[0]=="SHL"){
    	opcode.append("0000");
  
    	opcode.append(bitset<3>(instruccio[9]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[13]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

    	opcode.append("111");

    }

    else if(tokens[0]=="CMPLT"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[14]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[7]-'0').to_string());

    	opcode.append("000");


    }

    else if(tokens[0]=="CMPLE"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[14]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[7]-'0').to_string());

    	opcode.append("001");
	}

	else if(tokens[0]=="CMPEQ"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[14]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[7]-'0').to_string());

    	opcode.append("011");
	}

	else if(tokens[0]=="CMPLTU"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[12]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[15]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[8]-'0').to_string());

    	opcode.append("100");
	}

	else if(tokens[0]=="CMPLEU"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[12]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[15]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[8]-'0').to_string());

    	opcode.append("101");
	}

	else if(tokens[0]=="ADDI"){

    	opcode.append("0010");
  
    	opcode.append(bitset<3>(instruccio[10]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[6]-'0').to_string());

	    bitset<6> immediat = bitset<6>(instruccio[13]);

	    short int immediatShort = immediat.to_ulong();

	    if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<6>(instruccio[14]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
			opcode.append(immediat.to_string());
	    }

	    else{

	    	bitset<6> immediat = bitset<6>(instruccio[13]-'0');

	    }
	}

	else if(tokens[0]=="LD"){
		opcode.append("0011");
		bitset<6> immediat = bitset<6>(instruccio[7]);
	    short int immediatShort = immediat.to_ulong();

  		if(immediatShort==45)
    		opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	else
    		opcode.append(bitset<3>(instruccio[10]-'0').to_string());


    	opcode.append(bitset<3>(instruccio[4]-'0').to_string());

	    if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<6>(instruccio[8]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<6>(instruccio[7]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="ST"){
		opcode.append("0100");
		bitset<6> immediat = bitset<6>(instruccio[3]);
	    short int immediatShort = immediat.to_ulong();

  		if(immediatShort==45){
    		opcode.append(bitset<3>(instruccio[7]-'0').to_string());
    		opcode.append(bitset<3>(instruccio[12]-'0').to_string());
		}

    	else{
    		opcode.append(bitset<3>(instruccio[7]-'0').to_string());
    		opcode.append(bitset<3>(instruccio[11]-'0').to_string());
		}


	    if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<6>(instruccio[4]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<6>(instruccio[3]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="LDB"){
		opcode.append("0101");
		bitset<6> immediat = bitset<6>(instruccio[8]);
	    short int immediatShort = immediat.to_ulong();

  		if(immediatShort==45)
    		opcode.append(bitset<3>(instruccio[12]-'0').to_string());

    	else
    		opcode.append(bitset<3>(instruccio[11]-'0').to_string());


    	opcode.append(bitset<3>(instruccio[5]-'0').to_string());

	    if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<6>(instruccio[9]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<6>(instruccio[8]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="STB"){
		opcode.append("0110");
		bitset<6> immediat = bitset<6>(instruccio[4]);
	    short int immediatShort = immediat.to_ulong();

  		if(immediatShort==45){
    		opcode.append(bitset<3>(instruccio[8]-'0').to_string());
    		opcode.append(bitset<3>(instruccio[13]-'0').to_string());
		}

    	else{
    		opcode.append(bitset<3>(instruccio[8]-'0').to_string());
    		opcode.append(bitset<3>(instruccio[12]-'0').to_string());
		}


	    if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<6>(instruccio[5]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<6>(instruccio[4]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="JALR"){
		opcode.append("0111");

		opcode.append(bitset<3>(instruccio[10]-'0').to_string());
		opcode.append(bitset<3>(instruccio[6]-'0').to_string());
		opcode.append("000000");

	}

	//TODO De BZ a OUT.

	else if(tokens[0]=="BZ"){
		bitset<8> immediat = bitset<8>(instruccio[7]);
	    short int immediatShort = immediat.to_ulong();

		opcode.append("1000");
		opcode.append(bitset<3>(instruccio[4]-'0').to_string());
		opcode.append("0");

		if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<8>(instruccio[8]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<8>(instruccio[7]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="BNZ"){
		bitset<8> immediat = bitset<8>(instruccio[8]);
	    short int immediatShort = immediat.to_ulong();

		opcode.append("1000");
		opcode.append(bitset<3>(instruccio[5]-'0').to_string());
		opcode.append("1");

		if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<8>(instruccio[9]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<8>(instruccio[8]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="MOVI"){
		bitset<8> immediat = bitset<8>(instruccio[9]);
	    short int immediatShort = immediat.to_ulong();

		opcode.append("1001");
		opcode.append(bitset<3>(instruccio[6]-'0').to_string());
		opcode.append("0");

		if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<8>(instruccio[10]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<8>(instruccio[9]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="MOVHI"){
		bitset<8> immediat = bitset<8>(instruccio[10]);
	    short int immediatShort = immediat.to_ulong();

		opcode.append("1001");
		opcode.append(bitset<3>(instruccio[7]-'0').to_string());
		opcode.append("1");

		if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<8>(instruccio[11]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<8>(instruccio[10]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="IN"){
		bitset<8> immediat = bitset<8>(instruccio[7]);
	    short int immediatShort = immediat.to_ulong();

		opcode.append("1010");
		opcode.append(bitset<3>(instruccio[4]-'0').to_string());
		opcode.append("0");

		if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<8>(instruccio[8]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<8>(instruccio[7]-'0');

	    }

	    opcode.append(immediat.to_string());
	}

	else if(tokens[0]=="OUT"){
		bitset<8> immediat = bitset<8>(instruccio[4]);
	    short int immediatShort = immediat.to_ulong();

		opcode.append("1010");

		if(immediatShort==45){
			opcode.append(bitset<3>(instruccio[9]-'0').to_string());
		}
		else
			opcode.append(bitset<3>(instruccio[8]-'0').to_string());

		opcode.append("1");

		if(immediatShort==45){//IF es un numero negatiu, parsejarà el guió en comptes del número. Convertim el numero a negatiu en complement a dos.

	    	immediat = bitset<8>(instruccio[5]-'0');
	    	immediat.flip();// Invertim el numero
			if(immediat[0]==0)//Sumem 1 i contem els carrys.
				immediat[0]=1;
			else if(immediat[0]==1){
				immediat[0]=0;
				for(int i=1;i<8;i++){
					if(immediat[i]==0){
						immediat[i]=1;
						break;
					}

					else if(immediat[i]==1)
						immediat[i]=0;
				}
			}
	    }

	    else{

	    	immediat = bitset<8>(instruccio[4]-'0');

	    }

	    opcode.append(immediat.to_string());
	}









    bitset<16> x(opcode);

    cout<<opcode<<endl;
    return x.to_ulong();
}


void parseCode(int16_t *PC, int8_t Ram[]){
	ifstream codi;
	ofstream codimaquina;

	codimaquina.open("ProgramMachineCode.txt");
	codi.open("Program.txt");
	string linia;
	int opCode;

	while(getline(codi,linia)){
		opCode = translateToMachineCode(&linia);
		codimaquina <<bitset<16>(opCode)<<endl;	
	}

}


int main(){
	int8_t Ram[65536];
	int16_t Registers[8]={0};
	int16_t PC=0;

	
	parseCode(&PC,Ram);
}