          
int stepCount = 0;
int stepgoal = 1;
int spm = 60;
int gpm = 1;
int conc = 1/50; //concentration2
int mlpg = 3785;
int mlprev = 3; 
int sec = 60;
int spd= 5;//ms per wavelength/2 for up and down cycle
//ENBL 21 I-Enable input-Logic high to disable device outputs and indexer operation, logic low to enable. Internal pulldown.
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  digitalWrite(12, LOW);
  //sec= 60;   // time faucet is running
  stepgoal = 1000;//200 * (sec /spm) *gpm * (mlpg /mlprev);
}


// the loop function runs over and over again forever
void loop() {
  if (stepCount < stepgoal) {
  digitalWrite(8, HIGH);    
  delay(5);              
  digitalWrite(8, LOW);   
  delay(5);              
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  }else {//Serial.print(stepgoal);
  //digitalWrite(8, LOW);
  //digitalWrite(12, HIGH);
  delay(5000);
  stepCount=0;
  }
}
