ONLY_FOR_ARCHS=	i386 amd64

COMMENT=	simple tool to dump cpuid information

PKGNAME=	cpuid-20160409
REVISION=	1
DISTFILES=

CATEGORIES=	sysutils

# ISC
PERMIT_PACKAGE=	Yes

WANTLIB=	c

NO_TEST=	Yes

do-build:
	cp ${FILESDIR}/cpuid.c ${WRKSRC}/
	cd ${WRKSRC}; ${MAKE_PROGRAM} cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${PREFIX}/bin

.include <bsd.port.mk>
