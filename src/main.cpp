#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "bank.h"

using namespace std;

typedef struct information inf; 
typedef struct transaction trn;

struct information                               // استراکت اطلاعات بانک
{
     int count = 0;                             // تعداد مشتری
     long long int cash = 0;                    // موجودی کل بانک
     long long int loan = 0;                     // وام های داده شده
};

struct transaction                               // استراکت تراکنش
{
     string origin;                               // نگهداری اطلاعات مبدا
     string destination;                           // نگهداری اطلاعات مقصد
     long long int cash = 0;                       // مبلغ
     string transaction_date;                      // تاریخ تراکنش
};

void creat(string command, vector<bank>&custumer);           // ساخت حساب
void addip(string command, vector<bank>&custumer);            // اضافه کردن ای پی
void renewal(string command, vector<bank>&custumer);          // تمدید حساب
void deposit(string command, vector<bank>&custumer);           // واریز
void show(vector<bank>&custumer);                            // نمایش اطلاعات مشتری

void menu()        // نمابش منو
{
     cout << "+-------------------------------------------------------------------+" << endl; 
     cout << "|                        creat username:ip                          |" << endl;
     cout << "+-------------------------------------------------------------------+" << endl;
     cout << "|                      add_ip username:new_ip                       |" << endl;
     cout << "+-------------------------------------------------------------------+" << endl;
     cout << "|                       renewal username:ip                         |" << endl;
     cout << "+-------------------------------------------------------------------+" << endl;
     cout << "|                   deposit username:ip:money                       | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|    transfer sender_username:sender_ip:receiver_username:money     | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                   withdraw professor:ip:money                     | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                       add_profits username                        | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                    get_loan username:ip:money                     | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                      pay_loan username:money                      | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                              show                                 | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                              bank                                 | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;
     cout << "|                              exit                                 | "<< endl;
     cout << "+-------------------------------------------------------------------+ "<< endl;

}

void commands(vector<bank>&custumer)                       // گرفتن دستور و فراخوانی تابع مورد نظر
{

     string command;
     cout << "pleas enter your command" << endl;
     getline(cin, command);

     string delimiter = " "; 
     string split; 
    
     split = command.substr(0, command.find(delimiter));   // جداسازی کلمه اول

     if(split == "creat")
     {
          creat(command, custumer);
     }
     else if(split == "add_ip")
     {
          addip(command, custumer);
     }
     else if(split == "renewal")
     {
          addip(command, custumer);
     }
     else if(split == "deposit")
     {
          deposit(command, custumer);
     }
     else if(split == "show")
     {
          show(custumer);
     }
     else if(split == "exit")    
     {
         exit(0);
     }
     else 
     {
          cout << "your command is not correct , pleas enter again" << endl;
          commands(custumer);
     }
}

void creat(string command, vector<bank>&custumer)          // ساخت حساب
{
     string split;
     string usertest;
     string iptest;

     split = command.substr(command.find(' ') + 1); 
     usertest = split.substr(0, split.find(':'));       // جدا سازی نام کاربری
     iptest = split.substr(split.find(':') + 1);      // جدا سازی ای پی

     bool test = false;
     for(int i = 0; i < custumer.size(); i++)       // حلقه برای چک کردن تکراری نبودن نام کاربری داده شده
     {
          if(custumer[i].get_username() == usertest)
          {
               cout << "your username is repetitve" << endl;
               test = true;
          }
     }

     bank b;

     if(!test)
     {                              //  ساخت کلاس و پوش کردن کلاس در وکتور
          b.set_username(usertest);
          b.add_ip(iptest);
          custumer.push_back(b);    
     }  

     bool found = true;
     int random;
     while(found)                           // ایجاد شماره کارت رندوم و چک کردن تکراری نبودن
     {
          found = false;
          srand(time(nullptr));
          random = (rand() % 10001);

          for(int i = 0; i < custumer.size(); i++)
          {
               if(custumer[i].get_card_number() == random)
               {
                    found = true;
               }
          }
     }
     b.set_card_number(random);
}

