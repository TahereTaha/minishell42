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
	- [ ] general functions
		- [x] find if it is a builtin or a command
		- [ ] find the path of the command
			- [ ] manage the errors of no filename arg
			- [ ] manage the error of no permision cmd
			- [ ] manage the error of no file or dir
			- [ ] manage the error of no cmd

	- [ ] execute simple commands (no pipes)
		- [ ] execv command
		- [ ] execv builtin
	- [ ] execute pipes
		- [ ] piper
		- [ ] execv command
		- [ ] execv builtin
