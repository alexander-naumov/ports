COMMENT=	library for manipulating structured configuration files

DISTNAME=	libconfig-1.7.3

SHARED_LIBS +=  config               12.0     # 12.0
SHARED_LIBS +=  config++             12.0     # 12.0

CATEGORIES=	devel

HOMEPAGE=	https://hyperrealm.github.io/libconfig/

# LGPLv2.1
PERMIT_PACKAGE=	Yes

WANTLIB += m ${COMPILER_LIBCXX}

COMPILER=	base-clang ports-gcc base-gcc

MASTER_SITES=	https://hyperrealm.github.io/libconfig/dist/

CONFIGURE_STYLE=	gnu

TEST_TARGET=	test

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libconfig
	${INSTALL_DATA} ${WRKSRC}/examples/c/*.c \
		${PREFIX}/share/examples/libconfig
	${INSTALL_DATA} ${WRKSRC}/examples/c++/*.cpp \
		${PREFIX}/share/examples/libconfig
	${INSTALL_DATA} ${WRKSRC}/examples/c/*.cfg \
		${PREFIX}/share/examples/libconfig

.include <bsd.port.mk>
