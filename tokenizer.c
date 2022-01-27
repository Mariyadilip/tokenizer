#include <stdio.h>
#include <stdbool.h>

typedef char* Symbol;

const  Symbol  
           Plus                    = "SymbolPlus",
           Minus                   = "SymbolMinus",
           Multiply                = "SymbolMultiply",
           DivideTok               = "SymbolDivideTok",
           Path                    = "SymbolPath",
           Modulo                  = "SymbolModulo",
           Comma                   = "SymbolComma",
           LT                      = "SymbolLT",
           LTE                     = "SymbolLTE",
           GT                      = "SymbolGT",
           GTE                     = "SymbolGTE",
           LCurly                  = "SymbolLCurly",
           RCurly                  = "SymbolRCurly",
           LSquare                 = "SymbolLSquare",
           RSquare                 = "SymbolRSquare",
           LParan                  = "SymbolLParan",
           RParan                  = "SymbolRParan",
           MacroExpander           = "SymbolMacroExpander",
           NotEq                   = "SymbolNotEq",
           ErrorPascalCase         = "SymbolErrorPascalCase",
           ErrorLowerCase          = "SymbolErrorLowerCase",
           Newline                 = "SymbolNewline",
           TimePascalCase          = "SymbolTimePascalCase",
           TimeLowerCase           = "SymbolTimeLowerCase",
           DotDotDot               = "SymbolDotDotDot",
           DotDot                  = "SymbolDotDot",
           Dot                     = "SymbolDot",
           ColonEqual              = "SymbolColonEqual",
           Colon                   = "SymbolColon",
           Indent                  = "SymbolIndent",
           Dedent                  = "SymbolDedent",
           PrivateErrorPascalCase  = "SymbolPrivateErrorPascalCase",
           PrivateErrorLowerCase   = "SymbolPrivateErrorLowerCase",
           PrivateTimePascalCase   = "SymbolPrivateTimePascalCase",
           PrivateTimeLowerCase    = "SymbolPrivateTimeLowerCase",
           PrivatePascalCase       = "SymbolPrivatePascalCase",
           PrivateLowerCase        = "SymbolPrivateLowerCase",
           Underscore              = "SymbolUnderscore",
           PrivateEventPascalCase  = "SymbolPrivateEventPascalCase",
           EventPascalCase         = "SymbolEventPascalCase",
           PrivateBoolPascalCase   = "SymbolPrivateBoolPascalCase",
           BoolPascalCase          = "SymbolBoolPascalCase",
           PrivateEventLowerCase   = "SymbolPrivateEventLowerCase",
           EventLowerCase          = "SymbolEventLowerCase",
           PrivateBoolLowerCase    = "SymbolPrivateBoolLowerCase",
           BoolLowerCase           = "SymbolBoolLowerCase",
           NumberTok               = "SymbolNumberTok",
           StringTok               = "SymbolStringTok",
           PascalCase              = "SymbolPascalCase",
           LowerCase               = "SymbolLowerCase",
           LogicalAnd              = "SymbolLogicalAnd",
           LogicalOr               = "SymbolLogicalOr",
           TypeAlgebraAnd          = "SymbolTypeAlgebraAnd",
           TypeAlgebraOr           = "SymbolTypeAlgebraOr",
           TypeAlgebraAndNot       = "SymbolTypeAlgebraAndNot",
           AtomicScalr             = "SymbolAtomicScalr",
           Arrow                   = "SymbolArrow",
           EOF_                    = "SymbolEOF",       //Changed EOF to EOF_
           EqEq                    = "SymbolEqEq",
           LowerCaseWord           = "SymbolLowerCaseWord";


typedef  struct {
    char* err_str;     
    char* display_str; 
    int line_number; 
    int start;      
    int end ;        

    bool has_err_str ;    
    bool has_start ;     
    bool has_end ;        
    bool has_line_number;
    bool has_display_str; 
} Error;

char *itoa(int);

void main(){

}

char* String(Error* in){

  char *errStrStr = "None";
    if (in->has_err_str) {
        errStrStr = in->err_str;
    }
    char *startStr = "None";
    if (in->has_start) {
        startStr = itoa(in->start);
    }
    char *endStr = "None";
    if (in->has_end) {
        endStr = itoa(in->end);
    }
    char *lineNumberStr = "None";
    if (in->has_line_number) {
        lineNumberStr = itoa(in->line_number);
    }
    char *displayStrStr = "None";
    if (in->has_display_str) {
        displayStrStr = in->display_str;
    }
    char *c1 = "Error(err_str: ";
    char *c2 = errStrStr;
    c1 = concat(c1, c2);
    c1 = concat(c1, ", start: ");
    c1 = concat(c1, startStr);
    c1 = concat(c1, ", end: ");
    c1 = concat(c1, endStr);
    c1 = concat(c1, ", line_number: ");
    c1 = concat(c1, lineNumberStr);
    c1 = concat(c1, ", display_str: ");
    c1 = concat(c1, displayStrStr);
    c1 = concat(c1, ")");
    return c1;
}

char *itoa(int number){
    char* result = (char*)malloc(sizeof(char));
    int len = 0, cap = 0;
    if(number == 0)return "0";
    if(number < 0){
        result[0] = '-';
        result = (char*)realloc(result, sizeof(char)*2);
        number *= -1;
        len++;
    }
    while(number > 0){
       result[len] = number % 10 + '0';
       len++;
       if(len >= cap){
        cap = len * 2;
        result = (char*)realloc(result, sizeof(char)*cap);
       }
      number /= 10;
    }
    for(int i=(result[0] == '-' ? 1 : 0), j = len - 1 ; i < j ; i++,j--){
        char c = result[i];
        result[i] = result[j];
        result[j] = c;
    }
    result[len] = '\0';
    return result;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator   
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}