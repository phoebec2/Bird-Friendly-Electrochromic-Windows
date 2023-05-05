# Object Classification Subsystem Code (needs organizing)
# by Phoebe Chen

#!/usr/bin/env python
import code

import sys
import numpy as np
import cv2
from pylepton import Lepton
from PIL import Image as im
from gpiozero import LED, Button
import time

#Global Constants
IMAGE_HEIGHT = 60
IMAGE_WIDTH = 80

#Temperature (C) Range of Blob
TEMP_MIN = 30
TEMP_MAX = 44

#Blob's Bounding Box Size Threshold
MIN_BOX_SIZE = 10

#Input GPIO Pins
interrupt_pin = Button(16)
interrupt_pin.when_pressed = interruptHandler
block1_input_pin = Button(20)
block2_input_pin = Button(21)
block3_input_pin = Button(19)
block4_input_pin = Button(26)

#Output GPIO Pins
block1_pin = LED(15)
block2_pin = LED(18)
block3_pin = LED(5)
block4_pin = LED(6)

#Interrupt Variables
object_detected = False
check_block1 = False
check_block2 = False
check_block3 = False
check_block4 = False

#Lepton Device
device = "/dev/spidev0.0"

def interruptHandler():
  global check_block1  
  global check_block2  
  global check_block3 
  global check_block4  
  global object_detected 
  check_block1 = block1_input_pin.is_pressed
  check_block2 = block1_input_pin.is_pressed
  check_block3 = block1_input_pin.is_pressed
  check_block4 = block1_input_pin.is_pressed
  object_detected = True
  print("Object Detected!")

# #Warm Object Tracker Object
# tracker = cv2.legacy.TrackerKCF_create()

def centiKelvintoCelsius(image_data):
  return image_data*1.0/100 - 273.15

