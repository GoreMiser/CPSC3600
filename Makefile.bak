include Make.defines

PROGS =	 passwordBreaker passwordServer

OPTIONS = -DUNIX  -DUSE_SIGACTION -DANSI


COBJECTS =	DieWithError.o 
CSOURCES =	DieWithError.c 

CPLUSOBJECTS = 

COMMONSOURCES =

CPLUSSOURCES =

all:	${PROGS}


passwordBreaker:	client.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(COMMONSOURCES) $(SOURCES)
		${CC} ${LINKOPTIONS}  $@ client.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(LINKFLAGS)


passwordServer:		server.o $(CPLUSOBJECTS) $(COBJECTS)
		${CC} ${LINKOPTIONS} $@ server.o $(CPLUSOBJECTS) $(COBJECTS) $(LIBS) $(LINKFLAGS)


.cc.o:	$(HEADERS)
	$(CPLUS) $(CPLUSFLAGS) $(OPTIONS) $<

.c.o:	$(HEADERS)
	$(CC) $(CFLAGS) $(OPTIONS) $<



backup:
	rm -f password.tar.gz
	tar -cf password.tar *
	gzip -f password.tar

clean:
		rm -f ${PROGS} ${CLEANFILES}

depend:
		makedepend client.c server.c -I/usr/lib/gcc/x86_64-linux-gnu/4.6/include $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)
#		mkdep $(CFLAGS) $(HEADERS) $(SOURCES) $(COMMONSOURCES) $(CSOURCES)

# DO NOT DELETE

client.o: UDPIncludes.h /usr/include/stdio.h /usr/include/features.h
client.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
client.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
client.o: /usr/include/gnu/stubs-64.h
client.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
client.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
client.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
client.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
client.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
client.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
client.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
client.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
client.o: /usr/include/sys/types.h /usr/include/time.h
client.o: /usr/include/sys/select.h /usr/include/bits/select.h
client.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
client.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
client.o: /usr/include/alloca.h /usr/include/errno.h
client.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
client.o: /usr/include/asm/errno.h /usr/include/asm-generic/errno.h
client.o: /usr/include/asm-generic/errno-base.h /usr/include/string.h
client.o: /usr/include/xlocale.h /usr/include/netinet/in.h
client.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint.h
client.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint-gcc.h
client.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
client.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
client.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
client.o: /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h
client.o: /usr/include/asm-generic/sockios.h /usr/include/bits/in.h
client.o: /usr/include/arpa/inet.h /usr/include/netdb.h
client.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
client.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
client.o: /usr/include/bits/environments.h /usr/include/bits/confname.h
client.o: /usr/include/getopt.h /usr/include/signal.h
client.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
client.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
client.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
client.o: /usr/include/bits/sigthread.h
server.o: UDPIncludes.h /usr/include/stdio.h /usr/include/features.h
server.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
server.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
server.o: /usr/include/gnu/stubs-64.h
server.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
server.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
server.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
server.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
server.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
server.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
server.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
server.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
server.o: /usr/include/sys/types.h /usr/include/time.h
server.o: /usr/include/sys/select.h /usr/include/bits/select.h
server.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
server.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
server.o: /usr/include/alloca.h /usr/include/errno.h
server.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
server.o: /usr/include/asm/errno.h /usr/include/asm-generic/errno.h
server.o: /usr/include/asm-generic/errno-base.h /usr/include/string.h
server.o: /usr/include/xlocale.h /usr/include/netinet/in.h
server.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint.h
server.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdint-gcc.h
server.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
server.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
server.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
server.o: /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h
server.o: /usr/include/asm-generic/sockios.h /usr/include/bits/in.h
server.o: /usr/include/arpa/inet.h /usr/include/netdb.h
server.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
server.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
server.o: /usr/include/bits/environments.h /usr/include/bits/confname.h
server.o: /usr/include/getopt.h /usr/include/signal.h
server.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
server.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
server.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
server.o: /usr/include/bits/sigthread.h
DieWithError.o: /usr/include/stdio.h /usr/include/features.h
DieWithError.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
DieWithError.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
DieWithError.o: /usr/include/gnu/stubs-64.h
DieWithError.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stddef.h
DieWithError.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
DieWithError.o: /usr/include/libio.h /usr/include/_G_config.h
DieWithError.o: /usr/include/wchar.h
DieWithError.o: /usr/lib/gcc/x86_64-linux-gnu/4.6/include/stdarg.h
DieWithError.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
DieWithError.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
DieWithError.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
DieWithError.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
DieWithError.o: /usr/include/sys/types.h /usr/include/time.h
DieWithError.o: /usr/include/sys/select.h /usr/include/bits/select.h
DieWithError.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
DieWithError.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
DieWithError.o: /usr/include/alloca.h
