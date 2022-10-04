# Laboratory 2
nejaky uvodny text
v tomto lab si viem predstavit mozno nejaky 3d vytlaceny kit na ktorom by boli namontovane motory / zdroj 

## theory
V tomto cviku by som sa chcel zamerat na motory, ich ovladanie, spatnu vazby a mozno aj nejaky PID

### different kinds of motors a ich riadenie
nejaky opis toho ze arduino z pinu vie dat ~20ma, z napajania ~500ma ale to je malo a preto potrebujeme externy zdroj, pricom na to sluzia drivers a arduino dodava iba kontrolny signal 

### servo
opisat princip 
![](https://www.electrical4u.com/wp-content/uploads/What-is-a-Servomotor.png)
 - opisat zapojenie a sample kod v arduine
 - uloha - napada ma iba jednoucha uloha na sweep 
https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
alebo mozno este s potenciometrom (pouzitie scalingu z 1024 na 180) (na tom by sa mozno dalo ukazat ze ked sa "mrskne" s potenciometrom tak servu to chvilu trva nez sa pohne a taktiez ze servo bude drncat a sa na jeho vstup bude davat cisty nevyfiltrovany vstup z potenciometra - pointa - chcelo by to nejaky cislicovy filter na vstup z potenciometra)
- mozno poexperimentovat s riadenim serva pomocou PWM bez kniznice (osobne som to nikdy tak nerobil)

### stepper motor
maybe not, asi nebude cas na toto, ale mozno by som to tu nechal

opisat princip

![](https://arduinogetstarted.com/images/cover/arduino-uln2003-28byj-48-stepper-motor.jpg)
osobne sa mi paci driver ako je na foto kde su aj LED a je vidno signal "v priamom prenose"
- opisat zapojenie a sample code v arduine
- uloha - napr. napisat si vlastnu riadiacu funkciu ktorej sa da uhol a krokovy motor sa otoci o dany uhol
- ukazat ze na to exstuje kniznica

### dc motor
opisat princip a ze existuje vela sposobov riadenia
![](https://image.made-in-china.com/43f34j00eUoGENqyZnkt/High-Speed-6V-Small-DC-Motor-for-Cordless-Power-Tools.jpg)
#### -transistor

ukazat ze takto jednoucho sa ta ovladat motor + jednoduche zapojenie (mozno opisat ze naco je tam dioda)

![Motor Speed Control with One Transistor - Hackster.io](https://hackster.imgix.net/uploads/attachments/640551/schema_motore_YuJcrafONw.GIF?auto=compress%2Cformat&gifq=35&w=740&h=555&fit=max)

uloha na zapojenie, ovladanie cez PWM, mozno uloha na zvysovanie a znizovanie otacok
#### -H Bridge

opisat princip, 

takto sa da ovladat smer otacania motora a aj brzdenie ale ze existuje moznost skratu

![What Is an H-Bridge? - Build Electronic Circuits](https://www.build-electronic-circuits.com/wp-content/uploads/2018/11/H-bridge.png)

osobne neviem ci je dobry napad dat to zapojit studentom , skusal som to doma a trvalo mi to celkom dlho (hoci pouzival som mosfety s ktorymi som pracoval prvy raz) + treba vysvetlit NPN, PNP 

uloha na ovladanie rychlosti a smeru motora

#### - full smart driver

Sabertooth 2x5 RC

nakoniec ukazat ze existuju fancy drivers ktore dokazu ovladat motor tak ako H bridge ale bez toho aby hrozil skrat pri blbej konbinacii

### spatna vazba s enkoderom 
ako enkoder funguje 

![Rotary Encoder - Northwestern Mechatronics Wiki](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS3SAoy8jPpgp3jcm44ps__n6UeokNXEFtqXPDbwr6iLbGzdSuF1-mUNAy-WcthpmRv6fw&usqp=CAU)

mozno taketo jednoduche zapojenie na demonstraciu toho ako funguje enkoder

(mozno aj pouzit enkoder ktory nie je napojeny na motor [taky do kontaktneho pola])
![](https://www.electronicshub.org/wp-content/uploads/2016/02/Rotary-Encoder-LED-Test.jpg)

nasledne zapojenie enkodera do arduina 

note: U enkodérů bych zmínil, že existují jedno a dvoukanálové

#### Ulohy / zapojenia s enkoderom
-(nejaky popis math a teorie za tym)-
- zistit do akej strany sa enkoder otaca
- zistit ako rychlostou sa enkoder otaca
- zistit v akej polohe (v stupnoch ) enkoder je / zistit o kolko sa enkoder pootocil v metroch (napr ak by enkoder bol namontovany na kolese)
#### Ulohy na  zapojenie motora s enkoderom / nejako sa pohrat s meranim otacok na motore
nejaky naznak PID controller? mozno uloha na riadenie otacok pomocou P(bez ID)? (zalezi od toho kolko casu to zobere)
+ do kazdej ulohy by sa dal vlozit osciloskop a pozriet sa na priebehy signalov

 
