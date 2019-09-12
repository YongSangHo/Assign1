//
//  main.c
//  assign_Test22
//
//  Created by 용상호 on 12/09/2019.
//  Copyright © 2019 용상호. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_NR_TOKENS 32    /* Maximum number of tokens in a command */
#define MAX_TOKEN_LEN 64    /* Maximum length of single token */
#define MAX_COMMAND    256        /* Maximum length of command string */


static int parse_command(char *command, int *nr_tokens, char *tokens[])
{
    /* TODO
     * Followings are example code. You should delete them and implement
     * your own code here
     */
    int i =0;
    int j =0;
    int k =0;
    int a =0;
    int y = 0;
    int t = 0;
    char arr[32][64]={};
    char x = ' ';
    
    for(t=0;t<64;t++){
        if(command[t]=='\0' ){
            break;
        }
    }
    while(y<64){
        
        if(command[y] == '\0'){
            break;
        }
        
        if (command[i] != ' ' && command[i] != '\t'&& command[i]!='\0'&& command[i]!='\n') {
            a=i;
            for(k=0;k<64;k++){
                arr[j][k] = command[a];
                a++;
                if(command[a] == ' ' || command[a] == '\t'|| command[a] == '\0'||command[a] == '\n'){
                    arr[j][k+1] = '\0';
                    i=a;
                    //printf("%s\n",arr[j]);
                    tokens[j] = arr[j];
                    
                    j++;
                   
                    break;
                }
                else continue;
            }
            
            if(i == t){
                break;
            }
        }
        else{
            if(i == t){
                break;
            }
            i++;
        }
        y++;
    }
    
    *nr_tokens = j;
    tokens[j+1]= '\0';
    return 0;
}


/***********************************************************************
 * The main function of this program. SHOULD NOT CHANGE THE CODE BELOW
 */
int main(int argc, const char *argv[])
{
    char line[MAX_COMMAND] = { '\0' };
    FILE *input = stdin;
    
    if (argc == 2) {
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "No input file %s\n", argv[1]);
            return -EINVAL;
        }
    }
    
    
    
    while (fgets(line, sizeof(line), input)) {
        char *tokens[MAX_NR_TOKENS] = { NULL };
        int nr_tokens= 0;
        
        parse_command(line, &nr_tokens, tokens);
        
        fprintf(stderr, "nr_tokens = %d\n", nr_tokens);
        for (int i = 0; i < nr_tokens; i++) {
            fprintf(stderr, "tokens[%d] = %s\n", i, tokens[i]);
        }
        printf("\n");
    }
    
    if (input != stdin) fclose(input);
    
    
    
    return 0;
}
