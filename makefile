CFLAGS = -g -Wall -o
LFLAGS = -lssl -lcrypto

text2shaLookup_v1:
	gcc $(CFLAGS) text2shaLookup_v1 text2shaLookup_v1.c $(LFLAGS)
text2shaLookup_v2:
	gcc $(CFLAGS) text2shaLookup_v2 text2shaLookup_v2.c $(LFLAGS)
clean:
	/bin/rm -f text2shaLookup_v1 text2shaLookup_v1 text2shaLookup_v2