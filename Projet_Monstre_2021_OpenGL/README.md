# OpenGL - Projet CC 2021 - Jack Hogg

## Présentation

Ce projet a pour but de reproduire une version modifiée du gardien dans le jeu "Zelda : Breath of the wild" et de l'intégrer à un environnement.

J'ai donc fait le choix d'un sol de granite ainsi qu'un monstre brillant.

L'animation choisie a été Guybrush, vue en TP à l'université.

Les obstacles choisies sont des cartons, auxquels j'ai appliqué une texture, ainsi que des lampadaires.

Il se peut que le fichier "crate.ppm" déclenche un SEGFAULT, ayant testé sur un autre ordinateur. Il suffit d'exécuter à nouveau l'exécutable.

### Touches (Pour usage manuel)

**L'univers :**

>   TAB : Changer le contrôle de la caméra (Sujet/Univers/Scène)
>
>   Espace : Repositionner la caméra au point d'origine
>
>   Escape : Fermer la fenêtre
>
>   B ou b : Activer/Désactiver le blend
>
>   L ou l : Activer/Désactiver la lumière
>
>   Flèches directionnelles : Bouger la caméra
>
>   c ou C : Activer/Désactiver le culling 


**Touches des pattes :**

>   a : Pattes avant
>
>   z : Pattes centrales
>
>   e : Pattes arrières
>
>   r : Avancer
>
>   t : Pivoter à gauche
>
>   y : Pivoter à droite

**Touches des bras :**

>   q : lever le bras 1
>
>   s : lever le bras 2
>
>   d : lever le bras 3
>
>   f : lever le bras 4
>
>   g : lever le bras 5


>   Q : baisser le bras 1
>
>   S : baisser le bras 2
>
>   D : baisser le bras 3
>
>   F : baisser le bras 4
>
>   G : baisser le bras 5


### Contrôle automatique

ATTENTION : Pour le bon fonctionnement de l'animation, il faut désactiver et réactiver le blend avec la touche 'b' ou 'B'.

>   P (as in play...) : Démarre/Arrêt des déplacements de la réplique
>
>   p (as in play...) : Démarre/Arrêt de l'animation 


### Documentation code :

- angle_pattes_AD -> Patte avant-droit ;
- angle_pattes_AG -> Patte avant-gauche ;
- angle_pattes_CD -> Patte lattérale droite ;
- angle_pattes_CG -> Patte lattérale gauche ;
- angle_pattes_ARD -> Patte arrière-droit ;
- angle_pattes_ARG -> Patte arrière-gauche ;
- X_y : Avec X un des angles cités précédemment, le '_y' en plus gère la rotation sur l'axe des y (lever des pattes).

- xrot_objet / yrot_objet / zrot_objet : Rotation du sujet ;
- xrot_scene / yrot_scene / zrot_scene : Rotation de la scène ;
- xrot_camera / yrot_camera / zrot_camera : Rotation de la caméra ;
- z : Zoom.

- angle_tete : Rotation de la tête.

- angle_bras_X : Rotation du bras X ;
- bras_leve_X : Indique si le bras X est levée.

- diametre_univers : Diamètre de l'univers (le sol) sur lequel le monstre "voyagera".

- automatique : Booléen qui déclenche, ou non, les mouvements automatiques ;
- tourner : Indique au programme la direction à prendre lors d'une rotation (Gauche ou droite) ;
- culling : Booléen qui indique si le culling est activé ou non ;
- anim : Booléen qui indique si l'animation est activée ou non.

- texture[] : Tableau des textures.