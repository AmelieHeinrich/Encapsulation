# Exercice 1

## 1. Qu'est-ce que la programmation orientée objet (POO) ?

La programmation orientée objet est un paradigme où l'on va structurer les données en objet (classes, structures) afin de mieux les organiser.
La programmation orientée objet profite aussi du système de polymorphisme et de hiérarchie des classes qui permet de créer des interfaces ayant des méthodes/membres en commun, sans avoir besoin de réecrire une partie du code.

## 2. Quels sont les avantages de la POO par rapport à la programmation procédurale ?

Les avantages sont plus subjectifs qu'objectifs -- subjectivement, cela permet d'avoir une structure du code plus lisible et plus compréhensible.
Du point de vue performance, la programmation orientée objet à souvent été critiqué pour la génération plus lourde de machine code comparé à sa variante procédurale.

## 3. Décrivez les concepts clés de la POO en C++.

Abstraction: Représenter des données sous forme d'objet
Encapsulation: Garder des membres d'une classe privé et permettre la modification de ces dernières à l'aide de méthodes publiques (getter/setter)
Inheritance: Permet de partager des méthodes/membres entre classes
Polymorphisme: Quand une méthode d'une classe n'est pas défini (virtual functions) et qu'on peut l'override pour en définir son comportement

## 4. Expliquez ce qu'est une classe en C++.

Une classe en C++ est un concept qui permet de créer un type pour englober des données. On peut lui donner des méthodes (des fonctions appartenant a cette classe qui vont agir sur les membres de l'instance) et des membres qui sont des variables appartenant a l'instance de la classe.

## 5. Quelle est la différence entre une classe et un objet ?

Un objet est une variable dont le type est la classe. Un objet est un exemplaire d'une classe.

## 6. Qu'est-ce que l'encapsulation et pourquoi est-elle importante en POO ?

L'encapsulation est important en POO car elle permet de garder les attributes critiques d'une classe privé.

## 7. Comment accède-t-on aux attributs privés d'une classe ?

Elle sont accessible à l'intérieur des méthodes de la classe, ou en utilisant des getter/setter adaptés.

## 8. Quel est le rôle d'un constructeur en C++ ?

Le rôle d'un constructeur est d'initialiser la classe lorsque qu'une instance est déclaré.

## 9. Expliquez ce qu'est un destructeur et son rôle.

Un destructeur est appelé lorsque l'objet est détruit (mémoire libéré ou automatiquement libéré en fin de scope) et son but est de déinitialiser la classe et ses données.

## 10. Quelles sont les différentes formes d’héritage en C++ ?

- Classe mère
- Classe fille (dérive de classe mère)
