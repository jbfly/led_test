// Define the LED pins
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const int numLeds = sizeof(ledPins) / sizeof(int);

// Define the delay times
int delayTime1 = 200; // Delay time for the first pattern
int delayTime2 = 200; // Delay time for the second pattern
int delayTime3 = 100; // Delay time for the third pattern
int delayTime4 = 100; // Delay time for the fourth pattern
int delayTime5 = 200;  // Delay time for the fifth pattern

void setup()
{
    // Set the LED pins as output
    for (int i = 0; i < numLeds; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop()
{
    // Repeat the pattern twice
    for (int repeat = 0; repeat < 2; repeat++)
    {

        // Turn each LED on in sequence from the outside to the middle
        for (int i = 0; i <= numLeds / 2; i++) // Modified condition to include the middle LED
        {
            digitalWrite(ledPins[i], HIGH);
            digitalWrite(ledPins[numLeds - i - 1], HIGH);
            delay(delayTime1);
            digitalWrite(ledPins[i], LOW);
            digitalWrite(ledPins[numLeds - i - 1], LOW);
        }


        // Turn each LED on in sequence from the middle to the outside
        for (int i = numLeds / 2 - 1; i >= 0; i--)
        {
            digitalWrite(ledPins[i], HIGH);
            digitalWrite(ledPins[numLeds - i - 1], HIGH);
            delay(delayTime2);
            digitalWrite(ledPins[i], LOW);
            digitalWrite(ledPins[numLeds - i - 1], LOW);
        }
    }

    // New pattern: Bounce up and down the whole string from end to end
    for (int repeat = 0; repeat < 2; repeat++)
    {

        // Turn each LED on in sequence from the first to the last
        for (int i = 0; i < numLeds; i++)
        {
            digitalWrite(ledPins[i], HIGH);
            delay(delayTime3);
            digitalWrite(ledPins[i], LOW);
        }


        // Turn each LED on in sequence from the last to the first
        for (int i = numLeds - 1; i >= 0; i--)
        {
            digitalWrite(ledPins[i], HIGH);
            delay(delayTime4);
            digitalWrite(ledPins[i], LOW);
        }
    }

    // New pattern: Randomly light LEDs for 14 flashes
    int maxDelayTime = 500; // Maximum delay time
    int minDelayTime = 30; // Minimum delay time
    int acceleration = 20; // Acceleration factor

    for (int flash = 0; flash < 52; flash++)
    {
        // Randomly select an LED to light up
        int randomLed = random(numLeds);
        digitalWrite(ledPins[randomLed], HIGH);
        delay(maxDelayTime);

        // Decrease the delay time using quadratic easing
        maxDelayTime = max(maxDelayTime - acceleration * (maxDelayTime - minDelayTime), minDelayTime);

        digitalWrite(ledPins[randomLed], LOW);
        delay(maxDelayTime);
    }
    
    

        // New pattern: Flash the first two and last two LEDs in red and green
        
            // Alternate between the first two LEDs and the last two LEDs
            for (int i = 0; i < 2; i++)
            {
                // Turn on the first LED and turn off the second LED
                digitalWrite(ledPins[0], HIGH);
                digitalWrite(ledPins[1], LOW);
                digitalWrite(ledPins[numLeds - 2], LOW);
                digitalWrite(ledPins[numLeds - 1], HIGH);
                delay(delayTime1);
                // Turn off the first LED and turn on the second LED
                digitalWrite(ledPins[0], LOW);
                digitalWrite(ledPins[1], HIGH);
                digitalWrite(ledPins[numLeds - 2], HIGH);
                digitalWrite(ledPins[numLeds - 1], LOW);
                delay(delayTime1);
            }

            // Alternate between red and green LEDs
            for (int i = 0; i < 4; i++)
            {
                // Turn on both red LEDs
                digitalWrite(ledPins[0], HIGH);
                digitalWrite(ledPins[1], HIGH);
                digitalWrite(ledPins[numLeds - 2], LOW);
                digitalWrite(ledPins[numLeds - 1], LOW);
                delay(delayTime1);
                // Turn off both red LEDs
                digitalWrite(ledPins[0], LOW);
                digitalWrite(ledPins[1], LOW);
                digitalWrite(ledPins[numLeds - 2], LOW);
                digitalWrite(ledPins[numLeds - 1], LOW);

                // Turn on both green LEDs
                digitalWrite(ledPins[0], LOW);
                digitalWrite(ledPins[1], LOW);
                digitalWrite(ledPins[numLeds - 2], HIGH);
                digitalWrite(ledPins[numLeds - 1], HIGH);
                delay(delayTime1);
                // Turn off both green LEDs
                digitalWrite(ledPins[0], LOW);
                digitalWrite(ledPins[1], LOW);
                digitalWrite(ledPins[numLeds - 2], LOW);
                digitalWrite(ledPins[numLeds - 1], LOW);
            }
            
        // Alternate between LED 2 and LED 4
        for (int i = 0; i < 4; i++)
        {
            // Turn on LED 2 and turn off LED 4
            digitalWrite(ledPins[4], HIGH);
            digitalWrite(ledPins[6], LOW);
            delay(delayTime1);
            // Turn off LED 2 and turn on LED 4
            digitalWrite(ledPins[4], LOW);
            digitalWrite(ledPins[6], HIGH);
            delay(delayTime1);
        }
}
