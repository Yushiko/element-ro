
COMMON_OBJ = ../common/obj_all/core.o ../common/obj_all/socket.o ../common/obj_all/timer.o \
	../common/obj_all/db.o ../common/obj_all/plugins.o ../common/obj_all/lock.o \
	../common/obj_all/malloc.o ../common/obj_all/showmsg.o ../common/obj_all/utils.o \
	../common/obj_all/strlib.o ../common/obj_all/grfio.o ../common/obj_all/mapindex.o \
	../common/obj_all/ers.o ../common/obj_all/md5calc.o ../common/obj_sql/sql.o 
COMMON_H = ../common/core.h ../common/socket.h ../common/timer.h ../common/mmo.h \
	../common/version.h ../common/db.h ../common/plugins.h ../common/lock.h \
	../common/malloc.h ../common/showmsg.h ../common/utils.h ../common/strlib.h \
	../common/grfio.h ../common/mapindex.h \
	../common/ers.h ../common/md5calc.h ../common/sql.h 

LOGIN_OBJ = obj_sql/login.o
LOGIN_H = login.h

HAVE_MYSQL=yes
ifeq ($(HAVE_MYSQL),yes)
	LOGIN_SERVER_SQL_DEPENDS=obj_sql $(LOGIN_OBJ) $(COMMON_OBJ)
else
	LOGIN_SERVER_SQL_DEPENDS=needs_mysql
endif



#####################################################################
.PHONY : all login-server_sql clean help

all: login-server_sql

login-server_sql: $(LOGIN_SERVER_SQL_DEPENDS)
	gcc  -L/usr/lib -o ../../login-server_sql.exe $(LOGIN_OBJ) $(COMMON_OBJ) -lm -lz  -L/usr/local/lib/mysql -lmysqlclient -lz -lcrypt -lm

clean:
	rm -rf *.o obj_sql ../../login-server_sql.exe

help:
	@echo "possible targets are 'login-server_sql' 'all' 'clean' 'help'"
	@echo "'login-server_sql'  - login server (SQL version)"
	@echo "'all'               - builds all above targets"
	@echo "'clean'             - cleans builds and objects"
	@echo "'help'              - outputs this message"

#####################################################################

needs_mysql:
	@echo "MySQL not found or disabled by the configure script"
	@exit 1

obj_sql:
	-mkdir obj_sql

obj_sql/%.o: %.c $(LOGIN_H) $(COMMON_H)
	gcc -g -O2 -pipe -ffast-math -Wall -Wno-sign-compare -Wno-unused-parameter -Wno-switch -I/usr/local/include/mysql  -I../common -I/usr/include -DFD_SETSIZE=4096 -DCYGWIN -c $(OUTPUT_OPTION) $<

# missing common object files
../common/obj_all/%.o:
	@$(MAKE) -C ../common sql

../common/obj_sql/%.o:
	@$(MAKE) -C ../common sql
