# to do list

- [x] vasics
- [x] tokenizer 1st stage
	- [x] sintax error 1st
	- [x] lexer
	- [x] sintax error 2nd
	- [x] expanions
- [ ] executer 1st stage
	- [x] preparation
	- [ ] here documents <-- gasroman
	- [ ] piping <-- tatahere
	- [ ] redirection
	- [ ] execution <-- tatahere
- [x] enviroment
- [ ] builtins
- [ ] signal handeling

small todo list
- [x] do research on the pipex
- [x] modify the pipes front and back to be on the redirections
- [ ] do the executor
	- [x] general functions
		- [x] find if it is a builtin or a command
		- [x] find the path of the command
			- [x] manage errors
				- [x] manage the errors of no filename arg
				- [x] manage the error of no permision cmd
				- [x] manage the error of no file or dir
				- [x] manage the error of no cmd
			- [x] manage outputs
				- [x] relative paths (./ls or /dev/ls or ls)
				- [x] commands throught the path env

	- [ ] execute simple commands (no pipes)
		- [ ] execv command
			- [x] recive the only the coresponding input no more memory elsewere
			- [x] whait for the child to finish
			- [x] find the program and exeve it
				- [x] manage the diferent error from pathfinder
				- [x] add to the enviroment module the env get env:
		- [x] execv builtin
	- [ ] execute pipes
		- [ ] piper
		- [ ] execv builtin
