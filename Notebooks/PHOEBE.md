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

	- Things to consider
		○ Make sure people don't hang on the poles for the 3D frame, if they can actually reach it
		○ Make the hardware water proof - in the case of rainy weather
			§ Ultrasonic sensors/the circuit should be rained on…
	- (3 ultrasonic sensors)*(4 frame sides) + (3 ultrasonic sensors across) = 15 ultrasonic sensors for now….
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
