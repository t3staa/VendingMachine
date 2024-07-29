/*Dados:
* Leonardo Testa
* Fatec Ribeir�o Preto - Curso ADS Manh�
* Data: 07/06/2022
*/

#include <iostream>
#include <iomanip>

using namespace std;

//DECLARAÇÃO DAS FUNCÕES
int funcaoCompra(string nomePdt[5], float precoPdt[5], int codPdt[5], int quantMaq[5]);
int funcaoAdm(string nomePdt[5], float precoPdt[5], int codPdt[5], int quantMaq[5]);

//VARIAVEIS GLOBAIS PARA CONTROLE DO USUARIO E CONTROLE DO FATURAMENTO DA MAQUINA
float faturamento = 0;
float faturamento_possivel = 0;
bool controleUsuario = true;

//SENHA PARA O MODO ADM
string senhaAdm = "1234";

/////////////////////////////////////////////////INICIO FUNÇÃO MAIN/////////////////////////////////////////////////
int main (){
    
    //Variaveis
    char modoEntrada, continuaCompra; //Char para verifica��o do modo de uso da maquina.
    int codigoProduto;

    
    //Vetores para controle de produtos
    string nomeProduto[5];
    float precoProduto[5];
    int codProduto[5];
    int quantidadeMaquina[5];
    


    //Definindo o nome dos produtos.
    nomeProduto[0] = "Coca Cola"; 
    nomeProduto[1] = "Pepsi    "; 
    nomeProduto[2] = "Fanta    "; 
    nomeProduto[3] = "Guarana  "; 
    nomeProduto[4] = "Sprite   ";    
     
    //Definindo o preco dos produtos.
    precoProduto[0] = 3.50; //CocaCola
    precoProduto[1] = 2.50; //Pepsi
    precoProduto[2] = 2.30; //Fanta
    precoProduto[3] = 2.50; //Guarana
    precoProduto[4] = 1.90; //Sprite
    
    //Definindo o codigo dos produtos para controle.
    codProduto[0] = 1; //CocaCola
    codProduto[1] = 2; //Pepsi
    codProduto[2] = 3; //Fanta
    codProduto[3] = 4; //Guarana
    codProduto[4] = 5; //Sprite
    
    //Definindo a quantidade inicial de produtos na maquina.
    quantidadeMaquina[0] = 10;
    quantidadeMaquina[1] = 10;
    quantidadeMaquina[2] = 10;
    quantidadeMaquina[3] = 10;
    quantidadeMaquina[4] = 10;

   
       
    /////////////////////////////////////////////////VERIFICAÇÃO DO USUÁRIO/////////////////////////////////////////////////
    while(controleUsuario == true){
       
       system("cls");                   
       cout << "Bem vindo a maquina de compras !!" << endl;
       cout << "Deseja entrar no modo usuario ou modo adm: " << endl;
       cout << "Use apenas [U]suario / [A]dministrador: ";
       cin >> modoEntrada;
          
       if(modoEntrada == 'u' || modoEntrada == 'U'){
              //CHAMA A FUNÇÃO COMPRA.
              cout << "\n";
              funcaoCompra(nomeProduto, precoProduto, codProduto, quantidadeMaquina);
                      
       }else if(modoEntrada == 'a' || modoEntrada == 'A'){
              //CHAMA A FUNÇÃO ADMINISTRADOR.
              cout << "\n";
              funcaoAdm(nomeProduto, precoProduto, codProduto, quantidadeMaquina);

       }
    }
    
    system("pause");
    return 0;
}



