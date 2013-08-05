#!/usr/bin/python
# -*- coding: iso-8859-15 -*-

import Leap, sys, serial, time
 
# Liaison série avec la carte Arduino
ser = serial.Serial('/dev/ttyACM0', 115200)

class SampleListener(Leap.Listener):

    def on_init(self, controller):
        print "Leap Motion initialisé"

    def on_connect(self, controller):
        print "Leap Motion connecté"

    def on_disconnect(self, controller):
        print "Leap Motion déconnecté"

    def on_exit(self, controller):
        print "Sortie du programme Leap Delta"

    def on_frame(self, controller):
	# récupérer la photo d'informations en sortie du contrôleur
        frame = controller.frame()

        if not frame.hands.empty:
	    # récupérer la première main (une seule à utiliser
            hand = frame.hands[0]

            if not hand.fingers.empty:	
		position = hand.palm_position
		print "Position : %s %s %s" % (int(position.x),int(position.y),int(position.z))
		ser.write('X')
		ser.write(str(int(position.x)))
		ser.write('Y')
		ser.write(str(int(position.y)))
		ser.write('Z')
		ser.write(str(int(position.z)))

		#print "%s" % (ser.readline())

    def state_string(self, state):
        if state == Leap.Gesture.STATE_START:
            return "STATE_START"

        if state == Leap.Gesture.STATE_UPDATE:
            return "STATE_UPDATE"

        if state == Leap.Gesture.STATE_STOP:
            return "STATE_STOP"

        if state == Leap.Gesture.STATE_INVALID:
            return "STATE_INVALID"

def main():

    # Création de l'objet contrôleur Leap Motion et d'une instance du listener ci-dessus
    listener = SampleListener()
    controller = Leap.Controller()

    # Lier les deux ensemble
    controller.add_listener(listener)

   
    # Attente d'une pression de touche pour fermer le programme
    print "Presser une touche pour sortir..."
    sys.stdin.readline()

    # Enlever le lien avec le contrôleur à la fin
    controller.remove_listener(listener)


if __name__ == "__main__":
    main()
