#include <iostream>//c++ 输入输出流文件
#include<map>//映射头文件
#include <cstring>//对char字符串做操作的头文件
#include<string>//string类型头文件
#include<fstream>//输入输出流文件

using namespace std;
namespace data{//将基本数据封装在data中
    static map<string,int>goods;//商品的名称数量
    static map<string,double>price;//商品的价格
    static map<string,string>basic_information;//商品的基本信息描述
    static map<string,string>user;//用户id和密码
    static map<string,double>balance;//用户余额
    static map<string,int>shopping_cart;//用户购物车
    static map<string,double>discount;//折扣
    static map<string,string>user_discount;//用户所拥有的折扣券
    static string address=R"(D:\Ccode\Clion\shoppingsystem\shopping_cart.txt)";//储存购物车内容文件地址
    static string history_address=R"(D:\Ccode\Clion\shoppingsystem\shopping_history.txt)";//储存购买历史文件
    static double activity=1;//活动时的优惠
}
using namespace data;
static void init(){//预定义一些商品和测试用户
        goods["sony"]=5;
        price["sony"]=9998;
        basic_information["sony"]="a camera that is very good!!!";
        goods["sanzhisongshu"]=98;
        price["sanzhisongshu"]=53;
        basic_information["sanzhisongshu"]="a kind of snack that is very good!!!";
        discount["123456"]=0.88;
        user["test0001"]="123456";//id和密码
        user_discount["123456"]="test0001";
        user["test0002"]="654321";
        balance["test0001"]=10000;
        balance["test0002"]=20000;
};

void go_on(){//使用回车继续
    cout<<"press 'Enter' to continue"<<endl;
    getchar();
    getchar();
}

static int search(const string& a){//查找是否有a
    if(goods.find(a)==goods.end()){
        return 0;
    }
    else{
        return 1;
    }
}
class Operator{//管理员
private:
    const  char name[100]="administrator";//预定义管理员名称
    const char password[100]="password";//管理员密码
public:
    Operator(char id[],char pass[]);//构造函数，登录界面
    static int information_set();//设置商品的价格和描述
    static int add_goods();//增添商品的数量
    static int display();//展示商品信息
    static int display_user_info();//展示用户信息
    static int delete_goods();//删除商品
    static int delete_goods(const string& a);//删除商品的过载函数
    static int rename();//为商品重新命名
    static int set_discount();//设置一个折扣
    static int set_activity();//设置一个活动折扣
    static int set_discount_user();//将优惠券发给用户
};

int Operator::information_set() {//设置商品价格和描述
    cout<<"please input the name of the goods"<<endl;
    string a;
    cin>>a;
    if(goods.find(a)==goods.end()){
        cout<<"the goods is not existed";
        return 0;
    }
    cout<<"if you want to edit the price,input '1'"<<endl;
    cout<<"if you want to edit the description of the goods ,input '2'"<<endl;
    int n;
    cin>>n;
    if(n==1){
        cout<<"input the price :"<<endl;
        cin>>price[a];
        cout<<"set the price successfully "<<endl;
        return 1;
    }
    else if(n==2){
        cout<<"input new description:"<<endl;
        cin>>basic_information[a];
        cout<<"edit the description successfully"<<endl;
        return 2;
    }
    else{
        cout<<"error"<<endl;
        return 0;
    }
}

