
COMMON_OBJ = ../common/obj_all/core.o ../common/obj_all/socket.o ../common/obj_all/timer.o \
	../common/obj_all/db.o ../common/obj_all/plugins.o ../common/obj_all/lock.o \
	../common/obj_all/malloc.o ../common/obj_all/showmsg.o ../common/obj_all/utils.o \
	../common/obj_all/strlib.o ../common/obj_all/grfio.o \
	../common/obj_all/mapindex.o ../common/obj_all/ers.o
COMMON_H = ../common/core.h ../common/socket.h ../common/timer.h ../common/mmo.h \
	../common/version.h ../common/db.h ../common/plugins.h ../common/lock.h \
	../common/malloc.h ../common/showmsg.h ../common/utils.h \
	../common/strlib.h ../common/grfio.h \
	../common/mapindex.h ../common/ers.h

COMMON_SQL_OBJ = ../common/obj_sql/sql.o
COMMON_H = ../common/sql.h

CHAR_OBJ = obj_sql/char.o obj_sql/inter.o obj_sql/int_party.o obj_sql/int_guild.o \
	obj_sql/int_storage.o obj_sql/int_pet.o obj_sql/int_homun.o obj_sql/int_mail.o obj_sql/int_auction.o
CHAR_H = char.h inter.h int_party.h int_guild.h int_storage.h int_pet.h int_homun.h int_mail.h int_auction.h

HAVE_MYSQL=yes
ifeq ($(HAVE_MYSQL),yes)
	CHAR_SERVER_SQL_DEPENDS=obj_sql $(CHAR_OBJ) $(COMMON_OBJ) $(COMMON_SQL_OBJ)
else
	CHAR_SERVER_SQL_DEPENDS=needs_mysql
endif



#####################################################################
.PHONY : all char-server_sql clean help

all: char-server_sql

char-server_sql: $(CHAR_SERVER_SQL_DEPENDS)
	gcc  -L/usr/lib -o ../../char-server_sql.exe $(CHAR_OBJ) $(COMMON_OBJ) $(COMMON_SQL_OBJ) -lm -lz  -L/usr/local/lib/mysql -lmysqlclient -lz -lcrypt -lm

clean:
	rm -rf *.o obj_sql ../../char-server_sql.exe

help:
	@echo "possible targets are 'char-server_sql' 'all' 'clean' 'help'"
	@echo "'char-server_sql'  - char server (SQL version)"
	@echo "'all'              - builds all above targets"
	@echo "'clean'            - cleans builds and objects"
	@echo "'help'             - outputs this message"

#####################################################################

needs_mysql:
	@echo "MySQL not found or disabled by the configure script"
	@exit 1

obj_sql:
	-mkdir obj_sql

obj_sql/%.o: %.c $(CHAR_H) $(COMMON_H) $(COMMON_SQL_H)
	gcc -g -O2 -pipe -ffast-math -Wall -Wno-sign-compare -Wno-unused-parameter -Wno-switch -I/usr/local/include/mysql  -I../common -I/usr/include -DFD_SETSIZE=4096 -DCYGWIN -c $(OUTPUT_OPTION) $<

# missing common object files
../common/obj_all/%.o:
	@$(MAKE) -C ../common sql

../common/obj_sql/%.o:
	@$(MAKE) -C ../common sql
