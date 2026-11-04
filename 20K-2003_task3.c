#include<stdio.h>

int i=0,j=0,k=0;
void input_function(int sensors, int hourly_readings, int green_house_data[sensors][hourly_readings]);
float highest_avrage_function(int sensors, float avrage_reading[sensors]);

int main(){
	int sensors=0;
	int hourly_readings=0;
	
	printf("Enter Number of Sensors in a Green house : ");
	scanf("%d", &sensors);
	printf("Enter Number of Readings (Temperatuer in celsius) shoud be taken to Estimate data : ");
	scanf("%d", &hourly_readings);
	printf("\n");
	
	//2D Array
	int green_house_data[sensors][hourly_readings];
	/*Array to store Total, average of all temperature readings of a sensor &
	 Highert, lowest of all temperature readings amoung a sensor  */
	int total_reading[sensors];
	float avrage_reading[sensors];
	int highest_reading[sensors];
	int lowest_reading[sensors];
	/*Number of critical(>=40), warning(35-39) readings amoung thr sensors & 
	 Longest streak of consecutive readings(35 or above)*/
	int no_critical_readings[sensors];
	int no_warning_readings[sensors];
	int steak[sensors];
	int current_steak=0;//streak for the current sensor
	
	/*just to initialise all array element to 0 so no garbage vale can exist*/
	for(i=0;i<sensors;i++){
	total_reading[i]=0;
	avrage_reading[i]=0.0;
	highest_reading[i]=0;
	lowest_reading[i]=5500;//5500 is a sun surface temoperature
	no_critical_readings[i]=0;
	no_warning_readings[i]=0;
	steak[i]=0;
		for(j=0;j<hourly_readings;j++){
			green_house_data[i][j]=0;
		}
	}
	//Input Temperature redings in Array through function
	input_function(sensors, hourly_readings, green_house_data);
	
	for(i=0;i<sensors;i++){
		for(j=0;j<hourly_readings;j++){
			total_reading[i]+=green_house_data[i][j];
			if(green_house_data[i][j]>highest_reading[i]){
				highest_reading[i]=green_house_data[i][j];
			}
			if(green_house_data[i][j]<lowest_reading[i]){
				lowest_reading[i]=green_house_data[i][j];
			}
			if(green_house_data[i][j]>=40){
				no_critical_readings[i]++;
			}
			if(green_house_data[i][j]>=35 && green_house_data[i][j]<=39){
				no_warning_readings[i]++;
			}
			if(green_house_data[i][j]>=35){
            	current_steak++;
            	if(current_steak>steak[i]){
                	steak[i]=current_steak;
            	}
        	}
			else {
            	current_steak=0;
        	}
        }
        current_steak=0;
		avrage_reading[i]=((float)total_reading[i]/hourly_readings);
	}
	
	printf("\n\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for(i=0;i<sensors;i++){
		printf("\nSensor%d : \n", i+1);
		printf("\tTotal = %d C\n", total_reading[i]);
		printf("\tAverage = %.2f C\n", avrage_reading[i]);
		printf("\tMax = %d C ", highest_reading[i]);
		printf("\tMin = %d C\n", lowest_reading[i]);
		printf("\tNo. of Critical readings = %d", no_critical_readings[i]);
		printf("\tNo. of Warning readings = %d\n", no_warning_readings[i]);
		printf("\tLongest Temperatur (hot) Steak = %d",steak[i]);
	}
	
	printf("\n\nHighest average : Sensor%d (%.2f)", k, highest_avrage_function(sensors, avrage_reading));
	
	return 0;
}

void input_function(int sensors, int hourly_readings, int green_house_data[sensors][hourly_readings]){
	for(i=0;i<sensors;i++){
	for(j=0;j<hourly_readings;j++){
		printf("Sensor%d : ", i+1);
		scanf("%d", &green_house_data[i][j]);
		}
		printf("\n");
	}
}


float highest_avrage_function(int sensors, float avrage_reading[sensors]){
	float highest_avrage=0.0;
	
	for(i=0;i<sensors;i++){
		if(avrage_reading[i]>highest_avrage){
			highest_avrage=avrage_reading[i];
			k=i+1;// tell us which sensor give highest avrage
		}
	}
	return highest_avrage;
}
