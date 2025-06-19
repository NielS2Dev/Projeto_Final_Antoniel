#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h> 

//                                                          Aluno: Antoniel da Silva Alves.         	Matrícula: 20250017003    
//                                                          Aluno: Pedro Gabriel Machado de Barros. 	Matrícula: 20250038783  


// funções basicas.
void definirCorTexto(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    /* Colinha da tabela de cores kk
     0  - Preto (Black)
	 1  - Azul
	 2  - Verde
	 3  - Ciano
	 4  - Vermelho
	 5  - Roxo
	 6  - Amarelo
	 7  - Branco
	 8  - Cinza
	 9  - Azul Claro
	10  - Verde Claro
	11  - Ciano Claro
	12  - Vermelho Claro
	13  - Roxo Claro
	14  - Amarelo Claro
	15  - Branco Brilhante
*/
}


void animacao(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void print_animado_multilinha(const char *linhas[], int num_linhas, int delay_ms) {
    int max_len = 0;
    int i = 0, pos = 0, linha = 0;
    
    for (i = 0; i < num_linhas; i++) {
        int len = (int)strlen(linhas[i]);
        if (len > max_len) max_len = len;
    }

    system("cls");
    for (pos = 0; pos < max_len; pos++) {
        for (linha = 0; linha < num_linhas; linha++) {
            if (pos < (int)strlen(linhas[linha])) {
                animacao(pos, linha);
                putchar(linhas[linha][pos]);
            }
        }
        Sleep(delay_ms);
    }
    
    animacao(0, num_linhas + 1);
}



// Imagens em art ASCII

void pedra(){
	definirCorTexto(3);
    printf("                                                           \n");
    printf("        --:::---::::----:                                 \n");
    printf("      ---=--:::::::::::::::-::::::::-::::::::-:--         \n");
    printf("    =======++===------------::::::::::::::::::::::-       \n");
    printf("   =======+++==++++++**++++==========--------::::---      \n");
    printf("  --====+++==-=====+***++++++++++++++++======---====-     \n");
    printf("  --====+++====+++++++==++++++++++++++++++============-   \n");
    printf("  --=======++**#**++++====++++++++++++++++++=======+++==  \n");
    printf("  --====+**#######*++++++++++++++++++++++++++====++*#%#+  \n");
    printf("  --==+*###*++**###*+++*****++++++++++++++++++++++*#%%%*  \n");
    printf("  --==+***++++++*****#####*+++++++++++++++++++++*#%%%%%%  \n");
    printf("   =++***++**************++=======+++++++++++++*#%%%%%%%  \n");
    printf("   =++****++*******++++++=======+++++***+++++++*%%%%%%%%  \n");
    printf("   =+++*****************+===++++++++*####**++++#%%%%%%%%  \n");
    printf("    +++****************+++++++++++++***+++++***%%%%%%%%%  \n");
    printf("    ++++*************++++++++++++++++++++++*****##%%%%%   \n");
    printf("     ++********************+++++++++++++++++++++*#%%%%%   \n");
    printf("        #**********************++++++++****++++++**%%%    \n");
    printf("           =+****++++****************+**+++++++++****     \n");
    printf("                     ====+++++++++***+++****+**           \n");
    printf("                                                        \n");
	definirCorTexto(7);
}


void papel(){
	definirCorTexto(2);
	printf("         ,..........   ..........,         \n");
    printf("     ,..,'          '.'          ',..,     \n");
    printf("    ,' ,'            :            ', ',    \n");
    printf("   ,' ,'             :             ', ',   \n");
    printf("  ,' ,'              :              ', ',  \n");
    printf(" ,' ,'............., : ,.............', ', \n");
    printf(",'  '............   '.'   ............'  ',\n");
    printf(" '''''''''''''''''';''';'''''''''''''''''' \n");
    printf("                    '''                   \n");
    definirCorTexto(7);
}


void tesoura(){
		definirCorTexto(6);
	    printf(
        "    ########                                      \n"
        "  ##      ##                                      \n"
        "  ##        ##                          ########  \n"
        "  ##                                ############  \n"
        "    ##########                ############        \n"
        "                ######  ##############            \n"
        "                  ##############                  \n"
        "                  ##############                  \n"
        "                ######  ##############            \n"
        "    ##########                ############        \n"
        "  ##                                ############  \n"
        "  ##        ##                            ######  \n"
        "  ##        ##                                    \n"
        "    ########                                      \n"
    );
    definirCorTexto(7);
}


// Textos em art ASCII

void textoPedra(){
    const char *arte[] = {
        " _______  _______  ______   ______    _______ ",
        "|       ||       ||      | |    _ |  |   _   |",
        "|    _  ||    ___||  _    ||   | ||  |  |_|  |",
        "|   |_| ||   |___ | | |   ||   |_||_ |       |",
        "|    ___||    ___|| |_|   ||    __  ||       |",
        "|   |    |   |___ |       ||   |  | ||   _   |",
        "|___|    |_______||______| |___|  |_||__| |__|"
    };

    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    definirCorTexto(3); 
    print_animado_multilinha(arte, num_linhas, 30);
    definirCorTexto(7);
}


void textoPapel(){
    const char *arte[] = {
        " _______  _______  _______  _______  ___     ",
        "|       ||   _   ||       ||       ||   |    ",
        "|    _  ||  |_|  ||    _  ||    ___||   |    ",
        "|   |_| ||       ||   |_| ||   |___ |   |    ",
        "|    ___||       ||    ___||    ___||   |___ ",
        "|   |    |   _   ||   |    |   |___ |       |",
        "|___|    |__| |__||___|    |_______||_______|"
    };

    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    definirCorTexto(2);
    print_animado_multilinha(arte, num_linhas, 30);
    definirCorTexto(7);
}


void textoTesoura() {
    const char *arte[] = {
        " _______  _______  _______  _______  __   __  ______    _______ ",
        "|       ||       ||       ||       ||  | |  ||    _ |  |   _   |",
        "|_     _||    ___||  _____||   _   ||  | |  ||   | ||  |  |_|  |",
        "  |   |  |   |___ | |_____ |  | |  ||  |_|  ||   |_||_ |       |",
        "  |   |  |    ___||_____  ||  |_|  ||       ||    __  ||       |",
        "  |   |  |   |___  _____| ||       ||       ||   |  | ||   _   |",
        "  |___|  |_______||_______||_______||_______||___|  |_||__| |__|"
    };
    
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    definirCorTexto(6); 
    print_animado_multilinha(arte, num_linhas, 30);
    definirCorTexto(7);
}


void pedraPapelTesoura(){
	definirCorTexto(10);
	printf(" ___  ___  __   ___   _       ___   _   ___  ___  _     ___    ___  ___  __   _   _ _  ___   _  \n");
    printf("| o \\| __||  \\ | o \\ / \\     | o \\ / \\ | o \\| __|| |   | __|  |_ _|| __|/ _| / \\ | | || o \\ / \\ \n");
    printf("|  _/| _| | o )|   /| o |    |  _/| o ||  _/| _| | |_  | _|    | | | _| \\_ \\( o )| U ||   /| o |\n");
    printf("|_|  |___||__/ |_|\\\\|_n_|()  |_|  |_n_||_|  |___||___| |___|   |_| |___||__/ \\_/ |___||_|\\\\|_n_|\n");
    printf("                                                                                                \n");
    definirCorTexto(7);
}



void inicioJogo(){
	definirCorTexto(2);
	printf("  ___   _  _   ___    ___   ___     _     ___      ___         _    ___     ___    ___  \n");
    printf(" |_ _| | \\| | |_ _|  / __| |_ _|   /_\\   | _ \\    / _ \\     _ | |  / _ \\   / __|  / _ \\ \n");
    printf("  | |  | .` |  | |  | (__   | |   / _ \\  |   /   | (_) |   | || | | (_) | | (_ | | (_) |\n");
    printf(" |___| |_|\\_| |___|  \\___| |___| /_/ \\_\\ |_|_\\    \\___/     \\__/   \\___/   \\___|  \\___/ \n");
    printf("                                                                                         \n");
    definirCorTexto(7);
}


void gameover(){
	printf("  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      \n");
	printf(" /  _____|    /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\     \n");
	printf("|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    \n");
	printf("|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     \n");
	printf("|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--'  |    \\    /    |  |____ |  |\\  \\----. \n");
	printf(" \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| `._____|   \n");
}


// Compacto de partes funcionais do meu código, parte propriamente dito do funcionameto do meu jogo.

void parteInicial(){
	// fiz esse void para ficar mais organizado o meu principal "Main".
	textoPedra();
	pedra();
	Sleep(2000);
	system("cls");
	
	textoPapel();
	papel();
	Sleep(2000);
	system("cls");
	
	textoTesoura();
	tesoura();
	Sleep(2000);
	system("cls");
}


void exibirCabecalho() {
    definirCorTexto(14);
    printf("==========================================================================================================\n");
    printf("                                       JOGO: PEDRA, PAPEL E TESOURA\n");
    printf("==========================================================================================================\n");
    definirCorTexto(7);
}






int main(){
    SetConsoleOutputCP(1252);
	srand(time(NULL));
	
	inicioJogo();
	definirCorTexto(15); // cor branca forte!
	printf("Aperte qualquer tecla para Iniciar o Jogo:	");
	definirCorTexto(7);
	getch();
	system("cls"); // para garantir que vai limpar a tela pois ocorreu alguns bugs, entãoo decidi por por redundanciaa.
	
	parteInicial();
	exibirCabecalho();
	
	
	// Jogo propriamente dito!
	int opcaoJogador, opcaoMaquina, pontosJogador;
	
	do {
		pedraPapelTesoura();
		opcaoMaquina = rand() % 3 + 1;

		// Deixei essa parte aqui
		// coloquei essa parte para ele ficar testando o programa ja sabendo oq o computador tinha "escolhido".
		
		/*
		if(opcaoMaquina == 1){
	    		definirCorTexto(14);
	    		printf("Máquina escolheu ___PEDRA___\n\n");
	    		//system("cls");
	    		//pedraPapelTesoura();
			} else if (opcaoMaquina == 2){
				definirCorTexto(14);
				printf("Máquina escolheu ___PAPEL___\n\n");
				//system("cls");
				//pedraPapelTesoura();
			} else {
				definirCorTexto(14);
				printf("Máquina escolheu ___TESOURA___\n\n");
				//system("cls");
				//pedraPapelTesoura();
			}
		*/	
		
		definirCorTexto(15);
		printf("Escolha alguma das opções abaixo:\n1 - Pedra\n2 - Papel\n3 - Tesoura\n4 - Finalizar Programa\n");
		printf("Digite o número correpondente a sua escolha: ");
		scanf("%d", &opcaoJogador);	
		definirCorTexto(7);
		

		if (opcaoJogador <1 || opcaoJogador > 4){
		definirCorTexto(4);
		printf("\nDigite algum número válido!, amigo(a)!!!\n");
		printf("Os valores são...\n\n");
		definirCorTexto(7);
		continue;
		}
		
		
		if (opcaoJogador == 4){
			printf("Programa Finalizando!\n");
			int temp = 0;
			for (temp = 3; temp >= 0; temp--){
				printf("Finalizando o jogo em %d segundos...\n", temp);
				Sleep(500); 
			}
			system("CLS");
			definirCorTexto(13);
			gameover();
			definirCorTexto(7);
			break;
		}
		
		
		if (opcaoJogador == opcaoMaquina){
			definirCorTexto(3);
			system("cls");
			if(opcaoMaquina == 1){
			    printf("------------------------------------------------------------------------------------------------------------\n");
			    printf("                                         A Máquina escolheu Pedra                                           \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			} else if (opcaoMaquina == 2){
				printf("------------------------------------------------------------------------------------------------------------\n");
			    printf("                                       A Máquina escolheu Papel                                             \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");

			} else {
				printf("------------------------------------------------------------------------------------------------------------\n");
   				printf("                                        A Máquina escolheu Tesoura                                          \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			}
			printf("------------------------------------------------------------------------------------------------------------\n");
			printf("                                               EMPATE!!                                                    \n");
			printf("------------------------------------------------------------------------------------------------------------\n");
			definirCorTexto(15);
			printf("Pontuação atual [%d] Pontos.\n", pontosJogador);

		} else if ((opcaoJogador == 1 && opcaoMaquina == 3) || (opcaoJogador == 2 && opcaoMaquina == 1) || (opcaoJogador == 3 && opcaoMaquina== 2)){
			definirCorTexto(2); 
			system("cls");
			if(opcaoMaquina == 1){
			    printf("------------------------------------------------------------------------------------------------------------\n");
			    printf("                                         A Máquina escolheu Pedra                                           \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			} else if (opcaoMaquina == 2){
				printf("------------------------------------------------------------------------------------------------------------\n");
			    printf("                                       A Máquina escolheu Papel                                             \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			} else {
				printf("------------------------------------------------------------------------------------------------------------\n");
   				printf("                                        A Máquina escolheu Tesoura                                          \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			}
			printf("------------------------------------------------------------------------------------------------------------\n");
			printf("                                               VOCÊ VENCEU                                                  \n");
			printf("------------------------------------------------------------------------------------------------------------\n");
			definirCorTexto(15);
			printf("Pontuação atual [%d] Pontos.\n", pontosJogador);
			pontosJogador ++;
		} else{
			definirCorTexto(4);
			system("cls");
			if(opcaoMaquina == 1){
			    printf("------------------------------------------------------------------------------------------------------------\n");
			    printf("                                         A Máquina escolheu Pedra                                           \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			} else if (opcaoMaquina == 2){
				printf("------------------------------------------------------------------------------------------------------------\n");
			    printf("                                       A Máquina escolheu Papel                                             \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			} else {
				printf("------------------------------------------------------------------------------------------------------------\n");
   				printf("                                        A Máquina escolheu Tesoura                                          \n");
			    printf("------------------------------------------------------------------------------------------------------------\n");
			}
			printf("------------------------------------------------------------------------------------------------------------\n");
			printf("                                          O COMPUTADOR VENCEU!!                                             \n");
			printf("------------------------------------------------------------------------------------------------------------\n");
			definirCorTexto(15);
			printf("Pontuação atual [%d] Pontos.\n", pontosJogador);
			pontosJogador --;
		}
		

		
	} while(1);
	// Esse while (1) é um loop inifiti até ocorrer um brek dentro do meu programa.

}













