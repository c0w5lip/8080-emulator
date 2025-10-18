# 8080-emulator
Intel 8080 emulator written in ANSI C, for learning purposes.

Cross platform, uses SDL2 for graphics.


⚠️ Project under development. Some functions still need to be implemented, as well as IO and graphics rendering.


## About the Intel 8080

8-bit microprocessor from 1974, and the first to be used in arcade machines! (Gun Fight)

![](https://upload.wikimedia.org/wikipedia/commons/thumb/a/ac/Intel_8080_open-closed.jpg/1280px-Intel_8080_open-closed.jpg)

https://en.wikipedia.org/wiki/Intel_8080

[Arcade machines & games using the 8080](https://www.system16.com/list.php?type=h&search=8080)


## TODO

- Implement missing instructions
- Implement IO operations
- Implement graphics rendering

- For each operation with a condition (e.g CNC), cancel the increment of PC if the condition is met

## Ressources used

[Instruction set table](https://pastraiser.com/cpu/i8080/i8080_opcodes.html)

[Small cheatsheet](http://dunfield.classiccmp.org/r/8080.txt)

[Assembly Language Programming (8085)](https://pravin-hub-rgb.github.io/BCA/resources/sem4/micro_tbc402/unit4/index.html) for a deeper understanding of related instructions, though the ISA is slightly different.
