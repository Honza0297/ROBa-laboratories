

# Laboratory 1 
nejaky uvodny text

## theory
ako funguje kontakte pole  (obrazok na takyto styl)

![Breadboard | Electronics Club](https://electronicsclub.info/images/bblinks.gif)

Arduino IDE

![]( https://static.javatpoint.com/tutorial/arduino/images/arduino-ide.png )

Ako co funguje, compile, nahrat, setup/loop (mozno ako config usb device)

Dalej periferie arduina
![](https://i.imgur.com/xHaln73.png)
GPIO, ADC, interrup, built in led

## excercises

### 1 (vyskusanie si Output)
na zaciatok iba blikanie embeded ledky / aby sa vedelo ci arduino zije

### 2 
zapojenie ledky a rezistora do pola a blikanie s tym (mozno poskusat zmenit delay aby to blikalo rychlejsie pomalsie)

### 3 (Vyskusanie si Input)

zapojenie tlacitka na input arduino pin a blikanie led (napr aj NOT operacia), opisat nejako debounce - v ako fuguju v realite real tlacitka / mozno aj nejake meranie na osciloscope

### 4 
zapojenie potenciometra a citanie z analog inputu a zaroven posielanie spravy cez seriovu linku (aby vedeli debuggovat)

### 5 PWM
jemna teoria na to co pwm je 

![](https://www.researchgate.net/publication/319071311/figure/fig4/AS:631655408611389@1527609793990/Ideal-pulse-width-modulation-PWM-inverter-output-voltage-instantaneous-component-blue.png)

a napisanie kodu na generovanie pwm ( na ledku ) aby bolo vidno ze ledka sveti menej / viacej
(idealne bez analog write) (mozno experimentacia so striedou)

### uloha num 1
spravit to aby sa ledka zhasinala a isla do plna 

### 5 analog write
teraz ukazat ze arudino ma vlastne uz analog write co je PWM (a ze nema realny analog write)
a to iste co v preodslej ulohe ale teraz s analog write (mozno nejake demo here s osciloskopom aby sa videlo ako to je / nejaky kondenzator co to vyhladi a je z toho analog voltage)


### 6 sonar hc sr04

Jednoduchý sonar ktorý používa echo/trigger na detekciu. Nacvičenie interruptu. (možno ukázať že sa to dá tak aj tak ale interrupt je superior) 
kod by vratil cas v ms (pripade us)
* Signál z HC-SR04 bych zpracovával různými způsoby: manuálně, přes interrupty, přes funkci pulseIn(), přes nějakou knihovnu jestli pro HC-SR04 existuje... a popsal bych rozdíly, výhody a nevýhody.


### uloha num 2
kedze predosla uloha vracia cas v sekundach tak uloha pre studentov by bola nech to prekonvertuju na centimetre ( rychlost zvuku ) (podla mna to dobre prepaja fyzikalny svet s tym co je v PC)  

ako dalsiu ulohu by som dal na pohranie sa s ultrazvukom a spravenie nejakeho reportu ako moc je presny/ jeho limity
diagram takehoto typu a na nom zopar bodov aby sa vedelo aky ma range/ ako je presny sonar

![](https://raw.githubusercontent.com/DFRobot/DFRobotMediaWikiImage/master/Image/URM07_Detecting_Angle.jpg)

taktiez ma napada jedna uloha na zetekovanie uhla ktory sonar zachyti

![HC-SR04 and NewPing shows crap - Sensors - Arduino Forum](https://aws1.discourse-cdn.com/arduino/original/4X/1/a/9/1a9acce39b842ecb0572cf1e473a2e8709fc619b.png)
pointa toho by bola ze senzor vie byt celkom nepresny a netreba sa na jeho merania vzdy spoliehat a tak celkovo v realite sa suciastky chovaju inak ako na papiery (alebo nieco na taky styl)


## uloha na koniec
ak by sa dalo tak by som mozno spravil to ze studenti budu mat na vyber z roznych senzorov (stacilo by ak by boli po jenom ak nevydu $) pricom jeden by zapojili a spravili by s tym jendoduche cvicenie.
take jednoduche a lacne mi napadaju RGB LED, fototranzistor, svetelna zavora, thermistor, piezo, spravit zo sonaru detektor rychlosti
![Top Arduino Sensors - The Ultimate list - Tutorial45](https://tutorial45.com/wp-content/uploads/2015/12/sensors-for-Arduino.jpg)

