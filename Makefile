ex ?= ex0001
target = "target/practice/$(ex)"
practice:
	@mkdir -p $(target)
	@\
	cd ./src/practice/$(ex)/;\
	g++ main.cpp -o ../../../$(target)/main
	@$(target)/main

ex ?= ex0001
target1 = "target/exercise/$(ex)"
exercise:
	@mkdir -p $(target1)
	@\
	cd ./src/exercise/$(ex)/;\
	g++ main.cpp -o ../../../$(target1)/main
	@$(target1)/main

