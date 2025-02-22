ONLY_FOR_ARCHS =	amd64 i386

COMMENT =		open source compiler for Pascal/Object Pascal

V =			3.2.2
DISTNAME =		fpcbuild-${V}
PKGNAME =		fpc-${V}

FPCBOOT-amd64 =		fpcboot-openbsd-amd64-$V-1.tar.gz
FPCBOOT-i386 =		fpcboot-openbsd-i386-$V-1.tar.gz

CATEGORIES =		lang

HOMEPAGE =		http://www.freepascal.org/

MAINTAINER =		Pascal Stumpf <pascal@stumpf.co>

# compiler: GPLv2+, packages/rtl: modified LGPLv2
PERMIT_PACKAGE =	Yes

WANTLIB += c iconv pthread

LIB_DEPENDS =		converters/libiconv

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=freepascal/}
MASTER_SITES0 =		https://distfiles.stumpf.co/
DIST_SUBDIR =		fpc

.if ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Mi386}
DISTFILES =		${DISTNAME}${EXTRACT_SUFX} ${FPCBOOT-${MACHINE_ARCH}}:0
.endif
SUPDISTFILES =		${FPCBOOT-amd64}:0 ${FPCBOOT-i386}:0

.if ${MACHINE_ARCH} == "amd64"
COMPNAME =		ppcx64
CONFIG =		x86_64-openbsd
PKG_ARGS +=		-Damd64=1
PKG_ARGS +=		-Di386=0
.else
COMPNAME =		ppc386
CONFIG =		i386-openbsd
PKG_ARGS +=		-Di386=1
PKG_ARGS +=		-Damd64=0
.endif

SUBST_VARS +=		V CONFIG

TEST_DEPENDS =		devel/nasm

MAKE_FLAGS =		NOGDB=1
COMMON_ENV =		MKDIRPROG=/bin/mkdir ECHO=/bin/echo \
			GINSTALL=/usr/bin/install DATE=/bin/date \
			TARPROG=/bin/tar
MAKE_ENV =		${COMMON_ENV} \
			FPC="${WRKDIR}/bootstrap/bin/${COMPNAME}" \
			LD_LIBRARY_PATH="${WRKDIR}/bootstrap/lib"
TEST_ENV =		${COMMON_ENV}
FAKE_FLAGS =		INSTALLEXE="${INSTALL_PROGRAM}" \
			MKDIR="${INSTALL_DATA_DIR}" \
			INSTALL="${INSTALL_DATA}"

TEST_FLAGS =		TEST_FPC="${WRKSRC}/fpcsrc/compiler/${COMPNAME}" \
			FPC="${WRKSRC}/fpcsrc/compiler/${COMPNAME}" \
			OPT="-Fu${WRKSRC}/fpcsrc/rtl/units/${CONFIG} -Fu${WRKSRC}/fpcsrc/packages/rtl-objpas/units/${CONFIG}" \
			TEST_OPT="-Fu${WRKSRC}/fpcsrc/rtl/units/${CONFIG}" \
			FPCMAKE="${WRKSRC}/fpcsrc/utils/fpcm/bin/${CONFIG}/fpcmake"

USE_GMAKE =		Yes

post-install:
	cd ${PREFIX}/bin && ln -s ../lib/fpc/${V}/${COMPNAME} .
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/fpc/lexyacc
	chmod ${DIRMODE} ${PREFIX}/lib/fpc/lexyacc/
	chmod ${SHAREMODE} ${PREFIX}/lib/fpc/lexyacc/*
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/fpc-${V}/fpc
	chmod ${DIRMODE} ${PREFIX}/share/doc/fpc-${V}/fpc/
	chmod ${SHAREMODE} ${PREFIX}/share/doc/fpc-${V}/fpc/*
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fpc-$V
	# generate sample config file
	${PREFIX}/bin/fpcmkcfg -d "basepath=${TRUEPREFIX}/lib/fpc/$V" \
		-o ${PREFIX}/share/examples/fpc-$V/fpc.cfg.sample

do-test:
	find ${WRKSRC} -name Package.fpc -delete
	cd ${WRKSRC}/fpcsrc/tests && \
		env -i ${ALL_TEST_ENV} ${MAKE_PROGRAM} ${ALL_TEST_FLAGS} full

BOOTSTRAPDIR=${WRKDIR}/bootstrap-prepare
bootstrap: build
	mkdir -p ${BOOTSTRAPDIR}/bootstrap/{bin,lib}
	cp ${WRKSRC}/fpcsrc/compiler/${COMPNAME} ${BOOTSTRAPDIR}/bootstrap/bin
	ldd ${BOOTSTRAPDIR}/bootstrap/bin/${COMPNAME} \
		| awk '$$3 == "rlib" { print $$7 }' \
		| xargs -J % cp % ${BOOTSTRAPDIR}/bootstrap/lib
	cd ${BOOTSTRAPDIR} && tar cf - bootstrap | \
		gzip > ${FULLDISTDIR}/${FPCBOOT-${MACHINE_ARCH}}

.include <bsd.port.mk>
