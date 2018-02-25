# Computer-Fan-Control-Using-Arduino (Laboratory Work)

Introduction  
This laboratory report has 4 different laboratory sessions and at the end of the laboratory sessions we aim to control the fan speed. In the first laboratory session we established that how Arduino and LCD screen work. Next week, we implemented and observed how fan’s RPM is changing. Third week, we measured RPM values for different duty cycles. Finally, in the last laboratory we set the middle RPM value in the code and observed that how interrupts effects to the duty cycle.  

Laboratory-1  
In this lab session, we implemented a simple circuit to display "hello world" on an LCD screen. We used an analog read on a potentiometer to display the percentage that the potentiometer. To make all of these steps we used the LiquidCrystal library to control LCD displays that are compatible with the Hitachi HD44780 driver.  

Laboratory-2  
In this lab session, we explored how to use an IR transmitter and receiver. The input came in the form of a signal state change from 5v to 0v when the IR break‐beam is interrupted and then the Arduino incremented an internal counter. We calculated the time between two interrupts in microseconds and RPM by using the formula below and final RPM value displayed on the LCD screen.  

RPM = 60*(1000000/(time*7))  

Sometimes we could not measure the RPM on our screen, because second potentiometer(100k ohm) was not on the correct value. To solve this problem, we increased or decreased the value of potentiometer(100k ohm). The another problem that we realized at the beginning.

Laboratory-3  
In this session, we learned how PWM works with Arduino. We used external voltage resource (12v). The value of resource was changed via given PWM signal value. We measured RPM values for duty cycle 0 - 255 which is shown belown, Also there was an important point that we realized before establishing the circuit. This problem was that unless we connect the grounds of 5v and 12v sources to the common ground point, circuit does not work as expected.  

Laboratory-4  
In this lab session, we set the desired RPM value as 1200 (duty cycle = %50) in our code, we set Kp value to 2 which is too high and Ki to 1 which has no effect. We decreased our Kp value to 0.47 then we set Ki value to 0.16 After this parameter we tested our system, system run effective RPM on 1170-1250. if we interrupt the fan , PI controller increase the duty cycle to reach adjusted RPM value. 

Conclusion  
In conclusion, we learned a lot of things about how Arduino and its components (i.e LCD) works and how to establish a PI controller circuit using some circuit elements such as potentiometer, resistor, transistor, diode, transmitter and phototransistor. 
