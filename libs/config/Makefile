DOKUDIR=config
DOKUPATH="../../doku/quellcode/$(DOKUDIR)"
DOKUWEBPATH="/var/www/Doku/mrsystem/quellcode/$(DOKUDIR)"
TARGET=libmrconfig.a
OBJS=cfg_create.o cfg_destroy.o cfg_init.o cfg_exit.o cfg_read.o cfg_cmdline.o cfg_gint.o cfg_sint.o cfg_gstr.o cfg_sstr.o

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $<

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rvs $@ $+
	cp $@  $(LIB_PATH)
	cp config.h $(INCLUDE_PATH)

cfg_create.o: cfg_create.c config.h

cfg_destroy.o: cfg_destroy.c config.h

cfg_init.o: cfg_init.c config.h cfg_intern.h

cfg_exit.o: cfg_exit.c config.h

cfg_read.o: cfg_read.c config.h

cfg_cmdline.o: cfg_cmdline.c config.h

cfg_gint.o: cfg_gint.c config.h cfg_intern.h

cfg_sint.o: cfg_sint.c config.h cfg_intern.h

cfg_gstr.o: cfg_gstr.c config.h cfg_intern.h

cfg_sstr.o: cfg_sstr.c config.h cfg_intern.h

doku:
	if [ ! -d $(DOKUPATH) ] ; then mkdir $(DOKUPATH) ; fi
	doxygen Doxyfile

install_web:
	if [ ! -d $(DOKUWEBPATH) ] ; then mkdir $(DOKUWEBPATH) ; fi
	if [ ! -d $(DOKUWEBPATH)/search ] ; then mkdir $(DOKUWEBPATH)/search ; fi
	find $(DOKUPATH) -type f -maxdepth 0 -exec install -m 644 -D "{}" $(DOKUWEBPATH) ";"
	find $(DOKUPATH)/search -type f -maxdepth 0 -exec install -m 644 -D "{}" $(DOKUWEBPATH)/search ";"

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f $(INCLUDE_PATH)/config.h
	rm -f $(LIB_PATH)/$(TARGET)

clean_doku:
	if [ -d $(DOKUPATH) ] ; then rm -r $(DOKUPATH) ; fi
