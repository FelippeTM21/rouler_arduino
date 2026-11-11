// Le code minimal

#include <Arduino.h>
#include <M5_Encoder.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

M5_Encoder monEncodeur;

void setup()
{
    Serial.begin(115200);
    Wire.begin();
    monEncodeur.begin();
}

void loop()
{
    monEncodeur.update(); // Mise à jour des valeurs de l’encodeur.
    int changementEncodeur = monEncodeur.getEncoderChange();
    if (changementEncodeur != 0) // l’encodeur a été tourné
    {
        monOsc.sendInt("/enc/rot", changementEncodeur);
    }
    // ..
    if (monEncodeur.wasPressed())
    {
        monOsc.sendInt("/enc/but", 1);
    }

    if (monEncodeur.wasReleased())
    {
        monOsc.sendInt("/enc/but", 0);
    }
}