/////////////////////////////////////////////////FUNCOES/////////////////////////////////////////////////
//Função administrador.
int funcaoAdm(string nomePdt[5], float precoPdt[5], int codPdt[5], int quantMaq[5]){

       string senha;
       bool vC = true;
       int codLista = 0;
       int codRep = 0;
       int quantRep = 0;
       
       //Limpa a tela
       system("cls");
       
       //Requisitando a senha para entrar no modo ADM
       cout << "Digite a senha do modo ADM: ";
       cin >> senha;
       //A SENHA "1234".

       while(vC){
              
              //TODO PROGRAMA ESTARA DENTRO DESSE IF, CASO O OPERADOR ACERTAR A SENHA O CODIGO É EXECUTADO.
              if(senha == senhaAdm){
                     
                     system("cls");
                       
                     cout << "O que voce deseja fazer ? " << endl;
                     cout << "1 - Repor Itens " << endl;
                     cout << "2 - Ver faturamento total da maquina " << endl;
                     cout << "3 - Ver Lista de Itens" << endl;
                     cout << "4 - Sair" << endl;
                     cout << "\n";
                     
                     cout << "Desejo: ";
                     cin >> codLista;


                     if(codLista > 0 || codLista <= 4){
                            switch (codLista){
                                   case 1: 
                                          //Limpa a tela
                                          system("cls");
                                          
                                          cout << "\\\\\\\\\\Modo Repor Itens\\\\\\\\\\" << endl;
                                          cout << "\n";
                                          
                                          //REPOR ITENS.
                                          
                                          for(int pd = 0; pd <= 4; pd++){
                                                 cout << nomePdt[pd] << "  -  " << "R$" << fixed << setprecision(2) << precoPdt[pd] << "   Cod: " <<  codPdt[pd] << "  Quant:  " << quantMaq[pd] << endl;
                                          }

                                          //Entrada do codigo do produto que o usuario quer.
                                          cout << "\nDigite o codigo do produto para repor: ";
                                          cin >> codRep;
                                          
                                          if(codRep > 0 && codRep <= 5){
                                          
                                              //entrada da quantidade do produto que o usuario quer.
                                              cout << "Digite a quantidade para reposicao: ";
                                              cin >> quantRep;
                                              
                                              //CONTROLE PARA REPOR ITENS.
                                              switch (codRep){
                                                     case 1://Coca
                                                            quantMaq[0] += quantRep;
                                                            cout << "\nVoce repos " << quantRep << " Coca Colas"  << endl; 
                                                            system("pause");                                                                                                              
                                                            break;    
                                                     
                                                     case 2://Pepsi
                                                            quantMaq[1] += quantRep; 
                                                            cout << "\nVoce repos " << quantRep << " Pepsis"  << endl;  
                                                            system("pause");
                                                            break; 
                                                            
                                                     case 3://Fanta
                                                            quantMaq[2] += quantRep;
                                                            cout << "\nVoce repos " << quantRep << " Fantas"  << endl; 
                                                            system("pause");
                                                            break;
                                                            
                                                     case 4://Guarana
                                                            quantMaq[3] += quantRep;  
                                                            cout << "\nVoce repos " << quantRep << " Guaranas"  << endl; 
                                                            system("pause");
                                                            break; 
                                                            
                                                     case 5://Sprite
                                                            quantMaq[4] += quantRep; 
                                                            cout << "\nVoce repos " << quantRep << " Sprites" << endl; 
                                                            system("pause");
                                                            break;  
                                                     }
                                          }else{
                                               cout << "\nCodigo Invalido!!" << endl;
                                               system("pause");       
                                          }
                                          break;
                                          
                                   case 2:
                                          system("cls");
                                          cout << "\\\\\\\\\\Modo visualizacao faturamento\\\\\\\\\\" << endl;
                                          //VER FATURAMENTO DOS ITENS.
                                          cout << "\n";
                                          cout << "Faturamento total da maquina: R$" << faturamento << endl;
                                          //CONTA PARA SABER O FUTURAMENTO POSSIVEL TOTAL DA MAQUINA
                                          for(int pd = 0; pd < 5; pd++){
                                                  faturamento_possivel = faturamento_possivel + (precoPdt[pd] * quantMaq[pd]);
                                          }
                                          cout << "Faturamento Possivel maximo da maquina: R$" << faturamento_possivel << endl; 
                                          cout << "\n";
                                          faturamento_possivel = 0;
                                          system("pause");
                                          break;
                                          
                                   case 3: 
                                          system("cls");
                                          cout << "\\\\\\\\\\Modo Visualizacao Lista de Itens\\\\\\\\\\" << endl;
                                          cout << "\n";
                                          //MOSTRA A TABELA DE ITENS.
                                          for(int pd = 0; pd <= 4; pd++){
                                                 cout << nomePdt[pd] << "  -  " << "R$" << fixed << setprecision(2) << precoPdt[pd] << "   Cod: " <<  codPdt[pd] << "  Quant:  " << quantMaq[pd] << endl;
                                          }
                                          system("pause");
                                          break;
                                          
                                   case 4:
                                          //SAIR
                                          system("cls");
                                          cout << "Voce Saiu!!" << endl;
                                          system("pause");                                      
                                          vC = false;
                                          break;

                            }
                     }else{
                            cout << "Codigo Invalido!" << endl;
                            vC = true;
                     }
                     
                     



              }else if(senha != senhaAdm){
                     system("cls");
                     cout << "Senha Incorreta, tente novamente ! " << endl;
                     cout << "Aperte enter para tentar novamente" << endl;
                     vC = false;
                     system("pause");
              }
       }
       
       
        
}

