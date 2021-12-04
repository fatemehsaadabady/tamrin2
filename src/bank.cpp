#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "bank.h"

using namespace std;

bank:: bank(string username1, string ip1, int card_number1)          // کانستراکتور
{
     set_username(username1);
     add_ip(ip1);
     set_card_number(card_number1);
     set_open_date();
     set_exp_date();
     inventory = 0;
}


void bank:: set_username(string username2)    // گرفتن نام کاربری
{
     username = username2;
}

void bank:: add_ip(string ip2)    // اضافه کردن ای پی
{
     bool test = false;

     if(((ip2.length()) > 7) && ((ip2.length()) < 15))    // چک کردن صحیح بودن فرم ای پی
     {
          for(int i = 0; i < 5; i++)
          {
               string delimiter = "."; 
               string split; 
               split = ip2.substr(0, ip2.find(delimiter));
               int item = stoi(split);

               if((item > -1) && (item < 256))
               {
                    if(i == 4)
                    {
                         for(int i = 0; i < ip.size(); i++)       // حلقه برای چک کردن تکراری نبودن ای پی داده شده
                         {
                              if(ip[i] == ip2)
                              {
                                   cout << "your ip is repetitve" << endl;
                                   test = true;
                              }
                         }
                         if(!test)
                         {
                              ip.push_back(ip2); 
                         } 
                    }
               }
               else
               {
                    cout << "ip not valid" << endl;
               }
          }
     }
}


void bank:: set_card_number(int card_number2)    // ایجاد شماره کارت رندوم چهار رقمی
{
     
     card_number = card_number2; 
}

void bank:: set_open_date()                // ست کردن تاریخ افتتاح حساب
{
     time_t now = time(0);
     tm *ltm = localtime(&now);
     string date;

     if((1 + ltm->tm_mon) < 10)
     {
          if((ltm->tm_mday) < 10)
          {
               date = to_string(1900 + ltm->tm_year) + "/" + "0" + to_string(1 + ltm->tm_mon) + "/" + "0" + to_string(ltm->tm_mday);
          }
          else
          {
               date = to_string(1900 + ltm->tm_year) + "/" + "0" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
          }
     }
     else
     {
          if((ltm->tm_mday) < 10)
          {
               date = to_string(1900 + ltm->tm_year) + "/" + to_string(1 + ltm->tm_mon) + "/" + "0" + to_string(ltm->tm_mday);
          }
          else
          {
               date = to_string(1900 + ltm->tm_year) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
          }
     }

     open_date = date;
}

void bank:: set_exp_date()              // ست کردن تاریخ انقضای کارت
{
     time_t now = time(0);
     tm *ltm = localtime(&now);
     string date;

     if((1 + ltm->tm_mon) < 10)
     {
          if((ltm->tm_mday) < 10)
          {
               date = to_string(1900 + ltm->tm_year + 2) + "/" + "0" + to_string(1 + ltm->tm_mon) + "/" + "0" + to_string(ltm->tm_mday);
          }
          else
          {
               date = to_string(1900 + ltm->tm_year + 2) + "/" + "0" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
          }
     }
     else
     {
          if((ltm->tm_mday) < 10)
          {
               date = to_string(1900 + ltm->tm_year + 2) + "/" + to_string(1 + ltm->tm_mon) + "/" + "0" + to_string(ltm->tm_mday);
          }
          else
          {
               date = to_string(1900 + ltm->tm_year + 2) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
          }
     }

     exp_date = date;
}

void bank:: set_inventory(long long int inventory2)     // ست کردن موجودی حساب
{
     inventory = inventory2;
}

bool bank:: check_exp_date()                      // چک کردن تاریخ انقضا
{
     time_t now = time(0);
     tm *ltm = localtime(&now);
     string date;
     string expdate;

     if((1 + ltm->tm_mon) < 10)
     {
          if((ltm->tm_mday) < 10)
          {
               date = to_string(1900 + ltm->tm_year) + "/" + "0" + to_string(1 + ltm->tm_mon) + "/" + "0" + to_string(ltm->tm_mday);
          }
          else
          {
               date = to_string(1900 + ltm->tm_year) + "/" + "0" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
          }
     }
     else
     {
          if((ltm->tm_mday) < 10)
          {
               date = to_string(1900 + ltm->tm_year) + "/" + to_string(1 + ltm->tm_mon) + "/" + "0" + to_string(ltm->tm_mday);
          }
          else
          {
               date = to_string(1900 + ltm->tm_year) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
          }
     }
     
     expdate = get_exp_date();

     if(strcmp(&expdate[0], &date[0]) >= 0)
     {
          return false;
     }
     else
     {
          return true;
     }
}

string bank:: get_username()
{
     return username;
}

int bank:: get_card_number()
{
     return card_number;
}

string bank:: get_open_date()
{
     return open_date;
}

string bank:: get_exp_date()
{
     return exp_date;
}

long long int bank:: get_inventory()
{
     return inventory;
}
