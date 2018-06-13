#include <stdio.h>
#include <string.h>

/*
Autor: Felipe Caliel RA: 1888/18-1
 */
 
void menu() {
	
	system ("cls");
  	printf("\n  === LOJA DE ROUPAS > ESTOQUE ===\n\n");
 	printf("|============== MENU ==============|\n");
 	printf("|                                  |\n"); 
 	printf("| 1 - CADASTRAR PRODUTOS           |\n");
 	printf("| 2 - ALTERAR PRODUTOS             |\n");
	printf("| 3 - EXCLUIR PRODUTO              |\n");
	printf("| 4 - LOCALIZAR PRODUTO            |\n");
	printf("| 5 - LISTAR TODOS PRODUTOS        |\n");
	printf("| 6 - RELATORIO ESTOQUE            |\n");
	printf("| 7 - SAIR                         |\n");
	printf("|                                  |\n");
	printf("|==================================|\n");
	printf("\nInforme a opcao desejada -> ");

}
 
int main(){
  	
  struct produto {
	int codigo, quantidade, tamanho, sexo;
	char descricao[60];
	float valor; 	
	};	
	
	
  FILE *pont_arq;
  char texto_str[250];
  char* token;
  
  struct produto vetor[200];
  int i = 0,opcao;
  int p = 0,j;
  int x = 0,pos,resp;
  float s,t;
  
  pont_arq = fopen("dados.txt", "r");

  while(fgets(texto_str, 250, pont_arq) != NULL) {

	token = strtok(texto_str, "@");
     
    while (token != NULL) {
        
		if (p == 0) {
      	strcpy(vetor[i].descricao,token);
        p++;
	  }
	  
	  else if (p == 1) {
	  	vetor[i].sexo = atoi(token);
	    p++;
	  }
	  
	  else if (p == 2) {
	  	vetor[i].tamanho = atoi(token);
	    p++;
	  }
	  
	  else if (p == 3) {
      	vetor[i].quantidade = atoi(token); 
        p++;
	  }
	  else if (p == 4) {
	  	sscanf(token, "%f", &vetor[i].valor); 
	    p++;
	  }
        token = strtok(NULL, "@"); 
       
    }
     p=0;
     i++; 
}
  
  fclose(pont_arq); 
  
  menu(); 
  scanf("%d",&opcao);
  
  while (opcao != 7) {
  	
  	
  	switch(opcao) {
  		case 1:
  			system ("cls");
  					printf("Voce selecionou a opcao 1 - Cadastrar Produto\n");
					printf("-----  DIGITE AS INFORMACOES DO PRODUTO  -----\n\n");
    	
    				printf("CODIGO: %d\n", i);
    	
    				printf("DESCRICAO:");
    				scanf("%s",&vetor[i].descricao);
    	
    				printf("OPCAO: 1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
    				scanf("%d",&vetor[i].sexo);
    				
    				while (vetor[i].sexo >=4 ){
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
    					scanf("%d",&vetor[i].sexo);
    					
    				}	
				
    				printf("TAMANHO: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    				scanf("%d",&vetor[i].tamanho);
    				
    				while (vetor[i].tamanho >= 7){			
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("TAMANHO: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    					scanf("%d",&vetor[i].tamanho);
    					
    				} 
    	
    				printf("QUANTIDADE:");
    				scanf("%d",&vetor[i].quantidade);
    	
    				printf("VALOR:");
    				scanf("%f",&vetor[i].valor);
	
    		system ("cls");
  			
  			i++;
  			
  			printf("Deseja cadastrar um novo produto sim(s) ou nao(n)?");
  			scanf("%s",&resp);
  				
  			while ( ( resp == 'S' ) || ( resp == 's' ) ){
                    system ("cls");
  					printf("Voce selecionou - Cadastrar Novo Produto\n");
					printf("****  DIGITE AS INFORMACOES DO PRODUTO  ****\n\n");
    	
    				printf("CODIGO: %d\n", i);
    	
    				printf("DESCRICAO:");
    				scanf("%s",&vetor[i].descricao);
    	
    				printf("OPCAO: 1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
    				scanf("%d",&vetor[i].sexo);
    				
    				while (vetor[i].sexo >=4 ){
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
    					scanf("%d",&vetor[i].sexo);
    					
    				}	
				
    				printf("TAMANHO: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    				scanf("%d",&vetor[i].tamanho);
    				
    				while (vetor[i].tamanho >= 7){			
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("TAMANHO: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    					scanf("%d",&vetor[i].tamanho);
    					
    				} 
    	
    				printf("QUANTIDADE:");
    				scanf("%d",&vetor[i].quantidade);
    	
    				printf("VALOR:");
    				scanf("%f",&vetor[i].valor);
    				
    		system ("cls");
    		
    		i++;
    		
    		printf("Deseja cadastrar um novo produto sim(s) ou nao(n)?");
  			scanf("%s",&resp);
  		}
  		break;
  		
  		case 2:
  			system ("cls");
  			printf("Voce selecionou a opcao 2 - Alterar Produto\n\n");
			printf("Informe o codigo do produto que deseja alterar:");
  			scanf("%d",&pos);
  			
  			while (pos > 0 && pos >= i  ){
    				 	
               	printf("\nCodigo invalido, informe novamente:\n\n");
               	
               	printf("Informe o codigo do produto que deseja alterar:");
  				scanf("%d",&pos);
  				system ("cls");
               } 
			system ("cls");			
  			printf("\nDESCRICAO: %s ", vetor[pos].descricao);
  			
  			printf("| OPCAO: ",vetor[pos].sexo);
  			
  			if (vetor[pos].sexo == 1){
      			printf("MASCULINO");
      			
	  		}if (vetor[pos].sexo == 2){
	  			printf("FEMININO");
			
			}if (vetor[pos].sexo == 3){
	  			printf("UNISSEX");
	  			
	  		}
  			
  			printf("| TAMANHO: ", vetor[pos].tamanho);
  			
  			if (vetor[pos].tamanho == 1){
      			printf("PP");
      			
	  		}if (vetor[pos].tamanho == 2){
	  			printf("PEQUENO");
			
			}if (vetor[pos].tamanho == 3){
	  			printf("MEDIO");
	  			
	  		}if (vetor[pos].tamanho == 4){
	  			printf("GRANDE");
	  			
	  		}if (vetor[pos].tamanho == 5){
	  			printf("GG");
	  			
	  		}if (vetor[pos].tamanho == 6){
	  			printf("UNICO");
		}
			
			
			printf("| QUANTIDADE: %d| VALOR: R$ %.2f|\n",vetor[pos].quantidade,vetor[pos].valor);
  			
  			
  			printf("\n\n-------------------- DIGITE AS NOVAS INFORMACOES DO PRODUTO  --------------------\n\n");
  			
    				printf("Informe a Descricao do produto:");
    				scanf("%s",&vetor[pos].descricao);
    	
    				printf("Informe a Opcao: 1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
					scanf("%d",&vetor[pos].sexo);
					
					while (vetor[pos].sexo >=4 ){
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("Informe a Opcao: 1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
						scanf("%d",&vetor[pos].sexo);
						
    				}	
    				
    				printf("Informe o Tamanho: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    				scanf("%d",&vetor[pos].tamanho);
    				
    				while (vetor[pos].tamanho >= 7){			
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("Informe o Tamanho: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    					scanf("%d",&vetor[pos].tamanho);
    					
    				} 
    	
    				printf("Informe a Quantidade:");
    				scanf("%d",&vetor[pos].quantidade);
    	
    				printf("Informe o Valor:");
    				scanf("%f",&vetor[pos].valor);
    				
			system ("cls");
			
			printf("Deseja alterar um novo produto sim(s) ou nao(n)?");
  			scanf("%s",&resp);
  				
  			while ( ( resp == 'S' ) || ( resp == 's' ) ){
                    system ("cls");
  					printf("Voce selecionou - Alterar Novo Produto\n");
  					
  					printf("Informe o codigo do produto que deseja alterar:");
  					scanf("%d",&pos);
  					
  					printf("\nDESCRICAO: %s ", vetor[pos].descricao);
  			
  			printf("| OPCAO: ",vetor[pos].sexo);
  			
  			if (vetor[pos].sexo == 1){
      			printf("MASCULINO");
      			
	  		}if (vetor[pos].sexo == 2){
	  			printf("FEMININO");
			
			}if (vetor[pos].sexo == 3){
	  			printf("UNISSEX");
	  			
	  		}
  			
  			printf("| TAMANHO: ", vetor[pos].tamanho);
  			
  			if (vetor[pos].tamanho == 1){
      			printf("PP");
      			
	  		}if (vetor[pos].tamanho == 2){
	  			printf("PEQUENO");
			
			}if (vetor[pos].tamanho == 3){
	  			printf("MEDIO");
	  			
	  		}if (vetor[pos].tamanho == 4){
	  			printf("GRANDE");
	  			
	  		}if (vetor[pos].tamanho == 5){
	  			printf("GG");
	  			
	  		}if (vetor[pos].tamanho == 6){
	  			printf("UNICO");
		}
		
			printf("| QUANTIDADE: %d| VALOR: R$ %.2f|\n",vetor[pos].quantidade,vetor[pos].valor);
  			
  					printf("\n\n-------------------- DIGITE AS NOVAS INFORMACOES DO PRODUTO  --------------------\n\n");
  			
    				printf("Informe a Descricao do produto:");
    				scanf("%s",&vetor[pos].descricao);
    	
    				printf("Informe a Opcao: 1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
					scanf("%d",&vetor[pos].sexo);
					
					while (vetor[pos].sexo >=4 ){
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("Informe a Opcao: 1- MASCULINO | 2- FEMININO | 3- UNISSEX: ");
						scanf("%d",&vetor[pos].sexo);
						
    				}	
    				
    				printf("Informe o Tamanho: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    				scanf("%d",&vetor[pos].tamanho);
    				
    				while (vetor[pos].tamanho >= 7){			
    				 	
                    	printf("\nOpcao invalida, informe novamente:\n\n");
                    	
                    	printf("Informe o Tamanho: 1- PP | 2- P | 3- M | 4- G | 5- GG | 6- UN: ");
    					scanf("%d",&vetor[pos].tamanho);
    				
    				} 
    	
    				printf("Informe a Quantidade:");
    				scanf("%d",&vetor[pos].quantidade);
    	
    				printf("Informe o Valor:");
    				scanf("%f",&vetor[pos].valor);
    				
    				system ("cls");
    				
    				printf("Deseja Alterar um novo produto sim(s) ou nao(n)?");
  					scanf("%s",&resp);
  		}
  		
  		break;
  		
  		case 3:
  			system ("cls");
  			printf("Voce selecionou a opcao 3 - Excluir Produto\n\n");
			printf("Informe o codigo do produto que excluir:");
  			scanf("%d",&pos);
  			
  			while (pos > 0 && pos >= i  ){
    				 	
               	printf("\nCodigo invalido, informe novamente:\n\n");
               	
               	printf("Informe o codigo do produto que deseja localizar:");
  				scanf("%d",&pos);
  				system ("cls");
               }         
  			system ("cls");
  			
  			printf("\nDESCRICAO: %s", vetor[pos].descricao);
  			
  			printf("| OPCAO: ",&vetor[pos].sexo);
  			
  			if (vetor[pos].sexo == 1){
      			printf("MASCULINO");
      			
	  		}if (vetor[pos].sexo == 2){
	  			printf("FEMININO");
			
			}if (vetor[pos].sexo == 3){
	  			printf("UNISSEX");
	  			
	  		}
  			
  			printf("| TAMANHO: ", vetor[pos].tamanho);
  			
  			if (vetor[pos].tamanho == 1){
      			printf("PP");
      			
	  		}if (vetor[pos].tamanho == 2){
	  			printf("PEQUENO");
			
			}if (vetor[pos].tamanho == 3){
	  			printf("MEDIO");
	  			
	  		}if (vetor[pos].tamanho == 4){
	  			printf("GRANDE");
	  			
	  		}if (vetor[pos].tamanho == 5){
	  			printf("GG");
	  			
	  		}if (vetor[pos].tamanho == 6){
	  			printf("UNICO");
		}
				
			printf("| QUANTIDADE: %d| VALOR: R$ %.2f|\n",vetor[pos].quantidade,vetor[pos].valor);
  			
  			printf("\nDeseja realmente excluir o produto? sim(s) ou nao(n): ");
            scanf("%s",&resp);
            
            if ( ( resp == 'S' ) || ( resp == 's' ) ){
                    vetor[pos].quantidade=0;
                    printf("\nExclusao realizada com sucesso\n\n");
                }else{
                    if ( ( resp == 'N' ) || ( resp == 'n' ) ){
                        printf("Exclusao cancelada!\n");
  					}
  			}
  			
  			system("pause");
  			
  		break;
  		
  		case 4:
  			system ("cls");
  			printf("Voce selecionou a opcao 4 - Localizar Produto\n\n");
  			printf("Informe o codigo do produto que deseja localizar:");
  			scanf("%d",&pos);
  		
  			
  			while (pos > 0 && pos >= i  ){
    				 	
               	printf("\nCodigo invalido, informe novamente:\n\n");
               	
               	printf("Informe o codigo do produto que deseja localizar:");
  				scanf("%d",&pos);
  				system ("cls");
               }         
  			system ("cls");
  			printf("\nDESCRICAO: %s", vetor[pos].descricao);
  			
  			printf("| OPCAO: ",&vetor[pos].sexo);
  			
  			if (vetor[pos].sexo == 1){
      			printf("MASCULINO");
      			
	  		}if (vetor[pos].sexo == 2){
	  			printf("FEMININO");
			
			}if (vetor[pos].sexo == 3){
	  			printf("UNISSEX");
	  			
	  		}
  			
  			printf("| TAMANHO: ", vetor[pos].tamanho);
  			
  			if (vetor[pos].tamanho == 1){
      			printf("PP");
      			
	  		}if (vetor[pos].tamanho == 2){
	  			printf("PEQUENO");
			
			}if (vetor[pos].tamanho == 3){
	  			printf("MEDIO");
	  			
	  		}if (vetor[pos].tamanho == 4){
	  			printf("GRANDE");
	  			
	  		}if (vetor[pos].tamanho == 5){
	  			printf("GG");
	  			
	  		}if (vetor[pos].tamanho == 6){
	  			printf("UNICO");
		}
			
			
			printf("| QUANTIDADE: %d| VALOR: R$ %.2f|\n",vetor[pos].quantidade,vetor[pos].valor);
        	system ("pause");
    

  		break;
  		
  		case 5:
  			system ("cls");
  			printf("Voce selecionou a opcao 5 - Listar Produtos\n\n");
  			
  			printf("********************************************** PRODUTOS EM ESTOQUE **********************************************");
  			printf("\n|===============================================================================================================|");
  			printf("\n|    CODIGO	|	DESCRICAO	|	OPCAO	  |	TAMANHO	  |	  QUANTIDADE	|  VALOR	|");
			printf("\n|===============================================================================================================|");
	
			for(x=0; x != i; x++) {
				
			if (x < i){
				
			
			printf("\n|	%d	|	%s		|", x , vetor[x].descricao);
				
  			printf("	 ",&vetor[x].sexo);
  			
  			if (vetor[x].sexo == 1){
      			printf("MASCULINO");
      			
	  		}if (vetor[x].sexo == 2){
	  			printf("FEMININO ");
			
			}if (vetor[x].sexo == 3){
	  			printf("UNISSEX  ");
	  			
	  		}
  			  
  			printf("|	   ", vetor[x].tamanho);
  			 
  			if (vetor[x].tamanho == 1){
      			printf("PP     ");
      			
	  		}if (vetor[x].tamanho == 2){
	  			printf("PEQUENO");
			
			}if (vetor[x].tamanho == 3){
	  			printf("MEDIO  ");
	  			
	  		}if (vetor[x].tamanho == 4){
	  			printf("GRANDE ");
	  			
	  		}if (vetor[x].tamanho == 5){
	  			printf("GG     ");
	  			
	  		}if (vetor[x].tamanho == 6){
	  			printf("UNICO  ");
		}
			
			
			printf("|		%d	|  R$ %.2f	|",vetor[x].quantidade,vetor[x].valor);
        
				}
			}
			printf("\n|===============================================================================================================|\n");
  			system("pause");
  			
  		break;
		case 6:
			system ("cls");
  			printf("Voce selecionou a opcao 6 - Relatorio Estoque\n\n");
  			
  			printf("*************************************** RELATORIOS DE PRODUTOS EM ESTOQUE ****************************************");
  			printf("\n|================================================================================================================|");
  			printf("\n|	DESCRICAO	|	OPCAO	  |	TAMANHO	  |	  QUANTIDADE	|  VALOR	|	TOTAL	 |");
			printf("\n|================================================================================================================|");
			
			for(x=0; x != i; x++) {
				
			if (x < i){
				
			s = vetor[x].quantidade*vetor[x].valor;
	
			printf("\n|	%s		|", vetor[x].descricao);
			printf("	 ",&vetor[x].sexo);
  			
  			if (vetor[x].sexo == 1){
      			printf("MASCULINO");
      			
	  		}if (vetor[x].sexo == 2){
	  			printf("FEMININO ");
			
			}if (vetor[x].sexo == 3){
	  			printf("UNISSEX  ");
	  			
	  		}
  			  
  			printf("|	   ", vetor[x].tamanho);
  			 
  			if (vetor[x].tamanho == 1){
      			printf("PP     ");
      			
	  		}if (vetor[x].tamanho == 2){
	  			printf("PEQUENO");
			
			}if (vetor[x].tamanho == 3){
	  			printf("MEDIO  ");
	  			
	  		}if (vetor[x].tamanho == 4){
	  			printf("GRANDE ");
	  			
	  		}if (vetor[x].tamanho == 5){
	  			printf("GG     ");
	  			
	  		}if (vetor[x].tamanho == 6){
	  			printf("UNICO  ");
		}
			
			printf("|		%d	|  R$ %.2f	| R$ %.2f	 |",vetor[x].quantidade,vetor[x].valor, s);
        	
				}
			}
			printf("\n|================================================================================================================|\n");	 
  			system("pause");
  			
		break;	
		
  		default:
  			printf("Opcao invalida!\n");
		break;    		
  		
	  }
  	
  	menu();
  	scanf("%d",&opcao);
  	
  	
  }

  pont_arq = fopen("dados.txt", "w");
  
  for(j=0; j < i; j++) {
  	
    if (vetor[j].quantidade >= 1){
	  	fprintf(pont_arq,"%s@%d@%d@%d@%.2f\n", vetor[j].descricao,vetor[j].sexo,vetor[j].tamanho,vetor[j].quantidade,vetor[j].valor);
    }
  }
  
  fclose(pont_arq);
  
  
}
