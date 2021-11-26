//Julian Apodaca
//September 14, 2019
//Audio player that plays wav files. 

#include <SPI.h>
#include <SD.h>
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#define CHIPSELECT_PIN 4
#define SPEAKER_PIN 9

TMRpcm tmrpcm;
Sd2Card card;
SdFile root;


void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin = SPEAKER_PIN;
  if(!SD.begin(CHIPSELECT_PIN))
  {
    Serial.println("SD Reader failed");
    return;
  }
  tmrpcm.setVolume(2);

}

void play()
{
  tmrpcm.stopPlayback();
  tmrpcm.play("bats.wav",4);//45
  delay(240000);
  delay(100);
  return;
}

void loop() 
{
	play();
}
