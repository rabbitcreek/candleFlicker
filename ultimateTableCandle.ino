
int curStrength = 120;
// Maximum amplitude of flickering
int maxAmp = 100;
// Milliseconds per frame
int frameLength = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(D3, OUTPUT);
digitalWrite(D3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
flicker();
}
void flicker() {//these functions produce flickering...they are all borrowed...thanx
    // Amplitude of flickering
    int amp = random(maxAmp)+1;
    
    // Length of flickering in milliseconds
    int length = random(10000/amp)+1000;
    
    // Strength to go toward
    int endStrength = random(255-(amp/4))+(amp/4);
    
    // Flicker function
    flickerSection(length, amp, endStrength);
}

void flickerSection(int length, int amp, int endStrength) {
    // Initilize variables
    int i, max, min;
    double oldStrengthRatio, endStrengthRatio;
    
    // Number of frames to loop through
    int frameNum = length/frameLength;
    
    // Use variable to hold the old LED strength
    int oldStrength = curStrength;
    
    
    // Loop <frameNum> times 
    for(i = 0; i <= frameNum; i += 1){
        // The ratio of the old/end strengths should be proprtional to the ratio of total frames/current frames
        // Use type casting to allow decimals
        oldStrengthRatio = (1-(double)i/(double)frameNum);
        endStrengthRatio = ((double)i/(double)frameNum);
        
        // Fade current LED strength from the old value to the end value
        curStrength = (oldStrength*oldStrengthRatio) + (endStrength*endStrengthRatio);
        
        // LED brightnesses must be in between max and min values
        // Both values are half an amplitude's distance from the average
        max = curStrength+(amp/2);
        min = curStrength-(amp/2);
        
        // Light LEDs to random brightnesses
        //for(int LedPin = 0; LedPin < fakePrime +1; LedPin ++){   //fakePrime is used by several functions to produce the wiggle light numbers
        
        analogWrite(D3, random(max - min) + min);
    
        
        
        // Wait until next frame
        delay(frameLength);
    }
}

void setRandom(int led, int max, int min) {
    // Set chosen LED to a random brightness between the maximum and minimum values
    analogWrite(led, random(max - min) + min);
}