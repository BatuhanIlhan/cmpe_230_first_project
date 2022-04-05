#include "main.h"
char* strrev (char *str) {
    if (!str) { return NULL; }

    int len = strnlen(str, 100);
    char*  reverse = malloc( sizeof(char) * len );

    int i;
    for (i = 0; i < len; i++) {
        reverse[i] = str[len - (i+1)];
    }

    reverse[i] = 0;

    return reverse;
}

char *deleteParanthesis(char *str){
    
    //delete last parant.
    withoutLastParanthesis=strtok(str,")");

    //take it's reverse
    reverseStr=strrev(withoutLastParanthesis);

    //delete open paranth.
    reverse= strtok(reverseStr,"(");

    return strrev(reverse);
}

char *remove_spaces(char *str)
{   
    char *t;
    int i=0;
    for (t = str; *t != '\0'; t++) {
        //res[i-j] = t;
        if( *t == ' '){
            t++;
        }
        if(*t == '\0'){
            break;
        }
        strncat(res,t,1);  
        i++;
    }
    return res;
}

//parse all expression without paranthesis and send them to expression handler function
char *parseParanthesis(char *str){

    char *token;
    char *prev="";
    char *copy;
    char *tempCopy;
    char *innerTemp;
    copy=strdup(str);
    //if there is no paranthesis send expression to expression function else paste it
    if(strstr(copy,"(")==NULL || strstr(copy,")")==NULL){
        return str;
    }

    int is_exp=0;
    while((token=strsep(&copy," "))!=NULL){
        if(strcmp(token,"(")==0){

            if(prev==NULL || prev==""){
                prev=strdup(token);
                continue;
            }

            else if(strcmp(prev,"sqrt")==0||strcmp(prev,"tr")==0||strcmp(prev,"choose")==0){
                tempCopy=strdup(copy);

                if((token=strsep(&copy," "))!=NULL){
                    //printf("%s\n",token);
                    if(strcmp((token=strsep(&copy," ")),")")!=0){
                        is_exp=0;
                    }
                }
                else{
                    is_exp=0;
                }
                copy=strdup(tempCopy);
            }

            else{
                is_exp=0;
            }

        }

        prev=strdup(token);
    }

    if(is_exp==1){
        return "3";
    }
    //take it's reverse
    reverseFull=strrev(str);
    //create reverse copy string
    char *reverseCopy=strndup(reverseFull,strlen(reverseFull));
    //merge all
    char *tempToken;
    char *firstPrev;
    char *secondPrev;
    while((token=strsep(&reverseCopy," "))!=NULL){
        if(strcmp(token,"(")==0){
            
            if(reverseCopy==NULL || reverseCopy==""){
                beforeParantReverse="";
                break;
            }
            
            tempCopy=strdup(reverseCopy);
            tempToken=strrev(strsep(&reverseCopy," "));

            if(tempToken!=NULL && tempToken!="" && (strcmp(tempToken,"tr")==0 || strcmp(tempToken,"choose")==0 || strcmp(tempToken,"sqrt")==0)){
                if(strcmp(secondPrev,")")==0){
                    reverseCopy=strdup(tempCopy);
                }
                else{
                    beforeParantReverse=strdup(tempCopy);
                    break;
                }

            }
            else{
                beforeParantReverse=strdup(tempCopy);
                break;
            }
        }

        strcat(afterParantReverse," ");
        strcat(afterParantReverse,token);
        
        if(firstPrev!=NULL){
            secondPrev=strdup(firstPrev);
        }
        if(token!=NULL){
            firstPrev=strdup(token);
        }
    }
    //printf("d");
    strcpy(afterParant,strrev(afterParantReverse)); //include expression
    strcpy(beforeParant,strrev(beforeParantReverse));

    token=strrev(strtok(beforeParantReverse," "));
    int is_func=0;
    if(token!= NULL && (strcmp(token,"tr")==0 || strcmp(token,"sqrt")==0 || strcmp(token,"choose")==0)){
        is_func=1;
    }
    
    char *temp=strdup(afterParant);
    int stack_num=1;
    char *new;
    while((new=strsep(&temp," "))!=NULL){
        if(strcmp(new,")")==0){
            stack_num--;
            if(stack_num==0){
                break;
            }
        }
        else if(strcmp(new,"(")==0){
            stack_num++;
        }
        strcat(innerExpression," ");
        strcat(innerExpression,new);
    }
    //if there is no paranthesis send expression to expression function else paste it
    /*char *tempInnerExpression;
    if(strstr(innerExpression," ( ")==NULL){
        return innerExpression;
        tempInnerExpression=expression_parser(innerExpression);
    }*/
    //concatenate string after changing expression with old value
    strcat(beforeParant," ");
    /*if(is_func==1){
        strcat(beforeParant," ");
    }*/
    strcat(beforeParant,"asd");
    /*if(is_func==1){
        strcat(beforeParant," ");
    }*/
    strcat(beforeParant," ");


    if(temp!=NULL){
        strcat(beforeParant,temp);
    }

    return beforeParant;
    //if there is no paranthesis send expression to expression function else paste it

    copy=strdup(beforeParant);

    while((token=strsep(&copy," "))!=NULL){
        if(strcmp(token,"(")== 0 ||strcmp(token,")")==0){
            return parseParanthesis(beforeParant);
        }
    }

    //return expression_parser(beforeParant);
   
}

int main(){
    
    char str[]="( A * B )  * B";
    printf("\nreturn value:  %s\n",parseParanthesis(str));
    
    //printf("%s",remove_spaces(" y - x "));
    return (0);
}