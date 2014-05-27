all :
	sudo apt-get install freeglut3-dev
	cc main.c -lGL -lm -lGLU -lglut
	./a.out

clean:
	rm *.out
