# to do list

- [x] vasics
- [x] tokenizer 1st stage
	- [x] sintax error 1st
	- [x] lexer
	- [x] sintax error 2nd
	- [x] expanions
- [ ] executer 1st stage
	- [x] preparation
	- [x] here documents <-- gasroman
	- [x] piping <-- tatahere
	- [x] redirection
	- [x] execution <-- tatahere
- [x] enviroment
- [x] builtins
- [ ] signal handeling

small todo list
- [ ] make all the cases for the signals.
	- [ ] in all cases.
		- [ ] all signals recibed will write themself to the global variabl.
	- [ ] ^C.
		- [ ] interactive (you are inputing to the minishell not cat or grep.).
			- [ ] stop the readline input.
		- [ ] non interactive (waitng for stoping commands to finish).
			- [ ] ignore it.
	- [ ] ^\
		- [ ] interactive (you are inputing to the minishell not cat or grep.).
			- [] ignore it.
		- [ ] non interactive (waitng for stoping commands to finish).
			- [ ] ignore it.
	- [ ] after all readline interprets the g_signal and do
		- [ ] make the exit status 130 and continue to do the next command.
				on the prompt
		- [ ] make the exit status 130 and stop the heredoc from continuing.
	- [ ] after the wait_all_children interpret the g_signal and do
		- [ ] make the exit status 130 for ^c or 131 ^\
	
- [ ] 
