# Project-17
Binary number game
Program plays game with 8 LEDs representing an 8 bit decimal interger. 
Before Void setup program defines DATA, LATCH, and CLOCk pins on board. 
Void Setup sets the pin output, begins a random # generator for the LED, and clears the LED from any previous game.
Display number loop does its name and displays the random # generated to the LED.
Get answer loop gets the answer from input from Serial availables and reads. The input is then displayed in print lines.
Check answer chesks the answer with if statements diplaying a correct print line if correct and else displaying wrong if incorrect.
Final loop runs all the identified loops before, assigning a random number within 256 (8-bit max total), and running a print asking what the displayed LEDS represent. Get answer loop is then appended to run getting an inputm and check answer to display result.
