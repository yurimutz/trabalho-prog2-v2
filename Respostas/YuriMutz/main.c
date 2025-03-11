#include "bancoTecnico.h"
#include "tecnico.h"
#include "outros.h"
#include "manutencao.h"
#include "software.h"
#include "ticket.h"
#include "fila.h"
#include "bancoUsuario.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    bancoTec *bancoTec = criaBancoTecnico();

    bancoUser *bancoUser = criabancoUser();

    Fila *filaTicket = criaFila();

    int flag = 0;

    char mode;

    while(1){

        if(flag == 1){

            break;

        }

        scanf("%c", &mode);
        getchar();

        switch (mode)
        {
        case 'T':
            
            Tecnico *tecAux = lerTecnico(); 
            scanf("%*[\n]");

            if(!verificaTecCadastrado(bancoTec, getCpfTecnico(tecAux))){

                adicionaTecBanco(bancoTec, tecAux); 

            } else {

                desalocaTecnico(tecAux);

                tecAux = NULL;

            }     

            break;

        case 'U':
            
            Usuario *userAux = lerUsuario();
            scanf("%*[\n]");

            if(!verificaUserCadastrado(bancoUser, getCPFUser(userAux))){

                adicionaUserBanco(bancoUser, userAux); 

            } else {

                desalocaUsuario(userAux);

            }     

            break;

        case 'E':
            
            char acao[50];
            scanf("%[^\n]", acao);
            scanf("%*[\n]");

            if(strcmp(acao, "NOTIFICA") == 0){

                printf("----- FILA DE TICKETS -----\n");
                notificaFila(filaTicket); 
                printf("---------------------------\n");
                printf("\n");

            } else if(strcmp(acao, "USUARIOS") == 0){

                printf("----- BANCO DE USUARIOS -----\n");
                notificaBancoUser(bancoUser);
                printf("----------------------------\n");
                printf("\n");

            } else if(strcmp(acao, "TECNICOS") == 0){

                printf("----- BANCO DE TECNICOS -----\n");
                notificaBancoTecnico(bancoTec);
                printf("----------------------------\n");
                printf("\n");

            } else if(strcmp(acao, "RANKING TECNICOS") == 0){

                printf("\n----- RANKING DE TECNICOS -----\n");
                notificaRankingTec(bancoTec);
                printf("-------------------------------\n");
                printf("\n");

            } else if(strcmp(acao, "RANKING USUARIOS") == 0){

                printf("\n----- RANKING DE USUARIOS -----\n");
                notificaRankingUser(bancoUser);
                printf("-------------------------------\n");
                printf("\n");

            } else if(strcmp(acao, "RELATORIO") == 0){
                
                printf("----- RELATORIO GERAL -----\n");
                printf("- Qtd tickets: %d\n", getQtdTicketsNaFila(filaTicket));
                printf("- Qtd tickets (A): %d\n", getQtdTicketsPorStatusNaFila(filaTicket, 'A'));
                printf("- Qtd tickets (F): %d\n", getQtdTicketsPorStatusNaFila(filaTicket, 'F'));
                printf("- Qtd usuarios: %d\n", getQtdUsuariosNoBanco(bancoUser));
                printf("- Md idade usuarios: %d\n", getMediaIdadeUsuarios(bancoUser));
                printf("- Qtd tecnicos: %d\n", getQtdTecBanco(bancoTec));
                printf("- Md idade tecnicos: %d\n", getMediaIdadeTec(bancoTec));
                printf("- Md trabalho tecnicos: %d\n", getMediaTempTrabBanco(bancoTec));
                printf("---------------------------\n");
                printf("\n");

            }else if(strcmp(acao, "DISTRIBUI") == 0){

                for(int i = 0; i < getQtdTicketsNaFila(filaTicket); i++){

                    if(getStatusTicket(getTicketNaFila(filaTicket, i)) == 'A'){

                        if(getTipoTicket(getTicketNaFila(filaTicket, i)) == 'S'){

                            for(int j = 0; j < getQtdTecBanco(bancoTec); j++){

                                if(strcmp(getAreaTecnico(retornaTecBanco(bancoTec, j)), "TI") == 0){

                                    if(getTempoDispTec(retornaTecBanco(bancoTec, j)) >= getTempoEstimadoTicket(getTicketNaFila(filaTicket, i))){

                                        Ticket *tkAux = getTicketNaFila(filaTicket, i);

                                        finalizaTicket(tkAux);

                                        int temp = getTempoEstimadoTicket(tkAux);

                                        atualizaTemposTec(retornaTecBanco(bancoTec, j), getTempoEstimadoTicket(tkAux));
                                        
                                        atualizaSequenciaTec(bancoTec, j);

                                        break;

                                    }
                                
                                }

                            }

                        } else {                

                            for(int j = 0; j < getQtdTecBanco(bancoTec); j++){

                                if(strcmp(getAreaTecnico(retornaTecBanco(bancoTec, j)), "TI") != 0){

                                    if(getTempoDispTec(retornaTecBanco(bancoTec, j)) >= getTempoEstimadoTicket(getTicketNaFila(filaTicket, i))){

                                        finalizaTicket(getTicketNaFila(filaTicket, i));

                                        atualizaTemposTec(retornaTecBanco(bancoTec, j), getTempoEstimadoTicket(getTicketNaFila(filaTicket, i)));

                                        atualizaSequenciaTec(bancoTec, j);

                                        break;

                                    }

                                }

                            }

                        }

                    }

                }

            }

            break;

        case 'A':
            
            char cpfAux[20];
            scanf("%14[^\n]", cpfAux);
            getchar();

            char tipoTick[50];
            scanf("%50[^\n]", tipoTick);
            getchar();

            if(verificaUserCadastrado(bancoUser, cpfAux)){

                if(strcmp(tipoTick, "OUTROS") == 0){


                    Outros *outroAux = lerOutros();
                    scanf("%*[\n]");

                    insereTicketFila(filaTicket, cpfAux, outroAux, getTempoEstimadoOutros,
                        getTipoOutros, notificaOutros, desalocaOutros);   

                } else if(strcmp(tipoTick, "SOFTWARE") == 0){

                    Software *soft = lerSoftware();
                    scanf("%*[\n]");

                    setTempoEstimadoSoftware(soft);

                    insereTicketFila(filaTicket, cpfAux, soft, getTempoEstimadoSoftware,
                        getTipoSoftware, notificaSoftware, desalocaSoftware);

                } else {

                    Manutencao *man = lerManutencao();
                    scanf("%*[\n]");

                    setTempoEstimadoManutencao(man, retornaSetorDoUsuarioBanco(bancoUser, cpfAux));

                    insereTicketFila(filaTicket, cpfAux, man, getTempoEstimadoManutencao,
                        getTipoManutencao, notificaManutencao, desalocaManutencao);

                }

                atualizaNumTickets(retornaUserBanco(bancoUser, cpfAux));

            } else {

                if(strcmp(tipoTick, "OUTROS") == 0){


                    Outros *outroAux = lerOutros();
                    scanf("%*[\n]");
 
                    desalocaOutros(outroAux); 

                } else if(strcmp(tipoTick, "SOFTWARE") == 0){

                    Software *soft = lerSoftware();
                    scanf("%*[\n]");

                    desalocaSoftware(soft);

                } else {

                    Manutencao *man = lerManutencao();
                    scanf("%*[\n]");

                    desalocaManutencao(man);

                }

            }

            break;

        case 'F':

            flag = 1;

            break;
        
        default:
            break;
        }

    }

    desalocaFila(filaTicket);

    desalocaBancoUser(bancoUser);

    desalocaBancoTecnico(bancoTec);

    return 0;

}