Operator::Operator(char *id, char *pass) {//构造函数，可以选择功能
    if(strcmp(id,this->name) == 0 && strcmp(pass,this->password)==0){
        cout<<"login successfully"<<endl;
        for(;;){//选择功能
            cout<<"**********************************************************************************************"<<endl;
            cout<<"choose what you want to do:"<<endl;
            cout<<"display the information of the goods:please input 'display'"<<"   rename goods:input 'rename'"<<endl;
            cout<<"add the amount of the goods,please input 'add'   ";
            cout<<"edit the information of the goods,please input 'edit'"<<endl;
            cout<<"show user information:'show'   "<<"delete things:'delete'"<<endl;
            cout<<"set a activity:input 'set_activity'"<<endl;
            cout<<"give discount to user:input 'give_user'"<<endl;
            cout<<"set discount number :input  'set_discount' ,exit the administration:please input 'exit"<<endl;
            cout<<"**********************************************************************************************"<<endl;
            cout<<"please input:"<<endl;
            string a;
            cin>>a;
            if(a=="display"){//展示所有商品
                Operator::display();
            }
            else if(a=="add"){//添加商品
                add_goods();
            }
            else if(a=="edit"){//编辑商品数量
                information_set();
            }
            else if(a=="exit"){//退出
                cout<<"exit successfully"<<endl;
                go_on();
                break;
            }
            else if(a=="show"){//展示用户信息
                display_user_info();
            }
            else if(a=="delete"){//删除商品
                delete_goods();
            }
            else if(a=="rename"){//更改商品名字
                rename();
            }
            else if(a=="set_discount"){//设置折扣
                set_discount();
            }
            else if(a=="set_activity"){//设置活动
                set_activity();
            }
            else if(a=="give_user"){//将优惠券给用户
                set_discount_user();
            }
            else{//非法输入
                cout<<"invalid token"<<endl;
                go_on();
            }
        }


    }
    else{//用户名或者密码错误
        cout<<"error"<<endl;
    }
}

int Operator::display() {//展示商品基本信息
    auto p=price.begin();
    auto in=basic_information.begin();
    for(auto it =goods.begin();it!=goods.end();it++,p++,in++){
        cout<<"the name and the price of the goods:"<<"  ||name: "<<it->first<<" ||"<<"  "<<"||amount: "<<it->second<<" ||"<<"  "<<"||price:"<<p->second<<"||"<<endl;
        cout<<"the description of the goods:"<<endl;
        cout<<in->first+": "<<in->second<<endl;
        cout<<"*******************************************************"<<endl<<endl;
    }
    go_on();
    return 0;
}

int Operator::add_goods() {//增添商品
    string a;
    cout<<"please input the name of the goods:"<<endl;
    cin>>a;
    cout<<"please input the added number:"<<endl;
    int num ;
    cin>>num;
    getchar();
    if(goods.find(a)==goods.end()){//如果商品不存在，先初始化
        goods[a]=0;
        goods[a]+=num;
        cout<<"input the price :"<<endl;
        cin>>price[a];
        getchar();
        cout<<"set the price successfully "<<endl;
        cout<<"input new description:"<<endl;
        cin>>basic_information[a];
        getchar();
        cout<<"edit the description successfully"<<endl;
        cout<<"add successfully"<<endl;
    }
    else{//若存在就直接数量相加
        goods[a]+=num;
        cout<<"add successfully"<<endl;
        go_on();
    }
    return 0;
}

int Operator::display_user_info() {//展示用户信息
    int i=0;
    for(auto it =user.begin();it!=user.end();it++,i++){
        cout<<"number: "<<i<<"  ||id: "<<it->first<<" ||"<<endl;
        cout<<"*******************************************************"<<endl;
    }
    go_on();
    return 0;
}

int Operator::delete_goods() {//删除商品
    cout<<"the thing you want to delete:"<<endl;
    string a;
    cin>>a;
    auto p1=price.begin();
    auto p2=basic_information.begin();
    for(auto iter = goods.begin(); iter != goods.end();iter++,p1++,p2++)
    {
        if (iter->first == a)
        {
            cout<<"the "<<a<<" has been deleted"<<endl;
            goods.erase(iter);
            price.erase(p1);
            basic_information.erase(p2);
            go_on();

            return 0;
        }
    }
    if(p1==price.end()){//不存在
        cout<<"the goods is not existed!!!"<<endl;
        go_on();
    }
    return 0;
}

int Operator::rename() {//更改名字
    cout<<"input the name of the goods:";
    string a;
    cin>>a;
    if(goods.find(a)==goods.end()){
        cout<<"the goods is not existed!!"<<endl;
        go_on();
    }
    else{
        cout<<"input a new name:";
        string name;
        cin>>name;
        if(name==a){
            cout<<"the name is the same with the old one!!"<<endl;
            go_on();
        }
        else{
            goods[name]=goods[a];
            price[name]=price[a];
            basic_information[name]=basic_information[a];
            delete_goods(a);
            cout<<"rename successfully!"<<endl;
            go_on();
        }
    }
    return 0;
}

int Operator::delete_goods(const string& a) {//删除商品（过载）
    auto p1=price.begin();
    auto p2=basic_information.begin();
    for(auto iter = goods.begin(); iter != goods.end();iter++,p1++,p2++)
    {
        if (iter->first == a)
        {
            goods.erase(iter);
            price.erase(p1);
            basic_information.erase(p2);

            return 0;
        }
    }
}

