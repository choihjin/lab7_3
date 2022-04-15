CFLAGS = -W -Wall
TARGET = product
DTARGET = product_debug
OBJECTS = main.c product.c manager.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	gcc $(CFLAGS) -DDEBUG -o $@ $^
clean: 
	rm *.o
	rm product product_debug
