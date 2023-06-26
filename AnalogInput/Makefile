#
#INCLUDE_DIR = /usr/src/linux/include

build:
	mkdir -p target
	gcc -o ./target/analog_input analog_input.c -lcaio

run:
	mkdir -p target
	gcc -o ./target/analog_input analog_input.c -lcaio
	./target/analog_input

clean:
	rm -rf ./target 
