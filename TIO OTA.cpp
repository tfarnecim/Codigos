#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define C system("cls")

string toupper(string s){
	int sum = 'A'-'a';
	for(int i=0;i<s.length();i++){
		s[i]=(char)(s[i]+sum);
	}
	return s;
}

int main(){
	
	string s = "Otacilio meu bb\ncoisinha mais fofa desse mundo\nquer ser o padrinho da nossa turma?\n[S/N]: ";
	
	Sleep(1000);
	
	for(int i=0;i<s.length();i++){
		cout << s[i];
		Sleep(50);
	}
	
	string ans;
	
	cin >> ans;
	
	string choro[20] = 
	{"Vai Vai, A gente nunca te pediu nada :/\n",
	"Homi Deixe de onda\n",
	"A gente ta pedindo namoral\n",
	"Da pra parar?\n",
	"Nao to vendo a minima grasssssa\n",
	"Palhacada isso em professor\n",
	"Faz o coracao :D\n",
	"Ta achando que eu tenho criatividade assim pra digitar essas frases eh?\n",
	"Homi ja deu\n",
	"AAAAAAAAAAAAAAAAAAAAAAAAA\n",
	"PARA COM ISSO\n",
	"Professor aceita vai\n",
	"Eh serio vei\n",
	"Namoral mesmo?\n",
	"Criatividade pra frases chorando ta no final\n",
	"Eh so digitar sim que todo mundo fica feliz\n",
	"Homi por favor\n",
	"Vou ter que lhe dar um shuetdown\n",
	"Shuetdown -r now\n",
	"Digita sim vai\n"};
	string def = "Acho que o senhor nao pensou bem\nTente novamente\n[S/N]: ";
	
	//cout << toupper(ans) << endl;
	
	int x = 0;
	
	while(toupper(ans) != "SIM" && toupper(ans) != "S"){
		C;
		for(int i=0;i<choro[x].length();i++){
			cout << choro[x][i];
			Sleep(50);
		}
		
		if(x==18){
			C;
			Sleep(5000);
			string aux = "TROLEI NEH KAKAKKAKAKAKAKA\n";
			for(int i=0;i<aux.length();i++){
				cout << aux[i];
				Sleep(50);
			}
		}
		
		Sleep(1000);
		
		x=(x+1)%20;
		for(int i=0;i<def.length();i++){
			cout << def[i];
			Sleep(50);
		}
		//cout << endl;
		cin >> ans;
	}
	
	string coracao[9] = {"                                ","     ######    ######           ","    ##################           ","     ################           ","      ##############           ","        ##########                      ","          ######                      ","            ##                      "};
	
	//agora vai viado
	
	for(int k=0;k<25;k++){
		C;
		for(int i=0;i<8;i++){
			for(int j=0;j<k;j++){
				cout << coracao[i][j];
			}
			cout << endl;
		}
		Sleep(100);
	}
	
	return 0;
}