void addip(string command, vector<bank>&custumer)      // اضافه کردن ای پی
{
     string split;
     string usertest;
     string newip;

     split = command.substr(command.find(' ') + 1);    // جداسازی قسمت های مختلف
     usertest = split.substr(0, split.find(':'));
     newip = split.substr(split.find(':') + 1);

     bool test = true;

     for(int i = 0; i < custumer.size(); i++)       // حلقه برای پیدا کردن نام کاربری داده شده و اضافه کردن ای پی
     {
          if(custumer[i].get_username() == usertest)
          {
               add_ip(newip);
               test = false;
               cout << "Your IP has been successfully added" << endl;
          }
     }

     if(!test)
     {
          cout << "Username not found" << endl;
     }
     
}

void renewal(string command, vector<bank>&custumer)              //تمدید حساب 
{ 
     string split;
     string usertest;
     string iptest;
     string com;

     split = command.substr(command.find(' ') + 1);     // جداسازی قسمت های مختلف
     usertest = split.substr(0, split.find(':'));
     iptest = split.substr(split.find(':') + 1);

     if(!check_exp_date())                            // چک کردن تاریخ انقضا
     {
          cout << "Your card has expired" << endl << "If you want to renew enter yes , Otherwise enter no" << endl;
          cin >> com;
          if(com == "yes")
          {
               for(int i = 0; i < custumer.size(); i++)   // حلقه برای پیدا کردن نام کاربری و تمدید حساب
               {
                    if(custumer[i].get_username() == usertest)
                    {
                         custumer[i].set_inventory(get_inventory() - 15000);
                         string date = custumer[i].get_exp_date();
                         string spl = date.substr(0, date.find('/'));
                         int date2 = stoi(spl);
                         spl.clear();
                         date2 += 2;
                         spl = to_string(date2);
                         string newdate = spl + date;
                         custumer[i].set_exp_date(newdate);
                    }
               }
          }
          else if(com == "no")
          {
               exit(0);
          }
          else
          {
               cout << "your command is not correct" << endl;
          }
     }
     else
     {
          cout << "Your card is valid" << endl;
     }
}

void deposit(string command, vector<bank>&custumer)
{
     string split;
     string usertest;
     string iptest;

     split = command.substr(command.find(' ') + 1);
     usertest = split.substr(0, split.find(':'));
     iptest = split.substr(split.find(':') + 1);
     
}
void show(vector<bank>&custumer)
{
     cout << "pleas enter your ip or your user name" << endl << "if enter ip enter 1 and if enter username enter 2" << endl;
     int tset;
     cin >> tset;
     string command;
     switch(test)
     {
          case 1:
          {
               cin >> command;
               for(int i = 0; i < custumer.size(); i++)       
               {
                    if( == command)
                    {
                         cout << custumer[i].get_username() << endl;
                         cout << custumer[i].get_card_number() << endl;
                         cout << custumer[i].get_open_date() << endl;
                         cout << custumer[i].get_exp_date() << endl;
                         cout << custumer[i].get_inventory() << endl;
                    }
               }
               break;
          }
          
          case 2:
          {
               cin >> command;
               for(int i = 0; i < custumer.size(); i++)       
               {
                    if(custumer[i].get_username() == commands)
                    {
                         cout << custumer[i].get_username() << endl;
                         cout << custumer[i].get_card_number() << endl;
                         cout << custumer[i].get_open_date() << endl;
                         cout << custumer[i].get_exp_date() << endl;
                         cout << custumer[i].get_inventory() << endl;
                    }
               }
               break;
          }
          default:
               cout << "your information is not correct" << endl;
     }
}

void bannk()
{
     
}
int main()
{
     vector<bank> custumer;
     void menu();

     while(1)
     {
          commands(custumer);
     }
     
     return 0;
}