//Função compra.
int funcaoCompra(string nomePdt[5], float precoPdt[5], int codPdt[5], int quantMaq[5]){
    
    int quantidade;
    int codigo;
    char continuaCompra;
    float total = 0;
    float troco;
    float dinheiro;
    bool vC = true;
    char trocaUsuario;

    
    while(vC == true){
              //Mostrando a tabela de itens.
              for(int pd = 0; pd <= 4; pd++){
                     cout << nomePdt[pd] << "  -  " << "R$" << fixed << setprecision(2) << precoPdt[pd] << "   Cod: " <<  codPdt[pd] << "  Quant:  " << quantMaq[pd] << endl;
              } 
              
              //Mostrando o total da compra ate o momento:
              cout << "\nTotal da compra ate o momento: R$" << total << endl;
              
              //Entrada do codigo do produto que o usuario quer.
              cout << "Digite o codigo do produto desejado: ";
              cin >> codigo;
              
              if(codigo > 0 && codigo <= 5){
                                  
                      //entrada da quantidade do produto que o usuario quer.
                      cout << "Digite a quantidade: ";
                      cin >> quantidade;
                      
                      if(quantidade > 0){
                      		//controle de compra dos itens.
			                      switch (codigo){
			                             case 1://Coca
			                                    if(quantidade > 0 && quantidade <= quantMaq[0]){
			                                           total += (precoPdt[0] * quantidade);
			                                    }else{
			                                           cout << "A quantidade desejada nao esta disponivel" << endl;
			                                           quantidade = 0;
			                                    }
			                                    break;    
			                             
			                             case 2://Pepsi
			                                    if(quantidade > 0 && quantidade <= quantMaq[1]){
			                                           total += (precoPdt[1] * quantidade);
			                                    }else{
			                                           cout << "A quantidade desejada nao esta disponivel" << endl;
			                                           quantidade = 0;
			                                    }  
			                                    break; 
			                                    
			                             case 3://Fanta
			                                    if(quantidade > 0 && quantidade <= quantMaq[2]){
			                                           total += (precoPdt[2] * quantidade);
			                                    }else{
			                                           cout << "A quantidade desejada nao esta disponivel" << endl;
			                                           quantidade = 0;
			                                    }
			                                    break;
			                                    
			                             case 4://Guarana
			                                    if(quantidade > 0 && quantidade <= quantMaq[3]){
			                                           total += (precoPdt[3] * quantidade);
			                                    }else{
			                                           cout << "A quantidade desejada nao esta disponivel" << endl;
			                                           quantidade = 0;
			                                    }   
			                                    break; 
			                                    
			                             case 5://Sprite
			                                    if(quantidade > 0 && quantidade <= quantMaq[4]){
			                                           total += (precoPdt[4] * quantidade);
			                                    }else{
			                                           cout << "A quantidade desejada nao esta disponivel" << endl;
			                                           quantidade = 0;
			                                    }  
			                                    break;  
			                             }
			              
			              }else{
			                    cout << "Codigo Invalido !!" << endl;
			                    quantidade = 0;
			              }
					  }else{
					  		cout << "Digite uma quantidade valida!!" << endl;
					  		quantidade = 0;
					  }
                      
                      
              
              cout << "\nTotal da compra: " << total << endl;
              
              cout << "Deseja continuar comprando: [S/N]" << endl;
              cin >> continuaCompra;
              
              //CONDIÇÃO PARA CONTINUAR A COMPRA OU NÃO.
              if(continuaCompra == 's' || continuaCompra == 'S'){
                     if(quantidade <= quantMaq[codigo - 1]){
                            quantMaq[codigo - 1] -= quantidade;
                     }
                     system("cls");
                     vC = true;          
                           
              }else if(continuaCompra == 'n' || continuaCompra == 'N'){
                     vC = false;
                     if(total != 0){
                            system("cls");  
                            cout << fixed;
                            cout.precision(2);
                            cout << "Total: R$" << total << endl;
                            cout << "Insira o valor para o pagamento: ";
                            cin >> dinheiro;
              
                            //Controle do troco
                            if(dinheiro == total) { 
                                   cout << "\nVoce nao tem troco !! " << endl;
                                   total = 0;
                                   
                            }else if(dinheiro >= total){
                                   troco = dinheiro - total;
                                   quantMaq[codigo - 1] -= quantidade;
                                   faturamento += total;
                                   cout << fixed;
                                   cout.precision(2);
                                   cout << "\nO seu troco e de: R$" << troco << endl;
                                   total = 0;
                                   
                            }else{
                                   cout << "\nSaldo Insuficiente!!" << endl;  
                                   total = 0;  
                                   cout << "\nCompra Cancelada" << endl;
                            }    
                     } 
              }
       }  
       
       
              cout << "\nDeseja trocar o usuario ? [S/N]: " << endl;
              cin >> trocaUsuario;
       
              if(trocaUsuario == 's' || trocaUsuario == 'S'){
                     controleUsuario = true;
                     vC = false;
              }
              else if(trocaUsuario == 'n' || trocaUsuario == 'N'){
                     controleUsuario = false;
                     vC = true;
              }
}