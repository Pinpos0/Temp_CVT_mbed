#include "mbed.h"
#include "MLX90614.h"

#define default_addr   (0x00)

// setup serial
Serial pc(PA_9,PA_10,115200); //TX,RX,Freq

I2C i2c(PB_7, PB_6); //I2C_SDA, I2C_SCL
MLX90614 mlx90614(&i2c);

double temp;

int main(){

    //teste comunicação i2c
    char ucdata_write [2];

    ucdata_write[0]=0;
    ucdata_write[1]=0;

    while(true){
      
      if (!i2c.write((default_addr|0x00), ucdata_write, 1, 0))// Check for ACK from i2c Device
    {
        temp = mlx90614.read_temp(1);
        pc.printf("%.2f Celcius\n", temp);
        thread_sleep_for (1000);
    } else {
            pc.printf("funfou mizera");
    }
    thread_sleep_for (100);
    }
}