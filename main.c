#include "main.h"

<<<<<<< HEAD:main.c
void assignment_statement(char * statement){
    char * token;
    int token_number=1;
    while((token=strsep(&statement," "))!=NULL){
        if(token_number==1){
            if(strcmp(token,"=")!=0){
                exit_program();
            }
            fprintf(pOutputFile,"%s",token);
        }else{
            fprintf(pOutputFile,"%s",expression_parser(statement));
            fprintf(pOutputFile,"%s",";\n");      
            break;
        }
        token_number++;
    }
        

}

void print_line(char * line){
    fprintf(pOutputFile,"\t%s","printScalar");
    char * token;
    int token_number=1;
    while((token=strsep(&line," "))!=NULL){
        if(token_number==1){
            if(strcmp(token,"(")!=0){
                exit_program();
            }else{
                fprintf(pOutputFile,"%s","(");
            }
        }else if(token_number==2){
            fprintf(pOutputFile,"%s",expression_parser(token));

        }else if(token_number==3) {
            if(strcmp(token,")")!=0){
                exit_program();
            }else{
                fprintf(pOutputFile,"%s",");\n");
            }
        }else{
            exit_program();
        }
        token_number++;
        token = strtok(NULL, " ");

    }
    if(token_number!=4){
        exit_program();
    }
}


int main(){
=======
int main(int argc,char *argv[]){

>>>>>>> main:main/main.c
    char line[256];
    pOutputFile=fopen("file.c","w");
    print_usual();
    /*if (argc != 2) {
        printf("Give filename as command line argument\n") ;
        pInputFile = fopen("trial.txt", "r");
        return 1;
    }*/
    pInputFile = fopen("trial.txt", "r");
    if(pInputFile == NULL) {
        printf("Cannot open %s\n","trial.txt");
        return 1;
    }

    char * token;
    int is_declaration=1;
    int is_infor=0;
<<<<<<< HEAD:main.c
    scalarNumber=0;
    vectorNumber=0;
    matrixNumber=0;

=======
    
    //reads input line by line from txt file 
>>>>>>> main:main/main.c
    while( fgets(line,256,pInputFile) != NULL ) {
        lineNumber++;
        // checks if line starts with '#' or line is an empty line, if so continues with next line
        if(line[0]=='#' || line[0]== '\n'){
            continue;
        }
        int cur=0;
        char extended[512];
        
        /* adds whitespace before and after characters which is not alpha_numeric. So we can reach token by using strtok and strsep 
            ex: matrix A[4,4]==> matrix A [ 4 , 4 ]
        */

        for(int i =0; i<strlen(line);i++){
            char as = line[i];
            char *ps = &as;
            if (isspace(as)) {
                extended[cur] = ' ';
                cur++;
                continue;
            }
            if(!is_alphanumeric(ps)){
                extended[cur]=' ';
                cur++;
                extended[cur]=as;
                cur++;
                extended[cur]=' ';
                cur++;
                continue;
                
            }
            extended[cur]=line[i];
            cur++;
        }
        extended[cur]='\0';

        char * pextended = strdup(trim(extended));
        char * pextendeds = strdup(trim(extended));

<<<<<<< HEAD:main.c
        // declaration while
        while ( is_declaration==1 && (token=strsep(&pextended," "))!=NULL ){
=======
        // declaration while. Reads first token of each line and decides type then sends line to the corresponding function.
        while ( is_declaratiion==1 && (token=strsep(&pextended," "))!=NULL ){
>>>>>>> main:main/main.c
            if(strcmp(token,"")==0){
                continue;
            }
            if (strcmp("scalar",token)==0){
                scalar_line(pextended);
                break;
            }else if(strcmp("vector",token)==0){
                vector_line(pextended);
                break;
            }else if(strcmp("matrix",token)==0){
                matrix_line(pextended);
                break;
            }else{
                is_declaration=0;
            }
        }

<<<<<<< HEAD:main.c
        //statement while
        while((token=strsep(&pextendeds," "))!=NULL && is_declaration==0){
=======
        //statement while. Reads first token of each line and decides type of the statement then sends line to the corresponding function.
        while((token=strsep(&pextendeds," "))!=NULL && is_declaratiion==0){
>>>>>>> main:main/main.c
            if(strcmp(token,"")==0){
                continue;
            }
            // if first token is "}", it should be end of the for loop.Otherwise gives error(exit_program).
            if (strcmp(token,"}")==0){
                if(is_infor==1){
                    is_infor=0;
                    break;
                }else{
                    exit_program(lineNumber);
                }
            }

            else if(is_infor==1){
                //print to other file
                break;
            }
            else if(strcmp(token,"for")==0){
                is_infor=1;
                //for function;
                if(strstr(pextendeds,",")!=NULL){
                    parseDoubleFor(pextendeds);
                }
                else{
                    parseSingleFor(pextendeds);
                }
                break;

            }else if(strcmp(token,"print")==0){
                print_line(pextendeds);
                break;
            }else if(strcmp(token,"printsep")==0){
                printsep();
                break;
            }else{
<<<<<<< HEAD:main.c
                enum types type= isDeclared(token);
                if(type==empty){
                    exit_program();
                }
                fprintf(pOutputFile,"\t%s",token);
                assignment_statement(trim(pextendeds));
=======
                //if variable is valid
                char *variable_name;
                variable_name=token;
                assignment_statement(trim(pextendeds),variable_name);
>>>>>>> main:main/main.c
                break;
            }

        }
        memset(extended, 0, 256);
    }
    printCloseBracket();
    fclose(pOutputFile);
    fclose(pInputFile);
    return(0);
}