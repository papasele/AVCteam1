#include  <stdio.h>
#include  <time.h>
// constants
#define MESSAGE_LENGTH 6
#define MOTOR_SPEED 50
#define SLEEP_TIME 100000
#define PICTURE_WIDTH 320
#define PICTURE_HEIGHT 240
#define THRESHOLD 500000
#define KP 0.0015
#define KD 0.0005
#define KI 0
//line following methods
extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row,int col,int colour);
extern "C" int Sleep( int sec, int usec );
// Motor is the pin it is connected to, dir is direction 1 or 2, speed is 0-255
extern "C" int set_motor(int motor, int speed);
//Server methods
extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);
//Digital sensors methods
extern "C" int init(int d_lev);
extern "C" int read_analog(int ch_adc);
//extern "C" int select_IO(int chan, int direct);

void openGate(){
    connect_to_server("130.195.6.196", 1024);
    send_to_server("Please server");
    char message[24];
    receive_from_server(message);
    message[MESSAGE_LENGTH] = '\0';
    send_to_server(message);
    printf("%s", message);
}

void testSensors(){
    //int select_IO(0, 1);
    int analog_sensor_reading = read_analog(0);
    printf("%d\n",analog_sensor_reading);
    Sleep(0,500000);
}


int main(){
    // Sets up raspbery pi hardware and ensures everything is working.
    init(0);

    //openGate();
	 int prev_error = 0;
    // Test code for camera, takes picture and prints it.
    while(true){
        for(int i=0; i<PICTURE_HEIGHT; i++){
            c = get_pixel(PICTURE_WIDTH/2, i, 3) > 127;
            num_col_white += c;
        }
        // Reads current image from camera stores in memory.
        take_picture();
        int total=0;

        int total_error = 0;
        int num_white = 0;
        int num_col_white = 0;
        bool c;
        for(int i=0; i<PICTURE_WIDTH; i++){
            for(int j = 0; j<5; j++){
                c = get_pixel(i, (PICTURE_HEIGHT/2)+j, 3) > 127;
            }
            c = get_pixel(i, PICTURE_HEIGHT/2, 3) > 127;
            num_white += c;
            total += (i-(PICTURE_WIDTH/2))*c;
	    }

        total_error += total;

        double proportional_signal = total*KP;
        double derivative_signal = (total-prev_error/0.1)*KD;
        double integral_signal =  total_error*KI;
        prev_error = total;

        int total_signal = proportional_signal + derivative_signal + integral_signal;


        for(int i=0; i<PICTURE_HEIGHT; i++){
            c = get_pixel(PICTURE_WIDTH/2, i, 3) > 127;
            num_col_white += c;
        }
        if (num_white > 280){
            set_motor(1, MOTOR_SPEED - total_signal);
            set_motor(2, MOTOR_SPEED - total_signal);
        }
        else if(num_white > 0){
            set_motor(1, MOTOR_SPEED - total_signal);
            set_motor(2, -MOTOR_SPEED - total_signal);
        } else {
            set_motor(1, -MOTOR_SPEED);
            set_motor(2, MOTOR_SPEED);
        }


            //printf("tot:%d\nprop:%f\n",total, proportional_signal);
            printf("num white:%d\n", num_white);
            printf("Row:%d\n", num_white);
            printf("Col:%d\n", num_col_white);

            Sleep(0,SLEEP_TIME);
        }



    return 0;
}
