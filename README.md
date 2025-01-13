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
- [x] signal handeling
- [ ] trobleshoot the last details
	- [x] fix the heredoc
	- [x] add error handeling to all the dup and dup2
	- [x] make the cd builtin
	- [x] pass the norm on the last files
	- [ ] make sure nothing is wrong
		- [x] the pathfinder has a bug no relative executable
		- [x] manage the ^d in the heredoc
		- [x] check that enviroment variable don't start with numbers (the $. too )
		- [x] there is no need to manage the signals on execution
		- [x] exit with something that is bigger than long long not int

