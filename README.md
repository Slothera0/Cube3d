# Cub3d

Projet graphique de 42 inspiré du jeu "Doom" dont le but est de créer un labyrinthe en pseudo 3d.

Ce projet étant fait en binôme il se découpe en 2 parties, le parse et le rend dont je me suis occupé.

## Parse

Lis la map donné en entrée du programme pour vérifier que toutes les infos sont valides : pas de trou dans la map, les textures donné en arguments existent et sont lisibles...
Puis se charge de tout stocker dans une structure avant d'envoyer ces informations au rend.

## Rend

Gère les entrées du clavier pour les déplacement du personnage et crée le rendu graphique.
En utilisant des méthodes de raycasting, le programme va envoyer des rayons pour chaques colonnes de la fenêtre pour déterminer la distance avec chaques murs devant le joueur.
Ensuite en utilisantt la minilibx, une bibliothéque graphique donné pour le projet, on imprime les pixel sur la fenêtre grâce aux informations récolté dans le raycasting.
