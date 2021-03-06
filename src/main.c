/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2020-01                         *
 *                                                                                *
 * Copyright (C) 2020                                                             *
 *                                                                                *
 * main.c: Arquivo principal do programa bank                                     *
 *                                                                                *
 * bank é um caixa eletronico escrito em C que faz cadastro e listagem de contas, *
 * cadastro e listagem de movimentações de saque e de deposito.                   *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Este programa é software livre; você pode redistribuí-lo e/ou modificá-lo      *
 * sob os termos da GNU General Public License conforme publicada pela Free       *
 * Software Foundation; quer a versão 2 da licença, ou (conforme você escolha)    *
 * qualquer versão posterior.                                                     *
 *                                                                                *
 * Este programa é distribuído com a esperança de que seja útil, mas SEM          *
 * QUALQUER GARANTIA; mesmo sem a garantia implícita de MERCANTIBILIDADE OU       *
 * ADEQUAÇÃO A UM DETERMINADO PROPÓSITO. Para mais detalhes, veja a               *
 * GNU General Public License.                                                    *
 *                                                                                *
 * Você deve ter recebido uma cópia da GNU General Public License juntamente      *
 * com este programa; caso contrário, veja <https://www.gnu.org/licenses/>        *
 *                                                                                *
 * Data de inicio: 29/06/2020                                                     *
 * Data da última modificação: 11/02/2021                                         *
 **********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <fatec/fatec.h>
#include "../include/bank.h"
#include "../include/sl.h"

int main(int argc, char **argv){
    setlocale(LC_ALL, "");
    if(argc == 1){
        menu();
    }
    else if(argc == 2){
        if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
            puts(VERSION);
            puts(HELP);
        }
        else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")){
            puts(VERSION);
        }
        else if(!strcmp(argv[1], "-dev") || !strcmp(argv[1], "--developers")){
            developers(); // Mostra os desenvolvedores do programa
        }
        else if(!strcmp(argv[1], "--license")){
            cat(LICENSE); // Mostra a licença do software
        }
        else if(!strcmp(argv[1], "--train")){ // This is top secret
            train();
        }
        else{
            fprintf(stderr, "Erro: argumento inválido!\n");
            return 1;
        }
    }
    else{
        fprintf(stderr, "Erro: Você digitou mais de um argumento!\n");
        return 1;
    }
    return 0;
}

