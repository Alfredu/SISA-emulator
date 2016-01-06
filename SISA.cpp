#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<bitset>
#include<stdlib.h>
#include<iomanip>
#include<cmath>
//#include"stringManipulation.hpp"
//#include<stdint.h>

using namespace std;

	static const bitset<4> AL = bitset<4>(string("0000"));
	const bitset<4> CMP = bitset<4>(string("0001"));
	const bitset<4> ADDI = bitset<4>(string("0010"));
	const bitset<4> LD = bitset<4>(string("0011"));
	const bitset<4> ST = bitset<4>(string("0100"));
	const bitset<4> LDB = bitset<4>(string("0101"));
	const bitset<4> STB = bitset<4>(string("0110"));
	const bitset<4> JALR = bitset<4>(string("0111"));
	const bitset<4> BZ = bitset<4>(string("1000"));
	const bitset<4> BNZ = bitset<4>(string("1000"));
	const bitset<4> MOVI = bitset<4>(string("1001"));
	const bitset<4> MOVHI = bitset<4>(string("1001"));
	const bitset<4> IN = bitset<4>(string("1010"));
	const bitset<4> OUT = bitset<4>(string("1010"));

	const bitset<3> AND = bitset<3>(string("000"));
	const bitset<3> OR = bitset<3>(string("001"));
	const bitset<3> XOR = bitset<3>(string("010"));
	const bitset<3> NOT = bitset<3>(string("011"));
	const bitset<3> ADD = bitset<3>(string("100"));
	const bitset<3> SUB = bitset<3>(string("101"));
	const bitset<3> SHA = bitset<3>(string("110"));
	const bitset<3> SHL = bitset<3>(string("111"));

	const bitset<3> CMPLT = bitset<3>(string("000"));
	const bitset<3> CMPLE = bitset<3>(string("001"));
	const bitset<3> CMPEQ = bitset<3>(string("011"));
	const bitset<3> CMPLTU = bitset<3>(string("100"));
	const bitset<3> CMPLEU = bitset<3>(string("101"));


	int8_t Ram[65536];
	int16_t Registers[8]={0};
	int16_t PC=0;	

bitset<16> translateToMachineCode(string *linia){
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

    	opcode.append(bitset<3>(instruccio[15]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[7]-'0').to_string());

    	opcode.append("000");


    }

    else if(tokens[0]=="CMPLE"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[15]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[7]-'0').to_string());

    	opcode.append("001");
	}

	else if(tokens[0]=="CMPEQ"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[11]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[15]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[7]-'0').to_string());

    	opcode.append("011");
	}

	else if(tokens[0]=="CMPLTU"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[12]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[16]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[8]-'0').to_string());

    	opcode.append("100");
	}

	else if(tokens[0]=="CMPLEU"){
    	opcode.append("0001");
  
    	opcode.append(bitset<3>(instruccio[12]-'0').to_string());

    	opcode.append(bitset<3>(instruccio[16]-'0').to_string());

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

	    	immediatShort = -(instruccio[14]-'0');
	    	int i=15;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);
	    }

	    else{

	    	immediatShort = instruccio[13]-'0';
	    	int i=14;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);

	    }
	    opcode.append(immediat.to_string());

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

	    	immediatShort = -(instruccio[8]-'0');
	    	int i=9;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);
	    }

	    else{
	    	immediatShort = instruccio[7]-'0';
	    	int i=8;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);


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

	    	immediatShort = -(instruccio[4]-'0');
	    	int i=5;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);
	    }

	    else{
	    	immediatShort = instruccio[3]-'0';
	    	int i=4;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);

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

	    	immediatShort = -(instruccio[13]-'0');
	    	int i=14;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);
	    }

	    else{

	    	immediatShort = instruccio[8]-'0';
	    	int i=9;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);

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

	    	immediatShort = -(instruccio[5]-'0');
	    	int i=6;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);
	    }

	    else{
	    	immediatShort = instruccio[4]-'0';
	    	int i=5;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<6>(immediatShort);

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

	    	immediat = bitset<8>(-(instruccio[8]-'0'));
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

	    	immediatShort = -(instruccio[9]-'0');
	    	int i=10;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);	    }

	    else{

	    	immediatShort = instruccio[8]-'0';
	    	int i=9;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);

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

	    	immediatShort = -(instruccio[10]-'0');
	    	int i=11;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);
	    }

	    else{

	    	immediatShort = instruccio[9]-'0';
	    	int i=10;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);
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

	    	immediatShort = -(instruccio[11]-'0');
	    	int i=12;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);
	    	
	    }

	    else{

			immediatShort = instruccio[10]-'0';
	    	int i=11;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);
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

	    	immediatShort = -(instruccio[8]-'0');
	    	int i=9;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);
	    }

	    else{

	    	immediatShort = instruccio[7]-'0';
	    	int i=8;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);

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

	    	immediatShort = -(instruccio[5]-'0');
	    	int i=6;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) - (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);
	    }

	    else{
	    	immediatShort = instruccio[4]-'0';
	    	int i=5;
	    	while(instruccio[i]>='0' && instruccio [i]<='9'){
	    		immediatShort =  (immediatShort)*pow(10,1) + (instruccio[i]-'0');
	    		i++;
	    	}
	    	immediat = bitset<8>(immediatShort);

	    }

	    opcode.append(immediat.to_string());
	}


    bitset<16> x(opcode);
    return x;
}