int Operator::set_discount() {//设置折扣
    cout<<"input the discount and the corresponding number:"<<endl;
    cout<<"input the discount";
    double a;
    cin>>a;
    cout<<"input the corresponding number:";
    string s;
    cin>>s;
    cout<<"set successfully"<<endl;
    go_on();
    return 0;
}

int Operator::set_activity() {//设置活动
    cout<<"please input the activity discount :";
    lable1:
    cin>>activity;
    if(activity>=1){
        cout<<"the discount >= 1"<<endl;
        cout<<"please input again!"<<endl;
        goto lable1;
    }

    else{
        cout<<"set successfully"<<endl;
    }
}

int Operator::set_discount_user() {//给用户发优惠券
    cout<<"please input the discount you want to send to user"<<endl;
    double s;
    cin>>s;
    cout<<"please input the discount code :"<<endl;
    string code;
    cin>>code;
    discount[code]=s;
    cout<<"please select which user to give:"<<endl;
    cout<<"if you want to give the discount to all users please input all"<<endl;
    string a;
    cin>>a;
    if(a=="all"){
        for(auto iter=user.begin();iter!=user.end();iter++){
            user_discount[code]=iter->first;
        }
        cout<<"give successfully"<<endl;
    }
    else{
        if(user.find(a)==user.end()){
            cout<<"the user is not existed"<<endl;
        }
        else{
            user_discount[code]=a;
            cout<<"give successfully"<<endl;
        }
    }
}


class User{//用户
private:
    string user_id;//用户id
    string user_password;//用户密码


public:
     int setpassword(string a);//设置密码
     string setname();//设置一个新id
    int clear_cart(string a[],int n,string name);//清空购物车
     bool login(const string& id,string passw);//登录，并选择功能
      int buy(string a);//购买
      int buy(string a ,string s);//过载
     int edit_password(string a);//重置密码
     int basic_information(string a);//显示基本信息，id以及账户余额
     int add_balance(string a);//为账户增添余额
     int search(string a,string n);//搜索商品
     int add_to_cart(string a);//加入购物车
     int search_in_cart();//在购物车中搜索
     int edit_num_in_cart();//编辑购物车中的商品数量
     int save_shopping_history(int amount[],string name[],int n,double price);//保存购物记录
     int save_shopping_history(string name,double price,int amount);//过载函数
     int analyse_shopping_data();//分析购物数据
};

string User::setname() {//设置一个新id
    string a;
    cin>>a;
    if(user[a].length()){
        cout<<"the id has been created"<<endl;
        return "error";
    }
    return a;

}

int User::setpassword(string a) {//设置密码
    if(a=="error"){
        cout<<"create failed"<<endl;
        go_on();
        return 0;
    }
    cout<<"please input the password"<<endl;
    cin>>user[a];
    cout<<"create successfully"<<endl;
    go_on();
    return 1;
}

