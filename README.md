# OOP-Farm-Ecology

## Description
This is a project implementing Object-oriented programming in C++ language.  
This project is to design a farm ecology. There are goat and grass in the farm. 
Grass will grow grass every day, and the grass will die when the time comes. When goat reach a certain age, 
they will give birth to lambs, and goat must eat grass to have energy to survive. If there is no energy, it will die.  

The three main characteristics of object orientation: encapsulation, inheritance, polytype.  
I use encapsulation in the function and variable declarations, so that the object can only modify the variables of the object through the implicit call. Because all creatures have a life cycle, I used the Creature object to let the goat and grass objects Inheritance. Finally, Polymorphism is used in the function call, and different functions are executed through different variables.  

The display of the farm is drawn through the linux terminal. Farms will be printed every fixed number of days until the specified number of days is reached.  

## Sample output
The sample output can see in data file.  
'I' represent grass and 'X' represent goat.  
![image](https://user-images.githubusercontent.com/48405514/208472449-d84f2c87-c5e9-413f-ad59-840ef6f6ed24.png)  

## Compile
Execute the Makefile
```
make clean  
make
```

## File description
```
． ALifeTest.cc has the main function that start the code.
． World.cc& World.h iterates over all locations in the farm every day.
． Creature.cc& Creature.h declare the object function.
． Goat.cc& Goat.h inherit the Creature object and declare the function about goat life.
． Grass.cc& Grass.h inherit the Creature object and declare the function about grass life.
． RandomNum.cc& RandomNum.h declare the function that return ramdom number.
```