void parseCode(int16_t *PC, int8_t Ram[]){
	ifstream codi;
	ofstream codimaquina;
	bitset<16> opCode;

	codimaquina.open("ProgramMachineCode.txt");
	codi.open("Program.txt");
	string linia;
	

	while(getline(codi,linia)){
		opCode = translateToMachineCode(&linia);
		codimaquina <<opCode<<endl;

	}

}

void executeInstruction(string linia){
	string instruccio;
	for(int i=0;i<4;i++){
		instruccio+=linia[i];
	}

	if(instruccio==AL.to_string()){
		string funcio;
		for(int i=13;i<16;i++){
			funcio+=linia[i];
		}

		if(funcio==AND.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();
			Registers[regDestino] = Registers[regFont] & Registers [regFont2];
		}

		if(funcio==OR.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();
			Registers[regDestino] = Registers[regFont] | Registers [regFont2];

		}

		if(funcio==XOR.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();
			Registers[regDestino] = Registers[regFont] ^ Registers [regFont2];

		}

		if(funcio==NOT.to_string()){
			unsigned long regFont, regDestino = 0;

			string sRegFont, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();
			Registers[regDestino] = ~	Registers[regFont];
		}


		if(funcio==ADD.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = Registers[regFont] + Registers [regFont2];
		}
		else if(funcio==SUB.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = Registers[regFont] - Registers [regFont2];

		}
		else if(funcio==SHA.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();

			int16_t baseFont = Registers[regFont];
			bitset<5> baseExponent = bitset<5>(Registers[regFont2]);
			short int exponent=0;
			for(int i=0;i<5;i++){
				if(i==4){
					exponent = exponent - baseExponent[i]*pow(2,i);
				}
				else if(i!=4){
					exponent = exponent + baseExponent[i]*pow(2,i);
				}

			}

			regDestino = bitset<3>(sRegDestino).to_ulong();

			if(exponent>=0){
				baseFont >>= exponent;
				Registers[regDestino] = baseFont;
			}
			else{
				short int exponentAbs = abs(exponent);
				baseFont <<= exponentAbs;
				Registers[regDestino] = baseFont;

			}
		}

		else if(funcio==SHL.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();

			uint16_t baseFont = Registers[regFont];
			bitset<5> baseExponent = bitset<5>(Registers[regFont2]);
			short int exponent=0;
			for(int i=0;i<5;i++){
				if(i==4){
					exponent = exponent - baseExponent[i]*pow(2,i);
				}
				else if(i!=4){
					exponent = exponent + baseExponent[i]*pow(2,i);
				}

			}

			regDestino = bitset<3>(sRegDestino).to_ulong();

			if(exponent>=0){
				baseFont <<= exponent;

				Registers[regDestino]=baseFont;
			}
			else{
				short int exponentAbs = abs(exponent);
				baseFont <<= exponentAbs;
				Registers[regDestino] = baseFont;
			}
		}



	}
	else if(instruccio==CMP.to_string()){
		string funcio;
		funcio+=linia[13];
		funcio+=linia[14];
		funcio+=linia[15];

		if(funcio==CMPLT.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			cout<<linia<<endl;

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = Registers[regFont] < Registers[regFont2];
		}

		else if(funcio==CMPLE.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			cout<<linia<<endl;

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = Registers[regFont] <= Registers[regFont2];
		}
		else if(funcio==CMPEQ.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			cout<<linia<<endl;

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = Registers[regFont] == Registers[regFont2];
		}
		else if(funcio==CMPLTU.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			cout<<linia<<endl;

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = bitset<16>(Registers[regFont]).to_ulong() < bitset<16>(Registers[regFont2]).to_ulong();
		}
		else if(funcio==CMPLEU.to_string()){
			unsigned long regFont, regFont2, regDestino = 0;

			string sRegFont, sRegFont2, sRegDestino;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegFont2 +=linia[i];
			}
			for(int i=10;i<13;i++){
				sRegDestino +=linia[i];
			}

			regFont = bitset<3>(sRegFont).to_ulong();
			regFont2 = bitset<3>(sRegFont2).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = bitset<16>(Registers[regFont]).to_ulong() <= bitset<16>(Registers[regFont2]).to_ulong();
		}
	}

	else if(instruccio==ADDI.to_string()){
		unsigned long regFont, regDestino = 0;

			string sRegFont, sRegDestino, sImmediat;

			for(int i=4;i<7;i++){
				sRegFont +=linia[i];
			}
			for(int i=7;i<10;i++){
				sRegDestino +=linia[i];
			}
			for(int i=10;i<16;i++){
				sImmediat +=linia[i];
			}

			bitset<6> bitsImmediat = bitset<6>(sImmediat);
			short int exponent=0;

			for(int i=0;i<6;i++){
				if(i==5){
					exponent = exponent - (bitsImmediat[i] * pow(2,i));
				}
				else
					exponent = exponent + (bitsImmediat[i] * pow(2,i));
			}

			cout<<exponent<<endl;


			regFont = bitset<3>(sRegFont).to_ulong();
			regDestino = bitset<3>(sRegDestino).to_ulong();

			Registers[regDestino] = Registers[regFont] + exponent;
	}

	else if(instruccio==LD.to_string()){

	}
	else if(instruccio==ST.to_string()){

	}
	else if(instruccio==LDB.to_string()){

	}
	else if(instruccio==STB.to_string()){

	}
	else if(instruccio==JALR.to_string()){

	}
	else if(instruccio==BZ.to_string()||instruccio==BNZ.to_string()){

	}
	else if(instruccio==MOVI.to_string() || instruccio==MOVHI.to_string()){

		unsigned long regFont = 0;

		string sRegFont;

		for(int i=4;i<7;i++){
			sRegFont +=linia[i];
		}
		

		regFont = bitset<3>(sRegFont).to_ulong();

		string movhi;
		movhi += linia[7];
		bitset<16> bitsDestino;
		int16_t exponent;

		if(movhi=="1"){
			string N;
			string bitset16;

			for(int i=8;i<16;i++){
				N+=linia[i];
			}

			bitset16.append(N);
			bitset16.append(bitset<8>(Registers[regFont]).to_string());

			bitsDestino = bitset<16>(bitset16);
			exponent = 0;

			for(int i=0;i<16;i++){
				if(i==15){
					exponent = exponent - bitsDestino[i]*pow(2,i);
				}
				else{
					exponent = exponent + bitsDestino[i]*pow(2,i);
				}

			}

			Registers[regFont]=exponent;


		}

		else{
			string N;
			string bitset16;

			for(int i=8;i<16;i++){
				N+=linia[i];
			}
			if(N[0]=='0'){
				bitset16.append("00000000");
				bitset16.append(N);
			}
			else{
				bitset16.append("11111111");
				bitset16.append(N);
			}
			bitsDestino = bitset<16>(bitset16);

			exponent=0;

			for(int i=0;i<16;i++){
				if(i==15){
					exponent = exponent - bitsDestino[i]*pow(2,i);
				}
				else if(i!=15){
					exponent = exponent + bitsDestino[i]*pow(2,i);
				}

			}
			Registers[regFont]=exponent;	
		}

	}
	else if(instruccio==IN.to_string()||instruccio==OUT.to_string()){

	}



}

void parseBinaryFile(){
	ifstream binaryCode;

	binaryCode.open("ProgramMachineCode.txt");
	string linia;

	while(getline(binaryCode,linia)){
		executeInstruction(linia);
	}
}




int main(){
	string fitxerCodiFont;
	string fitxerCodiCompilat;
	
	parseCode(&PC,Ram);
	parseBinaryFile();

	for(int i=0;i<8;i++){
		cout<<"R"<<i<<": "<<Registers[i]<<endl;
	}
}

//TODO ADDI