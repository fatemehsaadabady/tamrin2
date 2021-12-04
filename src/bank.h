#include <iostream>
#include <string>
#include <vector>
#ifndef bank_h
#define bank_h

using namespace std;

class bank                    
{
     public:
          bank();                                        // کانستزاکتور
          void set_username(string);                 
          void add_ip(string);
          void set_card_number(int);
          void set_open_date();
          void set_exp_date();
          void set_inventory(long long int);
          bool check_exp_date();                        // چک کردن تاریخ کارت با تاریخ روز 
          string get_username();
          int get_card_number();
          string get_open_date();
          string get_exp_date();
          long long int get_inventory();

     private:
          string username;            // نام کاربری
          vector<string> ip;          // لیست ای پی ها
          int card_number;             // شماره کارت
          string open_date;             // تاریخ افتتاح حساب
          string exp_date;              // تاریخ انقضا
          long long int inventory;      // موجودی
          
};
#endif