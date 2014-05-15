#include<avr/io.h>
#include<util/delay.h>

#define NODE (0b00001110) // in node just check the status of middle three LEDs
#define ANTINODE (0b00000000) // in antinode middle three on black
#define row 6
#define column 6


int main(void)
{
    DDRA=0xFF;
    DDRB=0x00;
    
    int a[row][column],i,j,count;
    while(1)
    stop();
    if(PINA==0b00000001)   // giving an interrupt to start the bot
    {
    
    /************ DEMO RUN *************/
    for(i=0;i<row;i++)
    {
                    for(j=0;j<column;j++)
                    {
                                          while(1)
                                          {
                                                  forward();
                                                  if((PINA&0xFF)==NODE)
                                               {
                                                                slow();  //stop for 1 second
                                                                a[i][j]=0;
                                                                PORTB=0x01;  // glowing a LED to indicate a NODE
                                                                break;
                                               }
                                                else 
                                                {
                                                       if((PINA&0xFF)==ANTINODE)
                                                            {
                                                                slow();         //stop for 1 second
                                                                a[i][j]=1;
                                                                PORTB=0x02;  // glowing a LED to indicate an Antinode
                                                                break;
                                                            }
                                                }  
                                          }
                                          ++count;  // after first line traversal count=1
                                          
                    }
                    if((count%2)!=0)
                    {
                                    sharpright();
                                    while(1)
                                    {
                                            forward();
                                            if(((PINA&0xFF)==NODE)||((PINA&0xFF)==ANTINODE))
                                            {
                                                                                            slow();
                                                                                            sharpright();
                                                                                            stop();
                                                                                            break;
                                            }
                                    }
                    }
                    if((count%2)==0)
                    {               sharpleft();
                                    while(1)
                                    {
                                            forward();
                                            if(((PINA&0xFF)==NODE)||((PINA&0xFF)==ANTINODE))
                                            {
                                                                                            slow();
                                                                                            sharpleft();
                                                                                            stop();
                                                                                            break;
                                            }
                                    }
                    }
    }
    
    //// positions of nodes and antinodes stored 0 for node and 1 for antinode
     i=0;                               
    if((count%2)==0)
    {
                    sharpleft();
                    while(i<=count-1)
                    {
                                     forward();
                                      if(((PINA&0xFF)==NODE)||((PINA&0xFF)==ANTINODE))
                                      
                                                                                      ++i;

                                     
                    }
                    stop();
                    sharpleft();
                    i=0;
                    while(i<=row)
                    {
                               forward();
                                if(((PINA&0xFF)==NODE)||((PINA&0xFF)==ANTINODE))
                                                                                     ++i;
                    }
                    stop();
                    
                    //// ********************* DEMO RUN OVER ********************/////
                    
                    
        ///********** now the shortest path algo *****************/////  
                    
                    
                    
                    
                    
                    
                                                  
                                         
    