bool User::login(const string& a,string passw) {//登录，并选择功能
    if(user.find(a)!=user.end()&&user[a]==passw){
        cout<<"login successfully"<<endl;
        user_id=a;
        user_password=passw;
        for(;;){
            cout<<"**********************************************************"<<endl;
            cout<<"choose what you want to do:  " ;
            cout<<"display the information of the goods:please input 'display'"<<endl;
            cout<<"buy things:input 'buy'  " ;
            cout<<"search goods,please input 'search'"<<endl;
            cout<<"show your personal details:input 'show'" ;
            cout<<"  exit the system:please input 'exit'"<<endl;
            cout<<"add your balance:'add'" ;
            cout<<"  edit your password:input 'edit'"<<endl;
            cout<<"clear your shopping cart:input 'clear'";
            cout<<"edit the number of thing in your cart,input 'edit_cart'"<<endl;
            cout<<"search thing in your cart:input search_cart"<<endl;
            cout<<"analyse shopping data:input 'analyse'"<<endl;
            cout<<"**********************************************************"<<endl;
            cout<<"please input:"<<endl;
            string input;
            cin>>input;
            if(input== "display"){//展示商品信息
                Operator::display();
            }
            else if(input =="exit"){//退出
                cout<<"exit your id successfully"<<endl;
                go_on();
                break;
            }
            else if(input=="search"){//搜索
                cout<<"please input a string:";
                string re;
                cin>>re;
                search(re,a);
            }
            else if(input=="buy"){//买

                buy(a);
            }
            else if(input =="analyse"){//分析购买数据
                analyse_shopping_data();
            }
            else if(input =="show"){//展示用户基本信息
                basic_information(a);
            }
            else if(input =="add"){//增添余额
                add_balance(a);
            }
            else if(input=="edit"){//编辑密码
                edit_password(a);
            }
            else if(input =="clear"){//清空购物车
                int i=0;string p[100];
                for(auto iter=shopping_cart.begin();iter!=shopping_cart.end();iter++,i++){
                    p[i]=iter->first;
                }
                clear_cart(p,i,a);
            }
            else if(input =="edit_cart"){//编辑购物车中的商品数量
                edit_num_in_cart();
            }
            else if(input =="search_cart"){//在购物车中搜索商品
                search_in_cart();
            }
            else{//非法输入
                cout<<"invalid token"<< endl;
                go_on();
            }
        }

    }
    else if(user.find(a)==user.end()){//用户不存在，需要要求用户注册
        cout<<"the id is never created"<<endl;
        cout<<"please create a new user id"<<endl;
        cout<<"input the id:"<<endl;
        User::setpassword(User::setname());

    }
    else{//密码错误
        cout<<"the password is error"<<endl;
        cout<<"please connect with the administrator to reset the password"<<endl;
        go_on();
    }
}

int User::basic_information(string a) {//显示基本信息，id以及账户余额
    cout<<"id name:"<<a<<"\n";
    cout<<"your balance:"<<balance[a]<<"\n";
    go_on();
    return 0;
}

int User::buy(string a) {//购买
    cout<<"input the goods you want to buy:"<<endl;
    string s;
    cin>>s;
    if(add_to_cart(s)){
        return 0;
    }
    cout<<"input the amount of the thing you want to buy"<<endl;
    int n;
    cin>>n;
    if(goods.find(s)==goods.end()){
        cout<<"the thing is not existed"<<endl;
        go_on();
    }
    else {
        if(n>goods[s]){
            cout<<"the goods are not enough"<<endl;
            go_on();
        }
        else{
            goods[s]-=n;
            if(balance[a]-price[s]*n<0){
                cout<<"your balance is not enough"<<endl;
                go_on();
            }
            else {
                balance[a]-=price[s]*n;
                cout<<"you have bought them"<<endl;
                go_on();
            }

        }
    }
}


int User::buy(string a,string l) {//过载
    if(add_to_cart(l)){
        return 0;
    }
    cout<<"input the amount of the thing you want to buy"<<endl;
    int n;
    cin>>n;

        if(n>goods[l]){
            cout<<"the goods are not enough"<<endl;
            go_on();
        }
        else{
            goods[l]-=n;
            if(balance[a]-price[l]*n<0){
                cout<<"your balance is not enough"<<endl;
                go_on();
            }
            else {
                balance[a]-=price[l]*n;
                cout<<"you have bought them"<<endl;
                go_on();
            }

        }

}

int User::add_balance(string a) {//为账户增添余额
    cout<<"the balance your want to add"<<endl;
    double n;
    cin>>n;
    if(n<=0){
        cout<<"invalid token"<<endl;
    }
    balance[a]+=n;
    cout<<"add successfully"<<endl;
}

int User::edit_password(string a) {//重置密码
    cout<<"input your new password:"<<endl;
    string g;
    cin>>g;
    if(user[a]==g){
        cout<<"the password is the same with the old one"<<endl;
        go_on();
        return 0;
    }
    user[a]=g;
    cout<<"edit your new password successfully"<<endl;
    go_on();
    return 1;
}

int User::add_to_cart(string a) {//加入购物车
    cout<<"if you want to add it to the cart,input 'yes',else input 'no'"<<endl;
    string n;
    cin>>n;
    if(n=="no"){//如果不想加入购物车直接返回0，会跳过if、判断部分
        cout<<"then you can continue buying things"<<endl;
        return 0;
    }
    else if(n=="yes"){
        cout<<"input the number of thing you want to add to your cart:"<<endl;
        int num;
        cin>>num;
        if(goods[a]<num){
            cout<<"the goods is not enough now!"<<endl;
            go_on();
        }
        else {
            goods[a]-=num;
                shopping_cart[a]+=num;
                cout<<"add to your cart successfully"<<endl;
                for(auto iter=shopping_cart.begin();iter!=shopping_cart.end();iter++){
                    if(iter->second==0){
                        shopping_cart.erase(iter);
                    }
                }
                go_on();
        }

    }
    return 1;
}

