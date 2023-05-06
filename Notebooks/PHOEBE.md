# Phoebe's Lab Notebook

[[_TOC_]]

# 2023-01-26 

	- Planning design of bird-repellent windows
		○ Bird Detection
			§ Sensors
				□ Motion/Object classification
					® Camera
				□ Object detection
					® Grid of 2D IR sensors
				□ Proximity/Distance
					® ToF sensors (Time of Flight - Measures distance using an IR beam)
			§ Overall logic
				□ If a (warm?) object is detected from basic sensors (proximity, heat), the camera takes a picture of that grid block area (as soon as it can, before the bird flies closer,) for image processing.
					® Though, this means birds over a certain size (one grid block size, which is probably rare) might not be classified as a bird…however, tall buildings with large glass windows/walls are normally in urban areas, so the range of bird species we will encounter is probably smaller.
					® Most birds captured by the camera would appear within a certain size range on the image
				□ https://ieeexplore.ieee.org/document/8932891
					® ^ Research paper on "image preprocessing and bird detection methods in all dynamic environments using CNN technology."
						◊ Image preprocessing to separate moving creature from dynamic background and removes background.
							} Outputs image of moving object
						◊ CNN determines whether bird is in frame
				□ Ways to implement image preprocessing…
					® If no objects are detected in a grid block, the camera captures an image of the grid block area every minute.
					® So, when an object is within proximity/detected, we can compare (the object and non-object) images and remove the background more accurately.
					® Finally, make the bird pixels grayscale maybe…? We don't need to classify birds of different colors, just their shape and outline.
					® Use edge detection so that the birds' outlines stand out much more compared to the birds' feathers/patterns maybe…?
				□ Image pre-processing should allow for a simpler/less-complex (convolutional) neural network for bird classification/recognition.
					® *Note: CNN still needs to output true for >1 birds in preprocessed image
		○ Additional notes
			§ Things to research:
				□ Bird reaction time? - minimum distance needed for proximity sensors to alert system
				□ How long should we repel the bird for (can save some power)?
				□ What objects (with body warmth) actually fly near tall glass buildings?
				□ Is the opaque glass only visible from the outside?
		○ Assumptions:
			§ System is off in certain weather conditions (rain, snow)
				□ Birds would not be soaring in the sky anyways
			§ System is on at night…? (hopefully works if we implement image pre-processing; would need a non-visual repellent though)
	- Bird Repellent
		○ Sound
			§ Frequencies that humans can't hear
			§ However, might actually have unexpected psychological/brain-related effects…?
		○ Testing
			§ Possibly a functional demo with UV light (in bird's visible range) and a demo with light in 380-400 nm spectrum (common visible range between humans and birds)
![image](https://user-images.githubusercontent.com/90936268/236611359-cb4f53b5-ce88-4366-8d6f-9c1ddf144e0c.png)

# 2023-01-30 

	- Bird Detection
		○ https://www.fierceelectronics.com/sensors/what-ir-sensor
		○ Research later if IR or Laser sensors might actually be better, since Ultrasonic Sensors may be inaccurate sometimes…
		 
		○ Motion/object detection (ToF sensors…?) -> microcontroller -> raspberry pi -> camera (captures photo) -> raspberry pi (image processing) -> microcontroller (controls) -> electrochromic glass + UV lights

# 2023-02-07

	- High Level Requirements
		○ The system can successfully detect when a bird is approaching or in close proximity
			§ Before passing the 1.37 meter mark, so maybe at 2 meters…?
		○ The system can turn the electrochromic panels opaque in response to bird detection
		○ The system can direct UV light in the 300-380 nm range at an approaching bird
	- 1 Subsystem Requirement
		○ Ultrasonic sensors (2 cm - 4 m range) will be able to locate the approximate location of the bird by using grid indices
	- Concerns: do flashing UV lights pose too great of a safety risk?
Might raise the stress level of birds and cause them to react differently than we want![image](https://user-images.githubusercontent.com/90936268/236611114-2d75bcd4-cf8d-4a50-8261-5f4b075185c2.png)

# 2023-02-08 

Things to consider
	○ Make sure people don't hang on the poles for the 3D frame, if they can actually reach it
	○ Make the hardware water proof - in the case of rainy weather
		§ Ultrasonic sensors/the circuit should be rained on…
(3 ultrasonic sensors)*(4 frame sides) + (3 ultrasonic sensors across) = 15 ultrasonic sensors for now….
	○ Would we have enough pins for this….?
![image](https://user-images.githubusercontent.com/90936268/236611170-1c987eb7-538f-4082-bb55-194141b9f43a.png)

# 2023-02-10 

Machine shop had concerns with the physical size of the frame…how do we make the frame smaller?![image](https://user-images.githubusercontent.com/90936268/236611206-ffa06482-6923-4e03-a61c-0599c94666ce.png)

# 2023-02-13 

	- FliR Lepton thermal camera is very small
	- Discuss hardware circuit design with Matthew Qi tomorrow at 3:30
	- Come to OH at 4 again to discuss the video processing portion with Yixuan
![image](https://user-images.githubusercontent.com/90936268/236611240-c62e9218-ea1b-47b3-b43b-7f40d0c03b74.png)

# 2023-02-14

	- Video Processing discussion with Yixuan
		○ Recommends transfer learning for bird recognition 
	- Sensor beam across frame 20x92 cm frame sides
	
	
	- Sensor placement across 20x20 cm frame side (the side across from the windows)
	
	- Order these parts soon
		○ Object Detection Sensors - Ultrasonic Sensors 
			§ https://www.digikey.com/en/products/detail/adafruit-industries-llc/3942/9658069?utm_adgroup=Temperature%20Sensors%20-%20NTC%20Thermistors&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Sensors%2C%20Transducers_NEW&utm_term=&utm_content=Temperature%20Sensors%20-%20NTC%20Thermistors&gclid=Cj0KCQiA8t2eBhDeARIsAAVEga3-LKmSwy4SyDMLpOr_Q5RPnhG3XU94vhnl-hMCGgMaYcTvqeA6XF4aAudnEALw_wcB
			§ 12 + 2 extra
		○ Electrochromic glass panels - 10x10 cm
			§ 4*1 glass block
		○ Microcontroller that connects with:
			§ 12 ultrasonic sensors
				□ 2 pins per sensor (trigger and echo pins)
			§ Raspberry Pi
			§ 4 Electrochromic glass panels
				□ 1 control pin per glass panel
![image](https://user-images.githubusercontent.com/90936268/236611286-e53c29bf-32c3-40de-8fa9-8de94756035f.png)

# 2023-02-15

	- Notes:
		○ Apparently we are mainly saving white-throated sparrows now…? They're 26-29 cm long
			§ How far apart should our ultrasonic sensors be?
	- If we buy 4 of the 8x6 in electrochromic glasses…
		○ 
![image](https://user-images.githubusercontent.com/90936268/236611408-89554076-a590-4b0a-a660-cdcef232c562.png)

# 2023-02-22

	- Raspberry Pi
		○ Can the glass panels be directly connected to the Raspberry Pi's GPIO pins instead?
		○ How do we communicate floats of distance sensors…?
	- Updated Number of IO pins needed for microcontroller
	- 
		○ 1 pin per electrochromic glass
		○ (Trigger and echo pins for each ultrasonic sensor)*(6 ultrasonic sensors) = 12 pins
		○ Raspberry Pi
			§ 1 interrupt pin + 3 pins (top left, top right, bottom left, bottom right, top half, left half, right half, bottom half) 
			§ 3 pins
		○ 12 + 7 + 4 = 23 GPIO pins
	- Updated Number of IO pins needed for microcontroller
	- 
		○ Interface with raspberry pi
			§ Output: 1 interrupt pin + 4 pins (one per glass block)
			§ Input: 4 pins (one per glass block)
		○ We have one spare GPIO pin for Atmega32U-4
	- Ultrasonic sensor beams for 20x20x92 cm frame
	- 

	
	

![image](https://user-images.githubusercontent.com/90936268/236611449-7cd060de-a7be-47bf-9891-f577d379fad4.png)

# 2023-02-23

	- Apparently, the driving voltage for the electrochromic panels is 48-75V (AC50/50Hz)
		○ How do we get that driving voltage…?
			§ Transformer…? Not sure what that is
	- 
	- Do we need this part..?
	- 
![image](https://user-images.githubusercontent.com/90936268/236611510-47f0f479-b1f6-4f3f-9a27-14c82a429f2c.png)

# 2023-02-27

	- Researching on mosfets for the electrochromic panel switches + voltage driver parts with Mary-Rose…
		○ Need N-Channel mosfets
	- Additional parts needed:
		○ Two inverters
		○ DC Barrel Power Jack
			§ + a USB to 5.5 mm adaptor
![image](https://user-images.githubusercontent.com/90936268/236611526-33fecc23-999f-44b2-96ee-ac23acde20ad.png)

# 2023-03-02

Reorganized ATmega32U4's GPIO Pin interface so that the echo pins of the ultrasonic sensors connect to the PB Pins, which are interrupt pins. ![image](https://user-images.githubusercontent.com/90936268/236611547-63dd8642-722b-4294-a4a6-23ef300c267e.png)

# 2023-03-07

	- Tried to make first round PCBWay, but had a lot of trouble with the routing. 
	- 
![image](https://user-images.githubusercontent.com/90936268/236611560-1224ad09-8c6b-4c0f-8f59-85bcd6ab10ee.png)

# 2023-03-21

	- Took out part of the power system. We only need 4 MOSFET switches leading up to the electrochromic panel connectors now.
		○ Before:
			§ 
		○ After:
			§ We decided to switch the drivers we had with MOSFET switches, so the output pins of the ATMega32U4 connect the gates of the switching MOSFET, and the DC voltages we apply to the panels act as the loads
![image](https://user-images.githubusercontent.com/90936268/236611583-e8ba3d31-c705-4fb3-a983-9ae11e04a1cd.png)

# 2023-03-23

	- (Electrochromic panels interface) updated schematic with MOSFET switches 
	- 
![image](https://user-images.githubusercontent.com/90936268/236611597-5cfd9c84-cc78-42c2-a63b-49f3c550d9a5.png)

# 2023-03-24

	- DC-AC converters for electrochromic panels
	- Barrel jack should be from the wall outlet to the PCB
		○ AC-DC converter and regulator (120V/60Hz -> 5V DC)
	- Organized block diagram
	
	
![image](https://user-images.githubusercontent.com/90936268/236611607-63194ea2-8c3e-4008-9302-2466e23bcbb1.png)

# 2023-03-27

	- Long wires (figure it out, can probably get/buy this from ECEB)…?
		○ 9 Wires from PCB MTA-100 Connectors (or KK254…) to Raspberry Pi GPIO Pins
			§ We need to supply power to the Raspberry Pi in another way…(https://www.raspberrypi.com/products/raspberry-pi-universal-power-supply/)
		○ 4x6 Wires from PCB MTA-100 Connectors (or KK254) to HC-SR04 Ultrasonic Sensor Pins
		○ 8 Female-Female Jumper Wires from Raspberry Pi to Thermal Camera (can buy from ECEB)
![image](https://user-images.githubusercontent.com/90936268/236611613-20e93458-9aef-408a-8739-9fed39f6907d.png)

# 2023-03-29

	- Confused about mic2091-1ym5-tr….
		○ How to connect its fault pin to a test pad and a pull up resistor…?
		○ How to calculate what pull up resistor value we need?
		○ What should the connections/circuit look like
	- Updated PCB schematic (because we were just using random power switch symbols before)
	- 
	- Finished routing
	- Updated PCB Schematic - connected the  mic2091-1ym5-trs' fault pins
	- 
No more routing errors![image](https://user-images.githubusercontent.com/90936268/236611636-f39d61e9-c623-49ea-9edd-52195eb5a42d.png)

# 2023-03-30

	- Went through each bullet point in the PCB Checklist and satisfied all of them! - It is kind of late in the semester, so I want to increase the chance of our PCB working on the first try/design. 
	- ZIP file sent to Abhi!
	- Final Schematic:
	
	
	
	- Final PCB Layout
	
	
![image](https://user-images.githubusercontent.com/90936268/236611646-81998f52-980e-4af2-a6f6-a9bad8b343ff.png)

# 2023-04-04

	- What's the difference between USBASP Programmer and ISP 6 Pin Programmer Header on the Design Document's components list?
I think we only need one of these two…![image](https://user-images.githubusercontent.com/90936268/236611665-35fa60cb-2393-4a16-b259-28107eb735a0.png)

# 2023-04-06

The Raspberry Pi has a 2.54 mm pin pitch![image](https://user-images.githubusercontent.com/90936268/236611679-a22405f2-2f7c-450d-abb2-6cdf43b9936c.png)

# 2023-04-10

Connected Raspberry Pi hardware together and started Raspberry Pi account and Desktop![image](https://user-images.githubusercontent.com/90936268/236611693-387a7d6c-138e-47ec-ab83-b7f9f51b26bd.png)

# 2023-04-11

	- Had problems with connecting Raspberry Pi to Internet - for getting code
		○ Pulled out the sd card and edited the wpa_supplicant.conf file
		○ Connected to my home wifi
	- Had problems with installing QT for qmake-ing the raspberry_video example of the raspberry pi thermal lepton GitHub source code
		○ https://forums.raspberrypi.com/viewtopic.php?t=69163
			§ Had trouble with sudo apt-get install qt5-default
				□ https://forum.qt.io/topic/132190/issue-with-sudo-apt-get-install-qt5-default
	- Able to display thermal camera video on Raspberry Pi desktop
![image](https://user-images.githubusercontent.com/90936268/236611706-cc6bfbb3-96cf-4049-8c72-748025e36b40.png)

# 2023-04-12

	- Raspberry Pi Power supply cancelled our request because it's out of stock, so I'm currently using my power bank for now
		○ Not sure if it's ok, because the board gets a bit warm…
		○ Check the supply shop
	- Trying to display thermal camera data on raspberry pi's monitor
		○ Change CS pin to pin 24
	- Finally solved all raspberry pi's + thermal camera's hook-up/software issues, and can access and display the thermal camera's data now!
	- 
	- ^ Using groupgets's LeptonModule GitHub repository, raspberrypi_video example (for working with the Raspberry Pi)
		○ Not exactly sure how the code (logic) works yet, but the output seems weird, and has an undesirable latency.
		○ Not sure what "Perform FFC" does

![image](https://user-images.githubusercontent.com/90936268/236611721-0fc2d4df-cfb8-4b9d-9b43-ceea14806175.png)

# 2023-04-13

	- Helped out with making HC-SR04 Arduino code run faster (macros + order of function calls)
		○ Response time a bit too slow -  3.2 ms when we needed 2.75 ms
		○ Figure out how to use interrupts to make 6 tasks (one per ultrasonic sensor) run synchronously….
			§ Can potentially speed up everything, because putting everything in series and the delay functions take so much time…
			§ For one rising edge for echo interrupts, we simply read the time, and one more interrupt for the falling edge, and we get the duration
			§ We can have a new reading flag - if the flag is high, we calculate the distance + other stuff for object detection logic
	- Looked through LeptonModule source code
	- Looked into OpenCV for warm-blooded object classification
		○ Reading about the Sort Tracker - a multiple object tracker
			§ https://subscription.packtpub.com/book/data/9781789801811/10/ch10lvl1sec96/implementing-a-sort-tracker#:~:text=The%20Sort%20algorithm%20is%20a,box%20for%20each%20tracked%20object.
![image](https://user-images.githubusercontent.com/90936268/236611762-f5ff09c2-59ee-4fd1-944e-4a8c58b65bde.png)

# 2023-04-14

	- HC-SR04 Arduino code
		○ Sequential reading of sensor data (removed some excess code) - 14 ms total

4/15/2023
	- Implementing interrupts might be overly complicated given the amount of time we have left for our project, assembly should happen first

4/18/2023
	- Installing v4l2loopback kernel module on raspberry pi
		○ https://forums.raspberrypi.com/viewtopic.php?t=273788
	- Compiling v4i2loopback 
		○ https://github.com/umlaeute/v4l2loopback
		○ Could not solve "ERROR: modpost: "__aeabi_ldivmod" [/home/phoebec2/Desktop/ECE445/v4l2loopback/v4l2loopback.ko] undefined!"
			§ Tried finding the 64-bit division in v4l2loopback.cpp. Found divisions in lines 107, 449, 2309, 2329; still could not solve issue (through typecasting, commenting out, etc…)
	- Tried installing pylepton module instead (https://github.com/groupgets/pylepton)
		○ Encountered "OSError: [Errno 90] Message too long
			§ Solution: changed SPI buffer size
		○ There are two vertical white lines on my thermal image
		○ 
		○ https://hackaday.io/project/5359-pylepton-video-overlay
![image](https://user-images.githubusercontent.com/90936268/236611776-64e4c2ee-f254-451d-80af-fd4e0abb5e66.png)

# 2023-04-24

	- Ultrasonic Sensors Progress
		○ While programming the ATMega32U4, it started burning…we did not order enough parts to try out our PCB design again…
	- Image Processing Progress
		○ Decided to simplify algorithm to just checking if the object is large/warm enough for each interrupt. We might not be able to do tracking, because there are issues with the output image where there are two random vertical white lines…finding/implementing another algorithm might be a bit too complicated given the time we have left.
			§ Solved! I just went through each row of the 60x80 pixel temperature-thresholded thermal image and set columns 43 and 78 to white if both of their left and right pixels are also white
		○ Contours after temperature-thresholding the input image (image pre-processing):
		○ 
		○ Included a size range for the blobs/contours - used bounding box dimensions
		○ 
		
		○ Since we cannot run our Controls Subsystem with the ATMega32U4 on our PCB, and we are using an Arduino Uno instead, we do not have enough pins to integrate the Controls Subsystem and Object Classification Subsystem together…
			§ Can use a button for the interrupt pin from the Controls to the Raspberry Pi
			§ Can use switches for the 4 pins from the Controls to the Raspberry Pi
Can use LEDs for the 4 pins from the Raspberry Pi to the Controls![image](https://user-images.githubusercontent.com/90936268/236611798-a8a5556d-bf42-433d-bbe3-1ef71d66dcae.png)

# 2023-04-25

	- The temperature thresholds for the thermal image processing need to be changed whenever we move the thermal camera to a new environment
		○ This means we would have to test/calibrate outputs of the thermal camera before using our bird-friendly window in a new environment
Should not take long, though![image](https://user-images.githubusercontent.com/90936268/236611813-36606303-f570-4b66-a202-9eaaefdc36e5.png)

# 2023-04-26

	- I am trying to read in thermal images, and outputting which glass blocks warm-blooded objects are at through LEDs. I am delaying for one second per frame read + processing for now. 
	- 
	- I am now trying to process the first thermal image, put a bounding box around my hand, and tracking my hand until it leaves the frame. 
		○ Warm object detected function
			§ Outputs
				□ Whether or not detected object is warm-blooded or not
					® Returns false if multiple warm-blooded objects/blobs are detected
				□ Bounding box
		○ Warm object tracking function
			§ CV2 tracker options: KCF, MedianFlow
	- Implemented the KCF tracker for my classified warm-blooded object, but encountered some data type issues with the images
	- Simply re-finding contours on input images during tracking and then making sure that only one contour is within our desired temperature and size range might actually be more time and space efficient than implementing the KCF!
		○ Re-finding Contours Method (L = 60, W = 80)
			§ O(L*W) for temperature thresholding
			§ O (L*W) for finding blobs/contours
			§ Maximum L*W contours (1 pixel contours), going through each contour to find only one within the acceptable size range O(1)
				□ I only put a minimum size limit right now, for easier testing with my hands
			§ Maximum L*W contour perimeter, going through each boundary point to see which 2x2 grid block it is in O(1)
			§ => O(L*W) per image
		○ KCF Method
			§ O(L*W) for temperature thresholding
			§ Updating tracker - larger runtime then O(L*W)
			§ We still have to find contours within the Region of Interest (ROI)/Bounding Box, and go through its perimeter to see which 2x2 grid block it intersects
	- Implemented tracking with the Re-finding Contours Method successfully. LEDs also respond with minimal latency! Very accurate LED outputs.
	- Changed the method of analyzing size of blob/contour
		○ Before: dimensions of its bounding box
		○ After: cv2.contourArea(blob)
	- Added a button for the interrupt. Successful functioning of logic!
	- 
	
	- Final Thermal Image/Video Processing Flowchart
	
	
![image](https://user-images.githubusercontent.com/90936268/236611837-94792cb3-c47e-4751-b715-28c9ed25fc9a.png)









