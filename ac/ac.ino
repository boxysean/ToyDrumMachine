//#define DEBUG

// MIDI defines

#define MIDI_CHANNEL 0
#define MIDI_POSITION (0xF2)
#define MIDI_SONG_SELECT (0xF3)
#define MIDI_START (0xFA)
#define MIDI_STOP (0xFC)
#define MIDI_CLOCK (0xF8)
#define MIDI_CONTINUE (0xFB)
#define MIDI_NOTE_OFF (0x80|MIDI_CHANNEL)
#define MIDI_NOTE_ON (0x90|MIDI_CHANNEL)
#define MIDI_AFTERTOUCH (0xA0|MIDI_CHANNEL)
#define MIDI_CONT_CHANGE (0xB0|MIDI_CHANNEL)
#define MIDI_PATCH_CHANGE (0xC0|MIDI_CHANNEL)
#define MIDI_CHANNEL_PRESSURE (0xD0|MIDI_CHANNEL)
#define MIDI_PITCH_BEND (0xE0|MIDI_CHANNEL)
#define MIDI_COMMAND (0xF0|MIDI_CHANNEL)

#define MIDI_C-3 0
#define MIDI_C-3_SHARP 1
#define MIDI_D-3 2
#define MIDI_D-3_SHARP 3
#define MIDI_E-3 4
#define MIDI_F-3 5
#define MIDI_F-3_SHARP 6
#define MIDI_G-3 7
#define MIDI_G-3_SHARP 8
#define MIDI_A-3 9
#define MIDI_A-3_SHARP 10
#define MIDI_B-3 11
#define MIDI_C-2 12
#define MIDI_C-2_SHARP 13
#define MIDI_D-2 14
#define MIDI_D-2_SHARP 15
#define MIDI_E-2 16
#define MIDI_F-2 17
#define MIDI_F-2_SHARP 18
#define MIDI_G-2 19
#define MIDI_G-2_SHARP 20
#define MIDI_A-2 21
#define MIDI_A-2_SHARP 22
#define MIDI_B-2 23
#define MIDI_C-1 24
#define MIDI_C-1_SHARP 25
#define MIDI_D-1 26
#define MIDI_D-1_SHARP 27
#define MIDI_E-1 28
#define MIDI_F-1 29
#define MIDI_F-1_SHARP 30
#define MIDI_G-1 31
#define MIDI_G-1_SHARP 32
#define MIDI_A-1 33
#define MIDI_A-1_SHARP 34
#define MIDI_B-1 35
#define MIDI_C0 36
#define MIDI_C0_SHARP 37
#define MIDI_D0 38
#define MIDI_D0_SHARP 39
#define MIDI_E0 40
#define MIDI_F0 41
#define MIDI_F0_SHARP 42
#define MIDI_G0 43
#define MIDI_G0_SHARP 44
#define MIDI_A0 45
#define MIDI_A0_SHARP 46
#define MIDI_B0 47
#define MIDI_C1 48
#define MIDI_C1_SHARP 49
#define MIDI_D1 50
#define MIDI_D1_SHARP 51
#define MIDI_E1 52
#define MIDI_F1 53
#define MIDI_F1_SHARP 54
#define MIDI_G1 55
#define MIDI_G1_SHARP 56
#define MIDI_A1 57
#define MIDI_A1_SHARP 58
#define MIDI_B1 59
#define MIDI_C2 60
#define MIDI_C2_SHARP 61
#define MIDI_D2 62
#define MIDI_D2_SHARP 63
#define MIDI_E2 64
#define MIDI_F2 65
#define MIDI_F2_SHARP 66
#define MIDI_G2 67
#define MIDI_G2_SHARP 68
#define MIDI_A2 69
#define MIDI_A2_SHARP 70
#define MIDI_B2 71
#define MIDI_C3 72
#define MIDI_C3_SHARP 73
#define MIDI_D3 74
#define MIDI_D3_SHARP 75
#define MIDI_E3 76
#define MIDI_F3 77
#define MIDI_F3_SHARP 78
#define MIDI_G3 79
#define MIDI_G3_SHARP 80
#define MIDI_A3 81
#define MIDI_A3_SHARP 82
#define MIDI_B3 83
#define MIDI_C4 84
#define MIDI_C4_SHARP 85
#define MIDI_D4 86
#define MIDI_D4_SHARP 87
#define MIDI_E4 88
#define MIDI_F4 89
#define MIDI_F4_SHARP 90
#define MIDI_G4 91
#define MIDI_G4_SHARP 92
#define MIDI_A4 93
#define MIDI_A4_SHARP 94
#define MIDI_B4 95
#define MIDI_C5 96
#define MIDI_C5_SHARP 97
#define MIDI_D5 98
#define MIDI_D5_SHARP 99
#define MIDI_E5 100
#define MIDI_F5 101
#define MIDI_F5_SHARP 102
#define MIDI_G5 103
#define MIDI_G5_SHARP 104
#define MIDI_A5 105
#define MIDI_A5_SHARP 106
#define MIDI_B5 107
#define MIDI_C6 108
#define MIDI_C6_SHARP 109
#define MIDI_D6 110
#define MIDI_D6_SHARP 111
#define MIDI_E6 112
#define MIDI_F6 113
#define MIDI_F6_SHARP 114
#define MIDI_G6 115
#define MIDI_G6_SHARP 116
#define MIDI_A6 117
#define MIDI_A6_SHARP 118
#define MIDI_B6 119

