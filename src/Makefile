CC      = g++
#PROF    = -p

#Uncomment to compile in Cygwin
#CYGWIN = -DCYGWIN

#Uncomment the line below if you are getting undefined references to dlsym, dlopen, and dlclose.
#Comment it out if you get errors about ldl not being found.
NEED_DL = -ldl

#Some systems need this for dynamic linking to work.
EXPORT_SYMBOLS = -export-dynamic

# Uncomment the two lines below if compiling on a Solaris box
#SOLARIS_FLAG = -Dsun -DSYSV
#SOLARIS_LINK = -lnsl -lsocket

#IMC2 - Comment out to disable IMC2 support
#IMC = 1

W_FLAGS = -std=c++1z -Wall -Wshadow -Wformat-security -Wpointer-arith -Wcast-align -Wredundant-decls

C_FLAGS = -g2 $(W_FLAGS) $(SOLARIS_FLAG) $(PROF) $(EXPORT_SYMBOLS)
L_FLAGS = $(PROF) $(SOLARIS_LINK) -lz $(NEED_DL)
#D_FLAGS : For the DNS Slave process. No need in linking all the extra libs for this.
D_FLAGS = -g2 -O $(PROF) $(SOLARIS_LINK)

C_FILES = act_comm.c act_info.c act_move.c act_obj.c act_wiz.c ban.c boards.c \
          build.c calendar.c chess.c clans.c color.c comm.c comments.c const.c db.c deity.c \
          dns.c fight.c handler.c hashstr.c hint.c hotboot.c house.c imm_host.c interp.c \
          liquids.c magic.c makeobjs.c mapout.c mapper.c mccp.c \
          misc.c mpxset.c mssp.c mud_comm.c mud_prog.c news.c planes.c player.c polymorph.c protocol.c \
          renumber.c reset.c save.c services.c sha256.c shops.c skills.c special.c tables.c \
          track.c update.c variables.c weather.c

ifdef IMC
   C_FILES := imc.c $(C_FILES)
   C_FLAGS := $(C_FLAGS) -DIMC -DIMCSMAUG
endif

O_FILES := $(patsubst %.c,o/%.o,$(C_FILES))

H_FILES = $(wildcard *.h) 

all:
	$(MAKE) -s sagas
	$(MAKE) -s dns

# pull in dependency info for *existing* .o files
-include dependencies.d

ifdef CYGWIN
sagas: $(O_FILES)
	rm -f sagas.exe
	dlltool --export-all --output-def sagas.def $(O_FILES)
	dlltool --dllname sagas.exe --output-exp sagas.exp --def sagas.def
	$(CC) -o sagas.exe $(O_FILES) sagas.exp $(L_FLAGS)
	@echo "Generating dependency file ...";
	@$(CC) -MM $(C_FLAGS) $(C_FILES) > dependencies.d
	@perl -pi -e 's.^([a-z]).o/$$1.g' dependencies.d
	@echo "Done compiling mud.";
	chmod g+w sagas.exe
	chmod a+x sagas.exe
	chmod g+w $(O_FILES)

clean:
	@rm -f o/*.o sagas.exe dependencies.d resolver.exe resolver.o *~

else
sagas: $(O_FILES)
	rm -f sagas
	$(CC) -export-dynamic -o sagas $(O_FILES) $(L_FLAGS)
	@echo "Generating dependency file ...";
	@$(CC) -MM $(C_FLAGS) $(C_FILES) > dependencies.d
	@perl -pi -e 's.^([a-z]).o/$$1.g' dependencies.d
	@echo "Done compiling mud.";
	chmod g+w sagas
	chmod a+x sagas
	chmod g+w $(O_FILES)
	chmod 755 startup
	chmod g+w startup

clean:
	@rm -f o/*.o sagas dependencies.d resolver resolver.o *~
endif

dns: resolver.o
	rm -f resolver
	$(CC) $(D_FLAGS) -o resolver resolver.o
	@echo "Done compiling DNS resolver.";
	chmod g+w resolver
	chmod a+x resolver
	chmod g+w resolver.o

indent:
	indent -ts3 -nut -nsaf -nsai -nsaw -npcs -npsl -ncs -nbc -bls -prs -bap -cbi0 -cli3 -bli0 -l125 -lp -i3 -cdb -c1 -cd1 -sc -pmt $(C_FILES)
	indent -ts3 -nut -nsaf -nsai -nsaw -npcs -npsl -ncs -nbc -bls -prs -bap -cbi0 -cli3 -bli0 -l125 -lp -i3 -cdb -c1 -cd1 -sc -pmt $(H_FILES)

indentclean:
	rm *.c~ *.h~

o/%.o: %.c
	echo "  Compiling $@....";
	$(CC) -c $(C_FLAGS) $< -o $@

.c.o: mud.h
	$(CC) -c $(C_FLAGS) $<
