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
    char *copy;
    copy=strdup(str);
    if(strstr(copy," ( ")==NULL && strstr(copy," ) ")==NULL){
        return str;
    }
    

    //take it's reverse
    reverseFull=strrev(str);


    //create reverse copy string
    reverseCopy = (char *)malloc(strlen(str) + 1);
    strcpy(reverseCopy,reverseFull);

    //string after paranthesis
    /*while((token=strsep(&reverseCopy," ")) !=NULL){
        if(strcmp(token," ( ")==0){

        }
    }*/

    while((token=strsep(&reverseCopy," "))!=NULL){
        if(strcmp(token,"(")==0){
            beforeParantReverse=reverseCopy;
            break;
        }
        strcat(afterParantReverse,token);
    }
    char space[256]=" ";
    afterParant=strrev(afterParantReverse); //include expression
    strcat(space,afterParant);
    afterParant=space;
    printf("%s","0\n");

    beforeParant=strcat(strrev(beforeParantReverse)," ");
    //create string after paranthesis
    innerExpression=remove_spaces(strtok(afterParant, ")"));
    afterParantModified=strtok(NULL,"");


    //if there is no paranthesis send expression to expression function else paste it
    if(strstr(innerExpression," ( ")==NULL){
        innerExpression=parseParanthesis(innerExpression);
    }
    //concatenate string after changing expression with old value


    //printf(" ");
    strcat(beforeParant,"(");
    result=strcat(beforeParant,innerExpression);
    strcat(result,")");
    
    if(afterParantModified!=NULL){
        strcat(result," ");
        strcat(result,afterParantModified);
    }
    return result;
    //if there is no paranthesis send expression to expression function else paste it
    copy=strdup(result);
    while((token=strsep(&copy," "))!=NULL){
        if(strcmp(token,"(")== 0 ||strcmp(token,")")==0){
           return parseParanthesis(result);
        }
    }
    return str;
   
}




int main(){
    
    char str[]="sqrt ( tr ( y - x ) * (y-x) )";
    printf("%s\n",parseParanthesis(str));
    
    //printf("%s",remove_spaces(" y - x "));
    return (0);
}