import numpy as np
import sys

def plus_ou_moins():
    print("Bienvenue dans le jeu de plus ou moins\n")
    cible = np.random.randint(0, 101)
    touche = False
    while not touche:
        try:
            propo = int(input("Veuillez saisir un nombre entre 0 et 100 : "))
            if propo < 0 or propo > 100:
                print("Non votre proposition doit être entre 0 et 100 \n")
            elif propo < cible:
                print("Plus \n")
            elif propo > cible:
                print("Moins \n")
            elif propo == cible:
                print("Gagné !")
                touche = True
        except (KeyboardInterrupt, ValueError):
            print("Vous êtes un lâche")
            break;

plus_ou_moins()