int User::search(string a,string n) {//静态函数只能访问静态变量和其他静态函数，不能访问非静态成员变量和非静态成员函数
    if(::search(a)){
        cout<<"find exactly!"<<endl;
        cout<<"name :"<<a<<"  price:"<<price[a]<<endl;
        cout<<"description:"<<data::basic_information[a]<<endl;
        cout<<"if you want to buy it ,please input yes,else no:";
        string f;
        cin>>f;
        if(f=="yes"){

            buy(n,a);
        }
    }
    else{
         int note=0;
        if(note==0){//寻找最接近的string算法
            int n=0;
            string ao[100];//先使用string数组存储所有的字符串
            int ai[100];//使用该数组记录每一个string的匹配程度
            for(auto iter = goods.begin(); iter != goods.end();iter++,n++){
                ao[n]=iter->first;
            }
            for(int i=0;i<n;i++){

                if(ao[i].length()>a.length()){
                    int compare=0;
                    for(int ii=0;ii<ao[i].length();ii++){//下标
                        int c=0;//选出最大数
                        for(int iii=0;ii+iii<a.length();iii++){//匹配字符串的长度
                            if(ao[i][ii+iii]==a[iii]){
                                c++;
                            }
                        }
                        if(c>=compare){
                            compare=c;
                        }
                        if(ii==ao[i].length()-1){
                            ai[i]=compare;
                        }
                    }
                }
                else{
                    int compare=0;
                    for(int ii=0;ii<a.length();ii++){//下标
                        int c=0;//选出最大数
                        for(int iii=0;ii+iii<ao[i].length();iii++){//匹配字符串的长度
                            if(ao[i][ii+iii]==a[iii]){
                                c++;
                            }
                        }
                        if(c>=compare){
                            compare=c;
                        }
                        if(ii==ao[i].length()-1){
                            ai[i]=compare;
                        }
                    }

                }
            }
            int max=0;
            for(int i=0;i<goods.size();i++){
                if(ai[i]>max){
                    max=ai[i];
                }
            }
            if(max==0){
                cout<<"there is no keyword matching your input"<<endl;
                return 0;
            }
            for(int i=0;i<ao->length();i++){
                if(ai[i]==max){
                    cout<<endl;
                    cout<<"maybe you want to search:"<<ao[i]<<endl;
                    cout<<"name :"<<ao[i]<<"  price:"<<price[ao[i]]<<endl;
                    cout<<"description:"<<data::basic_information[ao[i]]<<endl<<endl;
                }
            }
            return 0;
        }
    }
}

