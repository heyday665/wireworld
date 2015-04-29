clean:
	@rm -rf a.out *.gch

good:
	@make clean    
	clang++ -Wall -Wextra wireworld.cpp
