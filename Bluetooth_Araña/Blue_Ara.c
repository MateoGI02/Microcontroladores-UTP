char registro;
char valor;

void main() 
{
   TRISD=0;
   Uart1_Init(9600);
   delay_ms(100);


   while(1)
   {
   if(Uart1_Data_Ready())
     {
          registro=Uart1_Read();
                            if(registro== 'A')
                            {
                              while(Uart1_Read()!='X')
                               {
                                Portd.rd0=1;
                                delay_ms(1000);
                                Portd.rd0=0;
                                delay_ms(1000);
                               }
                            }
                            if(registro== 'S')
                            {
                              while(Uart1_Read()!='X')
                               {
                                Portd.rd1=1;
                                delay_ms(1000);
                                Portd.rd1=0;
                                delay_ms(1000);
                               }
                            }
                            if(registro== 'D')
                            {
                              while(Uart1_Read()!='X')
                               {
                                Portd.rd2=1;
                                delay_ms(1000);
                                Portd.rd2=0;
                                delay_ms(1000);
                               }
                            }
                            if(registro== 'W')
                            {
                              while(Uart1_Read()!='X')
                               {
                                Portd.rd3=1;
                                delay_ms(1000);
                                Portd.rd3=0;
                                delay_ms(1000);
                               }
                            }
                            if(registro== 'P')
                            {
                              Portd.rd4=1;
                              delay_ms(1000);
                              Portd.rd4=0;
                              delay_ms(1000);
                            }
                            if(registro== 'R')
                            {
                              Portd.rd5=1;
                              delay_ms(1000);
                              Portd.rd5=0;
                              delay_ms(1000);
                            }
     }
   }
}