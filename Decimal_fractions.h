#pragma once
#include "basic_chain.h"
class Decimal_fractions :
   public basic_chain
{
   void(Decimal_fractions::* q) (char ch);
   
public:
   Decimal_fractions() 
   { 
      q = &Decimal_fractions::q0;
      register_count = 0;
      register_order = '0';
      register_sign = 1;
   }

   void P1(char ch)
   {
      register_number = ch;
      q = &Decimal_fractions::q1;
   }

   void P2(char ch)
   {
      register_number = '0';
      register_count = 0;
      q = &Decimal_fractions::q6;
   }

   void P3(char ch)
   {
      register_number += ch;
      q = &Decimal_fractions::q1;
   }

   void P4(char ch)
   {
      register_count = 0;
      q = &Decimal_fractions::q3;
   }

   void P5(char ch)
   {
      register_count = 0;
      q = &Decimal_fractions::q2;
   }

   void P6(char ch)
   {
      register_number += ch;
      register_count++;
      q = &Decimal_fractions::q2;
   }

   void P7(char ch)
   {
      q = &Decimal_fractions::q3;
   }

   void P8(char ch)
   {
      register_order = ch;
      register_sign = 1;
      q = &Decimal_fractions::q5;
   }

   void P9(char ch)
   {
      if (ch == '-')
         register_sign = -1;
      else
         register_sign = 1;

      q = &Decimal_fractions::q4;
   }

   void P10(char ch)
   {
      register_order = ch;
      q = &Decimal_fractions::q5;
   }

   void P11(char ch)
   {
      register_order += ch;
      q = &Decimal_fractions::q5;
   }

   void P12(char ch)
   {
      register_number = ch;
      register_count = 1;
      q = &Decimal_fractions::q2;
   }

   void k1()
   {
      cout << register_number << endl;
   }

   void k2()
   {
      
      if (((int)register_number.size()) - register_count <= 0)
      {
         cout << "0.";
         for (int i = 0; i < abs((int)register_number.size() - register_count)-1; i++)
            cout << '0';
         cout << register_number << endl;
         
      }
      else
      {
         string temp;
         temp = register_number;
         reverse(temp.begin(), temp.end());

      
         register_number.resize(register_number.size() - register_count);

         temp.resize(register_count);     
         reverse(temp.begin(), temp.end());

         cout << register_number << '.' << temp << endl;
      }
   }

   void k3()
   {
      if (register_sign == -1)
         register_count += stoi(register_order);
      else
         register_count -= stoi(register_order);
      
      if (register_count > 0)
      {
         k2();
      }
      else
      {
         
         for (int i = 0; i < abs(register_count); i++)
            register_number += '0';
         cout << register_number << endl;
      }
   }

   void start(string s)
   {
      q = &Decimal_fractions::q0;
      str = s;
      if (flag_work_print)
         cout << str << endl;
      for (int i = 0; i < str.size(); i++)
      {
         (this->*q)(str[i]);
         if (q == &Decimal_fractions::Error1)
            return;
         if (flag_work_state)
            cout << str[i] << endl;
      }

      if (q == &Decimal_fractions::q1)
         k1();
      else if (q == &Decimal_fractions::q2)
         k2();
      else if (q == &Decimal_fractions::q5)
         k3();
      else
         cout << "Bad" << endl;

   }

   void q0(char ch)
   {
      if (flag_work_state)
         cout << "work q0" << endl;

      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P1(ch);
         break;

      case('.'):
         P2(ch);
         break;

      default:
         Error();
      }
   }

   void q1(char ch)
   {
      if (flag_work_state)
         cout << "work q1" << endl;
      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P3(ch);
         break;

      case('E'): case('e'):
         P4(ch);
         break;

      case('.'):
         P5(ch);
         break;

      default:
         Error();
      }
   }

   void q2(char ch)
   {
      if (flag_work_state)
         cout << "work q2" << endl;
      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P6(ch);
         break;

      case('E'): case('e'):
         P7(ch);
         break;

      default:
         Error();
      }
   }

   void q3(char ch)
   {
      if (flag_work_state)
         cout << "work q3" << endl;
      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P8(ch);
         break;

      case('+'): case('-'):
         P9(ch);
         break;

      default:
         Error();
      }
   }

   void q4(char ch)
   {
      if (flag_work_state)
         cout << "work q4" << endl;
      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P10(ch);
         break;

      default:
         Error();
      }
   }

   void q5(char ch)
   {
      if (flag_work_state)
         cout << "work q5" << endl;
      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P11(ch);
         break;

      default:
         Error();
      }
   }
   
   void q6(char ch)
   {
      if (flag_work_state)
         cout << "work q6" << endl;
      switch (ch)
      {
      case('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
         P12(ch);
         break;

      default:
         Error();
      }
   }

   void Error()
   {
      cout << "wrong simbol" << endl;
      q = &Decimal_fractions::Error1;
   }

   void Error1(char ch)
   {
      cout << "wrong chain with simbol " << ch << endl;
      q = &Decimal_fractions::Error1;
   }
};

