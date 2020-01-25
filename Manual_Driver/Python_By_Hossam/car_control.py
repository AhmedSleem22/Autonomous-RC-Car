import pygame
import Jetson.GPIO as GPIO
import cv2
import xlwt
from xlwt import Workbook
#**************************initializations
pygame.init()
pygame.joystick.init()

#GPIO pins
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT, initial=GPIO.HIGH)   #MIN speed
GPIO.setup(11, GPIO.OUT, initial=GPIO.HIGH)   #MAX speed
GPIO.setup(7, GPIO.OUT, initial=GPIO.HIGH)    #Forward
GPIO.setup(13, GPIO.OUT, initial=GPIO.HIGH)   #Right
GPIO.setup(15, GPIO.OUT, initial=GPIO.HIGH)   #Left

OUT_ARR=[]                                  #output data
OUT_F = GPIO.HIGH                           #output data of forward button
OUT_R = GPIO.HIGH                           #output data of right button
OUT_L = GPIO.HIGH                           #output data of left button
OUT_S = GPIO.HIGH                           #output data of speed

#camera
cap = cv2.VideoCapture(1)

# Workbook is created
wb = Workbook()
# add_sheet is used to create sheet.
sheet1 = wb.add_sheet('Sheet 1')

#counter for multiple pictures
i = 1

#**************creating object to be the ID of joystick

controller = None
while controller is None:
    try:
        #try to detect controller
        controller = pygame.joystick.Joystick(0)
    except:
        pass

#**********************initiate controller
controller.init()
print("controller initiated with name ",controller.get_name())

#object for continue or stop playing
play = True

#*********************** the code for ps3
try:
    while play:
        #get a picture from the camera
        ret, frame = cap.read()
        frame = cv2.flip(frame,1)
        #cv2.waitKey(20)
        #clock.tick(60)


        #check for event from joystick
        OUT_ARR= [OUT_L , OUT_F , OUT_R , OUT_S] #output data
        print(OUT_ARR)

        cv2.imwrite('burst'+str(i)+'.png',frame) #save screenshot as burst.png

        #write data on excel sheet
        sheet1.write(i, 0, 'burst'+str(i)+'.png')
        sheet1.write(i, 1, '{}'.format(OUT_L))
        sheet1.write(i, 2,'{}'.format(OUT_F))
        sheet1.write(i, 3,'{}'.format(OUT_R))
        #sheet1.write(i, 4,'{}'.format(OUT_L))

        i=i+1       #updating the counter for next picture

        for event in pygame.event.get():

            #check to quit the screen
            if event.type == pygame.QUIT:
                print("exiting")
                play = False
                pygame.quit()
                sys.exit()
                break

            #check if the button pressed
            elif event.type == pygame.JOYBUTTONDOWN:
            # button is pressed

            #check for speed
                if event.button==10:
                    OUT_S=GPIO.HIGH

            #check for speed
                if event.button==10:
                    OUT_S=GPIO.HIGH
                    #L1 is pressed
                    print("L1 'maximum speed'")
                    GPIO.output(11, GPIO.LOW)


                elif event.button==11:
                    #R1 is pressed
                    OUT_S=GPIO.LOW
                    print("R1 'low speed'")
                    GPIO.output(12, GPIO.LOW)

        #check for directions
                elif event.button==4:
                    #Forward is pressed
                    print("Forward ")
                    OUT_F=GPIO.LOW
                    GPIO.output(7, GPIO.LOW)

                elif event.button==5:
                    #Right is pressed
                    print("Right")
                    OUT_R=GPIO.LOW
                    GPIO.output(13, GPIO.LOW)

                elif event.button==6:
                    #backward is pressed
                    print("Backward ")


                elif event.button==7:
                    #Left is pressed
                    print("Left ")
                    OUT_L=GPIO.LOW
                    GPIO.output(15, GPIO.LOW)

         #check for exitting
                elif event.button==3:
                    #START is pressed
                    #All pins are high
                    GPIO.output(15, GPIO.HIGH)
                    GPIO.output(7, GPIO.HIGH)
                    GPIO.output(13, GPIO.HIGH)
                    GPIO.output(12, GPIO.HIGH)
                    GPIO.output(11, GPIO.HIGH)
                    play = False
                    cap.release() #release the camera
                    #writer.release()
                    cv2.destroyAllWindows()
                    wb.save('xlwt example.xls')  #save the sheet
                    break

         #check for directions (only works on another driver for the Joystick)
            elif event.type == pygame.JOYHATMOTION:
                #hat is moved
                print ("hat is moved  horizontal by ",event.value[0]," 'and vertical by ",event.value[1])
                if event.value[0] == 1 :
                    print("Right")
                if event.value[0] == -1 :
                    print("Left")
                if event.value[1] == 1 :
                    print("Forward")
                if event.value[1] == -1 :
                    print("Backward")
                if (event.value[0] == 0 and event.value[1] == 0):
                    print("Stop")

            #check for releasing a button
            elif event.type == pygame.JOYBUTTONUP:
                #button is released
                GPIO.output(11, GPIO.HIGH)
                GPIO.output(12, GPIO.HIGH)

        #check for directions
                if event.button==4:
                    #Forward is pressed
                    GPIO.output(7, GPIO.HIGH)
                    OUT_F=GPIO.HIGH
                    print("F R")

                elif event.button==5:
                    #Right is pressed
                    print("R R")
                    OUT_R=GPIO.HIGH
                    GPIO.output(13, GPIO.HIGH)

                elif event.button==7:
                    #Left is pressed
                    GPIO.output(15, GPIO.HIGH)
                    OUT_L=GPIO.HIGH
                    print("L R")

finally:
    print("EXIT")
    GPIO.cleanup()
    cap.release()
    cv2.destroyAllWindows()
