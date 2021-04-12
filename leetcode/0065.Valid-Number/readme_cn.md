# 1. deterministic finite automaton, DFA solution by SimonS
* 0 初始无输入或者只有space的状态
* 1 输入了数字之后的状态
* 2 前面无数字，只输入了dot的状态
* 3 输入了+/-状态
* 4 前面有数字和有dot的状态
* 5 'e' or 'E'输入后的状态
* 6 输入e之后输入+/-的状态
* 7 输入e后输入数字的状态
* 8 前面有有效数输入之后，输入space的状态

<img src="./DFA_solution.png"  width="600" />