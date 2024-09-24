#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;

enum Token_value{//预定义
    NAME,    NUMBER,    END,
    PLUS='+',   MINUS='-',MUL='*',  DIV='/',
    PRINT=';',  ASSIGN='=', LP='(',  RP=')'
};
Token_value curr_tok =PRINT;

double term(bool b);//预定义

double prim(bool b);//同上

Token_value get_token();//同上

double error(const string&s);//
double expr(bool get){//加减的情况
    double left=term(get);
    for(;;){
        switch(curr_tok){
            case PLUS://加法
                left+=term(true);//先乘除后加减
                break;
            case MINUS://减法
                left-=term(true);
                break;
            default://返回值
                return left;

        }
    }
}


double term (bool get){//乘除的情况
    double left = prim (get);
    for(;;){
        switch(curr_tok){
            case MUL:
                left*=prim(true);//先判别括号再乘除
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
double number_value;
string string_value;
map<string,double>table;//建立键值
double prim(bool get){//判别括号、数字
    if(get)get_token();

    switch(curr_tok){
        case NUMBER://数字情况直接继续输入值
        {
            double v= number_value;
            get_token();//调用输入函数
            return v;

        }
        case NAME:
        {
            double& v=table[string_value];
            if(get_token()==ASSIGN) v=expr(true);//如果是等于号则返回运算值
            return v;

        }
        case MINUS:
            return  -prim(true);
        case LP:
        {
            double e = expr(true);
            if(curr_tok!=RP) return error(")exected");//如果没有右括号则返回错误
            get_token();
            return e;
        }
        default:
            return error("primary expected");//如果不是基本运算符号则返回错误
    }
}


Token_value get_token(){//输入函数
    char ch=0;
    cin>>ch;
    switch(ch){
        case '@'://终止
            return curr_tok=END;//返回终止
        case';':
        case'*':
        case'/':
        case'+':
        case'-':
        case'(':
        case')':
        case'='://上述判断是否是运算符
        return curr_tok=Token_value(ch);//将当前输入的操作运算符号赋给

        break;
        case'0':case'1':case'2':case'3':case'4':case'5':
        case'6':case'7':case'8':case'9':case'.'://判断是否是数字或者小数点
            cin.putback(ch);//记录输进的数字
            cin>>number_value;//输进值
            return curr_tok=NUMBER;//赋值
        default:
            if(isalpha(ch)){//否则判断是否是字母
                cin.putback(ch);//是则将输入的字符串赋一个新的定义的值
                cin>>string_value;
                return curr_tok=NAME;
            }
            error("bad token");//否则是非法输入
            return  curr_tok=PRINT;

    }
}
int no_of_errors;//定义错误个数
double error(const string&s){
    no_of_errors++;
    cerr<<"error:"<<s<<'\n';
    return 1;//有错误直接返回1
}
int main(){//主函数
    while(cin){
        get_token();
        if(curr_tok==END) break;//如果是end则直接跳出循环程序结束
        if(curr_tok==PRINT) continue;
        cout<<expr(false)<<'\n';
    }
    return no_of_errors;//返回错误个数
}