int User::clear_cart(string a[],int n,string name) {//清空购物车
    double num=0;
    double dis=1;
    for(int i=0;i<n;i++){
        num+=shopping_cart[a[i]]*price[a[i]];
    }
    cout<<"total number:"<<num<<endl;
    cout<<"your shopping cart:"<<endl;
    for(auto it=shopping_cart.begin();it!=shopping_cart.end();it++){

        cout<<"name: "<<it->first<<endl<<"  number: "<<it->second<<endl<<endl;

    }
    cout<<"please input the thing you want  to clear:"<<endl;
    cout<<"if you want to clear all your things ,please input all"<<endl;
    string a_1;
    cin>>a_1;
    if(a_1=="all"){
        if(activity<1){//如果有活动，则直接减少总价
            cout<<"an activity discount is available"<<endl;
            cout<<"the total number will be less"<<endl;
            num*=activity;
            dis*=activity;
            cout<<"if you have discount code,please input yes,else no"<<endl;
            string l;
            cin>>l;
            if(l=="yes"){
                cout<<"please input your discount number:"<<endl;//折扣使用
                string h;
                cin>>h;
                if(user_discount.find(h)!=user_discount.end()&&user_discount[h]==user_id){
                    num*=discount[h];
                    dis*=discount[h];
                    cout<<"use successfully"<<endl;
                }
                else{
                    cout<<"your discount number is error"<<endl;
                    go_on();
                }
            }
        }
        else{
            cout<<"if you have discount code,please input yes,else no"<<endl;
            string l;
            cin>>l;
            if(l=="yes"){
                cout<<"please input your discount number:"<<endl;//折扣使用
                string h;
                cin>>h;
                if(user_discount.find(h)!=user_discount.end()&&user_discount[h]==user_id){
                    num*=discount[h];
                    dis*=discount[h];
                    cout<<"use successfully"<<endl;
                }
                else{
                    cout<<"your discount number is error"<<endl;
                    go_on();
                }
            }
        }
        if(num>balance[name]){//余额不足
            cout<<"Your balance is not enough"<<endl;
            go_on();
        }
        else{
            int amount[100];
            for(int i=0;i<n;i++){
                amount[i]=shopping_cart[a[i]];
            }
            save_shopping_history(amount,a,n,dis);//保存购物数据
            shopping_cart.clear();
            balance[name]-=num;
            cout<<"clear successfully!"<<endl;
            go_on();
        }
    }
    else{
        num=shopping_cart[a_1]*price[a_1];
        cout<<"total number:"<<num<<endl;
        if(activity<1){//如果有活动，则直接减少总价
            cout<<"an activity discount is available"<<endl;
            cout<<"the total number will be less"<<endl;
            num*=activity;
            cout<<"if you have discount code,please input yes,else no"<<endl;
            string l;
            cin>>l;
            if(l=="yes"){
                cout<<"please input your discount number:"<<endl;//折扣使用
                string h;
                cin>>h;
                if(user_discount.find(h)!=user_discount.end()&&user_discount[h]==user_id){
                    num*=discount[h];
                    cout<<"use successfully"<<endl;
                }
                else{
                    cout<<"your discount number is error"<<endl;
                    go_on();
                }
            }
        }
        else{
            cout<<"if you have discount code,please input yes,else no"<<endl;
            string l;
            cin>>l;
            if(l=="yes"){
                cout<<"please input your discount number:"<<endl;//折扣使用
                string h;
                cin>>h;
                if(user_discount.find(h)!=user_discount.end()&&user_discount[h]==user_id){
                    num*=discount[h];
                    cout<<"use successfully"<<endl;
                }
                else{
                    cout<<"your discount number is error"<<endl;
                    go_on();
                }
            }
        }
        if(num>balance[name]){//余额不足
            cout<<"Your balance is not enough"<<endl;
            go_on();
        }
        else{
            save_shopping_history(a_1,num,shopping_cart[a_1]);//保存购物数据
            shopping_cart.erase(a_1);
            balance[name]-=num;
            cout<<"clear successfully"<<endl;
            go_on();
        }
    }

}

int User::edit_num_in_cart() {//编辑购物车中的商品数量
    string n;
    cout<<"please input the name of thing"<<endl;
    cin>>n;
    if(shopping_cart.find(n)==shopping_cart.end()){
        cout<<"no such thing in your cart!"<<endl;
        go_on();
        return 0;
    }
    else{
        int num;
        cout<<"please input the number:"<<endl;
        cin>>num;
        if(goods[n]+shopping_cart[n]<num){
            cout<<"the number is larger than the number of the goods"<<endl;
            go_on();
            return 0;
        }
        else{
            goods[n]+=shopping_cart[n];
            shopping_cart[n]=num;
            goods[n]-=num;
            cout<<"edit the number successfully!"<<endl;
            go_on();
            return 0;
        }
    }
}

int User::search_in_cart() {//在购物车中查找
    string a;
    cout<<"please input the thing you want to search"<<endl;
    cin>>a;
    if(shopping_cart.find(a)==shopping_cart.end()){
        cout<<"no such thing in your cart!"<<endl;
        go_on();
        return 0;
    }
    else{
        cout<<"find successfully!"<<endl;
        cout<<"name:"<<a<<"   amount:"<<shopping_cart[a]<<endl;
        cout<<"description:"<<data::basic_information[a]<<endl;
        go_on();
        return 0;
    }
}

