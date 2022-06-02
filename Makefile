EX ?= ex1
target = "target/exercise/$(EX)"
run:
	@mkdir -p $(target)
	@\
	cd ./src/exercise/$(EX)/;\
	g++ main.cpp -o ../../../$(target)/main
	@$(target)/main