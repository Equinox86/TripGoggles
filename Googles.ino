const int row[] = {2,3,4,5,6,7,8};
const int col[] = {9,10,11,12};
struct led { int row; int col; };
led lights[28];
boolean up = true; 

//This will setup the outputs as 7 rows / 4 columns
void setup() {
    for(int c = 0; c<4; c++) {
      pinMode(col[c], OUTPUT);
      digitalWrite(col[c], HIGH);
    }
    for(int r=0; r<7; r++){
      pinMode(row[r], OUTPUT);
      digitalWrite(row[r], LOW); 
    }
  lights[0] = {row[0],col[0]}; lights[1] = {row[1],col[0]};lights[2] = {row[2],col[0]}; lights[3] = {row[3],col[0]}; lights[4] = {row[4],col[0]}; lights[5] = {row[5],col[0]}; lights[6] = {row[6],col[0]};
  lights[7] = {row[6],col[1]}; lights[8] = {row[5],col[1]};lights[9] = {row[4],col[1]}; lights[10] = {row[3],col[1]}; lights[11] = {row[2],col[1]}; lights[12] = {row[1],col[1]}; lights[13] = {row[0],col[1]};
  lights[14] = {row[0],col[2]}; lights[15] = {row[1],col[2]};lights[16] = {row[2],col[2]}; lights[17] = {row[3],col[2]}; lights[18] = {row[4],col[2]}; lights[19] = {row[5],col[2]};lights[20] = {row[6],col[2]};
  lights[21] = {row[6],col[3]}; lights[22] = {row[5],col[3]};lights[23] = {row[4],col[3]}; lights[24] = {row[3],col[3]}; lights[25] = {row[2],col[3]}; lights[26] = {row[0],col[3]};lights[27] = {row[1],col[3]};
  
  Serial.begin(115200);

}

void loop() {
  //digitalWrite(2,HIGH); //ROWS GO HIGH
  //digitalWrite(9,LOW);  //COLUMNS GO LOW
  
  //Twisty Arm 1
  dTime = 850;
  for(int i = 0; i<dTime; i++){
  //Center Array
  turnOn(lights[25]);
  turnOn(lights[26]);
  turnOn(lights[27]);
  turnOn(lights[24]);
  turnOff(lights[25]);
  turnOff(lights[26]);
  turnOff(lights[27]);
  turnOff(lights[24]);
  
  turnOn(lights[0]);
  turnOff(lights[0]);
  turnOn(lights[16]);
  turnOff(lights[16]);
  turnOn(lights[8]);
  turnOff(lights[8]);
  turnOn(lights[20]);
  turnOff(lights[20]);
  turnOn(lights[4]);
  turnOff(lights[4]);
  turnOn(lights[18]);
  turnOff(lights[18]);
  turnOn(lights[22]);
  turnOff(lights[22]);
  turnOn(lights[12]);
  turnOff(lights[12]); } 

  //Mid point
  for(int i = 0; i<dTime; i++){
  //Center Array
  turnOn(lights[25]);
  turnOn(lights[26]);
  turnOn(lights[27]);
  turnOn(lights[24]);
  turnOff(lights[25]);
  turnOff(lights[26]);
  turnOff(lights[27]);
  turnOff(lights[24]);
  
  }

  //Twisty Arm 2
  for(int i = 0; i<dTime; i++){
    //Center Array
  turnOn(lights[25]);
  turnOn(lights[26]);
  turnOn(lights[27]);
  turnOn(lights[24]);
  turnOff(lights[25]);
  turnOff(lights[26]);
  turnOff(lights[27]);
  turnOff(lights[24]);
  //twitsting arms 1
  
  turnOn(lights[2]);
  turnOff(lights[2]);
  turnOn(lights[17]);
  turnOff(lights[17]);
  turnOn(lights[21]);
  turnOff(lights[21]);
  turnOn(lights[10]);
  turnOff(lights[10]);
  turnOn(lights[14]);
  turnOff(lights[14]);
  turnOn(lights[23]);
  turnOff(lights[23]);
  turnOn(lights[19]);
  turnOff(lights[19]);
  turnOn(lights[6]);
  turnOff(lights[6]); 
  } 
    
}


void turnOn(led l) { 
  digitalWrite(l.row,HIGH);
  digitalWrite(l.col,LOW);
}
void turnOff(led l){ 
  digitalWrite(l.row,LOW);
  digitalWrite(l.col,HIGH);
}
void spiral() { 
    for(int i = 0; i < 28; i++){ 
    turnOn(lights[i]);
    delay(100);
    turnOff(lights[i]);
  }
  for(int i = 28; i >=0; i--){ 
    turnOn(lights[i]);
    delay(100);
    turnOff(lights[i]);
  }
}

void allOff(){
  for(int i = 0; i < 28; i++){ 
    turnOff(lights[i]);
  }
}