int User::save_shopping_history( int *amount, string *name,int n,double dis) {//储存购物历史，年月日，商品名称及其数量,折扣
    ofstream outfile;
    int year;int month;int day;
    cout<<"please input the date when you buy"<<endl;
    cout<<"input the year:";
    cin>>year;
    cout<<"input the month:";
    cin>>month;
    cout<<"input the day:";
    cin>>day;
    double p[100];
    for(int i=0;i<n;i++){
        p[i]=shopping_cart[name[i]]*data::price[name[i]]*dis;
    }
    outfile.open(history_address,ios::app);

    for(int i=0;i<n;i++){
        outfile<<endl<<year<<" "<<month<<" "<<day<<endl;//将日期输进文件
        outfile<<name[i]<<" "<<amount[i]<<" "<<endl;
        outfile<<p[i];
    }
    cout<<"keep your shopping record successfully"<<endl;
    return 0;
}

int User::analyse_shopping_data() {//分析购物数据
    int year,month,day;
    cout<<"input the date you want to analyse:"<<endl;
    cout<<"year:";
    cin>>year;
    cout<<"month:";
    cin>>month;
    cout<<"day:";
    cin>>day;
    ifstream infile;
    infile.open(history_address,ios::in);
    int y,m,d;
    string name;int amount;
    double p;
    int o=0;
    while(!infile.eof()){
        infile>>y>>m>>d;
        infile>>name>>amount;
        infile>>p;
        if(o!=0){
            if(year==y&&month==m&&day==d){
                cout<<"name: "<<name<<"  "<<"amount: "<<amount<<endl;
                cout<<"total price: "<<p<<endl<<endl;
            }
        }
        else{
            if(year==y&&month==m&&day==d){
                cout<<"in "<<year<<"/"<<month<<"/"<<day<<endl;
                cout<<"you bought these things:"<<endl;
                cout<<"name: "<<name<<"  "<<"amount: "<<amount<<endl;
                cout<<"total price: "<<p<<endl<<endl;
                o++;
            }
        }

    }
    if(o==0){
        cout<<"no record!!"<<endl;
    }
    go_on();
    return 0;
}

int User::save_shopping_history(string name, double price, int amount) {//保存购物数据（过载）
    ofstream outfile;
    int year;int month;int day;
    cout<<"please input the date when you buy"<<endl;
    cout<<"input the year:";
    cin>>year;
    cout<<"input the month:";
    cin>>month;
    cout<<"input the day:";
    cin>>day;
    outfile.open(history_address,ios::app);
    outfile<<endl<<year<<" "<<month<<" "<<day<<endl;//将日期输进文件
    outfile<<name<<" "<<amount<<" ";

    outfile<<endl<<price;
    cout<<"keep your shopping record successfully"<<endl;
    return 0;
}



int main() {//主函数
    init();//初始化
    ifstream infile;
    infile.open(address,ios::in);
    while(!infile.eof()){
        string a;
        infile>>a;
        int i;
        infile>>i;
        shopping_cart[a]=i;
    }
    infile.close();
    for(;;){
        cout<<"1 choose the administrator 2 choose the user"<<endl;//选择功能
        cout<<"if you want to exit press 'exit'"<<endl;
        string n;//选择管理员或者客户
        cin>>n;//1代客户2代管理员
        getchar();//消除回车
        if(n=="1"){
            cout<<"please login:"<<endl;
            cout<<"please input your name id"<<endl;
            char id_1[100];
            gets(id_1);
            cout<<"please input your password"<<endl;
            char pa_1[100] ;
            gets(pa_1);
            Operator *c = new Operator(id_1, pa_1);

        }
        else if(n=="2"){
            cout<<"please login:"<<endl;
            cout<<"please input your name id"<<endl;
            string id_2;
            cin>>id_2;
            cout<<"please input your password"<<endl;
            string pass_2;
            cin>>pass_2;
            User c ;
            c.login(id_2,pass_2);
        }
        else if(n=="exit"){
            break;
        }
        else{
            cout<<"invalid token"<<endl;
        }
    }
    ofstream outfile;
   outfile.open(address,ios::trunc);//先对文件清空
   ofstream ol;
    ol.open(address,ios::app);
    for(auto it=shopping_cart.begin();it!=shopping_cart.end();it++){
        ol<<" "<<it->first<<" "<<it->second;
    }//再将现有购物车中内容加进文件中
    outfile.close();
    ol.close();
    cout<<"exit successfully"<<endl;
    return 1;
}