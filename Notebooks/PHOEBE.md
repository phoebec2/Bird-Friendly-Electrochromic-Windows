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

# 2021-02-10 - Parts Updates

Currently, I am looking at Dual VESC options that can simplify our design, minimize space.
Here are some examples:

![](esc1.png)

[link](https://flipsky.net/collections/electronic-products/products/dual-fsesc6-6-based-upon-vesc6-with-aluminum-heatsink)

This one has dual MCUs, with a physical switch to include or disclude the CAN connection
between both of the VESCs.

![](esc2.png)

[link](https://massivestator.com/products/focbox-unity-dual-motor-controller)

This one has a single MCU that acts for both motors.

I am currently speaking with Loaded Boards, a longboard deck and skateboard wheel company that Boosted had a business relationship with. They are willing to send a B-grade deck and wheels at a lower price. Wheel durometer options are 77a, 80a, 83a. The lower the durometer number, the softer the
wheel urethane.

After discussions with the team, we decided on the hardest wheel option, 83a, as it would slip easier than the softer wheels. We want to make sure we can demonstrate traction control in our project.

For weight sensing, I also came across a flexiforce sensor that we may consider using. The board will weigh about 20 pounds, we ideally would like a range of double that. This flexiforce sensor is high on my list.

![](flexiforce.png)

[link](https://www.tekscan.com/products-solutions/force-sensors/a401?tab=specifications-performance)

# 2021-02-12 - Acquiring a Battery

I have contacted several custom battery builders in the esk8 (custom electric longboard builders) forum, located [here](https://forum.esk8.news/).  Builder Zach Tetra from [Black Fox Builds](https://forum.esk8.news/t/black-fox-boards-east-coast-battery-building-services/37402) has the following pair of 6s4p batteries that he can send immediately:

![](blackfox_battery.png)

For our project, I would prefer a 12s battery for adequate performance. The pack above is made up of Samsung 30Q cells, I found more info [here](https://lygte-info.dk/review/batteries2012/Samsung%20INR18650-30Q%203000mAh%20(Pink)%20UK.html). We can convert the 6s4p pack into a 12s2p pack, which will be nearly 200Whr.
This will be plenty, for up to 10 miles of range. I have never worked on batteries before. When researching how to do so, I found this over-an-hour-long video [here]( https://www.youtube.com/watch?v=7QjO90LG67g), that clearly depicts and describes everything required to safely build a reliable battery pack.

I will need access to a spot welder to complete this - we’ve reached out to Illini Solar Car, as they have claimed the spot welder on campus.

# 2021-02-18 - Battery Update

Received the pair of 6s4p batteries, along with battery building supplies such as a Smart BMS, nickel strips, fishpaper, 10 gauge wire, and more. Upon closer inspection, splitting the 6s4p pack into a 12s2p pack is difficult, as there is no leverage to remove the existing H-shaped nickel strips.

The pair of 6s4p packs take up a lot less space than I expected. It would be easier to make a 12s4p pack out of them instead, which will provide us the same power as I required from earlier at nearly 500 Whr. Additionally, I have gotten in contact with a coworker who has a battery spot welder I can use.

Once I have planned out the build and assembled the materials, we should be good to go to complete the battery.

# 2021-02-24 - Investigation acquiring RPM data from VESCs

I have done some investigating of the VESC hardware and software and discovered that you can query them for RPM telemetry data. This removes the need for us to develop RPM sensing
around the motorized wheels.

To accomplish this however, we may need to talk to each VESC individually. Having a dual VESC is convenient, but this may interfere with our ability to query data from them properly. Some dual VESCs have dual MCUs, other more recent designs have single MCUs as shown earlier in this journal.

# 2021-03-01 - Parts update

From further discussions about the issue of communicating to both VESCs individually or to a ‘master’ VESC to both, we have decided to go with a pair of single VESCs. For example, we could attach a CANBUS cable between the pair of VESCs in order to allow them to communicate with each other, or simply split two PPM signals to pass throttle information individually, among various other choices. In other words, the VESCs can work in tandem with one another or can be independent from each other.

I have assembled a significant portion of the board at this point, as seen here in this picture below:

![](parts_update.png)

Some issues:

- The motor pulley is scraping on the motor mount. This is an issue of tolerances, as the
motor mount I am using is 6mm wide and the Motor shaft has a tolerance of 6.2mm +-
0.5mm. In theory, we should have 0.2mm of space, but the margin of error was not in our
favor.
  ![](motor_pulley_scraping.png)
- The threads on the ends of the trucks are not deep enough. We need bearing spacers to
push the wheel out.
  ![](bearing_spacer.png)
  
  