def classifyDetectedObject(first_block = False, second_block = False, third_block = False, fourth_block = False):
  block1_pin.off()
  block2_pin.off()
  block3_pin.off()
  block4_pin.off()
  
  with Lepton(device) as l:
    a,_ = l.capture()

  a_C = a*1.0/100#centiKelvintoCelsius(a)
  a_C_im = np.uint8(a_C)
  ret, a_C_thres = cv2.threshold(a_C_im,81.5,255,cv2.THRESH_BINARY)
  cv2.imwrite('threshold_image.png',a_C_thres)

  for i in range(60):
    a[i,43,0] = (a[i,42,0]+a[i,44,0])*1.0/2
    a[i,78,0] = (a[i,77,0]+a[i,79,0])*1.0/2
  cv2.normalize(a, a, 0, 65535, cv2.NORM_MINMAX)
  np.right_shift(a, 8, a)
  a_im = np.uint8(a)
  print(a_im.shape)

  # *Note: apparently column 43 is always a white vertical line for some unknown reason
  for i in range(60):
    if a_C_thres[i,42] == 255 and a_C_thres[i,44] == 255:
      a_C_thres[i,43] = 255
    else:
      a_C_thres[i,43] = 0
    if a_C_thres[i,77] == 255 and a_C_thres[i,79] == 255:
      a_C_thres[i,78] = 255
    else:
      a_C_thres[i,78] = 0
    
  #Detecting warm objects with the right size
  contours_C, _ = cv2.findContours(a_C_thres,cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
  num_warm_objects = 0
  for blob in contours_C:
    x,y,w,h = cv2.boundingRect(blob)
    if w < 10 or h < 10:
      continue
    num_warm_objects += 1
    warmObject = blob
  
  if num_warm_objects != 1:
    print("Error:",num_warm_objects,"warm objects detected/classified")
    return False 

  #Matching detected warm object's location
  x,y,w,h = cv2.boundingRect(warmObject)
  matched = False
  in_first_block = False
  in_second_block = False
  in_third_block = False
  in_fourth_block = False
  for point in warmObject:
    if point[0][0] < IMAGE_WIDTH/2:
      if point[0][1] < IMAGE_HEIGHT/2:
        in_first_block = True
        if first_block:
          matched = True
        else:
          matched = False
          break
      else:
        in_third_block = True
        if third_block:
          matched = True
        else:
          matched = False
          break
    else:
      if point[0][1] < IMAGE_HEIGHT/2:
        in_second_block = True
        if second_block:
          matched = True
        else:
          matched = False
          break
      else:
        in_fourth_block = True
        if fourth_block:
          matched = True
        else:
          matched = False
          break

  if matched:
    print("Indicated object is warm-blooded")
    if in_first_block:
      print("In First Block")
      block1_pin.on()
    if in_second_block:
      print("In Second Block")
      block2_pin.on()
    if in_third_block:
      print("In Third Block")
      block3_pin.on()
    if in_fourth_block:
      print("In Fourth Block")
      block4_pin.on()
    #Either start tracking or stop tracking warm-blooded object
    #Remember to update the electrochromic window control outputs
    tracker.init(a_im,(x,y,w,h))
    print((x,y,x+w,y+h))
    cv2.rectangle(a_im,(x,y),(x+w,y+h),(0,255,0),1)
    cv2.drawContours(a_im,[warmObject],-1,(0,255,0),1)
  else:
    print("Either the indicated object is not warm-blooded, or a warm-blooded object is detected somewhere else/not specified")
  # cv2.rectangle(a_C_im,(x,y),(x+w,y+h),(0,255,0),1)

  # a_C_im_blobs = a_C_im
  # cv2.drawContours(a_C_im_blobs,blobs_C,-1,(0,255,0),1)
  # cv2.imwrite('right-sized-blobs.png',a_C_im_blobs)

  # cv2.drawContours(a_C_im,contours_C,-1,(0,255,0),1)
  # cv2.imwrite('image_coooont.jpg',a_C_im) 
  
  cv2.imwrite('final_image.jpg',a_im)
  print("end")
  return matched 

def trackWarmObject():
  print("loop")

  with Lepton(device) as l:
    a,_ = l.capture()

  a_C = a*1.0/100#centiKelvintoCelsius(a)
  a_C_im = np.uint8(a_C)
  ret, a_C_thres = cv2.threshold(a_C_im,81.5,255,cv2.THRESH_BINARY)
  cv2.imwrite('threshold_image.png',a_C_thres)

  for i in range(60):
    a[i,43,0] = (a[i,42,0]+a[i,44,0])*1.0/2
    a[i,78,0] = (a[i,77,0]+a[i,79,0])*1.0/2
  cv2.normalize(a, a, 0, 65535, cv2.NORM_MINMAX)
  np.right_shift(a, 8, a)
  a_im = np.uint8(a)
  print(a_im.shape)

  # *Note: apparently column 43 is always a white vertical line for some unknown reason
  for i in range(60):
    if a_C_thres[i,42] == 255 and a_C_thres[i,44] == 255:
      a_C_thres[i,43] = 255
    else:
      a_C_thres[i,43] = 0
    if a_C_thres[i,77] == 255 and a_C_thres[i,79] == 255:
      a_C_thres[i,78] = 255
    else:
      a_C_thres[i,78] = 0
    
  #Detecting warm objects with the right size
  contours_C, _ = cv2.findContours(a_C_thres,cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
  num_warm_objects = 0
  for blob in contours_C:
    x,y,w,h = cv2.boundingRect(blob)
    if w < 10 or h < 10:
      continue
    num_warm_objects += 1
    warmObject = blob
  
  if num_warm_objects == 0:
    print("Error:",num_warm_objects,"warm objects detected/classified")
    block1_pin.off()
    block2_pin.off()
    block3_pin.off()
    block4_pin.off()
    return
  elif num_warm_objects > 1:
    print("Error:",num_warm_objects,"warm objects detected/classified")
    # block1_pin.off()
    # block2_pin.off()
    # block3_pin.off()
    # block4_pin.off()
    return

  #Matching detected warm object's location
  x,y,w,h = cv2.boundingRect(warmObject)
  matched = False
  in_first_block = False
  in_second_block = False
  in_third_block = False
  in_fourth_block = False
  for point in warmObject:
    if point[0][0] < IMAGE_WIDTH/2:
      if point[0][1] < IMAGE_HEIGHT/2:
        in_first_block = True
      else:
        in_third_block = True
    else:
      if point[0][1] < IMAGE_HEIGHT/2:
        in_second_block = True
      else:
        in_fourth_block = True

  if in_first_block:
    print("In First Block")
    block1_pin.on()
  else:
    block1_pin.off()
  if in_second_block:
    print("In Second Block")
    block2_pin.on()
  else:
    block2_pin.off()
  if in_third_block:
    print("In Third Block")
    block3_pin.on()
  else:
    block3_pin.off()
  if in_fourth_block:
    print("In Fourth Block")
    block4_pin.on()
  else:
    block4_pin.off()
    #Either start tracking or stop tracking warm-blooded object
    #Remember to update the electrochromic window control outputs
  print((x,y,x+w,y+h))
  cv2.rectangle(a_im,(x,y),(x+w,y+h),(0,255,0),1)
  cv2.drawContours(a_im,[warmObject],-1,(0,255,0),1)
  cv2.imshow("Tracking",a_im)

def capture(flip_v = False, device = "/dev/spidev0.0"):
  global object_detected  
  global check_block1  
  global check_block2  
  global check_block3  
  global check_block4  
  object_detected = False
  check_block1 = False
  check_block2 = False
  check_block3 = False
  check_block4 = False
  
  warm_object_inside = False
  while(True):
    if object_detected:
      isWarm = classifyDetectedObject(True,True,True,True)#first_block = check_block1, second_block = check_block2, third_block = check_block3, fourth_block = check_block4)
      print("Done classifying")
      if isWarm:
        if not warm_object_inside:
          warm_object_inside = True
          print("Initiating tracking...")
        else:
          warm_object_inside = False
          block1_pin.off()
          block2_pin.off()
          block3_pin.off()
          block4_pin.off()
      object_detected = False
    if warm_object_inside:
      trackWarmObject()
  return NULL


if _name_ == '_main_':
  from optparse import OptionParser

  usage = "usage: %prog [options] output_file[.format]"
  parser = OptionParser(usage=usage)

  parser.add_option("-f", "--flip-vertical",
                    action="store_true", dest="flip_v", default=False,
                    help="flip the output image vertically")

  parser.add_option("-d", "--device",
                    dest="device", default="/dev/spidev0.0",
                    help="specify the spi device node (might be /dev/spidev0.1 on a newer device)")

  (options, args) = parser.parse_args()

  if len(args) < 1:
    print("You must specify an output filename")
    sys.exit(1)

  image = capture(flip_v = options.flip_v, device = options.device)
  cv2.imwrite(args[0], image)
