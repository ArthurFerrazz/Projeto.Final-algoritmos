//Integrantes: Ianco Ferraz de Alencar UC22200346, Curso: Analise e Desenvolvimento de Sistemas.
//Arthur Ferraz dos Santos UC22200365, Curso: Analise e Desenvolvimento de Sistemas.
//Louise Lanne Monteiro Rodrigues UC22201022, Curso: Analise e Desenvolvimento de Sistemas.


#include<stdio.h>
#include<string.h>

//Inicio da função main e variáveis
int main (){
  int i, y, tipo_I, pagamento;
  int qtde_sessoes, qtde_pessoas[2], idade[100];
  int qtde_inteira = 0, qtde_meia = 0;
  int masculino = 0, feminino = 0, mascMaior = 0, femiMaior = 0, crianca = 0, adolescente = 0, adulto = 0, idoso = 0 ;
  char sexo[100][20], filme[2][50];
  float inteira[100], meia[100], total;
  
  //Solicitação da quantidade de sessoes permitindo apenas duas para dar continuidade.
do {
    printf ("Quantidade de sessoes: ");
    scanf ("%d", &qtde_sessoes);
} 
while (qtde_sessoes != 2);


// Loop criado para as duas sessoes
for (i = 0; i < 2; i++){
	//deixando os valores igual a 0, para os valores de cada sessão não se juntarem.
	total = 0.0;
	crianca = 0;
	adolescente = 0;
	adulto = 0;
	idoso = 0;
	masculino = 0;
	feminino = 0;
	mascMaior = 0; 
	femiMaior = 0;
	qtde_inteira = 0;
	qtde_meia = 0;
	
  	//Solicitação da quantidade de pessoas, permitindo no mínimo 10.  
	printf("\nQuantidade de pessoas que assistiram o filme: ");
	scanf ("%d", &qtde_pessoas[i]);
//aqui esá menor que 9 pois o contador começa do 0.	
	while (qtde_pessoas[i] < 1){
	printf("Valor invalido. Minimo 10 pessoas: ");
	scanf ("%d", &qtde_pessoas[i]);
}
// Solicitação e armazenamento do nome do filme.
	printf("\nNome do filme: ");
	fflush(stdin);
	fgets(filme[i], 50, stdin);
//Outro loop criado com o valor da quantidade de pessoas por sessão.
for (y = 0; y <= qtde_pessoas[i]; y++){
	printf ("\nSexo [M]asculino ou [F]eminino: ");
	scanf ("%s", &sexo[y]);
	fflush (stdin);
//Se o sexo for masculino, adiciona à variável masculino
  if (strcmp(sexo[y], "M") == 0){
    masculino++;
}
//Se o sexo for feminino, adiciona à variável feminino
  else if (strcmp(sexo[y], "F") == 0){
	feminino++;
}
//Caso não seja nenhum dos 2 a resposta é inválida e o usuario tera de repetir.
  else{
  	while (strcmp(sexo[y],"F") != 0 && strcmp(sexo[y], "M") != 0){
		printf ("Sexo invalido. Selecione: [M]asculino ou [F]eminino: ");
		scanf ("%s", &sexo[y]);
		fflush (stdin);
  if (strcmp(sexo[y], "M") == 0){
	    masculino++;
}
  else if (strcmp(sexo[y], "F") == 0){
	    feminino++;
}
 }
} 
//Solicitação e armazenamento da idade do cliente.
printf ("\nIdade: ");
scanf ("%d", &idade[y]);
//Enquanto a idade for menor que 3 e maior que 100 o usuario tem de repetir pois a idade mínima é 3 anos e a máxima é de 100 anos.
while ( idade[y] < 3 || idade[y] > 100 ){
		printf("\n\nIdade invalida. Idade minima 3 anos e maxima 100 anos: ");
		scanf ("%d", &idade[y]);
}
//Adicionando a idade nas respectivas faixas etárias, utilizando a mesma lógica, caso a idade inserida esteja dentro da condição é adicionada à variável.
	if (idade[y] >= 3 && idade[y] <= 13){
	    crianca++;
}
	else if (idade[y] >= 14 && idade[y] <= 17){
	    adolescente++;
}
	else if (idade[y] >= 18 && idade[y] <= 64){
	    adulto++;
}
	else if (idade[y] >= 65 && idade[y] <= 100){
		idoso++;
}
//Já aqui, caso a idade seja maior que 18 e de acordo com o sexo escolhido, é adicionado as respectivas variáveis. "mascMaior" == homem maior de 18 e "femiMaior" == mulher maior de 18.
    if (idade[y] >= 18 && strcmp(sexo[y], "M") == 0){
		mascMaior++;
}
	else if (idade[y] >= 18 && strcmp(sexo[y], "F") == 0){
		femiMaior++; 
}

//Solicitação e armazenamento do tipo de ingresso comprado.
printf("\nIngresso comprado: \n[1]INTEIRA - R$50,00\n[2]MEIA - R$25,00\n");
scanf ("%d", &tipo_I);
//Enquanto o tipo do ingresso for maior que 2 ou menor que 1 repete o processo pois só tem as opções 1 e 2.
while (tipo_I > 2 || tipo_I < 1){
	printf("Ingresso Invalido, \n[1]INTEIRA - R$50,00\n[2]MEIA - R$25,00\n");
	scanf ("%d", &tipo_I);
}
//Forma de pagamento utilizada para compra do ingresso. (Funcionalidade extra adicionada)
printf("Forma de pagamento\nOPCOES: [1]PIX  [2]Dinheiro  [3]Debito  [4]Credito");
printf("\nForma de pagamento utilizada: ");
scanf("%d",&pagamento);
//Switch para mostrar a forma de pagamento utilizada.
switch(pagamento){
	case 1:
		printf("Pagamento efetuado com: PIX\n");
		break;
	case 2:
		printf("Pagamento efetuado com: Dinheiro\n");
		break;
	case 3:
		printf("Pagamento efetuado com: Cartao de Debito\n");
		break;
	case 4:
		printf("Pagamento efetuado com: Cartao de Credito\n");
		
}

//Switch para o cálculo do valor arrecadado para cada tipo de ingresso comprado, e adição de 1 a variavel de quantidade.
  switch(tipo_I){
	case 1:
		qtde_inteira = qtde_inteira + 1;
		inteira[y] = 50.0 ;
		total = total + inteira[y];
		break;

	case 2:
		qtde_meia = qtde_meia + 1;
		meia[y] = 25.0 ; 
		total = total + meia[y];
		break;
}
        

	
}
//Dados de saída, contendo as informações solicitadas
printf("\nO Filme: %s\nConteve na sessao %d Mulheres e %d Homens\n",filme[i],feminino, masculino);
printf("Criancas de [3 a 13]: %d\nAdolescentes de [14 a 17]: %d\nAdultos de [18 a 64]: %d\nIdosos de [65 a 100]: %d\n", crianca, adolescente, adulto, idoso);
printf("Homens maiores de 18 anos: %d\nMulheres maiores de 18 anos: %d\n",mascMaior, femiMaior);
printf("\nValor total arrecadado na sessao: %2.f R$\n", total);
//Comparação de vendas entre inteiras e meias, caso a quantidade de inteiras vender mais que a de meias e vice-versa, um printf será lançado.	
	if (qtde_inteira > qtde_meia){
		printf("\nNesta sessao se teve mais vendas de entradas inteiras! ");
}
	else{
		printf("Nesta sessao se teve mais vendas de meias!");
}


}
    
  
    

}
