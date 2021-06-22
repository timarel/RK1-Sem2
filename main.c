#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Brackets validator!\n \n");
    FILE *input = fopen("input.txt", "r");

    char open_br_sym[3] = "({[";
    char validator[20];
    char expr_part[20];
    char expr[100] = "";

    int pos = 0;
    while(fscanf(input, "%s", expr_part)!=EOF) {
        strcat(expr, expr_part);
    }

    printf("Expression from input.txt: \n %s \n \n", expr);

    for(int i = 0; i < strlen(expr); i++) {
        switch(expr[i]) {
            case '(' :
                validator[pos] = '(';
                pos++;
                break;
            case '{' :
                validator[pos] = '{';
                pos++;
                break;
            case '[' :
                validator[pos] = '[';
                pos++;
                break;
            case ')' :
                if(validator[pos-1]!='('){
                    printf("Expression invalid on #%i position! \n", i+1);
                    return 0;
                }
                else {
                    validator[pos-1] = "";
                    pos--;
                    break;
                }
            case '}' :
                if(validator[pos-1]!='{'){
                    printf("Expression invalid on #%i position! \n", i+1);
                    return 0;
                }
                else {
                    validator[pos-1] = "";
                    pos--;
                    break;
                }
            case ']' :
                if(validator[pos-1]!='['){
                    printf("Expression invalid on #%i position! \n", i+1);
                    return 0;
                }
                else {
                    validator[pos-1] = "";
                    pos--;
                    break;
                }
        }
    }

    printf("Success! Expression valid.");

    return 0;
}