int midiState = 0;
int midiCount = 0;
int midiMeasure = 0;

byte b;
int note;
int velocity;

int FLIP = 0;

void setup() {
  // Initialze MIDI
  Serial.begin(31250);
  
  // Set pins
  for (int i = 6; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  // Initialize variables
  clean();
}

void loop() {
  /************** MIDI **************/
  if (Serial.available() > 0) {
    b = Serial.read();
    
    switch (midiState) {
    case 0:
      switch (b) {
      case MIDI_START:
#ifdef DEBUG
#endif
        break;
        
      case MIDI_CONTINUE:
#ifdef DEBUG
#endif
        break;
        
      case MIDI_STOP:
#ifdef DEBUG
#endif
        // Turn everything off
        clean();
        break;
        
      case MIDI_CLOCK:
//        if (midiCount == 0) {
//#ifdef DEBUG
//#else
//#endif
//        } else if (midiCount == 4) {
//#ifdef DEBUG
//#else
//#endif
//        }
//        
//        if (++midiCount >= 24) {
//          midiCount = 0;
//          midiMeasure++;
//        }
        break;
        
      case MIDI_NOTE_ON:
#ifdef DEBUG
#endif
        midiState = 1;
        break;
        
      case MIDI_NOTE_OFF:
#ifdef DEBUG
#endif DEBUG
        midiState = 3;
        break;
        
      case MIDI_AFTERTOUCH:
        midiState = -1; // nop
        break;
        
      case MIDI_CONT_CHANGE:
        midiState = -2; // nop
        break;
        
      case MIDI_PATCH_CHANGE:
        midiState = 5;
        break;
        
      case MIDI_CHANNEL_PRESSURE:
        midiState = -1; // nop
        break;
        
      case MIDI_PITCH_BEND:
        midiState = -2; // nop
        break;
      
      case MIDI_POSITION:
        midiState = -2; // nop
        break;
      
      case MIDI_SONG_SELECT:
        midiState = -1; // nop
        break;
      
#ifdef DEBUG
//      default:
//        strip.setPixelColor(6, 0, 0, 64);
#endif
      }
      
      break;
    
    case -2: // nop
      midiState = -1;
      break;
    
    case -1: // nop
      midiState = 0;
      break;
    
    case 1:
      note = b;
      midiState = 2;
      break;
      
    case 2:
      velocity = b;
      midiState = 0;
      noteOn(note, velocity);
      break;
    
    case 3:
      note = b;
      midiState = 4;
      break;
      
    case 4:
      velocity = b;
      midiState = 0;
      noteOff(note, velocity);
      break;
      
    case 5:
      midiState = 0;
      break;
    }
  }
}

void clean() {
}


void resetMidi() {
  midiCount = -1;
  midiMeasure = 0;
}

/************** MIDI FUNCTIONS **************/

void noteOn(int note, int velocity) {
  noteChange(note, velocity);
}

void noteOff(int note, int velocity) {
  noteChange(note, velocity);
}

void noteChange(int note, int velocity) {
  int pin = -1;
  
  switch (note) {
  case MIDI_C3:
#ifdef DEBUG
    FLIP = 1 - FLIP;
    digitalWrite(6, FLIP);
#endif
    pin = 10;
    break;
    
  case MIDI_C3_SHARP:
    pin = 11;
    break;

  case MIDI_D3:
    pin = 12;
    break;

  case MIDI_D3_SHARP:
    pin = 13;
    break;
  }
  
  if (pin >= 0) {
    digitalWrite(pin, velocity ? HIGH : LOW);
  }
}


