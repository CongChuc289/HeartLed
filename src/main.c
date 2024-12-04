#include<at89x52.h>

void Mode1();
void Mode2();
void Mode3(unsigned char count);
void Mode4(unsigned char count);
void Mode5();
void Mode6();
void Mode7();
void Mode8();
unsigned char map[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
void main(){
    Mode1();
    Mode2();
    //Mode3(3);
    Mode4(5);
    //Mode3(3);
    Mode5();
    //Mode3(3);
    Mode6();
    //Mode3(3);
    Mode7();
    //Mode3(3);
    Mode8();
}
void delay(int time)  // Ham delay
{
    int i,j;
    for(i=0;i<time;i++)
    for(j=0;j<1275;j++);
}
void Mode1(void){
    for(unsigned char i = 0; i < 8; i++){
        P0 &= ~(0x80 >> i);
        P1 = P2 = P3 &= ~(0x01<<i);
        delay(10);
    }
    delay(50);
    P0 = P1 = P2 = P3 = 0xFF;
}
void Mode2(void){
    for(unsigned char i = 0; i < 8; i++){
        P0 &= ~(0x01 << i);
        P1 = P2 = P3 &= ~(0x80 >> i);
        delay(10);
    }
    delay(50);
    P0 = P1 = P2 = P3 = 0xFF;
}
void Mode3(unsigned char count){
    for(unsigned char i = 0; i < count; i++){
        P0 = P1 = P2 = P3 = 0x00;
        delay(10);
        P0 = P1 = P2 = P3 = 0xFF;
        delay(10);
    }
}
void Mode4(unsigned char count){
    for(unsigned char i = 0; i < count; i++){
        P0 = 0x55;
        P1 = P2 = P3 = 0xAA;
        delay(50);
        P0 = 0xAA;
        P1 = P2 = P3 = 0x55;
        delay(50);
    }
    P0 = P1 = P2 = P3 = 0xFF;
}
void Mode5(void){
    for(unsigned char i = 0; i < 8; i++){
        P3 &= ~(0x01<<i);
        P0 &= ~(0x80 >> i);
        delay(10);
    }
    for(unsigned char i = 0; i < 8; i++){
        P2 &= ~(0x01<<i);
        P1 &= ~(0x01<<i);
        delay(10);
    }
    delay(50);
    P0 = P1 = P2 = P3 = 0xFF;    
}
void Mode6(void){
    for(unsigned char i = 0; i < 8; i++){
        P1 &= ~(0x80 >> i);
        P2 &= ~(0x80 >> i);
        delay(10);
    }
    for(unsigned char i = 0; i < 8; i++){
        P3 &= ~(0x80 >> i);
        P0 &= ~(0x01 << i);
        delay(10);
    }
    delay(50);
    P0 = P1 = P2 = P3 = 0xFF;    
}


void Mode7(void){
    for(unsigned char i = 0; i < 8; i++){
        P3 &= ~(0x01<<i);
        P1 &= ~(0x80 >> i);
        delay(10);
    }
    for(unsigned char i = 0; i < 8; i++){
        P2 &= ~(0x01 << i);
        P0 &= ~(0x01 << i);
        delay(10);
    }
    delay(50);
    P0 = P1 = P2 = P3 = 0xFF;    
}
void Mode8(void){
    for(unsigned char i = 0; i < 8; i++){
        P0 &= ~(0x80 >> i);
        P2 &= ~(0x80 >> i);
        delay(10);
    }
    for(unsigned char i = 0; i < 8; i++){
        P3 &= ~(0x80 >> i);
        P1 &= ~(0x01 << i);
        delay(10);
    }
    delay(50);
    P0 = P1 = P2 = P3 = 0xFF;    
}