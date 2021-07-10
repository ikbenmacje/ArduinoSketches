#include "MIDIUSB.h"

//https://tttapa.github.io/Control-Surface-doc/Doxygen/d8/d4a/md_pages_MIDI-over-USB.html

#define MIDI_CHANNEL     0  // default channel # is 0
// Set the value of first note, C is a good choice. Lowest C is 0.
// 36 is a good default. 48 is a high range. Set to 24 for a bass machine.
#define FIRST_MIDI_NOTE 10

// switches
const int buttonPin01 = 0;
int inPinsButton[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int buttonsActual[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int buttonsOld[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// pot meters
int inPins[] = {A0, A1, A2, A3, A4, A5};
int potMetersActual[6] = {0, 0, 0, 0, 0, 0};
int potMetersOld[6] = {0, 0, 0, 0, 0, 0};

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(31250);

  for (int i = 0; i < 12; i++) {
    pinMode(inPinsButton[i], INPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {

  for (int i = 0; i < 12; i++) {
    int b = digitalRead(inPinsButton[i]);
    
    if (b == LOW ) {
      if(buttonsActual[i] ==1){
        noteOn(MIDI_CHANNEL, FIRST_MIDI_NOTE + i, 64); // Channel 0, middle C, normal velocity
        MidiUSB.flush();
        buttonsActual[i] = 0;
      }
    }
    else {
      if(buttonsActual[i] == 0){
        noteOff(MIDI_CHANNEL, FIRST_MIDI_NOTE + i, 64); // Channel 0, middle C, normal velocity
        MidiUSB.flush();
        buttonsActual[i] = 1;
      }
    }
  }





  for (int i = 0; i < 6; i++) {
    potMetersActual[i] = analogRead(inPins[i]) / 8;
    Serial.print(i);
    Serial.print(" - ");
    Serial.print(potMetersActual[i]);
    Serial.println();


    // check for diff
    int diff = potMetersActual[i] -  potMetersOld[i];
    diff = abs(diff);
    if (diff > 1) {
      controlChange(MIDI_CHANNEL, FIRST_MIDI_NOTE + 12 + i, potMetersActual[i]);
      MidiUSB.flush();
    }

    potMetersOld[i] = potMetersActual[i];
  }
  Serial.println("--------");
  // read the input on analog pin 0:

  // print out the value you read:

  delay(100);        // delay in between reads for stability
}


// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
