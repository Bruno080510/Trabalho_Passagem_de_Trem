//Passagens_Trem_BrunoLeal_JoaoMedeiros

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    //VARIAVEIS FUNCIONÁRIO
    int i, numeroDoVagao;
    char nomeDaCompany[50], prefixoTrem[3], terminalPartida[3], terminalChegada[3];
    char horarioDePartida[6], horarioChegada[6];
    //VARIAVEIS USUÁRIO
    char opcaoUsuario, nomeUsuario[51], assentosNomes[20][51];
    int assentosDisponveis[20] = {0}, numeroAssento, flagLigado = 1;

    //TELA DO USUÁRIO NO MODO DO FUNCIONÁRIO
    system("color df");
    printf("-------CONFIGURAÇÃO FUNCIONÁRIO-------\n");
    printf("Digite o nome da empresa: ");
    scanf("%50[^\n]", nomeDaCompany);
    fflush(stdin);
    printf("Nome da empresa: %s\n", nomeDaCompany);

    printf("Digite o prefixo do trem: ");
    scanf("%3[^\n]", prefixoTrem);
    fflush(stdin);
    printf("Prefixo: %s\n", strupr(prefixoTrem));

    do{
    printf("Digite o numero do vagão: ");
    scanf("%3d",&numeroDoVagao);
    fflush(stdin);
    }while(numeroDoVagao < 0 || numeroDoVagao > 999 );

    printf("Numero do vagão: %03d\n", numeroDoVagao);

    printf("Digite o código de terminal de partida: ");
    scanf("%3[^\n]", terminalPartida);
    fflush(stdin);
    printf("%s\n", strupr(terminalPartida));

    printf("Digite o código de terminal de chegada: ");
    scanf("%3[^\n]", terminalChegada);
    fflush(stdin);
    printf("%s\n", strupr(terminalChegada));

    printf("Digite o horário de partida (escreva em hh:mm): ");
    scanf("%6[^\n]", horarioDePartida);
    fflush(stdin);
    printf("Digite o horário de chegada (escreva em hh:mm): ");
    scanf("%6[^\n]", horarioChegada);
    fflush(stdin);
    printf("\n\n");
    printf("O horário de partida será as %s, e o horário de chegada será as %s\n\n", horarioDePartida, horarioChegada);

    printf("MUDANDO PARA A TELA DO CLIENTE....\n");
    printf("\n");
    system("pause");
    system("cls");

    //TELA DO USUARIO NO MODO DO CLIENTE
    system("color b0");
    while (flagLigado)
    {
        system("cls");
        printf("Boa tarde....\n\n");
        printf("-----Selecione a opção que você gostaria de ver-----\n\n");
        printf("[A]Emissão de passagem\n [B]Exclusão de passagens\n [C]Consulta de ocpuação do trem\n [D]Encerrar\n\n");
        printf("Qual opção você gostaria de ver: ");
        scanf("%1c",&opcaoUsuario);
        fflush(stdin);
        //OPÇÃO DO MENU
        switch(opcaoUsuario)
        {
        //EMISSÃO DE PASSAGEM
        case 'a':
        case 'A':
            system("cls");
            system("color 3f");
            printf("Por favor, nos diga seu nome: ");
            fflush(stdin);
            scanf("%50[^\n]", nomeUsuario);
            system("cls");
            printf("Olá %s, temos esses assentos abaixo disponíveis no momento\n\n", nomeUsuario);
            for (i=0; i<20; i++)
            {
                printf("ASSENTO %02d: ", i+1);
                if (!assentosDisponveis[i])
                {
                    printf("LIVRE\n");
                }
                else
                {
                    printf("OCUPADO\n", nomeUsuario);
                }
            }

            printf("Qual assento você gostaria de ocupar: ");
            scanf("%d",&numeroAssento);
            if(numeroAssento<1 || numeroAssento > 20){
                printf("ASSENTO NÃO DISPONIVEL!\n\n");
                system("pause");
                break;
            }

            if (assentosDisponveis[numeroAssento - 1])
            {
                printf("ASSENTO JÁ OCUPADO!\n\n");
                system("pause");
                break;
            }

            assentosDisponveis[numeroAssento - 1] = 1;
            system("pause");
            break;
        //EXCLUSÃO DE PASSAGENS
        case 'b':
        case 'B':
            system("cls");
            system("color cf");
            printf("Olá %s, esses são os assentos que estão ocupados e desocupados...\n\n", nomeUsuario);

            for (i=0; i<20; i++)
            {
                printf("ASSENTO %02d: ", i+1);
                if (!assentosDisponveis[i])
                {
                    printf("LIVRE\n");
                }
                else
                {
                    printf("OCUPADO\n");
                }
            }

            printf("Qual assento você gostaria de desocupar: ");
            scanf("%d",&numeroAssento);

            if (!assentosDisponveis[numeroAssento - 1])
            {
                printf("ASSENTO NAO ESTA OCUPADO!\n\n");
                system("pause");
                break;
            }

            assentosDisponveis[numeroAssento - 1] = 0;
            system("pause");
            break;
        //CONSULTA DA OCUPAÇÃO DO TREM
        case 'c':
        case 'C':
             system("cls");
            system("color e0");
            printf("Esses são os assentos disponíveis e desocupados no momento\n\n");
            for (i=0; i<20; i++)
            {
                printf("ASSENTO %02d: ", i+1);
                if (!assentosDisponveis[i])
                {
                    printf("DISPONÍVEL\n");
                }
                else
                {
                    printf("OCUPADO\n", nomeUsuario);
                }
            }

            printf("\n\n");
            system("pause");

            break;
        //ENCERRAMENTO
        case 'd':
        case 'D': system("cls");
        system("color 4f");
            printf("Encerrando...\n\n\n");
        flagLigado = 0;
            break;
        }
    }

    return 0;
}
