#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main(){
	
	while(true){
		
		system("cls");
		
		cout << "-=-=-=-=-=-=-=-=-=-=-=-\n";
		cout << "|        MENU         |\n";
		cout << "-=-=-=-=-=-=-=-=-=-=-=-\n";
		cout << "[1]JOGAR\n";
		cout << "[2]INSTRUCOES\n";
		cout << "[3]SAIR\n\n\nCASO VOCE NAO DIGITE ALGO VALIDO, O JOGO PROVAVELMENTE VAI FECHAR\n\n";
		
		int opc;
		
		cin >> opc;
		
		if(opc==1){
			
			int pilhas[3];
			
			for(int i=0;i<3;i++){
				
				system("cls");
				cout << "DIGITE O NUMERO DE BOLAS NA PILHA " << i+1 << ": \n";
				cout << "MINIMO 5\nMAXIMO 100\n\n";
				
				cin >> pilhas[i];
				
				if(pilhas[i]<5 || pilhas[i]>100){
					i--;
				}
				
			}
			
			system("cls");
			
			Sleep(1000);
			
			if((pilhas[0] ^ pilhas[1] ^ pilhas[2]) != 0){
				
				cout << "\nMESMO QUE MINIMA, VOCE TEM CHANCE DE ME VENCER :)\n";
				
				Sleep(2000);
				
			}else{
				
				cout << "\nJA PODE DESISTIR SE QUISER :)\n";
				
				Sleep(2000);
				
			}
			
			cout << "\nMENTES INFERIORES PRIMEIRO :)\n";
			
			Sleep(2000);
			
			system("cls");
			
			bool humano = true;
			
			while(pilhas[0] + pilhas[1] + pilhas[2] > 0){
				
				system("cls");
				
				cout << "PILHA 1: " << pilhas[0] << endl;
				cout << "PILHA 2: " << pilhas[1] << endl;
				cout << "PILHA 3: " << pilhas[2] << endl;
				
				cout << endl;
				
				if(humano){
					
					int p,tira;
					
					cout << "PILHA: ";
					cin >> p;
					
					cout << "TIRA: ";
					cin >> tira;
					
					pilhas[p-1] -= tira;
					
					humano = false;
					
				}else{
					
					if((pilhas[0] ^ pilhas[1] ^ pilhas[2]) == 0){
						
						if(pilhas[0]>0){
							pilhas[0]--;
						}else if(pilhas[1]>0){
							pilhas[1]--;
						}else{
							pilhas[2]--;
						}
						
					}else{
						
						bool conseguiu = false;
						
						for(int i=1;i<=pilhas[0];i++){
							
							if(!conseguiu && ((pilhas[0]-i) ^ pilhas[1] ^ pilhas[2]) == 0){
								pilhas[0]-=i;
								conseguiu = true;
							}
							
						}
						
						for(int i=1;i<=pilhas[1];i++){
							
							if(!conseguiu && (pilhas[0] ^ (pilhas[1]-i) ^ pilhas[2]) == 0){
								pilhas[1]-=i;
								conseguiu = true;
							}
							
						}
						
						for(int i=1;i<=pilhas[2];i++){
							
							if(!conseguiu && (pilhas[0] ^ pilhas[1] ^ (pilhas[2]-i)) == 0){
								pilhas[2]-=i;
								conseguiu = true;
							}
							
						}
						
					}
					
					Sleep(2000);
					
					cout << "PENSANDO...\n";
					
					Sleep(3000);
					
					cout << "JA SEI...\n";
					
					Sleep(1000);
					
					system("cls");
							
					cout << "PILHA 1: " << pilhas[0] << endl;
					cout << "PILHA 2: " << pilhas[1] << endl;
					cout << "PILHA 3: " << pilhas[2] << endl;
					
					cout << endl;
					
					cout << "PENSANDO...\n";
					
					cout << "JA SEI...\n";
							
					Sleep(1000);
							
					cout << "SUA VEZ :)\n";
					
					Sleep(1000);
					
					humano = true;
			
				}
				
			}
			
			system("cls");
			
			cout << "PILHA 1: " << pilhas[0] << endl;
			cout << "PILHA 2: " << pilhas[1] << endl;
			cout << "PILHA 3: " << pilhas[2] << endl;
			
			cout << endl;
			
			if(humano){
					
				cout << "COMPUTADOR VENCEU\n";
				cout << "O ESPERADO ACONTECEU :)\nMENTES INFERIORES NAO ME SURPREENDEM :)\n\n";
				
			}else{
				
				cout << "HUMANO VENCEU\n";
				cout << "EITA KARAI :O\n";
				
			}
			
			system("pause");
			
		}else if(opc==2){
			
			system("cls");
			
			cout << "SE TU TA JOGANDO ESSA PORRA, JA SABE COMO JOGA ;-;\n";
			system("pause");
			
		}else{
			
			break;
			
		}
		
	}
	
	return 0;
}