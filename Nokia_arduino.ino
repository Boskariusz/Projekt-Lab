#define E5  659
#define D5  587
#define FS4 370
#define GS4 415
#define CS5 554
#define B4  494
#define D4  294
#define E4  330
#define A4  440
#define CS4 277

int tempo = 180;

int buzzer = 11;

int melodia[] = {

  E5, 8, D5, 8, FS4, 4, GS4, 4, 
  CS5, 8, B4, 8, D4, 4, E4, 4, 
  B4, 8, A4, 8, CS4, 4, E4, 4,
  A4, 2,

  E5, 8, D5, 8, FS4, 4, GS4, 4, 
  CS5, 8, B4, 8, D4, 4, E4, 4, 
  B4, 8, A4, 8, CS4, 4, E4, 4,
  A4, 2,
  
  E5, 8, D5, 8, FS4, 4, GS4, 4, 
  CS5, 8, B4, 8, D4, 4, E4, 4, 
  B4, 8, A4, 8, CS4, 4, E4, 4,
  A4, 2,
};

int k = sizeof(melodia) / sizeof(melodia[0]) / 2;

int ck = (60000 * 4) / tempo;

int d = 0;
int nd = 0;

void setup() {
  for (int t = 0; t < k * 2; t = t + 2) {

    d = melodia[t + 1];
    if (d > 0) {
      nd = (ck) / d;
    } 
    else if (d < 0) {
      nd = (ck) / abs(d);
      nd *= 1.5;
    }

    tone(buzzer, melodia[t], nd * 0.9);

    delay(nd);
    
    noTone(buzzer);
  }
}

void loop() {
}
