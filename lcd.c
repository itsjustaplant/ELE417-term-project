/*
 * lcd.c
 *
 *  Created on: May 28, 2022
 *      Author: alperen
 */

#include "lcd.h"

void LCD (unsigned int x)
{
    unsigned int a,b;


    P2OUT=0x02;
                  __delay_cycles(1000);
                  P2OUT=0x22;
                  __delay_cycles(1000);
                  P2OUT=0x02;
                  __delay_cycles(1000);



                  P2OUT=0x00;
                  __delay_cycles(1000);
                  P2OUT=0x20;
                  __delay_cycles(1000);
                  P2OUT=0x00;
                  __delay_cycles(1000);


                  P2OUT=0x01;
                  __delay_cycles(1000);
                  P2OUT=0x21;
                      __delay_cycles(1000);
                 P2OUT=0x01;
                 __delay_cycles(1000);



                  P2OUT= 0x00;
                  __delay_cycles(1000);
                  P2OUT= 0x20;
                  __delay_cycles(1000);
                  P2OUT=0x00;
                  __delay_cycles(1000);



                  P2OUT=0x02;
                  __delay_cycles(1000);
                  P2OUT=0x22;
                  __delay_cycles(1000);
                  P2OUT=0x02;
                  __delay_cycles(1000);



                  P2OUT=0x00;
                  __delay_cycles(1000);
                  P2OUT=0x20;
                  __delay_cycles(1000);
                 P2OUT=0x00;
                  __delay_cycles(1000);



                  P2OUT=0x0C;
                  __delay_cycles(1000);
                  P2OUT=0x2C;
                  __delay_cycles(1000);
                 P2OUT=0x0C;
                  __delay_cycles(1000);

  //-------------------------------------TEMPERATURE-----------------------------------------
  //---------------------------------------------------------------
                  P2OUT=0x05;                                      //T
                  __delay_cycles(1000);
                  P2OUT=0x35;
                  __delay_cycles(1000);
                  P2OUT=0x05;
                 __delay_cycles(1000);


                  P2OUT=0x04;
                  __delay_cycles(1000);
                  P2OUT=0x34;
                  __delay_cycles(1000);
                 P2OUT=0x04;
                 __delay_cycles(1000);

                 //---------------------------------------------------------------

                 P2OUT=0x04;                                      //E
                 __delay_cycles(1000);
                 P2OUT=0x34;
                 __delay_cycles(1000);
                 P2OUT=0x04;
                __delay_cycles(1000);


                 P2OUT=0x05;
                 __delay_cycles(1000);
                 P2OUT=0x35;
                 __delay_cycles(1000);
                P2OUT=0x05;
                __delay_cycles(1000);

                //---------------------------------------------------------------


                P2OUT=0x04;                                      //M
                __delay_cycles(1000);
                P2OUT=0x34;
                __delay_cycles(1000);
                P2OUT=0x04;
               __delay_cycles(1000);


                P2OUT=0x0D;
                __delay_cycles(1000);
                P2OUT=0x3D;
                __delay_cycles(1000);
               P2OUT=0x0D;
               __delay_cycles(1000);

               //---------------------------------------------------------------


               P2OUT=0x05;                                      //P
               __delay_cycles(1000);
               P2OUT=0x35;
               __delay_cycles(1000);
               P2OUT=0x05;
              __delay_cycles(1000);


               P2OUT=0x00;
               __delay_cycles(1000);
               P2OUT=0x30;
               __delay_cycles(1000);
              P2OUT=0x00;
              __delay_cycles(1000);


              //---------------------------------------------------------------

              P2OUT=0x04;                                      //E
              __delay_cycles(1000);
              P2OUT=0x34;
              __delay_cycles(1000);
              P2OUT=0x04;
             __delay_cycles(1000);


              P2OUT=0x05;
              __delay_cycles(1000);
              P2OUT=0x35;
              __delay_cycles(1000);
             P2OUT=0x05;
             __delay_cycles(1000);


             //---------------------------------------------------------------

             P2OUT=0x05;                                      //R
             __delay_cycles(1000);
             P2OUT=0x35;
             __delay_cycles(1000);
             P2OUT=0x05;
            __delay_cycles(1000);


             P2OUT=0x02;
             __delay_cycles(1000);
             P2OUT=0x32;
             __delay_cycles(1000);
            P2OUT=0x02;
            __delay_cycles(1000);


            //---------------------------------------------------------------

            P2OUT=0x04;                                      //A
            __delay_cycles(1000);
            P2OUT=0x34;
            __delay_cycles(1000);
            P2OUT=0x04;
           __delay_cycles(1000);


            P2OUT=0x01;
            __delay_cycles(1000);
            P2OUT=0x31;
            __delay_cycles(1000);
           P2OUT=0x01;
           __delay_cycles(1000);


           //---------------------------------------------------------------

           P2OUT=0x05;                                      //T
           __delay_cycles(1000);
           P2OUT=0x35;
           __delay_cycles(1000);
           P2OUT=0x05;
          __delay_cycles(1000);


           P2OUT=0x04;
           __delay_cycles(1000);
           P2OUT=0x34;
           __delay_cycles(1000);
          P2OUT=0x04;
          __delay_cycles(1000);


          //---------------------------------------------------------------

          P2OUT=0x05;                                      //U
          __delay_cycles(1000);
          P2OUT=0x35;
          __delay_cycles(1000);
          P2OUT=0x05;
         __delay_cycles(1000);


          P2OUT=0x05;
          __delay_cycles(1000);
          P2OUT=0x35;
          __delay_cycles(1000);
         P2OUT=0x05;
         __delay_cycles(1000);


         //---------------------------------------------------------------

         P2OUT=0x05;                                      //R
         __delay_cycles(1000);
         P2OUT=0x35;
         __delay_cycles(1000);
         P2OUT=0x05;
        __delay_cycles(1000);


         P2OUT=0x02;
         __delay_cycles(1000);
         P2OUT=0x32;
         __delay_cycles(1000);
        P2OUT=0x02;
        __delay_cycles(1000);

        //---------------------------------------------------------------


        P2OUT=0x04;                                      //E
        __delay_cycles(1000);
        P2OUT=0x34;
        __delay_cycles(1000);
        P2OUT=0x04;
       __delay_cycles(1000);


        P2OUT=0x05;
        __delay_cycles(1000);
        P2OUT=0x35;
        __delay_cycles(1000);
       P2OUT=0x05;
       __delay_cycles(1000);


       //---------------------------------------------------------------
       //---------------------------------------------------------------


       P2OUT=0x02;                                      //-
       __delay_cycles(1000);
       P2OUT=0x32;
       __delay_cycles(1000);
       P2OUT=0x02;
      __delay_cycles(1000);


       P2OUT=0x00;
       __delay_cycles(1000);
       P2OUT=0x30;
       __delay_cycles(1000);
      P2OUT=0x00;
      __delay_cycles(1000);


      //---------------------------------------------------------------



 b=x%10;
 x=x-b;
 a=x/10;

 if(a==0)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x00;
     __delay_cycles(1000);
     P2OUT=0x30;
     __delay_cycles(1000);
    P2OUT=0x00;
    __delay_cycles(1000);
 }

 else if(a==1)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x01;
     __delay_cycles(1000);
     P2OUT=0x31;
     __delay_cycles(1000);
    P2OUT=0x01;
    __delay_cycles(1000);
 }
 else if(a==2)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x02;
     __delay_cycles(1000);
     P2OUT=0x32;
     __delay_cycles(1000);
    P2OUT=0x02;
    __delay_cycles(1000);
 }
 else if(a==3)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
    P2OUT=0x03;
    __delay_cycles(1000);
 }
 else if(a==4)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x04;
     __delay_cycles(1000);
     P2OUT=0x34;
     __delay_cycles(1000);
    P2OUT=0x04;
    __delay_cycles(1000);
 }
 else if(a==5)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x05;
     __delay_cycles(1000);
     P2OUT=0x35;
     __delay_cycles(1000);
    P2OUT=0x05;
    __delay_cycles(1000);
 }
 else if(a==6)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x06;
     __delay_cycles(1000);
     P2OUT=0x36;
     __delay_cycles(1000);
    P2OUT=0x06;
    __delay_cycles(1000);
 }
 else if(a==7)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x07;
     __delay_cycles(1000);
     P2OUT=0x37;
     __delay_cycles(1000);
    P2OUT=0x07;
    __delay_cycles(1000);
 }
 else if(a==8)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x08;
     __delay_cycles(1000);
     P2OUT=0x38;
     __delay_cycles(1000);
    P2OUT=0x08;
    __delay_cycles(1000);
 }
 else if(a==9)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x09;
     __delay_cycles(1000);
     P2OUT=0x39;
     __delay_cycles(1000);
    P2OUT=0x09;
    __delay_cycles(1000);
 }


 if(b==0)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x00;
     __delay_cycles(1000);
     P2OUT=0x30;
     __delay_cycles(1000);
    P2OUT=0x00;
    __delay_cycles(1000);
 }

 else if(b==1)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x01;
     __delay_cycles(1000);
     P2OUT=0x31;
     __delay_cycles(1000);
    P2OUT=0x01;
    __delay_cycles(1000);
 }
 else if(b==2)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x02;
     __delay_cycles(1000);
     P2OUT=0x32;
     __delay_cycles(1000);
    P2OUT=0x02;
    __delay_cycles(1000);
 }
 else if(b==3)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
    P2OUT=0x03;
    __delay_cycles(1000);
 }
 else if(b==4)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x04;
     __delay_cycles(1000);
     P2OUT=0x34;
     __delay_cycles(1000);
    P2OUT=0x04;
    __delay_cycles(1000);
 }
 else if(b==5)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x05;
     __delay_cycles(1000);
     P2OUT=0x35;
     __delay_cycles(1000);
    P2OUT=0x05;
    __delay_cycles(1000);
 }
 else if(b==6)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x06;
     __delay_cycles(1000);
     P2OUT=0x36;
     __delay_cycles(1000);
    P2OUT=0x06;
    __delay_cycles(1000);
 }
 else if(b==7)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x07;
     __delay_cycles(1000);
     P2OUT=0x37;
     __delay_cycles(1000);
    P2OUT=0x07;
    __delay_cycles(1000);
 }
 else if(b==8)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x08;
     __delay_cycles(1000);
     P2OUT=0x38;
     __delay_cycles(1000);
    P2OUT=0x08;
    __delay_cycles(1000);
 }
 else if(b==9)
 {
     P2OUT=0x03;
     __delay_cycles(1000);
     P2OUT=0x33;
     __delay_cycles(1000);
     P2OUT=0x03;
    __delay_cycles(1000);


     P2OUT=0x09;
     __delay_cycles(1000);
     P2OUT=0x39;
     __delay_cycles(1000);
    P2OUT=0x09;
    __delay_cycles(1000);

 }



 P2OUT=0x0D;                                      //Degree
 __delay_cycles(1000);
 P2OUT=0x3D;
 __delay_cycles(1000);
 P2OUT=0x0D;
__delay_cycles(1000);


 P2OUT=0x0F;
 __delay_cycles(1000);
 P2OUT=0x3F;
 __delay_cycles(1000);
P2OUT=0x0F;
__delay_cycles(1000);




 return ;

}





