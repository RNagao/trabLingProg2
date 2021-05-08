CPP = g++
CPPFLAGS = -Wall

TRABALHO2OBJS = main.o grafo.o aresta.o vertice.o

trabalho2: $(TRABALHO2OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(TRABALHO2OBJS)