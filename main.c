#define RCCAHB1ENR *((unsigned volatile int*)0x40023830)
#define GPIODODR *((unsigned volatile int*)0x40020c14)
#define GPIODMODR *((unsigned volatile int*)0x40020c00)
#define gpiod 1<<3
#define gpiodPBlueLed 1<<30
#define gpiodPGreenLed 1<<24
#define GPIODPOnTheBlueLed 1<<15
#define GPIODPOffTheBlueLed 0<<15
#define GPIODPOonTheGreenLed 1<<12
#define GPIODPOoffTheGreenLed ~(1<<12)

void init_leds(){
	RCCAHB1ENR =gpiod;
	GPIODMODR=gpiodPBlueLed;
	GPIODMODR |=gpiodPGreenLed;
}
void name(){
	turn_name_on();
	delay();
	turn_name_off();
	delay();
}
void surname(){
	turn_surname_on();
	delay();
	turn_surname_off();
	delay();
}
void turn_surname_on(){
	GPIODODR =GPIODPOnTheBlueLed;

}
void turn_surname_off(){
	GPIODODR =GPIODPOffTheBlueLed;

}
void turn_name_on(){
	GPIODODR |=GPIODPOonTheGreenLed;

}
void turn_name_off(){
	GPIODODR &=GPIODPOoffTheGreenLed;

}
void delay(){
	int delay0 = 0x000FFFFF; //delay loop
	while (delay0--){
		}
}


int main(){
	init_leds();

	int i=0;

	while(i<4){
		name();
		i++;
	}
	for (i=0;i<5;i++){
		surname();
	}

	return 0;


}

