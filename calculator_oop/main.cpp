#include <iostream>
#include<map>
#include<string>
#include<cctype>
using namespace std;
double no_of_errors;
map<string,double>table;

//具体实现细节注释在过程设计上体现了
//在此代码中不在重复
namespace Lexer{//将基本数据封装在Lexer的空间中
    enum Token_value{
        NAME,NUMBER,
        END,
        PLUS='+',MINUS='-',
        MUL='*',DIV='/',
        PRINT=';',ASSIGN='=',
        LP='(',RP=')'
    };
    Token_value curr_tok;
    double number_value;
    basic_string<char> string_value;


}
namespace Parser{//将处理方法封装再Parser的空间中
    double expr(bool);
    double prim(bool get);
    double term(bool get);
    double expr(bool get);
    Lexer::Token_value get_token();
    double error(const string&s){
        no_of_errors++;
        cerr<<"error:"<<s<<'\n';
        return 1;
    }
}
using namespace Lexer;
double Parser::term (bool get){//每次调用必须声明在Parser的空间中否则会报错
    double left = prim (get);
    for(;;){
        switch(Lexer::curr_tok){
            case MUL:
                left*=prim(true);
                break;
            case DIV:
                if(double d =prim(true)){
                    left/=d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;

        }
    }
}

double Parser::prim(bool get){//同上
    if(get)get_token();

    switch(curr_tok){
        case NUMBER:
        {
            double v= number_value;
            get_token();
            return v;

        }
        case NAME:
        {
            double& v=table [string_value];
            if(get_token()==ASSIGN) v=expr(true);
            return v;

        }
        case MINUS:
            return  -prim(true);
        case LP:
        {
            double e = expr(true);
            if(curr_tok!=RP) return error(")exected");
            get_token();
            return e;
        }
        default:
            return error("primary expected");
    }
}

double Parser::expr(bool get){//鍔犲噺
    double left=term(get);
    for(;;){
        switch(curr_tok){
            case PLUS:
                left+=term(true);
                break;
            case MINUS:
                left-=term(true);
                break;
            default:
                return left;

        }
    }
}

Token_value Parser::get_token(){//杈撳叆
    char ch=0;
    cin>>ch;
    switch(ch){
        case '@':
            return curr_tok=END;
        case';':
        case'*':
        case'/':
        case'+':
        case'-':
        case'(':
        case')':
        case'=':
            return curr_tok=Token_value(ch);
            break;
        case'0':case'1':case'2':case'3':case'4':case'5':
        case'6':case'7':case'8':case'9':case'.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch)){
                cin.putback(ch);
                cin>>string_value;
                return curr_tok=NAME;
            }
            Parser::error("bad token");
            return  curr_tok=PRINT;

    }
}

int main(){
    table["pi"]=3.1415926535897932385;
    table["e"]=2.7182818284590452354;

    while(cin){
        Parser::get_token();
        if(curr_tok==END) break;
        if(curr_tok==PRINT) continue;
        cout<<Parser::expr(false)<<'\n';
    }
    return no_of_errors;
}