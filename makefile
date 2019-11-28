imagen.png: datos.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: clase32.cpp
	c++ clase32.cpp

clean:
	rm -rf a.out datos.dat imagen.png *~
