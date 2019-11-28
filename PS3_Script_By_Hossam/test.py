import pygame

#**************************initializations
pygame.init()
pygame.joystick.init()


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

#*********************open a screen to display values
screen = pygame.display.set_mode((640,480))
pygame.display.set_caption("pygame code")

#*********************setting background color
back = pygame.Surface(screen.get_size())
back = back.convert()
back.fill((255, 255, 255))

#setting clock
#clock = pygame.time.Clock()

#*********************** the code for ps3
while play:
    #clock.tick(60)
    #check for event from joystick
    for event in pygame.event.get():

        #check to quit the screen
        if event.type == pygame.QUIT:
            print("exiting")
            play = False
            pygame.quit()
            break

         #check if the button pressed   
        elif event.type == pygame.JOYBUTTONDOWN:
            # button is pressed
            
            if event.button == 9:
                #right analog is pressed
                print("RA")
                back.fill((0, 0, 255))  #change color
                
            elif event.button==0:
                #X is pressed
                print("X")
                back.fill((255, 0, 0)) #change color

            elif event.button==1:
                #O is pressed
                print("O")
                back.fill((0, 255, 0))    #change color

            elif event.button==2:
                #square is pressed
                print("Sq")
                back.fill((255, 255, 0)) #change color

            elif event.button==3:
                #tri is pressed
                print("tri")
                back.fill((255, 0, 255))    #change color

            elif event.button==4:
                #L1 is pressed
                print("L1")
                back.fill((255, 0, 0)) #change color

            elif event.button==5:
                #R1 is pressed
                print("R1")
                back.fill((0, 255, 255)) #change color

        #check for directions 
        elif event.type == pygame.JOYHATMOTION:
            #hat is moved      
            print ("hat is moved  horizontal by ",event.value[0]," 'and vertical by ",event.value[1])    

        #check for button release
        elif event.type == pygame.JOYBUTTONUP:
            #button is released
            back.fill((255, 255, 255))    #reset color to white

    screen.blit(back, (0, 0))
    pygame.display.flip()
    
